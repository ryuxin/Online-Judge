//入门题。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char info[200],sa1[21]={'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1',
		'2','3','5','8'},sa2[21]={'A','3','H','I','L','J','M','O','2','T','U',
		'V','W','X','Y','5','1','S','E','Z','8'};
char data[22];
int Is_P(char *s)
{
	int i,l;
	char t[22];
	l=strlen(s);
	for(i=l-1;i>=0;i--)
		t[i]=s[l-i-1];
	t[l]='\0';
	if(strcmp(s,t)!=0)
		return 0;
	else
		return 1;
}
int Is_M(char *s)
{
	int i,l;
	char t[22];
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(info[s[i]]==' ')
			return 0;
		t[l-i-1]=info[s[i]];
	}
	t[l]='\0';
	if(strcmp(s,t)!=0)
		return 0;
	else
		return 2;
}
int main()
{
	int i,re;
	for(i=0;i<200;i++)
		info[i]=' ';
	for(i=0;i<21;i++)
		info[sa1[i]]=sa2[i];
	while(cin>>data)
	{
		re=0;
		re=re+Is_P(data);
		re=re+Is_M(data);
		switch (re)
		{
		case 0:
			cout<<data<<" -- is not a palindrome."<<endl<<endl;
			break;
		case 1:
			cout<<data<<" -- is a regular palindrome."<<endl<<endl;
			break;
		case 2:
			cout<<data<<" -- is a mirrored string."<<endl<<endl;
			break;
		case 3:
			cout<<data<<" -- is a mirrored palindrome."<<endl<<endl;
		}
	}
	return 0;
}