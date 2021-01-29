/*基础题。动规。和题解思路大体一致。一个数是完全平方数，
 *当且仅当它的每个质数因子都有偶数个。动规状态s，其第k
 *位为1，代表第k个质数出现奇数次；否则为偶数次（或没有）。
 *dp(i, s)表示从[i...n]中乘积状态为s的个数。状态转移方程
 *dp(i, s) = C1(ai)*dp(i+1, s) + C2(ai)*dp(i+1, s^f(ai))。
 *两个分量分别对应ai取偶数次和奇数次。f(x)将x转化为其对应
 *的状态表示。dp(1, 0)为最终所求。一下几点说明：
 *1.实现中将大质数分离出来，而且这些质数只能出现偶数次；
 *2.从n中选取偶数和选取奇数的方法数相等，即C1(n) = C2(n) (n>0)
 *3.最后答案还要减1，对应的是没有选取任何数；
 *4.题中ai<70的条件很特殊，看到这种量级一般先考虑质数和位操作
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define NUM 100005
#define LEN 71
#define PRIN 11
#define MOD 1000000007
int np2[NUM], cnt[LEN] = {0}, prest[LEN];
int dp[2][1<<PRIN] = {0}, even[LEN], odd[LEN];
int pris[PRIN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int large_p[] = {37, 41, 43, 47, 53, 59, 61, 67};
static inline int
n2prim(int k)
{
	int ret = 0, i, c;
	for(i=0; i<PRIN; i++) {
		for(c=0; k%pris[i] == 0; c++) {
			k /= pris[i];
		}
		if (c % 2 == 1) ret |= (1<<i);
	}
	return ret;
}
int main()
{
	int i, n, j;
	long long t, r=1;
	scanf("%d", &n);
	for(np2[0]=1, i=0; i<n; i++) {
		scanf("%d", &j);
		cnt[j]++;
		np2[i+1] = (np2[i]*2) % MOD;
	}
	for(i=0; i<LEN; i++) {
		if (cnt[i] == 0) {
			even[i] = 1;
			odd[i] = 0;
		} else {
			even[i] = odd[i] = np2[cnt[i]-1];
		}
	}
	for(i=0; i<sizeof(large_p)/sizeof(int); i++) {
		r = (r*even[large_p[i]]) % MOD;
		even[large_p[i]] = 1;
		odd[large_p[i]] = 0;
	}
	for(i=1; i<LEN; i++) prest[i] = n2prim(i);
	dp[(LEN-1)%2][0] = even[LEN-1];
	dp[(LEN-1)%2][prest[LEN-1]] = odd[LEN-1];
	for(i=LEN-2; i>0; i--) {
		for(j=0; j<(1<<PRIN); j++) {
			t = even[i];
			dp[i%2][j] = (t*dp[(i+1)%2][j]) % MOD;
			t = odd[i];
			t = (t*dp[(i+1)%2][j^prest[i]]) % MOD;
			dp[i%2][j] = (dp[i%2][j]+t) % MOD;
		}
	}
	r = ((r*dp[1][0]) % MOD) - 1;
	printf("%lld\n", r);
	return 0;
}