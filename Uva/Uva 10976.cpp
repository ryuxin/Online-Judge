/*�����⡣ö��+����ѧ��1/k=1/x+1/y (x>=y)���ɵ�x=yk/(y-k)����x>=y�����y<=2k�����
��k<y<=2k��ö��y����y-k������yk�����������*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int store[10002];
int main()
{
	int i,k,l;
	while(cin>>k)
	{
		l=0;
		for(i=k+1;i<=2*k;i++)
			if(i*k%(i-k)==0)
				store[l++]=i;
		cout<<l<<endl;
		for(i=0;i<l;i++)
			cout<<"1/"<<k<<" = 1/"<<store[i]*k/(store[i]-k)<<" + 1/"<<store[i]<<endl;
	}
	return 0;
}