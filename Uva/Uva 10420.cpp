/*入门题。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define Len 80
struct name
{
	char na[Len];
	int num;
};
name data[2002];
int comp(const void *a1,const void *a2)
{
	char *p1,*p2;
	p1=(char *)a1;
	p2=(char *)a2;
	return strcmp(p1,p2);
}
int main()
{
	char temp[Len];
	int i,t,l=0;
	cin>>t;
	for(i=0;i<t;i++) {
		data[i].na[0]='\0';
		data[i].num=0;
	}
	while(t--) {
		cin>>temp;
		for(i=0;i<l;i++) {
			if(strcmp(data[i].na,temp)==0) {
				data[i].num++;
				break;
			}
		}
		if(i==l) {
			strcpy(data[l].na,temp);
			data[l++].num++;
		}
		gets(temp);
	}
	qsort(data,l,sizeof(name),comp);
	for(i=0;i<l;i++)
		cout<<data[i].na<<' '<<data[i].num<<endl;
	return 0;
}
