/*基础题。数据结构，栈。依次扫描每个字符，遇到左括号压栈，
  右括号，将其匹配的左括号弹栈，并检查次左括号前面是否是
  左括号，若不是，则将两个矩阵相乘。遇到矩阵，检查前面是
  否为左括号，若是，则将矩阵压栈，否则，与栈顶的矩阵相乘。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 28
#define LEN 100
struct Matrix {
	int row, col;
};
Matrix matrixes[NUM], stack[LEN];
int top = 0;
int main()
{
	int n, i, e = 0;
	long long int  r = 0;
	char c;
	for(i=0; i<NUM; i++) matrixes[i].col = matrixes[i].row = 0;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%c%c", &c, &c);
		scanf("%d %d", &matrixes[c-'A'].row, &matrixes[c-'A'].col);
	}
	scanf("%c", &c);
	while (scanf("%c", &c)>0) {
		if (c>='A' && c<='Z') {
			stack[top].row = matrixes[c-'A'].row;
			stack[top].col = matrixes[c-'A'].col;
		}
		else stack[top].row = -1;
		top++;
		while(scanf("%c", &c)>0) {
			if (c == '\n') break;
			if (e == 1) continue;
			switch(c) {
			case '(':
				stack[top++].row = -1;
				break;
			case ')':
				top--;
				stack[top-1] = stack[top];
				if(top-2 >=0 && stack[top-2].row != -1) {
					if (stack[top-2].col != stack[top-1].row) e = 1;
					else {
						r = r+stack[top-2].row*stack[top-2].col*stack[top-1].col;
						stack[top-2].col = stack[top-1].col;
						top--;
					}
				}
				break;
			default:
				if(stack[top-1].row == -1) {
					stack[top].row = matrixes[c-'A'].row;
					stack[top].col = matrixes[c-'A'].col;
					top++;
					break;
				}
				if (stack[top-1].col != matrixes[c-'A'].row) e = 1;
				else {
					r = r+stack[top-1].row*stack[top-1].col*matrixes[c-'A'].col;
					stack[top-1].col = matrixes[c-'A'].col;
				}
			}
		}
		if (e == 1) printf("error\n");
		else printf("%llu\n", r);
		r = e = top = 0;
	}
	return 0;
}