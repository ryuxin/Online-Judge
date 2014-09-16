/*基础题。DAG上的动规。虽然每一种砖都可以无限使用，但在一种可行方案中，它的每一个排列最多使用一次。
  这样我们可以将一种砖分为6种(一种对应它的一个排列), 但是每一种只能使用一次。两块砖的小于关系构成
  一个有向无环图。直接套用DAG上的动规。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 200
#define LEN 105
#define CONS(a, b, c) points[num].x = a; points[num].y = (b); points[num].z = (c); num++;
struct Point {
	int x, y, z;
};
Point points[NUM];
int num, arg[3], dp[6*NUM], grap[6*NUM][6*NUM];
inline bool Check(int a, int b)            //test points[a]<points[b]
{
	if (points[a].x<points[b].x && points[a].y<points[b].y)
		return true;
	return false;
}
inline void Cons()
{
	if (arg[0] != arg[1] && arg[0] != arg[2] && arg[1] != arg[2]) {
		CONS(arg[0], arg[1], arg[2]) 
		CONS(arg[1], arg[2], arg[0]) 
		CONS(arg[2], arg[0], arg[1]) 
	}
	CONS(arg[1], arg[0], arg[2]) 
	CONS(arg[0], arg[2], arg[1]) 
	CONS(arg[2], arg[1], arg[0]) 
}
int DP(int k)
{
	int i, m = 0, t;
	if (dp[k] == -1) {
		for(i=0; i<num; i++) {
			if (grap[k][i] ) {
				t = DP(i);
				if (t>m) m = t;
			}
		}
		dp[k] = points[k].z+m;
	}
	return dp[k];
}
int main()
{
	int t = 0, n, i, j, m;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		t++;
		num = 0;
		for(i=0; i<n; i++) {
			scanf("%d %d %d", &arg[0], &arg[1], &arg[2]);
			Cons();
		}
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
				grap[i][j] = Check(i, j);
		memset(dp, -1, sizeof(int)*num);
		for(i=0; i<num; i++) dp[i] = DP(i);
		m = dp[0];
		for(i=1; i<num; i++) if (dp[i]>m) m = dp[i];
		printf("Case %d: maximum height = %d\n", t, m);
	}
	return 0;
}