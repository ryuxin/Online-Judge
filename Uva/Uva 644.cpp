//入门题。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char code[20][20];
int comp(const void *a1,const void *a2)
{
	char *p1=(char *)a1;
	char *p2=(char *)a2;
	return strlen(p1)-strlen(p2);
}
int main()
{
	int i,j,k,c=0;
	bool re;
	i=0;
	while(cin>>code[i])
	{
		if(code[i][0]=='9')
		{
			c++;
			re=true;
			qsort(code,i,sizeof(code[0]),comp);
			for(j=0;j<i-1;j++)
			{
				for(k=j+1;k<i;k++)
				{
					//!!必须是前缀，也就是起始相同的位置必须在开始处
					if(strstr(code[k],code[j])==code[k])
					{
						re=false;
						break;
					}
				}
				if(re==false)
					break;
			}
			if(re==true)
				cout<<"Set "<<c<<" is immediately decodable"<<endl;
			else
				cout<<"Set "<<c<<" is not immediately decodable"<<endl;
			i=0;
		}
		else
			i++;
	}
	return 0;
}