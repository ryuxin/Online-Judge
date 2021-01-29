/*基础题。枚举；二分。解法1：依次枚举每个字母，求出该字母的支配长度。
 *具体地，对于一个字母，其连续两次出现的最大距离，即为其支配长度；
 *有两个边界情况，字符串开始到该字母的第一次出现，以及该字母最后出
 *现的位置到字符串结束，也要考虑进去。
 *解法2：二分枚举支配长度l，检查是否存在一些字符，在每个长度为l的
 *子串中都出现。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define NUM 100005
#define LEN 26
#define CHAE2NUM(c) ((c) - 'a')
char str[NUM];
int pos[LEN], ma[LEN];
int main()
{
	int i, m, len;
	scanf("%s", &str);
	len = strlen(str);
	memset(pos, -1, sizeof(pos)); //边界情况1，字符串开始到第一次出现
	memset(ma, 0, sizeof(ma));
	for(i=0; i<len; i++) {
		m = CHAE2NUM(str[i]);
		ma[m] = max(ma[m], i-pos[m]);
		pos[m] = i;
	}
	//边界情况2，最后一次出现到字符串结束
	for(i=0; i<LEN; i++) ma[i] = max(ma[i], len-pos[i]);
	for(m = len, i=0; i<LEN; i++) {
		if (ma[i]) m = min(m, ma[i]);
	}
	printf("%d\n", m);
	return 0;
}
/*

#define NUM 100005
#define LEN 26
char str[NUM];
int num[LEN], re[NUM];
static bool
check(int k, int len)
{
	int i, j;
	memset(re, 0, sizeof(re));
	memset(num, 0, sizeof(num));
	for(i=0, j=0; j<k; j++) {
		num[str[j]-'a']++;
	}
	//re[j]表示，包含字符j的子串数目
	for(j=0; j<LEN; j++) re[j] += !!num[j];

	for(i=1; i+k-1<len; i++) {
		num[str[i-1]-'a']--;
		num[str[i+k-1]-'a']++;
		for(j=0; j<LEN; j++) re[j] += !!num[j];
	}
	for(j=0; j<LEN; j++) {
		//字母j，在i（len-k+1）个子串中都出现
		if (re[j] == i) return true;
	}
	return false;
}
int main()
{
	int l=1, r, m, len;
	scanf("%s", &str);
	len = r = strlen(str);
	while (l<r) {
		m = l + (r-l)/2;
		if (check(m, len)) r = m;
		else l = m+1;
	}
	printf("%d\n", r);
	return 0;
}
*/