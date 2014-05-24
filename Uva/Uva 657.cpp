/*基础题。DFS. 进行两遍DFS.第一遍找出所有的dice，第二遍找出没个dice的dot.
  对每个dice进行标记时，标记他是第几个。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 55
char data[NUM][NUM];
int used[NUM][NUM], re[1500], num, cur = 0;
int o1[4] = {-1, 0, 1, 0}, o2[4] = {0, 1, 0, -1}; 
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p1)-(*p2);
}
void DFS_1(int a, int b)
{
	int i;
	used[a][b] = num;
	for(i=0; i<4; i++) 
		if (data[a+o1[i]][b+o2[i]] != '.' && used[a+o1[i]][b+o2[i]] == -1)
			DFS_1(a+o1[i], b+o2[i]);
	return ;
}
void DFS_2(int a, int b)
{
	int i;
	used[a][b] = -1;
	for(i=0; i<4; i++) 
		if (data[a+o1[i]][b+o2[i]] == 'X' && used[a+o1[i]][b+o2[i]]>-1)
			DFS_2(a+o1[i], b+o2[i]);
	return ;
}
int main()
{
	int w, h, i, j;
	for(i=0; i<NUM; i++) {
		data[0][i] = data[i][0] = '.';
		used[0][i] = used[i][0] = -1;
	}
	while(scanf("%d%d", &w, &h)>0) {
		if (w == 0) break;
		cur++;
		num = -1;
		for(i=1; i<h+2; i++)
			for(j=1; j<w+2; j++)
				used[i][j] = -1;
		for(i=1; i<=h; i++)  scanf("%s", &data[i][1]);
		for(i=0; i<w+2; i++) data[h+1][i] = '.';
		for(i=0; i<h+2; i++) data[i][w+1] = '.';
		for(i=1; i<=h; i++)
			for(j=1; j<=w; j++) {
				if (data[i][j] != '.' && used[i][j] == -1) {
					num++;
					DFS_1(i, j);
				}
			}
		for(i=0; i<=num; i++) re[i] = 0;
		for(i=1; i<=h; i++) 
			for(j=1; j<=w; j++) {
				if (data[i][j] == 'X' && used[i][j]>-1) {
					re[used[i][j]]++;
					DFS_2(i, j);
				}
			}
		qsort(re, num+1, sizeof(int), comp);
		printf("Throw %d\n%d", cur, re[0]);
		for(i=1; i<=num; i++) printf(" %d", re[i]);
		printf("\n\n");
	}
	return 0;
}