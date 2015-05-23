//入门题。注意此算法中的全排列生成算法是无序的。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
#define len 8
char dic[102][len],found[102][len],t[len];
int num_dic,num_found;
int comp(const void *a1,const void *a2)
{
	char *p1,*p2;
	p1=(char *)a1;
	p2=(char *)a2;
	return strcmp(p1,p2);
}
int Search(char *s,int right)
{
	int l,r;
	l=0;
	r=right;
	while(l<r)
	{
		if(strcmp(s,dic[(l+r)/2])==0)
			return (l+r)/2;
		if(strcmp(s,dic[(l+r)/2])>0)
			l=(l+r)/2+1;
		else
			r=(l+r)/2;
	}
	if(strcmp(s,dic[l])==0)
		return l;
	return -1;
}
void DFS(char *s,int pos)
{
	int i,l,temp;
	char tc;
	l=strlen(s);
	if(pos==l-1)
	{
		temp=Search(s,num_dic-1);
		if(temp!=-1)
		{
			strcpy(found[num_found],dic[temp]);
			num_found++;
		}
	}
	else
	{
		tc=s[pos];
		for(i=pos;i<l;i++)
		{
			s[pos]=s[i];
			s[i]=tc;
			DFS(s,pos+1);
			s[i]=s[pos];
			s[pos]=tc;
		}
	}
	return ;
}
void Amalgamation(char *s)
{
	int i,j,l;
	char temp;
	l=strlen(s);
	for(i=1;i<l;i++)
	{
		temp=s[i];
		for(j=i-1;j>=0;j--)
		{
			if(s[j]>temp)
				s[j+1]=s[j];
			else
				break;
		}
		s[j+1]=temp;
	}
	DFS(s,0);      //生成所有排列，并检索
	return ;
}
int main()
{
	int i;
	char pre[len];
	num_dic=0;
	//建立字典
	while(1)
	{
		cin>>pre;
		if(strcmp(pre,"XXXXXX")==0)
			break;
		strcpy(dic[num_dic++],pre);
	}
	qsort(dic,num_dic,sizeof(dic[0]),comp);
	while(1)
	{
		cin>>t;
		if(strcmp(t,"XXXXXX")==0)
			break;
		num_found=0;
		Amalgamation(t);          //将字母排序
		if(num_found==0)
			cout<<"NOT A VALID WORD"<<endl;
		qsort(found,num_found,sizeof(found[0]),comp);
		pre[0]='\0';
		for(i=0;i<num_found;i++)
		{
			if(strcmp(pre,found[i])!=0)
			{
				cout<<found[i]<<endl;
				strcpy(pre,found[i]);
			}
		}
		cout<<"******"<<endl;
	}
	return 0;
}
