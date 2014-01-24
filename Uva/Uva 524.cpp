/*
回溯搜索，圆排列。起始位置可以假定一直是1，因为对任意一个圆排列，都可以通过旋转，将1移到起始的位置。
相邻两个数之和为素数，则他们至少要有不同的奇偶性。因此奇数位置只需枚举奇数，偶数位置只需枚举偶数。
另外，可先将所有素数都存下来
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int n, re[20];
bool used[20],sushu[36];
void DFS(int k)
{
	int i,j;
	if(k>n) {
		if(sushu[1+re[k-1]]==true) {
			for(i=1;i<n;i++)
				printf("%d ",re[i]);
			printf("%d\n",re[n]);
		}
		return ;
	}
	j=k%2;
	for(i=2-j;i<=n;i=i+2) {
		if((used[i]==false)&&(sushu[i+re[k-1]]==true)) {
				re[k]=i;
				used[i]=true;
				DFS(k+1);
				used[i]=false;
		}
	}
}
int main()
{
	int i,t=0;
	for(i=0;i<36;i++)
		sushu[i]=true;
	for(i=2;i<36;i++) 
		if(sushu[i]==true) 
			for(t=2*i;t<36;t=t+i)
				sushu[t]=false;
	re[1]=1;
	used[1]=true;
	t=0;
	while(scanf("%d", &n)>0) {
		for(i=2;i<n;i++)
			used[i]=false;
		t++;
		if(t!=1)
				printf("\n");
		printf("Case %d:\n", t);
		DFS(2);
	}
	return 0;
}