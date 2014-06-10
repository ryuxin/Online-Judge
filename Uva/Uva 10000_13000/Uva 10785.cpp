/*入门题。简单搜索+排序。确定权值最小的名字不难，因为元音和辅音是分开计算的，所以
  这两个独立，可以分别求解。求解时，只要按照权值的顺序依次搜索，并控制使用的次数即
  可。最需要注意的地方是，最后的结果要是字符序最小的。所以要把所有选中的字母排序*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int n, tc[21], tv[5], cc, cv;
char re[220], vo[6] = "AUEOI";
char co[22] = "JSBKTCLDMVNWFXGPYHQZR";
char rec[120], rev[120];
void Calc_vo(int k)         //计算要使用到的元音
{
	int i;
	if (k>=n)
		return ;
	for (i=0; i<5; i++)
		if (tv[i] > 0) {
			rev[cv++] = vo[i];
			tv[i]--;
			Calc_vo(k+2);
			break;
		}
	return ;
}
void Calc_co(int k)          //计算要使用到的辅音
{
	int i;
	if (k>=n)
		return ;
	for (i=0; i<21; i++)
		if (tc[i] > 0) {
			rec[cc++] = co[i];
			tc[i]--;
			Calc_co(k+2);
			break;
		}
	return ;
}
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return (*p1)-(*p2);
}
int main()
{
	int i, t, j, t1, t2;
	scanf("%d", &t);
	for(i=1; i<=t; i++) {
		scanf("%d", &n);
		for(j=0; j<21; j++)
			tc[j] = 5;
		for(j=0; j<5; j++)
			tv[j] = 21;
		cc = cv = 0;
		Calc_vo(0);
		Calc_co(1);
		//对得到的字母排序
		qsort(rec, cc, sizeof(char), comp);
		qsort(rev, cv, sizeof(char), comp);
		t1 = t2 = 0;
		for(j=0; j<n; j++) {
			if(j%2 == 0)
				re[j] = rev[t1++];
			else
				re[j] = rec[t2++];
		}
		re[n] = '\0';
		printf("Case %d: %s\n", i, re);
	}
	return 0;
}