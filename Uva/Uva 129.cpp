/*
�����⡣���ѡ���ÿ��λ�ã�����ö�����п��ܵ���ĸ��������Ҫ�󣬼������������ظ��Ӵ�ʱ��
�ݹ�������һ��λ�ã��������һ��ֱ���ﵽ��Ҫ��Ľ�������жϵ�ǰ�ַ���s[1��n]�Ƿ�����Ҫ��ʱ��
�����ǵݹ����ò㣬����s[1��n-1]һ����������������ֻ���ж��Ƿ���ڰ���s[n]�������ظ��Ӵ���
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
char data[90];
int n,k,r;
bool Check_repeat(char *a, int l)     //�ַ���a�Ƿ������a[l]��β���ظ��ִ�
{
	int i=l-1,j;
	while(i>=l/2) {
		if(a[i]==a[l]) {              //ǰһ���Ӵ�����Ҳ��a[l]��β
			for(j=2*i+1-l;j<i;j++)
				if(a[j]!=a[j-i+l])
					break;
			if(j==i)
				return true;
			i=i-2;                    //��a[i]=a[l]����a[i-1]!=a[l]
		}
		else
			i=i-1;
	}
	return false;
}
void print_string(char *a, int l)
{
	int i,j,h,t,b=0;
	for(i=0;i<l;i++) {
		printf("%c",a[i]);
		if((1+i)%(4*16)==0)
			printf("\n");
		else if((1+i)%4==0)
			printf(" ");
	}
	printf("%c\n%d\n",a[l],l+1);
	return ;
}
void DFS(int a)
{
	int i;
	for(i=0;i<k;i++) {
		data[a]='A'+i;
		if(Check_repeat(data,a)==false) {
			r=r+1;
			if(r==n) {
				print_string(data,a);
				return ;
			}
			DFS(a+1);
			if(r>=n)
				return ;
		}
	}
	return ;
}
int main()
{
	while(scanf("%d%d",&n,&k)>0) {
		if(n==0&&k==0)
			break;
		r=0;
		DFS(0);
	}
	return 0;
}