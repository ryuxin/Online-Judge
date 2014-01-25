//»Î√≈Ã‚°£
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char data[220],re[5005][220],temp[220];
int num;
bool exist(char *s)
{
	int i;
	for(i=0;i<num;i++)
		if(strcmp(re[i],s)==0)
			return false;
	return true;
}
void Insert(char *s)
{
	if(exist(s)==true)
		strcpy(re[num++],s);
	return ;
}
int comp(const void *a1,const void *a2)
{
	char *p1=(char *)a1;
	char *p2=(char *)a2;
	return strcmp(p1,p2);
}
int main()
{
	int n,i,l,j;
	num=0;
	while(gets(data)) {
		l=strlen(data);
		for(i=0;i<l;i++)
			if(data[i]>='A'&&data[i]<='Z')
				data[i]=data[i]-'A'+'a';
		j=0;
		for(i=0;i<=l;i++) {
			if(data[i]>='a'&&data[i]<='z')
				temp[j++]=data[i];
			else {
				temp[j]='\0';
				if(strcmp(temp,"")!=0)
					Insert(temp);
				j=0;
			}
		}
	}
	qsort(re,num,sizeof(re[0]),comp);
	for(i=0;i<num;i++)
		cout<<re[i]<<endl;
	return 0;
}
