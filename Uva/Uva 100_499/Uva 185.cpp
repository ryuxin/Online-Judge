/*基础题。深搜。第一问始终没有读懂，不过实现并不麻烦。从左到右扫描，若当前的比下一位大，则当前这位取正，
 *否则取负。所以最后一位一定是正。
 *第二问是直观的深搜。对于每一个出现的字母，依次枚举0-9可能的取值，当前两个数确定后，判断第三个数是否
 *有可能的取值，使之等于前两个数之和。
 *一些剪枝条件：不能有前导0，两个字母不能去同一个数。当可行解多余一个的时候，就没有必要继续搜索了。*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 40
#define LEN 26
char input[NUM], *sum[3];
char *output[5] = {"Correct", "Incorrect", "ambiguous", "impossible", "valid"};
char letter[7] = {'I', 'V', 'X', 'L','C', 'D', 'M'};
int va[LEN], num[LEN], re[3], tot, shu[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int len[3], begin, used[10];
static inline void swap(int *a, int *b) {int c = *a; *a = *b; *b = c; }
static int roman_num(char *s)
{
	int l = strlen(s), i, r=0;
	for(i=0; i<l-1; i++) {
		if (va[s[i]-'A'] >= va[s[i+1]-'A']) r += va[s[i]-'A'];
		else r -= va[s[i]-'A'];
	}
	r += va[s[l-1]-'A'];
	return r;
}
static inline bool check(char *s, int l, int v)
{
	int r=1, i, t, t1;
	for(i=l-1; i>=0; i--) {
		t = v%10;
		v /= 10;
		t1 = num[s[i]-'A'];
		if (t1 != -1) {
			if (t1 != t && t1 != 10+t) r = 0;
		} else {
			if (used[t]) r = 0;
			else {
				used[t] = 1;
				num[s[i]-'A'] = t+10;
			}
		}
		if (!r) break;
	}
	if (v>0 || num[s[0]-'A'] == 0) r = 0;
	for(i=0; i<7; i++) {
		t = letter[i]-'A';
		if (num[t] >= 10) {
			used[num[t]-10] = 0;
			num[t] = -1;
		}
	}
	return r;
}
static void DFS(int r, int s, int l, int v)
{
	int i, t, c = 1;
	if (tot > 1) return ;
	if (s == l) {
		if (r == 1) {
			if (check(sum[2], len[2], re[0]+re[1])) tot++;
		} else DFS(r+1, 0, len[r+1], pow(10.0, len[r+1]-1));
		return ;
	}
	if (num[sum[r][s]-'A'] != -1) {
		re[r] += num[sum[r][s]-'A']*v;
		DFS(r, s+1, l, v/10);
		re[r] -= num[sum[r][s]-'A']*v;
	} else {
		t = begin;
		begin++;
		for(i=t; i<10; i++) {
			if (!s && !shu[i]) continue;
			used[shu[i]] = 1;
			swap(&shu[t], &shu[i]);
			num[sum[r][s]-'A'] = shu[t];
			re[r] += num[sum[r][s]-'A']*v;
			DFS(r, s+1, l, v/10);
			re[r] -= num[sum[r][s]-'A']*v;
			swap(&shu[t], &shu[i]);
			used[shu[i]] = 0;
		}
		begin--;
		num[sum[r][s]-'A'] = -1;
	}
}
int main()
{
	int i, r1, r2=3;
	va['I'-'A'] = 1;
	va['V'-'A'] = 5;
	va['X'-'A'] = 10;
	va['L'-'A'] = 50;
	va['C'-'A'] = 100;
	va['D'-'A'] = 500;
	va['M'-'A'] = 1000;
	while(1) {
		scanf("%s", input);
		if (input[0] == '#') break;
		i=0;
		while(1) {
			if (input[i] == '+') {
				sum[0] = &input[0];
				sum[1] = &input[i+1];
				input[i] = '\0';
			} else if (input[i] == '=') {
				sum[2] = &input[i+1];
				input[i] = '\0';
				break;
			}
			i++;
		}
		if (roman_num(sum[0]) + roman_num(sum[1]) == roman_num(sum[2])) r1 = 0;
		else r1 = 1;
		for(i=0; i<3; i++) len[i] = strlen(sum[i]);
		memset(num, -1, sizeof(num));
		memset(used, 0, sizeof(used));
		tot = begin = re[0] = re[1] = re[2] = 0;
		DFS(0, 0, len[0], pow(10.0, len[0]-1));
		if (tot == 0) r2 = 3;
		else if (tot == 1) r2 = 4;
		else r2 = 2;
		printf("%s %s\n", output[r1], output[r2]);
	}
	return 0;
}