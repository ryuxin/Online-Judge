//入门题。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char l[2][200],s[5][200];
int main()
{
	int p,len,i,j;
	cin>>p;
	gets(l[0]);
	while(p--) {
		gets(l[0]);
		gets(l[1]);
		len=strlen(l[0]);
		for(i=0;i<len;i++)
		{
			if(l[0][i]=='<')
				break;
			s[0][i]=l[0][i];
		}
		s[0][i++]='\0';
		j=0;
		for(;i<len;i++)
		{
			if(l[0][i]=='>')
				break;
			s[1][j++]=l[0][i];
		}
		s[1][j++]='\0';
		i++;
		j=0;
		for(;i<len;i++)
		{
			if(l[0][i]=='<')
				break;
			s[2][j++]=l[0][i];
		}
		s[2][j++]='\0';
		i++;
		j=0;
		for(;i<len;i++)
		{
			if(l[0][i]=='>')
				break;
			s[3][j++]=l[0][i];
		}
		s[3][j++]='\0';
		i++;
		j=0;
		for(;i<len;i++)
			s[4][j++]=l[0][i];
		s[4][j++]='\0';
		for(i=0;i<5;i++)
			cout<<s[i];
		cout<<endl;
		len=strlen(l[1]);
		for(i=0;i<len-3;i++)
			cout<<l[1][i];
		cout<<s[3]<<s[2]<<s[1]<<s[4]<<endl;
	}
	return 0;
}