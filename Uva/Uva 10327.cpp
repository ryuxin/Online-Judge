/*分治，逆序数。类似归并排序，将数组分为两半，分别求出这两半的逆序数并排序，再求这两半之间的逆序数*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define Maxl 1005
int data[Maxl], temp[Maxl];
int Reverse_num(int l, int r)
{
	int i, j, m, re, t;
	if(l == r)
		return 0;
	m = (l+r)/2;
	re = Reverse_num(l, m)+Reverse_num(m+1, r);
	i = t = l;
	j = m+1;
	while(i<=m && j<=r) {
		if(data[i]>data[j]) {
			re = re+m-i+1;
			temp[t++] = data[j++];
		}
		else
			temp[t++] = data[i++];
	}
	while (i<=m) {
		temp[t++] = data[i++];
	}
	for(i=l; i<t; i++)
		data[i] = temp[i];
	return re;
}
int main()
{
	int n, i, r;
	while(scanf("%d",&n)>0) {
		for(i=0; i<n; i++)
			scanf("%d", &data[i]);
		r = Reverse_num(0, n-1);
		printf("Minimum exchange operations : %d\n",r);
	}
	return 0;
}

