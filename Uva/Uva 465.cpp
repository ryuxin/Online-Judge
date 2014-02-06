#include "ryx_bignum.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
BigNum n1,n2,n3,m;
char *mint="2147483647",s1[20000],s2[20000],data[40000];
int main()
{
	char c;
	int i,l,j;
	StingtoBigNum(mint,&m);
	while(gets(data)) {
		l=strlen(data);
		for(i=0;i<l;i++) {
			if(data[i]>'9'||data[i]<'0')
				break;
			s1[i]=data[i];
		}
		s1[i]='\0';
		for(;i<l;i++)
			if(data[i]=='+'||data[i]=='*')
				break;
		c=data[i];
		i++;
		j=0;
		for(;i<l;i++)
			if(data[i]<='9'&&data[i]>='0')
				s2[j++]=data[i];
		s2[j]='\0';
		cout<<data<<endl;
		StingtoBigNum(s1,&n1);
		StingtoBigNum(s2,&n2);
		if(Unsign_comp(&n1,&m)>0)
			cout<<"first number too big"<<endl;
		if(Unsign_comp(&n2,&m)>0)
			cout<<"second number too big"<<endl;
		Initial(&n3);
		if(c=='+')
			Unsign_plus(&n1,&n2,&n3);
		else
			Unsign_mul(&n1,&n2,&n3);
		if(Unsign_comp(&n3,&m)>0)
			cout<<"result too big"<<endl;
	}
	return 0;
}