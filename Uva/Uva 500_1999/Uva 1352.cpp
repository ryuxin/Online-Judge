/*入门题。枚举，深搜。由于一个立方体最多有24种不同的旋转方式，依次
 *枚举每个立方体的所有旋转方式。当每个立方体的位置给定后，对于每一
 *个面，选出出现次数最多的一种颜色，其余颜色都改成那种颜色，显然这
 *使改动的次数最小化。
 *优化：第一个立方体不需要枚举所有旋转方式。
 *生成所有旋转方式，可以用常量表，也可以自动生成。可以用绕x轴和y轴
 *旋转确定朝前的面，然后绕x轴旋转，确定剩余的面。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 5
#define LEN 6
#define TRANS 24
#define COLOR 30
struct Cube {
	int face[LEN+1];
};
int mapping[TRANS][LEN] = {
	{1, 2, 3, 4, 5, 6}, {1, 4, 2, 5, 3, 6}, {1, 5, 4, 3, 2, 6}, {1, 3, 5, 2, 4, 6}, 
	{2, 6, 3, 4, 1, 5}, {2, 4, 6, 1, 3, 5}, {2, 1, 4, 3, 6, 5}, {2, 3, 1, 6, 4, 5}, 
	{3, 2, 6, 1, 5, 4}, {3, 1, 2, 5, 6, 4}, {3, 5, 1, 6, 2, 4}, {3, 6, 5, 2, 1, 4}, 
	{4, 2, 1, 6, 5, 3}, {4, 6, 2, 5, 1, 3}, {4, 5, 6, 1, 2, 3}, {4, 1, 5, 2, 6, 3}, 
	{5, 1, 3, 4, 6, 2}, {5, 4, 1, 6, 3, 2}, {5, 6, 4, 3, 1, 2}, {5, 3, 6, 1, 4, 2}, 
	{6, 5, 3, 4, 2, 1}, {6, 4, 5, 2, 3, 1}, {6, 2, 4, 3, 5, 1}, {6, 3, 2, 5, 4, 1}};
Cube cubes[NUM], transfer[NUM][TRANS], *re[NUM];
int tot[NUM], n, nc, best, cnt[COLOR];
char color[NUM*LEN][COLOR], input[COLOR];
static inline int Color_id(char *c)
{
	for(int i=0; i<nc; i++) if (!strcmp(c, color[i])) return i;
	strcpy(color[nc], c);
	return nc++;
}
static inline bool Cube_equal(Cube *c1, Cube *c2)
{
	for(int i=1; i<=LEN; i++) if (c1->face[i] != c2->face[i]) return false;
	return true;
}
static inline void do_transfer(Cube *c1, int *m, Cube *c2)
{
	for(int i=0; i<LEN; i++) c2->face[i+1] = c1->face[m[i]];
}
static inline void Cube_transfer(int k)
{
	int i, t = 0, j;
	for(i=0; i<TRANS; i++) {
		do_transfer(&cubes[k], mapping[i], &transfer[k][t]);
		for(j=0; j<t; j++) {
			if (Cube_equal(&transfer[k][j], &transfer[k][t])) break;
		}
		if (j == t) t++;
	}
	tot[k] = t;
}
static inline void Pretransfer(void)
{
	for(int i=1; i<n; i++) Cube_transfer(i);
	re[0] = &cubes[0];
}
static inline void Calc()
{
	int i, m, j, t = 0;
	for(i=1; i<=LEN; i++) {
		memset(cnt, 0, nc*sizeof(int));
		m = 0;
		for(j=0; j<n; j++) cnt[re[j]->face[i]]++;
		for(j=0; j<nc; j++) if (cnt[j] > m) m = cnt[j];
		t += (n-m);
		if (t>=best) return;
	}
	if (t<best) best = t;
}
static void DFS(int k)
{
	int i;
	while(1) {
		if (k>=n) {
			Calc();
			return ;
		}
		for(i=0; i<tot[k]-1; i++) {
			re[k] = &transfer[k][i];
			DFS(k+1);
		}
		re[k] = &transfer[k][i];
		k++;
	}
}
int main()
{
	int i, j;
	while(scanf("%d", &n)) {
		if (!n) break;
		nc = 0;
		for(i=0; i<n; i++) {
			for(j=1; j<=LEN; j++) {
				scanf("%s", input);
				cubes[i].face[j] = Color_id(input);
			}
		}
		if (n > 1 && nc > 1) {
			best = n*LEN;
			Pretransfer();
			DFS(1);
		} else best = 0;
		printf("%d\n", best);
	}
	return 0;
}