/*入门题。树。从根到叶的路径组成的数，就是叶子的索引。根在最高位，叶
  在最低位。根据输入，存储每个变量在哪一个位。再根据变量的赋值，确定
  用来选取叶子的索引。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 8
#define LEN 15
int index[NUM];
char lef[1<<NUM];
int main()
{
	int n, m, i, c = 1, re;
	char tree[NUM];
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=n-1; i>=0; --i) {
			scanf("%s", tree);
			index[tree[1]-'0'-1] = i;
		}
		scanf("%s%d",lef, &m);
		printf("S-Tree #%d:\n", c);
		while(m--) {
			re = 0;
			scanf("%s", tree);
			for(i=0; i<n; ++i) re |= ((tree[i]-'0')<<index[i]);
			printf("%c", lef[re]);
		}
		printf("\n\n");
		c++;
	}
	return 0;
}