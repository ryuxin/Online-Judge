//入门题。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char data[1000];
double P,U,I;
bool co_P,co_U,co_I;
double translate_num(int l,int r)
{
	int dian,i;
	double re=0,jw,fu=1;
	if(data[l]=='-')
		fu=-1;
	for(dian=l;dian<=r;dian++)
		if(data[dian]=='.')
			break;
	jw=1;
	for(i=dian-1;i>=l;i--)
	{
		re=(double)(data[i]-'0')*jw+re;
		jw=jw*10;
	}
	jw=10;
	for(i=dian+1;i<=r;i++)
	{
		re=re+(double)(data[i]-'0')/jw;
		jw=jw*10;
	}
	return re*fu;
}
void translate(int pos)
{
	int t;
	double jw=1;
	t=pos;
	while(1)
	{
		if(data[t]=='W'||data[t]=='A'||data[t]=='V')
			break;
		t++;
	}
	switch (data[t-1])
	{
	case 'm':
		jw=jw/1000;
		t=t-1;
		break;
	case 'k':
		jw=jw*1000;
		t=t-1;
		break;
	case 'M':
		jw=jw*1000*1000;
		t=t-1;
	}
	switch (data[pos-1])
	{
	case 'P':
		co_P=true;
		P=translate_num(pos+1,t-1)*jw;
		break;
	case 'U':
		co_U=true;
		U=translate_num(pos+1,t-1)*jw;
		break;
	case 'I':
		co_I=true;
		I=translate_num(pos+1,t-1)*jw;
	}
	return ;
}
int main()
{
	int n,i,j,l;
	cin>>n;
	gets(data);
	for(i=1;i<=n;i++)
	{
		gets(data);
		co_P=co_U=co_I=false;
		l=strlen(data);
		for(j=0;j<l;j++)
			if(data[j]=='=')
				translate(j);
		cout<<"Problem #"<<i<<endl;
		if(co_U==false)
			printf("U=%.2fV\n",P/I);
		else if(co_I==false)
			printf("I=%.2fA\n",P/U);
		else
			printf("P=%.2fW\n",U*I);
		cout<<endl;
	}
}