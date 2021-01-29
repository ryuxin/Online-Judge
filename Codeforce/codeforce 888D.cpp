/*基础题。数学，排列组合。f(x, y)为恰好有y个数，使得i != pi，
 *的x排列的数目。则所求答案为Sum{f(n, i) | 0<=i<=k}。求f可
 *分为两步，先选取i个数，再求出这i个数都不在其位置的排列数目
 *即f(i, i)。f(i, i)等于所有排列数，依次减去f(i, 0)……f(i, i-1)
 *综上可得：
 *        = 1，                             i = 0
 *        = 0,                              i = 1
 *f(n, i) = C(n, i)*f(i, i),                i < n
 *        = n! - Sum{f(n, k) | 0 <= k < i}, i = n
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

#define NUM 1005
#define LEN 5
long long chose[NUM][LEN], re[LEN][LEN];
int main()
{
	int i, j, n, k;
	long long r = 1LL;
	scanf("%d%d", &n, &k);
	for(i=1; i<=n; i++) chose[i][1] = i;
	for(i=2; i<=n; i++) {
		for(j=2; j<LEN; j++) {
			chose[i][j] = chose[i-1][j] + chose[i-1][j-1];
		}
	}
	re[2][2] = 2;
	for(i=3; i<LEN; i++) re[i][i] = i*re[i-1][i-1];
	for(i=0; i<LEN; i++) re[i][0] = 1;
	for(i=2; i<LEN; i++) {
		for(j=2; j<i; j++) {
			re[i][j] = chose[i][j]*re[j][j];
		}
		for(j=0; j<i; j++) re[i][i] -= re[i][j];
	}
	for(i=1; i<=k; i++) r += chose[n][i]*re[i][i];
	printf("%lld\n", r);
	return 0;
}