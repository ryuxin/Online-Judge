/*入门题。深搜。按照从左到右，从上到下的顺序处理所有格子，对于一
 *个格子，从小到大尝试每个字母，这样第一次填满方格时，即得到答案
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 13
#define LEN 25
#define COVERT(k, x, y) x=k/n+1; y=(k%n)+1
char gird[NUM][NUM];
int n;
static inline bool
Check(int x, int y, char c)
{
	if (gird[x+1][y] == c) return false;
	if (gird[x-1][y] == c) return false;
	if (gird[x][y+1] == c) return false;
	if (gird[x][y-1] == c) return false;
	return true;
}
static bool DFS(int k)
{
	int x, y, i;
	while(1) {
		if (k>=n*n) return true;
		COVERT(k, x, y);
		if (gird[x][y] != '.') k++;
		else {
			for(i=0; i<26; i++) {
				if (!Check(x, y, 'A'+i)) continue;
				gird[x][y] = 'A'+i;
				if (DFS(k+1)) return true;
				gird[x][y] = '.';
			}
			return false;
		}
	}
}
int main()
{
	int c, mcase, i, j;
	memset(gird, 0, sizeof(gird));
	scanf("%d", &mcase);
	for(c=1; c<=mcase; c++) {
		scanf("%d", &n);
		for(i=1; i<=n; i++) scanf("%s", &gird[i][1]);
		DFS(0);
		printf("Case %d:\n", c);
		for(i=1; i<=n; i++) printf("%s\n", &gird[i][1]);
	}
	return 0;
}