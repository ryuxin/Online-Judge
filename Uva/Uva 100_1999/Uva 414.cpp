//入门题。题目大意,第一列属于左面,第25列属于右面,要将两面连在一起.只要有一行全是X时,左右两面就算连在一起,求连接后空格的数目.
//一定是具有最多X的一行先连在一起。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char s[30];
int main()
{
	int i,max,sum,n,g,j;
	while(1)
	{
		cin>>g;
		cin.getline(s,30);       
		if(g==0)
			break;
		max=0;
		sum=0;
		for(j=0;j<g;j++)
		{
			n=0;
			cin.getline(s,30);
			for(i=0;i<25;i++)
				if(s[i]=='X')
					n++;
			if(n>max)
				max=n;
			sum+=n;
		}
		cout<<g*25-sum-g*(25-max)<<endl;
	}
	return 0;
}