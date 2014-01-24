/*»Î√≈Ã‚°£*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define Len 10002
int data[Len];
int comp(const void *a1,const void *a2)
{
	int *p1,*p2;
	p1=(int *)a1;
	p2=(int *)a2;
	return *p1-*p2;;
}
int main()
{
	int i,n,q,c=0,t;
	while(1)
	{
		cin>>n>>q;
		if(n==0)
			break;
		c++;
		cout<<"CASE# "<<c<<":"<<endl;
		for(i=0;i<n;i++)
			cin>>data[i];
		qsort(data,n,sizeof(int),comp);
		while(q--)
		{
			cin>>t;
			for(i=0;i<n;i++)
				if(data[i]==t)
					break;
			if(i==n)
				cout<<t<<" not found"<<endl;
			else
				cout<<t<<" found at "<<i+1<<endl;
		}
	}
	return 0;
}