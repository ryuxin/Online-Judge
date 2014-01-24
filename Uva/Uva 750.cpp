/*����+���ݡ���ĳһ�У�����ö�������У�ȷ���Ƿ���Է����ӡ�����һ���㣨x��y��������Ƶ����ҶԽ���,����
y��Ľؾ�ֱ��ʾΪleft[y+x]��right[y-x+8]
ע�⣬���ʱ�ǰ����������Ҫ����,���û�п���*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define right __right
#define left __left
bool row[9],__left[19],__right[19];
int re[9],c,x,y;
void DFS(int r)
{
	int i;
	if(r==9)
	{
		c++;
		printf("%2d     ",c);
		for(i=1;i<9;i++)
			cout<<' '<<re[i];
		cout<<endl;
	}
	if(r==x)
		DFS(r+1);
	else
	{
		for(i=1;i<9;i++)
		{
			if(row[i]&&left[r+i]&&right[i-r+8])
			{
				re[r]=i;
				row[i]=left[r+i]=right[i-r+8]=false;
				DFS(r+1);
				row[i]=left[r+i]=right[i-r+8]=true;
			}
		}
	}
}
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>y>>x;
		for(i=0;i<9;i++)
			row[i]=true;
		for(i=0;i<19;i++)
			left[i]=right[i]=true;
		row[y]=false;
		left[x+y]=false;
		right[y-x+8]=false;
		re[x]=y;
		c=0;
		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		DFS(1);
		if(t)
			cout<<endl;
	}
	return 0;
}