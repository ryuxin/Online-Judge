/*基础题。动规。dp[i][j]表示将s1[i:]转化为s2[j:]需要的最少
 *操作，path[i][j]表示相应采用的操作。dp可以压缩到2维。输
 *出每次的操作时，要注意维护当前需要修改的字符串的位置。
 *边界问题：输入的字符串最后一个字符是换行，要删掉。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 25
#define LEN 50
char path[NUM][NUM], dat[LEN];
int dp[2][NUM];
static void 
DP(char *s1, char *s2, int l1, int l2)
{
	int i, j, c, t1, t2, t3;
	dp[0][l2] = 0;
	for(i=l2-1; i>=0; i--) {
		dp[0][i] = l2-i;
		path[l1][i] = 'I';
	}
	for(c=1, i=l1-1; i>=0; i--) {
		dp[c][l2] = l1-i;
		path[i][l2] = 'D';
		for(j=l2-1; j>=0; j--) {
			if (s1[i] == s2[j]) {
				path[i][j] = 'N';
				dp[c][j] = dp[1-c][j+1];
			} else {
				t1 = dp[c][j+1];
				t2 = dp[1-c][j];
				t3 = dp[1-c][j+1];
				if (t1 <= t2 && t1 <= t3) {
					dp[c][j] = t1+1;
					path[i][j] = 'I';
				} else if (t2 <= t1 && t2 <= t3) {
					dp[c][j] = t2+1;
					path[i][j] = 'D';
				} else {
					dp[c][j] = t3+1;
					path[i][j] = 'C';
				}
			}
		}
		c = 1-c;
	}
}
static void
Print_path(char *s1, char *s2, int l1, int l2)
{
	int i=0, j=0, pos=1;
	while (i<l1 || j<l2) {
		switch (path[i][j]) {
		case 'I':
			printf("I%c%02d", s2[j++], pos++);
			break;
		case 'D':
			printf("D%c%02d", s1[i++], pos);
			break;
		case 'C':
			printf("C%c%02d", s2[j], pos);
		case 'N':
			i++;
			j++;
			pos++;
			break;
		}
	}
	printf("E\n");
}
int main()
{
	char *s2;
	int l1, l2;
	while (fgets(dat, LEN, stdin)) {
		if (dat[0] == '#') break;
		for(s2=dat+1, l1=1; *s2 != ' '; s2++, l1++) ;
		l2 = strlen(++s2)-1;
		DP(dat, s2, l1, l2);
		Print_path(dat, s2, l1, l2);
	}
	return 0;
}
