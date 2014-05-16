/*基础题。简单几何+枚举。大体思路，枚举所有点对，找出与该点对共线
  的所有点。优化，找到共线的点后，可将这些点记录下来，以后不再枚
  举这些点之间的点对。
  另外，可以枚举每一个点，计算其他点相对该点的斜率，斜率相同则说
  明共线，复杂度n*n*logn，但斜率实现比向量复杂*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 705
#define LEN 1010
struct Point {
	int x, y;
};
Point data[NUM];
int line[NUM], num, done[NUM][NUM], best;
char in[30];
void Line(int a, int b)
{
	int x1, y1, x2, y2, i, j;
	x1 = data[a].x-data[b].x;
	y1 = data[a].y-data[b].y;
	int cur = 0;
	for(i=0; i<num; i++) {
		x2 = data[i].x-data[b].x;
		y2 = data[i].y-data[b].y;
		if (x1*y2-x2*y1 == 0) 
			line[cur++] = i;
	}
	for(i=0; i<cur; i++)
		for(j=i+1; j<cur; j++) {
			done[line[i]][line[j]] = cur;
			done[line[j]][line[i]] = cur;
		}
	if (cur>best) best = cur;
	return ;
}
int main()
{
	int i, j, t, l;
	scanf("%d", &t);
	gets(in);
	gets(in);
	while(t--) {
		num = 0;
		while(gets(in) != NULL) {
			l = strlen(in);
			if (l == 0) break;
			sscanf(in, "%d", &data[num].x);
			for(i=0; i<l; i++) 
				if (in[i] == ' ')
					break;
			sscanf(in+i+1, "%d", &data[num].y);
			num++;
		}
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
				done[i][j] = 0;
		for(i=0; i<num; i++) done[i][i] = 1;
		best = 0;
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
				if (done[i][j] == 0)
					Line(i, j);
		printf("%d\n", best);
		if (t != 0) printf("\n");
	}
	return 0;
}	