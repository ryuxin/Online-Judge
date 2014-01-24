//入门题。字符串处理
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char find_s[12][100],reply[12][100],data[300];
int main()
{
	int n,i,j,lf,lr,ld;
	char *p;
	while(cin>>n)
	{
		if(n==0)
			break;
		gets(data);
		for(i=0;i<n;i++)
		{
			gets(find_s[i]);
			gets(reply[i]);
		}
		gets(data);
		for(i=0;i<n;i++)
		{
			lf=strlen(find_s[i]);
			lr=strlen(reply[i]);
			while((p=strstr(data,find_s[i]))!=NULL)
			{
				ld=strlen(data);
				if(lf>lr)
				{
					for(j=p-data+lf;j<=ld;j++)
						data[j-lf+lr]=data[j];
				}
				else
				{
					for(j=ld;j>=p-data+lf;j--)
						data[j-lf+lr]=data[j];
				}
				for(j=0;j<lr;j++)
					data[p-data+j]=reply[i][j];
			}
		}
		cout<<data<<endl;
	}
	return 0;
}