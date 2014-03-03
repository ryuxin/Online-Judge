/*入门题。动规。dp[i][j]表示从第j个硬币开始，拼出i的方案数。
  dp[i][j] = Sum(dp[i-p*vj][j+1]), p>=0*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define Max_v 10005
long long int dp[Max_v][21];
int v[21];
long long int DP(int va, int p)
{
	int i = 0;
	long long int s = 0;
	if (va<0)
		return 0;
	if (va == 0)
		return 1;
	if (p>20)
		return 0;
	if (dp[va][p] == -1) {
		while(i*v[p]<=va) {
			s = s+DP(va-i*v[p], p+1);
			i++;
		}
		dp[va][p] = s;
	}
	return dp[va][p];
}
int main()
{
	int i, j;
	long long int n;
	for(i=0; i<21; i++)
		v[i] = (i+1)*(i+1)*(i+1);
	while(cin>>n) {
		for(i=1; i<=n; i++)
			for(j=0; j<21; j++)
				dp[i][j] = -1;
		n = DP(n, 0);
		cout<<n<<endl;
	}
	return 0;
}