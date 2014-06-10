/*基础题。树的遍历。用栈实现DFS。遍历时，栈顶保存当前节点到根的距离。
  注意判断子树，空树和叶子。另外，从右子树返回时，要弹栈。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10005
int in[NUM], po[NUM], stack[NUM];
int top, best, bestl, num;
char data[6*NUM];
void DFS(int s1, int e1, int s2, int e2, bool left)
{
	int i, r, j;
	if (s1>e1) goto ret;            //空树
	else if (s1 == e1) {            //叶子
		r = stack[top-1]+in[s1];
		if (r<best) {
			bestl = in[s1];
			best = r;
		}
		else if (r == best) {
			if (in[s1]<bestl)
				bestl = in[s1];
		}
		goto ret;
	}
	r = stack[top-1]+po[e2];
	stack[top++] = r;
	for(i=s1; i<=e1; i++) 
		if (in[i] == po[e2])
			break;
	DFS(s1, i-1, s2, s2+i-1-s1, true);
	DFS(i+1, e1, s2+i-s1, e2-1, false);
ret:
	if (left == false) top--;
	return ;
}
int main()
{
	int i, j, l;
	while(gets(data) != NULL) {
		num = 0;
		sscanf(data, "%d", &in[num++]);
		l = strlen(data);
		for(i=0; i<l; i++) {
			if (data[i] == ' ')
				sscanf(data+i+1, "%d", &in[num++]);
		}
		gets(data);
		num = top = 0;
		stack[top++] = 0;
		sscanf(data, "%d", &po[num++]);
		l = strlen(data);
		for(i=0; i<l; i++) {
			if (data[i] == ' ')
				sscanf(data+i+1, "%d", &po[num++]);
		}
		best = bestl = (1<<30);
		DFS(0, num-1, 0, num-1, true);
		printf("%d\n", bestl);
	}
	return 0;
}