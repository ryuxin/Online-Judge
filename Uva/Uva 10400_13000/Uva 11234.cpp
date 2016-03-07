/*基础题。数据结构。树的遍历。后缀表达式对应表达式树的后根
  遍历。而用队列的顺序是该树宽度优先遍历的逆序。所以根据输
  入建树，然后进行BFS，最后逆序输出BFS的遍历结果。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 100005
#define LEN 35
struct Node {
	char v;
	int l, r;
};
Node tree[NUM];
int top, stack[NUM], n;
char data[NUM];
void Solve(void)
{
	int head = 0, t, tail = 1, i;
	while(head<tail) {
		t = stack[head++];
		if (tree[t].v>='a' && tree[t].v<='z') continue;
		stack[tail++] = tree[t].l;
		stack[tail++] = tree[t].r;
	}
	for(i=n-1; i>=0; i--) data[n-i-1] = tree[stack[i]].v;
	printf("%s\n", data);
}
int main()
{
	int i, t;
	char c;
	scanf("%d\n", &t);
	while(t--) {
		n = top = 0;
		scanf("%s", data);
		while(c = data[n]) {
			tree[n].v = c;
			if (c>='a' && c<='z') stack[top++] = n++;
			else if (c>='A' && c<='Z') {
				tree[n].r = stack[top-1];
				tree[n].l = stack[top-2];
				stack[top-2] = n++;
				top--;
			}
		}
		Solve();
	}
	return 0;
}