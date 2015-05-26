/*入门题。深搜回溯。枚举所有八皇后的解，选出总值最大的。
  记录下每一行放置皇后的位置。
  由于每行皇后所在的列构成了0-NUM的全排列，所以可以直接
  生成所有排列，并尽早剪去不符合要求的排列。
  下面给出这两种实现方法。直觉上感觉后一种应该快一些，但
  提交结果却相反，不知为什么。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 8
#define LEN 15
int data[NUM][NUM], cur, best;
int position[NUM];
/*bool Check(int a, int b)
{
	int i, t;
	for(i=a-1; i>=0; --i) {
		t = position[i]-b;
		if (t == 0 || a-i == t || i-a == t)
			return false;
	}
	return true;
}
void DFS(int k)
{
	int i, old;
	if (k == NUM) {
		if (best<cur) best = cur;
		return ;
	}
	for(i=0; i<NUM; ++i) {
		if (Check(k,i)) {
			old = cur;
			cur += data[k][i];
			position[k] = i;
			DFS(k+1);
			cur = old;
		}
	}
}*/
bool Check(int a, int b)
{
	int i, t;
	for(i=a-1; i>=0; --i) {
		t = position[i]-b;
		if (a-i == t || i-a == t)
			return false;
	}
	return true;
}
void DFS(int k)
{
	int i, old, t;
	if (k == NUM) {
		if (best<cur) best = cur;
		return ;
	}
	t = position[k];
	old = cur;
	for(i=k; i<NUM; ++i) {
		if (Check(k,position[i])) {
			cur += data[k][position[i]];
			position[k] = position[i];
			position[i] = t;
			DFS(k+1);
			cur = old;
			position[i] = position[k];
		}
	}
	position[k] = t;
}
int main()
{
	int k, i, j;
	scanf("%d", &k);
	while(k) {
		for(i=0; i<NUM; ++i) 
			scanf("%d%d%d%d%d%d%d%d", &data[i][0], &data[i][1], &data[i][2], 
			&data[i][3], &data[i][4], &data[i][5], &data[i][6], &data[i][7]);
		for(i=NUM-1; i>=0; --i) position[i] = i;
		cur = best = 0;
		DFS(0);
		printf("%5d\n", best);
		--k;
	}
	return 0;
}