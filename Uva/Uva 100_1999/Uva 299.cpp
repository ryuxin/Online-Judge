/*
  分治，逆序数。类似归并排序，将数组分为两半，分别求出这两半的逆序数并排序，再求这两半之间的逆序数
  注意，题目中0<=L!
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int l,data[60], temp[60];
int Inverse_num(int s, int e)
{
	int i,j,c,t1,t2,r,m;
	if(s>=e)
		return 0;
	m=(s+e)/2;
	t1=Inverse_num(s,m);
	t2=Inverse_num(m+1,e);
	r=t1+t2;
	c=i=s;
	j=m+1;
	while(i<=m && j<=e) {
		if(data[i]<=data[j])
			temp[c++]=data[i++];
		else {
			r=r+m+1-i;
			temp[c++]=data[j++];
		}
	}
	while(i<=m) {
		temp[c++]=data[i++];
	}
	for(i=s;i<c;i++)
		data[i]=temp[i];
	return r;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&l);
		for(i=0;i<l;i++)
			scanf("%d",&data[i]);
		i=Inverse_num(0,l-1);
		printf("Optimal train swapping takes %d swaps.\n",i);
	}
	return 0;
}

