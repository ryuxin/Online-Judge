//搜索回溯，注意所有等可能在5小时时同时变绿
//这种情况，应算允许。且此时相交的区间变为一个点
#include <iostream>
#include <cmath>
#include <cstring>	
#include <cstdlib> 
#include <stdio.h>
#include <iomanip>
using namespace std;
int len;       //交通灯的个数
int Left,Right;      //相交的区间，左开右闭，除非只有一个点
int cyc[102];
int start[102];
bool found;
int Com(const void *e1,const void *e2)
{
	int *p1=(int *)e1;
	int *p2=(int *)e2;
	return *p2-*p1;
}
int Jiao(int l,int r)
{
	if(r<=Left)	return -1;
	else {
		if(r<Right) {
			Right=r;
			Left=l>=Left? l :Left;
			return 0;
		} else {
			if(r==Right) {
				if(Left<Right) {
					Left=l>=Left? l :Left;
					return 0;
				}
				else return -1;
			} else {
				if(l>Right)	return 1;
				else {
					if(l==Right) {
						if(Left==Right)
							return 0;
						else
							return 1;
					} else {
						Left=l>=Left? l :Left;
						return 0;
					}	
				}
			}
		}
	}
}
void back(int k)
{
	if(k==len) {
		found=true;
		return ;
	} else {
		int i,j,l,r;
		l=Left;
		r=Right;
		for(i=start[k];found==false;i=i+2)
		{
			if(found==false)
			{
				Left=l;
				Right=r;
				j=Jiao(i*cyc[k],(i+1)*cyc[k]-5);
				if(j==-1)
					continue;
				if(j==1)
				{
					start[k]=i;
					break;
				}
				if(j==0)
					back(k+1);
			}
		}
		return ;
	}
}
int main()
{
	int i=0;
	while(cin>>cyc[i])
	{
		if(cyc[i]==0)
		{
			cin>>i>>i;
			break;
		}
		else
		{
			while(true)
			{
				i++;
				cin>>cyc[i];
				if(cyc[i]==0)
					break;
			}
			len=i;
			qsort(cyc,len,sizeof(int),Com);
			for(i=0;i<len-1;i++)
				start[i]=0;
			start[len-1]=2;
			for(i=0;i*cyc[0]<=5*3600;i=i+2)
			{
				if(found==false)
				{
					Left=i*cyc[0];
					Right=(i+1)*cyc[0]-5>5*3600? 5*3600:(i+1)*cyc[0]-5;
					back(1);
				}
				else
					break;
			}
			if(found)
			{
				int h,m,s;
				s=Left%60;
				Left=(Left-s)/60;
				m=Left%60;
				h=(Left-m)/60;
				cout<<setfill('0');
				cout<<setw(2)<<h<<':'<<setw(2)<<m<<':'<<setw(2)<<s<<endl;
			}
			else cout<<"Signals fail to synchronise in 5 hours"<<endl;
			i=0;
			found=false;
		}
	}
	return 0;
}