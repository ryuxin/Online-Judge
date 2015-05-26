//入门题
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char excuse[25][250],word[25][25],temp[250],t[25];
int num[25],best,key;
bool Find(char *s)
{
	int i;
	for(i=0;i<key;i++)
		if(strcmp(s,word[i])==0)
			return true;
	return false;
}
int Check(char *s)
{
	int i,len,re=0,j;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			temp[i]=s[i]-'A'+'a';
		else
			temp[i]=s[i];
	}
	temp[len]='\0';
	j=0;
	for(i=0;i<=len;i++)
	{
		if(temp[i]>='a'&&temp[i]<='z')
			t[j++]=temp[i];
		else
		{
			t[j]='\0';
			if(Find(t)==true)
				re++;
			j=0;
		}
	}
	return re;
}
int main()
{
	int ex,i,r=0;
	while(cin>>key>>ex)
	{
		best=0;
		r++;
		for(i=0;i<key;i++)
			cin>>word[i];
		gets(excuse[0]);
		for(i=0;i<ex;i++)
		{
			gets(excuse[i]);
			num[i]=Check(excuse[i]);
			if(num[i]>best)
				best=num[i];
		}
		cout<<"Excuse Set #"<<r<<endl;
		for(i=0;i<ex;i++)
			if(num[i]==best)
				cout<<excuse[i]<<endl;
		cout<<endl;
	}
}