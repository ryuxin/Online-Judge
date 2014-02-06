/*入门题.线性筛法求素数*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define Len 1000003
bool check[Len]={0};
int sushu[Len/2];
int Shaifa(void)
{
	int i,l=0,j;
	for(i=2;i<Len;i++) {
		if(check[i]==false) {
			for(j=i+i;j<Len;j=j+i)
				check[j]=true;
			sushu[l++]=i;
		}
	}
	return l;
}
int main()
{ 
	int n,i,l,r;
	l=Shaifa();
	while(1) {
		cin>>n;
		r=0;
		if(n==0)
			break;
		for(i=0;sushu[i]<=n/2;i++) {
			if(check[n-sushu[i]]==false) {
				cout<<n<<" = "<<sushu[i]<<" + "<<n-sushu[i]<<endl;
				break;
			}
		}	
	}
	return 0;
}


