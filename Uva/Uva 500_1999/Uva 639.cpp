/*基础题。回溯深搜。枚举所有可能状态。按照从左到右，从上到下的顺序搜索没个格子。
  若该格子不能放，搜索下一个。否则放一个棋子，并标记其所影响的格子，搜索下一个。
  之后回溯恢复状态，尝试不在该格子放棋子，搜索下一个。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 7
char chord[NUM][NUM];
int n, best, cur;
int Set(int a, int b, char c1, char c2)   //返回该行下一个尝试的位置
{
	int i, r =  n;
	for(i=b; i<n; i++) {
		if (chord[a][i] == c1) chord[a][i] = c2;
		else {
			r = i+1;
			break;
		}
	}
	for(i=a+1; i<n; i++) {
		if (chord[i][b] == c1) chord[i][b] = c2;
		else break;
	}
	return r;
}
void Backtrace(int a, int b)
{
	int i, j, t;
	for(i=b; i<n; i++) {
		if (chord[a][i] != '.') continue;
		cur++;
		t = Set(a, i, '.', 'a'+a*n+i);
		Backtrace(a, t);
		Set(a, i, 'a'+a*n+i, '.');
		cur--;
		Backtrace(a, i+1);
		break;
	}
	if (i < n) return;
	for(i=a+1; i<n; i++) {
		for(j=0; j<n; j++){
			if (chord[i][j] != '.') continue;
			cur++;
			t = Set(i, j, '.', 'a'+i*n+j);
			Backtrace(i, t);
			Set(i, j, 'a'+i*n+j, '.');
			cur--;
			Backtrace(i, j+1);
			return;
		}
	}
	if (i == n) {
		if (cur>best) best = cur;
		return ;
	}
	return ;
}
int main()
{
	int i, j;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=0; i<n; i++)
			scanf("%s", &chord[i]);
		cur = best = 0;
		Backtrace(0, 0);
		printf("%d\n", best);
	}
	return 0;
}