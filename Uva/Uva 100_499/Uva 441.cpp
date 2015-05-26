/*基础题。深搜。枚举所有的组合。用一个数组记录已经选定的元素，最后一起打出。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int k, s[15], c, r[7];
void Print(int n)
{
	int i;
	if (n == 6) {
		for (i=0; i<5; i++)
			printf("%d ", r[i]);
		printf("%d\n", r[5]);
		return ;
	}
	//c表示当前的开始位置
	//要保证集合内剩余的数大于未打印的数
	for(i=c; i<k+n-5; i++) {
		r[n] = s[i];
		c = i+1;
		Print(n+1);
	}
}
int main()
{
	int i, f = 0;
	while(scanf("%d", &k)>0) {
		if (k == 0) break;
		for(i=0; i<k; i++)
			scanf("%d", &s[i]);
		c = 0;
		if (f == 0) f = 1;
		else        printf("\n");
		Print(0);
	}
	return 0;
}