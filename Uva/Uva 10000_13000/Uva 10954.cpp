/*基础题。贪心。全部的合并过程构成一个满二叉树。一个数最后被加的次数，等于
  该数在树中的深度，所以最后的总和为S = Sum(d(i)*i)。这样此题和霍夫曼编
  码等价，每次选择最小的两个元素相加，并将二者的和作为新元素插回集合中。
  维护最小值可以二叉最小堆实现。*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 5005
#define Max 500000005
int num, data[NUM];
void Down(int k)
{
	int c = 1, t;
	if (2*k+1>=num) return ;
	if ((2*k+2<num) && (data[2*k+2]<data[2*k+1])) c = 2;
	if (data[k]>data[2*k+c]) {
		t = data[k];
		data[k] = data[2*k+c];
		data[2*k+c] = t;
		Down(2*k+c);
	}
	return ;
}
void Build(void)
{
	int i;
	for(i=(num-2)/2; i>=0; i--) Down(i);
	return ;
}
int Pop(void) 
{
	int r;
	r = data[0];
	data[0] = data[--num];
	Down(0);
	return r;
}
int main()
{
	int i, a, b, re, n;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=0; i<n; i++) scanf("%d", &data[i]);
		data[n] = Max;
		num = n;
		re = 0;
		Build();
		for(i=1; i<n; i++) {
			a = Pop();
			a += data[0];
			re += a;
			data[0] = a;
			Down(0);
		}
		printf("%d\n", re);
	}
	return 0;
}