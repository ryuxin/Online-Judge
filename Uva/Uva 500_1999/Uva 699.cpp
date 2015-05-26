/*基础题。DFS。由于输入就是先根的DFS遍历，可以根据输入通过
 *DFS直接建树，建树的同时可以知道当前节点的最终位置，就可
 *以把当前的值累加到最后结果上。
 *输出的行尾不能有空格，对DFS进行了尾递归的优化。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 10005
#define OFFSET(x) ((x+NUM)%NUM)
int re[NUM], left, right;
void DFS_INPUT(int r)
{
	int t;
	while(1) {
		scanf("%d", &t);
		if (t == -1) return ;
		if (r<left) left = r;
		if (r>right) right = r;
		re[OFFSET(r)] += t;
		DFS_INPUT(r-1);
		r++;
	}
}
int main()
{
	int c = 1, i;
	while(1) {
		left = NUM;
		right = -1;
		memset(re, 0, NUM*sizeof(int));
		DFS_INPUT(0);
		if (right == -1) break;
		printf("Case %d:\n", c++);
		printf("%d", re[OFFSET(left)]);
		for(i=left+1; i<=right; i++) {
			printf(" %d", re[OFFSET(i)]);
		}
		printf("\n\n");
	}
	return 0;
}