/*基础题。动规。最长公共子序列。此题要求打印结果，所以要用path
  数组保存结果产生的路径，但还可以用滚动数组进行压缩。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 105
#define LEN 35
char d1[NUM][LEN], d2[NUM][LEN];
int re[2][NUM], path[NUM][NUM], f, c;
void Print(int a, int b)
{
	if (re[c][0] == 0) return ;
	if (path[a][b] == 0) {
		if (f == 1) {
			printf("%s", d1[a]);
			f = 0;
		}
		else printf(" %s", d1[a]);
		re[c][0]--;
		Print(a+1, b+1);
	}
	if (path[a][b] == 1) Print(a+1, b);
	if (path[a][b] == -1) Print(a, b+1);
	return ;
}
int main()
{
	int l1, l2, i, j;
	l1 = l2 = 0;
	while(scanf("%s", &d1[l1])>0) {
		do {
			if (d1[l1][0] == '#') break;
			else l1++;
		}while(scanf("%s", &d1[l1])>0) ;
		while(scanf("%s", &d2[l2])>0) {
			if (d2[l2][0] == '#') break;
			else l2++;
		}
		for(i=0; i<=l2; i++) re[0][i] = 0;
		re[1][l2] = 0;
		c = 0;
		for(i=l1-1; i>=0; i--) {
			c = 1-c;
			for(j=l2-1; j>=0; j--) {
				if (strcmp(d1[i], d2[j]) == 0) {
					re[c][j] = re[1-c][j+1]+1;
					path[i][j] = 0;
				}
				else {
					if (re[c][j+1] > re[1-c][j]) {
						re[c][j] = re[c][j+1];
						path[i][j] = -1;
					}
					else {
						re[c][j] = re[1-c][j];
						path[i][j] = 1;
					}
				}
			}
		}
		f = 1;
		Print(0,0);
		printf("\n");
		l1 = l2 = 0;
	}
	return 0;
}