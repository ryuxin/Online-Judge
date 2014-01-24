/*�����⡣���档ת�Ʒ��� dp[i]=max{dp[i], dp[i]+dp[i-1]}�����⣬����Ҫ��������䷶Χ������Ҫ
�����Ĺ��ɡ����ע��һ��������ĿҪ��Ľ���������ܶ����Ҫ�Ƚ�*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
 int dp[20005], pos[20005];
 int main()
 {
    int t,i,n,j,m,p;
    scanf("%d",&t);
    for(i=1;i<=t;i++) {
        scanf("%d",&n);
        for(j=1; j<n; j++)
            scanf("%d", &dp[j]);
		pos[1] = 1;
		for(j=2; j<n; j++) {
			if(dp[j-1]<0) 
				pos[j] = j;
			else {
				dp[j]  = dp[j]+dp[j-1];
				pos[j] = pos[j-1];
			}
		}
        m = dp[1];
        p = 1;
		for(j=2;j<n;j++) {
            if(dp[j]>m) {
                m = dp[j];
                p = j;
            }
			else if(dp[j] == m) {
				if(j-pos[j]>p-pos[p]) {
					m = dp[j];
				    p = j;
				}
				else if(j-pos[j]>p-pos[p]) {
					if(pos[j]<pos[p]) {
						m = dp[j];
						p = j;
					}
				}
			}
		}
        if(m>0)
            printf("The nicest part of route %d is between stops %d and %d\n", i,pos[p],p+1);
        else
            printf("Route %d has no nice parts\n",i);
    }
	return 0;
 }






