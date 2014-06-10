/*
  入门题。先求出所有点之间的距离，在分别求出每个点的最近邻居。
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
struct point {
	double x,y,z;
};
point data[5005];
double dis[5005][5005];
int n,re[11];
double Dis(int a, int b)
{
	double t=0;
	t=t+(data[a].x-data[b].x)*(data[a].x-data[b].x);
	t=t+(data[a].y-data[b].y)*(data[a].y-data[b].y);
	t=t+(data[a].z-data[b].z)*(data[a].z-data[b].z);
	return sqrt(t);
}
int Min(double *a)
{
	double m;
	m=a[0];
	int i;
	for(i=1;i<n;i++)
		if(a[i]<m)
			m=a[i];	
	return (int)m;
}
int main()
{
	int i,j,temp;
	for(i=0;i<11;i++)
		re[i]=0;
	while(scanf("%lf%lf%lf",&data[n].x,&data[n].y,&data[n].z)) {
		if(data[n].x==0&&data[n].y==0&&data[n].z==0)
			break;
		n++;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) {
			dis[i][j]=Dis(i,j);
			dis[j][i]=dis[i][j];
		}
	for(i=0;i<n;i++)
		dis[i][i]=3*255*255;
	for(i=0;i<n;i++) {
		temp=Min(dis[i]);
		temp = 10<=temp? 10:temp;
		re[temp]++;
	}
	for(i=0;i<10;i++)
		printf("%4d",re[i]);
	printf("\n");
	return 0;
}
