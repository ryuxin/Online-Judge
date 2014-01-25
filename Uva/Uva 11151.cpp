/*基础动规。dp[i][j]表示从i到j的范围内最长的回文串长度。则转移方程为：若si==sj，dp[i][j]=2+dp[i+1][j-1]；
否则dp[i][j]=max{dp[i+1][j],dp[i][j-1]}。另外，题目中明确提到空串也是回文串，所以输入中可能含有空串，显然，空串的长度为0*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int dp[1010][1010];
char data[1010];
int main()
{ 
     int i,j,t,l,n;
     cin>>t;
     gets(data);
     while(t--) {
	  gets(data);
	  n=strlen(data);
	  for(i=0;i<n+1;i++)
	       for(j=0;j<n+1;j++)
		    dp[i][j]=0;
	  for(i=0;i<n+1;i++)
	       dp[i][i]=1;
	  for(l=2;l<=n;l++) {
	       for(i=0;i<=n-l;i++) {
		    if(data[i]==data[i+l-1])
			 dp[i][i+l-1]=2+dp[i+1][i+l-2];
		    else
			 dp[i][i+l-1]=dp[i+1][i+l-1]>dp[i][i+l-2]?dp[i+1][i+l-1]:dp[i][i+l-2];
	       }
	  }
	  if(n==0)
	       cout<<0<<endl;
	  else
	       cout<<dp[0][n-1]<<endl;	  
     }
     return 0;
}


