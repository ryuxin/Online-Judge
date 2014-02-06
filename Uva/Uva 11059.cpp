/*动规。max[i]和min[i]分别表示以i结尾的字串中的最大乘积和最小乘积。转移方程
  max[i]=Maxx{data[i],data[i]*max[i-1],data[i]*min[i-1]}。当然，也可以枚举所有子串*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int data[20];
long long int max_p[20],min_p[20];
int main()
{
	int i,j,n,c=0;
	long long int m,t;
	while(cin>>n) {
		for(i=0;i<n;i++)
			cin>>data[i];
		c++;
		max_p[0]=min_p[0]=data[0];
		for(i=1;i<n;i++) {
			max_p[i]=data[i]>data[i]*max_p[i-1]?data[i]:data[i]*max_p[i-1];
			max_p[i]=max_p[i]>data[i]*min_p[i-1]?max_p[i]:min_p[i-1]*data[i];
			min_p[i]=data[i]<data[i]*max_p[i-1]?data[i]:data[i]*max_p[i-1];
			min_p[i]=min_p[i]<data[i]*min_p[i-1]?min_p[i]:data[i]*min_p[i-1];
		}
		m=0;
		for(i=0;i<n;i++)
			if(max_p[i]>m)
				m=max_p[i];
		cout<<"Case #"<<c<<": The maximum product is "<<m<<"."<<endl<<endl;
	}
	return 0;
}
