/*入门题。树。将一棵树表示成“根（儿子1儿子2...）”的形式。根据节点下面是否有'|'判断
 *其是否有儿子，然后向左向右扩展'-'确定儿子的范围，最后递归进入每个儿子。注意空树。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 205
#define LEN 500
char tree[NUM][NUM], re[LEN];
int l;
void DFS(int x, int y)
{
	int s, e, len, i;
	re[l++]=tree[x][y];
	re[l++]='(';
	if (tree[x+1][y] == '|') {   //有儿子节点
		x += 2;
		len = strlen(tree[x]);
		for(s=y; tree[x][s] == '-' && s>=0; ) s--;
		for(e=y; tree[x][e] == '-' && e<len; ) e++;
		//找到儿子节点的开始和起始位置后，依次递归进入每个儿子
		len=strlen(tree[++x]);
		for(i=s+1; i<e && i<len; i++) {
			if (tree[x][i] != ' ')
				DFS(x, i);
		}
	}
	re[l++]=')';
}
void Process(void)
{
	int i, len;
	l = 0;
	len = strlen(tree[0]);
	re[l++]='(';
	for(i=0; i<len; i++) {
		if (tree[0][i] != ' ' && tree[0][i] != '#') {
			DFS(0, i);
			break;
		}
	}
	re[l++]=')';
	re[l]='\0';
}
int main()
{
	int c, n;
	scanf("%d", &c);
	gets(tree[0]);
	while(c--) {
		memset(tree, 0, sizeof(tree));
		n = 0;
		while(1) {
			gets(tree[n]);
			if (tree[n][0] == '#')
				break;
			n++;
		}
		Process();
		printf("%s\n", re);
	}
	return 0;
}
