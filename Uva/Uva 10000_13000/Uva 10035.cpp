//入门题。大整数。输出结果中的operation注意单复数
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
char s1[11],s2[11];
int re;
void Transfer(long long int a, char *s)
{
	int i=0;
	do {
		s[i++]='0'+a%10;
		a=a/10;
	}while(a!=0);
	s[i]='\0';
	return ;
}
void Jiafa(char *j1,char *j2)
{
	char *p1,*p2;
	int i,jw,l1,l2;
	if(strlen(j1)>strlen(j2))
	{
		p1=j1;
		p2=j2;
	}
	else
	{
		p1=j2;
		p2=j1;
	}
	l1=strlen(p1);
	l2=strlen(p2);
	jw=0;
	for(i=0;i<l2;i++)
	{
		jw=(p1[i]-'0'+p2[i]-'0'+jw)/10;
		if(jw>0) re++;
	}
	for(;i<l1;i++)
	{
		jw=(p1[i]-'0'+jw)/10;
		if(jw>0) re++;
	}
	return ;
}
int main()
{
	long long int a,b;
	while(cin>>a>>b)
	{
		if(a==0&&b==0) break;
		re=0;
		Transfer(a,s1);
		Transfer(b,s2);
		Jiafa(s1,s2);
		if(re==0)
			cout<<"No carry operation."<<endl;
		else if(re==1)
			cout<<re<<" carry operation."<<endl;
		else
			cout<<re<<" carry operations."<<endl;
	}
	return 0;
}