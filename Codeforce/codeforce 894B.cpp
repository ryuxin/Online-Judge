/*基础题。数学。题解很好理解。给定(m-1, n-1)的
 *任意一个方案，每行每列的最后一个数字被唯一确
 *定，最后再判断(m, n)的可能值。拿一行举例，若
 *其前n-1个数字的乘积为a，则最后一个数只能为
 *b = k/a。可得b=a，当k=1；b=-a，当k=-1；
 *例如k=-1，且m和n奇偶性不同，则每一行最后值的
 *乘积，与每一列最后值的乘积奇偶性不同，无论
 *最后(m, n)怎么选，都不符合条件。
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

#define NUM 200005
#define LEN 105
#define MOD 1000000007
static inline long long 
get_bk(long long b, long long k)
{
	long long a=1;
	while (k) {
		if (k % 2 == 0) {
			b = (b*b) % MOD;
			k /= 2;
		} else {
			a = (a*b) % MOD;
			k--;
		}
	}
	return a;
}
int main()
{
	long long m, n, k;
	scanf("%lld%lld%lld", &m, &n, &k);
	if (k == -1 && (m % 2 != n % 2)) printf("0\n");
	else {
		k = get_bk(2, m-1);
		k = get_bk(k, n-1);
		printf("%lld\n", k);
	}
	return 0;
}