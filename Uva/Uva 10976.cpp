/*入门题。枚举+简单数学。1/k=1/x+1/y (x>=y)，可得x=yk/(y-k)，由x>=y，解得y<=2k。因此
有k<y<=2k。枚举y，若y-k能整除yk，则符合题意*/
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