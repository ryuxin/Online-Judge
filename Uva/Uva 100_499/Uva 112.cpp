/*基础题。数据结构。树+栈。首先从输入建树。左括号压栈，右括号
  弹栈，栈为空时，构成一棵完整的树。
  遍历树，求出节点到根节点的距离。思想方法和建树一样。遇到一个
  节点压栈，右括号弹栈。栈中保存当前节点到根节点的距离。
  注意叶子的判断，压栈和弹栈要匹配。另外输入有负数！*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 10000
char tree[8*NUM];
int goal, top, stack[NUM], cur;
void readtree(void)
{
	char c;
	top = cur = 0;
	while(true) {
		scanf("%c", &c);
		if (c == '(') {
			top++;
			tree[cur++] = c;
		}
		else if (c == ')') {
			tree[cur++] = c;
			top--;
			if (top == 0) break;
		}
		else if (('0'<=c && c<='9')||(c == '-'))
			tree[cur++] = c;
	}
	tree[cur++] = '\0';
	return ;
}
int Calc(void)
{
	int len ,l, r;
	len = strlen(tree);
	if (len == 2) return 0;
	top = 1;
	l = stack[0] = 0;
	while (l<len) {
		if (('0'<=tree[l] && tree[l]<='9')||(tree[l] == '-')) {
			sscanf(tree+l, "%d", &r);
			l++;
			while('0'<=tree[l] && tree[l]<='9') l++;
			if (tree[l+1] == ')' && tree[l+3] == ')') {
				if (stack[top-1]+r == goal) return 1;
				l += 5;
			}
			else {
				stack[top] = r+stack[top-1];
				top++;
			}
		}
		else {
			if (tree[l] == ')') top--;
			if (tree[l] == '(' && tree[l+1] == ')') l++;
			l++;
		}
	}
	return 0;
}
int main()
{
	int r;
	while (scanf("%d", &goal)>0) {
		readtree();
		r = Calc();
		if (r == 1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}	