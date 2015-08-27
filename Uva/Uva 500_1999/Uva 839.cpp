/*基础题。深搜递归。整个天平结构组成一个二叉树。用dfs遍历
 *二叉树，在每个节点读入天平参数，若有子树，先递归处理子树
 *返回子树的重量，然后判断天平是否平衡。最后不能输出空行。
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 45
int DFS()
{
	int w1, d1, w2, d2;
	scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
	if (!w1) w1 = DFS();
	if (!w2) w2 = DFS();
	if (w1<0 || w2<0 || w1*d1 != w2*d2) return -1;
	return w1+w2;
}
int main()
{
	int t, r;
	scanf("%d", &t);
	while(t--) {
		r = DFS();
		if (r<0) printf("NO\n");
		else printf("YES\n");
		if (t) printf("\n");
	}
	return 0;
}