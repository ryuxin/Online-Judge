/*数学题。枚举全部排列.对原始数据排序后，记录每个元素出现的次数，并删除重复的元素。但会超时。
设有n个元素的可重复集合，分别有r1个t1...rk个tk，且r1+r2+…+rk=n。则有如下结论：
1.该集合的所有排列数为P=n!/(r1!*r2!*…*rk!);
2.任意一个元素r在位置i和j出现的次数相同。因此对于任意一列，出现的元素和对应的次数都是相同的，
所以每一列所有元素之和S都是相同的。S<9*12!，仍在int的范围。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define relen 15
using namespace std; 
int num[15],jiec[13];
char data[relen],nore[15];   //注意，最多要有n！个数相加，最后结果是输入的10^10倍
int main()
{
	int i,j,temp,n;
	char t;
	jiec[1]=1;
	for(i=2;i<13;i++)
		jiec[i]=i*jiec[i-1];
	while(cin>>n) {
		if(n==0)
			break;
		for(i=0;i<n;i++)
			cin>>data[i];
		for(i=1;i<n;i++) {              //插入排序
			t=data[i];
			for(j=i-1;j>=0;j--) {
				if(data[j]>t)
					data[j+1]=data[j];
				else
					break;
			}
			data[j+1]=t;
		}
		for(i=0;i<15;i++)
			num[i]=0;
		nore[0]=data[0];
		num[0]=1;
		j=1;
		for(i=1;i<n;i++) {
			if(data[i]!=data[i-1])
				nore[j++]=data[i];
			num[j-1]++;
		}
		/*计算每个元素在每一列出现的次数*/
		temp=1;
		for(i=0;i<j;i++)
			temp=temp*jiec[num[i]];
		temp=jiec[n]/temp;
		for(i=0;i<j;i++)
			num[i]=temp*num[i]/n;
		/*每一列元素的总和*/
		temp=0;
		for(i=0;i<j;i++)
			temp=temp+num[i]*(nore[i]-'0');
		j=0;
		for(i=0;i<n;i++) {
			num[i]=temp+j;
			j=num[i]/10;
			num[i]=num[i]%10;
		}
		i=n-1;
		if(j>0)
			cout<<j;
		else {
			for(i=n-1;i>=1;i--)
				if(num[i]!=0)
					break;
		}
		for(;i>=0;i--)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}
