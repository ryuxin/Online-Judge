/*
  基础题。深搜。对每个位置，依次枚举所有可能的字母。当满足要求，即不出现连续重复子串时，
  递归搜索下一个位置，结果数加一，直到达到所要求的结果数。判断当前字符串s[1…n]是否满足要求时，
  由于是递归进入该层，所以s[1…n-1]一定满足条件，所以只需判断是否存在包含s[n]的连续重复子串。
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
char data[90];
int n,k,r;
bool Check_repeat(char *a, int l)       //字符串a是否包含以a[l]结尾的重复字串
{
	int i=l-1,j;
	while(i>=l/2) {
		if(a[i]==a[l]) {               //前一个子串必须也以a[l]结尾
			for(j=2*i+1-l;j<i;j++)
				if(a[j]!=a[j-i+l])
					break;
			if(j==i)
				return true;
			i=i-2;                    //若a[i]=a[l]，则a[i-1]!=a[l]
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
