/*基础动规。组合数递推公式：C(m,n)=C(m-1,n)+C(m-1,n-1)*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int dp[102][102];
int Calu(int m,int n)
{
  if(dp[m][n]==-1)
    dp[m][n]=Calu(m-1,n)+Calu(m-1,n-1);
  return dp[m][n];
}
int main()
{
  int m,n,i,j;
  for(i=0;i<102;i++)
    for(j=0;j<102;j++)
      dp[i][j]=-1;
  for(i=0;i<102;i++)
    dp[i][0]=1;
  for(i=0;i<102;i++)
    dp[i][i]=1;
  while(cin>>m>>n)
  {
    if(m==0)
      break;
      Calu(m,n);
      cout<<m<<" things taken "<<n<<" at a time is "<<dp[m][n]<<" exactly."<<endl;
  }
  return 0;
}