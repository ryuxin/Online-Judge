//入门题.深搜。依次扫描每一个节点，发现一个@节点时，以他为根进行深搜，将与其相邻的都标为*，计数加一
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char data[105][105];
int pos1[8]={-1,-1,-1,0,0,1,1,1},pos2[8]={-1,0,1,-1,1,-1,0,1};
void DFS(int x,int y)
{
	data[x][y]='*';
	int i;
	for(i=0;i<8;i++)
		if(data[x+pos1[i]][y+pos2[i]]=='@')
			DFS(x+pos1[i],y+pos2[i]);
	return ;
}
int main()
{
	int m,n,r,i,j;
	while(cin>>m>>n) {
		if(m==0)
			break;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				cin>>data[i][j];
		for(i=0;i<=m+1;i++)
			data[i][0]=data[i][n+1]='*';
		for(i=0;i<=n+1;i++)
			data[0][i]=data[m+1][i]='*';
		r=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++) {
				if(data[i][j]=='@') {
					DFS(i,j);
					r++;
				}
			}
		cout<<r<<endl;
	}
	return 0;
}