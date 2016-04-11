/*中等题。枚举。题目大意：给定a的初始位置，可以对a进行平移，但不能旋转，输出
 *所有组成立方体的组合。首选，对每一种方格，其不同的旋转方式最多有24种。因为
 *每个方格只有六个面，固定向前的这个面后，还可以旋转四次，所以最多有6*4种。
 *预处理时求出每个方格的所有旋转方式，但这要求去掉可能重复的旋转。去重时，将
 *方格平移到离原点最近的位置，若平移后两个方格占据了同样的格子，则它们是重复的。
 *为此，用一个位数组表示哪一个格子被占据了，这就是每种方格的编码。
 *用DFS求解组合立方体的不同方式。对当前方格，要枚举它的所有旋转方式，且对每种
 *旋转方式，还要枚举所有平移位置，当所有方格都放完后，即找到了一种组合方式。
 *虽然可能有很多输入，但由前面可知，a的初始位置最多有24种，这样可以保存下每种
 *初始值所对应的所有组合方式，当遇到相同的初始值时，可以直接输出。
 *剪枝：摆放最后一个方格时，它显然只有一种摆放位置，组合成功后，不必枚举它的
 *其他的旋转和平移方式了。（貌似优化效果很小）
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 6
#define LEN 4
#define BIN 25
#define DIM 3
#define CUBE 30
#define INIT_POINT(p, a, b, c) do {    \
		(p)->coord[0] = (a);           \
		(p)->coord[1] = (b);           \
		(p)->coord[2] = (c); }while(0)
#define ADD_POINT(p, q, x, y, z) \
		INIT_POINT(p, (q)->coord[0]+(x), (q)->coord[1]+(y), (q)->coord[2]+(z))
struct Point {
	int coord[DIM];
};
struct Piece {
	Point points[LEN];       //构成该方格的所有点的坐标
	int code, xm, ym, zm;    //该方格的编码，以及各个方向的最大平移量
};
struct All_piece {
	int tot_cnt;
	Piece pieces[BIN];       //记录该方格的所有可能旋转方式
};
All_piece cons[NUM];
char input[CUBE], cube[DIM][DIM][DIM];
struct Solution {
	int cnt, code;
	char re[485][CUBE];
};
Solution re[BIN];
int re_cnt = 0;
static inline void
Piece_Translate_Max(Piece *p)
{
	int i, j, m[3] = {0};
	for(i=0; i<LEN; i++) {
		for(j=0; j<DIM; j++) {
			if (p->points[i].coord[j] > m[j])
				m[j] = p->points[i].coord[j];
		}
	}
	p->xm = DIM-m[0];
	p->ym = DIM-m[1];
	p->zm = DIM-m[2];
}
static inline void
Piece_Code(Piece *p)
{
	int i, t;
	p->code = 0;
	for(i=0; i<LEN; i++) {
		t = p->points[i].coord[0]*9
		  + p->points[i].coord[1]*3
		  + p->points[i].coord[2];
		p->code |= (1<<t);
	}
}
//将p平移到离原点最近的位置，且所有坐标都非负
static inline void
Piece_Translate(Piece *p)
{
	int i, j, m[3] = {100, 100, 100};
	for(i=0; i<LEN; i++) {
		for(j=0; j<DIM; j++) {
			if (p->points[i].coord[j] < m[j])
				m[j] = p->points[i].coord[j];
		}
	}
	for(i=0; i<LEN; i++) {
		for(j=0; j<DIM; j++)
			p->points[i].coord[j] -= m[j];
	}
	Piece_Code(p);
}
//在x1x2平面上，将点from顺时针旋转，结果保存在to
static inline void
Point_Rotate(Point *from, Point *to, int x1, int x2)
{
	int x3 = 3-x1-x2;
	to->coord[x1] = -1*from->coord[x2];
	to->coord[x2] = from->coord[x1];
	to->coord[x3] = from->coord[x3];
}
static inline void
Piece_Rotate(Piece *from, Piece *to, int x1, int x2)
{
	int i;
	for(i=0; i<LEN; i++) {
		Point_Rotate(&from->points[i], &to->points[i], x1, x2);
	}
	Piece_Translate(to);
}
static inline bool
Piece_Exist(All_piece *p, Piece *q)
{
	int i;
	for(i=0; i<p->tot_cnt; i++) {
		if (p->pieces[i].code == q->code) return true;
	}
	return false;
}
static inline void
Init_head()
{
	int i;
	INIT_POINT(&cons[0].pieces[0].points[1], 0, 0, 1);
	INIT_POINT(&cons[0].pieces[0].points[2], 0, 1, 0);

	INIT_POINT(&cons[1].pieces[0].points[1], 0, 1, 0);
	INIT_POINT(&cons[1].pieces[0].points[2], 0, 1, 1);
	INIT_POINT(&cons[1].pieces[0].points[3], 0, 2, 0);

	INIT_POINT(&cons[2].pieces[0].points[1], 0, 1, 0);
	INIT_POINT(&cons[2].pieces[0].points[2], 0, 1, 1);
	INIT_POINT(&cons[2].pieces[0].points[3], 0, 2, 1);

	INIT_POINT(&cons[3].pieces[0].points[1], 0, 0, 1);
	INIT_POINT(&cons[3].pieces[0].points[2], 0, 1, 0);
	INIT_POINT(&cons[3].pieces[0].points[3], 1, 0, 0);

	INIT_POINT(&cons[4].pieces[0].points[1], 0, 0, 1);
	INIT_POINT(&cons[4].pieces[0].points[2], 0, 1, 1);
	INIT_POINT(&cons[4].pieces[0].points[3], 1, 0, 0);

	INIT_POINT(&cons[5].pieces[0].points[1], 0, 0, 1);
	INIT_POINT(&cons[5].pieces[0].points[2], 0, 1, 1);
	INIT_POINT(&cons[5].pieces[0].points[3], 1, 1, 1);
	for(i=0; i<NUM; i++) Piece_Code(&cons[i].pieces[0]);
}
static inline void
Piece_Rotate_All(All_piece *p, Piece *q, int x1, int x2)
{
	int i, j = 1;
	Piece a[2];
	a[0] = *q;
	for(i=0; i<DIM; i++) {
		Piece_Rotate(&a[1-j], &a[j], x1, x2);
		if (!Piece_Exist(p, &a[j])) {
			p->pieces[p->tot_cnt++] = a[j];
		}
		j = 1-j;
	}
}
static inline void
Init_cons(All_piece *p)
{
	int i, j = 1;
	Piece *cur, *nxt;
	//先固定向前的面，共6种
	Piece_Rotate_All(p, &p->pieces[0], 0, 1);
	Piece_Rotate_All(p, &p->pieces[0], 0, 2);
	//对每一个向前的面，尝试另外的3种旋转
	for(i=0; i<p->tot_cnt; i++) {
		Piece_Rotate_All(p, &p->pieces[i], 1, 2);
	}
	for(i=0; i<p->tot_cnt; i++) {
		Piece_Translate_Max(&p->pieces[i]);
	}
}
static inline void
Init()
{
	int i;
	Init_head();
	for(i=0; i<NUM; i++) {
		cons[i].tot_cnt = 1;
		Init_cons(&cons[i]);
	}
}
static inline bool
Piece_valid(Piece *p)
{
	int i, *n;
	for(i=0; i<LEN; i++) {
		n = p->points[i].coord;
		if (cube[n[0]][n[1]][n[2]]) return false;
	}
	return true;
}
static inline void
Piece_Place(Piece *p, char c)
{
	int i, *n;
	for(i=0; i<LEN; i++) {
		n = p->points[i].coord;
		cube[n[0]][n[1]][n[2]] = c;
	}
}
static bool DFS(int n)
{
	Piece a, *p;
	int i, j, x, y, z;
	if (n == NUM) {
		memcpy(re[re_cnt].re[re[re_cnt].cnt++], cube, sizeof(cube));
		return true;
	}
	//遍历当前方格的所有可能旋转方式
	for(i=0; i<cons[n].tot_cnt; i++) {
		p = &cons[n].pieces[i];
		//枚举当前方格的所有可能平移位置
		for(x=0; x<p->xm; x++) {
			for(y=0; y<p->ym; y++) {
				for(z=0; z<p->zm; z++) {
					for(j=0; j<LEN; j++) {
						ADD_POINT(&a.points[j], &p->points[j], x, y, z);
					}
					if (Piece_valid(&a)) {
						Piece_Place(&a, 'b'+n);
						j = DFS(n+1);  // 摆放下一种方格
						Piece_Place(&a, 0);
						if (n == NUM-1 && j) return false;
					}
				}
			}
		}
	}
	return false;
}
static inline void
Process(Piece *p)
{
	Piece a;
	int x, y, z, i;
	//枚举a的所有可能平移位置
	for(x=0; x<p->xm; x++) {
		for(y=0; y<p->ym; y++) {
			for(z=0; z<p->zm; z++) {
				for(i=0; i<LEN; i++) {
					ADD_POINT(&a.points[i], &p->points[i], x, y, z);
				}
				memset(cube, 0, sizeof(cube));
				Piece_Place(&a, 'a');
				DFS(0);
			}
		}
	}
}
int main()
{
	int i, j;
	Piece init_a;
	memset(re, 0, sizeof(re));
	memset(cons, 0, sizeof(cons));
	Init();
	while(EOF != scanf("%s", input)) {
		j = 0;
		for(i=0; i<27; i++) {
			if (input[i] == 'a') {
				INIT_POINT(&init_a.points[j], i/9, (i%9)/3, i%3);
				j++;
			}
		}
		Piece_Translate(&init_a);
		for(i=0; i<re_cnt; i++) {
			if (re[i].code == init_a.code) break;
		}
		if (i == re_cnt) {
			Piece_Translate_Max(&init_a);
			re[re_cnt].code = init_a.code;
			Process(&init_a);
			re_cnt++;
		}
		for(j=0; j<re[i].cnt; j++) printf("%s\n", re[i].re[j]);
		printf("\n");
	}
	return 0;
}