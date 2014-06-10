/*基础题。排序。可以用类似快排的方法找中位数。另外，本题元素值的上界不大（65536），
  因此可以采用计数排序。对于偶数个元素，其上下中位数都满足条件。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 65540
#define LEN 85
int slot[NUM], n;
void Find_mid(int *u, int *d)      //u 上中位数  d 下中位数
{
	int i, r = 0;
	for(i=0; i<NUM; i++) {
		if (slot[i] == 0) continue;
		r = r+slot[i];
		if (r>=n/2+1) {
			*d = i;
			if (*u == -1) *u = i;
			break;
		}
		else if (r == n/2) *u = i;
	}
	return ;
}
int main()
{
	int i, m1, m2;
	while(scanf("%d", &n)>0) {
		memset(slot, 0, sizeof(int)*NUM);
		for(i=0; i<n; i++) {
			scanf("%d", &m1);
			slot[m1]++;
		}
		m1 = -1;
		Find_mid(&m1, &m2);
		if (n%2 == 1) m1 = m2;
		printf("%d %d %d\n", m1, slot[m1]+(m1 != m2)*slot[m2], m2-m1+1);
	}
	return 0;
}