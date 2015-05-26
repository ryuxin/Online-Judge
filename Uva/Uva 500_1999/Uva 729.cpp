/*基础题。枚举所有排列。注意回溯*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <strings.h>
using namespace std;
#define NUM 20
char data[NUM];
int n;
void DFS(int k, int h)
{
	if (k == n) {
		printf("%s\n", data);
		return ;
	}
	if (n-k<h) return ;
	if (n-k>h) {
		data[k] = '0';
		DFS(k+1, h);
	}
	if (h>0) {
		data[k] = '1';
		DFS(k+1, h-1);
		data[k] = '\0';
	}
	return ;
}
int main()
{
	int i, h, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &h);
		data[n] = '\0';
		DFS(0, h);
		if (t != 0) printf("\n");
	}
	return 0;
}
