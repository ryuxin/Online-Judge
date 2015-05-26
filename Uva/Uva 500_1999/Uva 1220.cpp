/*典型题。动规，树上的动规。dp[a][0]表示以a为的子树，且包含根节点a
  的最大值，dp[a][1]表示不包含a的最大值。可得 dp[a][1] = Sum{dp[s][0]},
  s是a的儿子, 因为此时一定不包含a的儿子。同理：
  dp[a][0] = Sum{max(dp[s][0], dp[s][1])}*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Employee {
	char name[105];
};
Employee employees[205];
int tree[205][205], dp[205][2];
int same[205][2], cur, n;
int name_add(char *c)
{
	int i;
	for(i=0; i<cur; i++)
		if(strcmp(employees[i].name, c) == 0)
			return i;
	strcpy(employees[cur++].name, c);
	return cur-1;
}
int DP(int k, int a)
{
	int i, t = 0, s = 0, t1, t2;
	if(dp[k][a] == -1) {
		if (a == 1) {
			t = 1;
			for (i=0; i<n; i++) {
				if (tree[k][i] == 1) {
					t += DP(i, 0);
					s |= same[i][0];
				}
			}
		}
		else {
			for (i=0; i<n; i++) {
				if (tree[k][i] == 1) {
					t1 = DP(i, 0);
					t2 = DP(i, 1);
					if (t1>=t2) {
						t += t1;
						s |= same[i][0]|(t1 == t2);
					}
					else {
						t += t2;
						s |= same[i][1];
					}
				}
			}
		}
		dp[k][a] = t;
		same[k][a] = s;
	}
	return dp[k][a];
}
int main()
{
	int i, p, s, j;
	char temp[105];
	while (scanf("%d", &n)>0) {
		if (n == 0) break;
		cin>>employees[0].name;
		cur = 1;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				tree[i][j] =  0;
		for(i=0; i<n; i++) {
			dp[i][0] = same[i][0] = -1;
			dp[i][1] = same[i][1] = -1;
		}
		for(i=1; i<n; i++) {
			cin>>temp;
			s = name_add(temp);
			cin>>temp;
			p = name_add(temp);
			tree[p][s] = 1;
		}
		DP(0, 0);
		DP(0, 1);
		if(dp[0][0] == dp[0][1]) {
			i = dp[0][0];
			j = 1;
		}
		else if(dp[0][0] > dp[0][1]) {
			i = dp[0][0];
			j = same[0][0];
		}
		else {
			i = dp[0][1];
			j = same[0][1];
		}
		printf("%d ", i);
		if (j == 0) printf("Yes\n");
		else        printf("No\n");
	}
	return 0;
}