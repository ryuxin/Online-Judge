/*
基础题。回溯。对每一个位置，枚举所有可能放置的顶点，并计算该顶点所带来的最大带宽，据此
更新当前的最大带宽，若更新后的最大带宽大于已知的最优带宽，则无需向下递归；否则，递归计算下一个位置
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int grap[10][10], vert_num[26], bestbw, curbest,n;
char data[100], bestor[10], curor[10], vert[10];
int Calbw(int k)        //calculate the maximun bandwidth including cur[k], for cur[0…k]
{
	int i,t,m,mb=0;
	t=vert_num[curor[k]-'A'];
	for(i=0;i<n;i++) {
		if(grap[t][i]==1&&grap[i][9]!=-1) {
			m=k-grap[i][9];
			if(m>mb)
				mb=m;
		}
	}
	return mb;
}
void Backtrace(int k)
{
	int i,j,t,p;
	if(k==n) {
		bestbw=curbest;
		for(i=0;i<n;i++)
			bestor[i]=curor[i];
	}
	else {
		for(i=0;i<n;i++) {
			if(grap[i][9]==-1) {
				curor[k]=vert[i];
				grap[i][9]=k;
				t=Calbw(k);
				p=curbest;
				if(t>curbest)
					curbest=t;
				if(curbest<bestbw) 
					Backtrace(k+1);
				curbest=p;
				grap[i][9]=-1;
			}
		}
	}
	return ;
}
int main()
{
	int i,j,l,pre,t;
	while(1) {
		scanf("%s",data);
		if(data[0]=='#')
			break;
		//collect vertex information
		for(i=0;i<26;i++)
			vert_num[i]=-1;
		l=strlen(data);
		for(i=0;i<l;i++)
			if(data[i]>='A'&&data[i]<='Z')
				vert_num[data[i]-'A']=1;
		n=0;
		for(i=0;i<26;i++)
			if(vert_num[i]==1)
				vert[n++]=i+'A';
		for(i=0;i<n;i++)
			vert_num[vert[i]-'A']=i;
		//construct grap
		for(i=0;i<10;i++) 
			for(j=0;j<10;j++)
				grap[i][j]=-1;
		data[l++]=';';
		pre=-1;
		for(i=0;i<l;i++) {
			if(data[i]==';') {
				t=vert_num[data[pre+1]-'A'];
				for(j=pre+3;j<i;j++) {
					grap[t][vert_num[data[j]-'A']]=1;
					grap[vert_num[data[j]-'A']][t]=1;
				}
				pre=i;
			}
		}
		bestbw=10;
		curbest=0;
		Backtrace(0);
		for(i=0;i<n;i++) 
			printf("%c ",bestor[i]);
		printf("-> %d\n",bestbw);
	}
	return 0;
}



