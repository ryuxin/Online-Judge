/*入门题。贪心。初始时，每个部件都选用最差的。此后，每次先找到最差
 *的部件，并试图提高它的质量。当不能提高质量，或钱数不够时，停止搜
 *索。此时最差部件的质量就是解。可以用最小堆加速寻找最差的部件。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 25
struct Item {
	int p, q;
};
Item items[NUM][NUM];
char name[NUM][LEN];
int ntype, n, money, item_cnt[NUM], map[NUM];
static inline int name_id(char *s)
{
	int i;
	for(i=0; i<ntype; i++) {
		if (!strcmp(name[i], s)) return i;
	}
	strcpy(name[ntype++], s);
	return i;
}
static inline int comp(const void *a1, const void *a2)
{
	Item *p1, *p2;
	p1 = (Item *)a1;
	p2 = (Item *)a2;
	if (p2->q != p1->q) return p2->q-p1->q;
	return p1->p-p2->p;
}
//当a的质量比b好，且价钱比b低时，b肯定不用选。
static inline void remove(int k)
{
	int i, c=0;
	Item *p = items[k];
	for(i=1; i<item_cnt[k]; i++) {
		if (p[i].p >= p[c].p) p[i].p = -1;
		else c = i;
	}
}
static int Proc()
{
	int i, j, sum = 0, mq, mi;
	for(i=0; i<ntype; i++) {
		for(j=item_cnt[i]-1; j>=0; j--) {
			if (items[i][j].p != -1) {
				map[i] = j;
				break;
			}
		}
	}
	for(i=0; i<ntype; i++) sum += items[i][map[i]].p;
	while(1) {
		mq = items[0][map[0]].q;
		mi = 0;
		for(i=1; i<ntype; i++) {
			if (items[i][map[i]].q < mq) {
				mq = items[i][map[i]].q;
				mi = i;
			}
		}
		for(i=map[mi]-1; i>=0; i--) {
			if (items[mi][i].p != -1) break;
		}
		sum = sum-items[mi][map[mi]].p+items[mi][i].p;
		if (i<0 || sum > money) return mq;
		map[mi] = i;
	}
}
int main()
{
	int c, i, id, l;
	char tname[LEN];
	scanf("%d", &c);
	while(c--) {
		ntype = 0;
		scanf("%d%d", &n, &money);
		memset(item_cnt, 0, n*sizeof(int));
		for(i=0; i<n; i++) {
			scanf("%s", tname);
			id = name_id(tname);
			l = item_cnt[id];
			item_cnt[id]++;
			scanf("%s%d%d", tname, &items[id][l].p, &items[id][l].q);
		}
		for(i=0; i<ntype; i++) qsort(items[i], item_cnt[i], sizeof(Item), comp);
		for(i=0; i<ntype; i++) remove(i);
		printf("%d\n", Proc());
	}
	return 0;
}