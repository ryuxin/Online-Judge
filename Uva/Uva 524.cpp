/*
����������Բ���С���ʼλ�ÿ��Լٶ�һֱ��1����Ϊ������һ��Բ���У�������ͨ����ת����1�Ƶ���ʼ��λ�á�
����������֮��Ϊ����������������Ҫ�в�ͬ����ż�ԡ��������λ��ֻ��ö��������ż��λ��ֻ��ö��ż����
���⣬���Ƚ�����������������
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