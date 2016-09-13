/*中等题。二分+贪心。有n个人，设编号从0开始。当n是偶数时，比较简单。所需要的
 *礼物数为：相邻两个人的所需礼物之和的最大值。证明:设最大值为M，则最优方案是
 *偶数人从第一个向后取，奇数人从最后一个向前取。反证，若存在两个人礼物重合，
 *则他们的礼物之和大于M，与M是最大值矛盾。
 *n为奇数是，比较麻烦。第i个人所需礼物为ri。对礼物总数进行二分搜索。对于一个
 *给定的总数P，0号肯定拿前r0个，为了使最后一个人不与0号重复，则n-1号应尽量
 *从后面取，同理，依次向前类推：n-2从前面取，n-3从后面取...剩余的人的最优方
 *案是偶数尽量从后面取，奇数人从前面取。但这需要严格的数学证明！！
 *具体实现时，礼物被分为两个区间[1, r0], [r0+1, P]。记录每个人在两个区间的
 *礼物数，若最后一个人在第一个区间有礼物，则和0号重复，分配失败。
 *二分的上下界：下界与第一种情况相同，是相邻两人之和的最大值。上界：任取一个
 *人i，他的礼物与其他人都不同，且剩余的人所需为他们相邻两人的最大和。为了
 *简化计算，上界可简单取最大礼物数的3倍。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 100005
#define LEN 160
int gift[NUM], n;
static inline int max_item(void)
{
	int i, m = gift[0];
	for(i=1; i<n; i++) if (m<gift[i]) m = gift[i];
	return m;
}
static inline int max_sum(void)
{
	int m = gift[0]+gift[n-1], t, i;
	for(i=0; i<n-1; i++) {
		t = gift[i]+gift[i+1];
		if (t>m) m = t;
	}
	return m;
}
static inline bool check(int m)
{
	int i, lr[2], tlr[2], t, idx;
	if (m<gift[0]) return false;
	lr[0]  = tlr[0] = gift[0];
	lr[1]  = 0;
	tlr[1] = m-lr[0];
	for(i=1; i<n; i++) {
		idx = 1-i%2;
		t   = tlr[idx]-lr[idx];
		if (t<0) t = 0;
		if (t > gift[i]) t = gift[i];
		lr[idx]   = t;
		lr[1-idx] = gift[i]-t;
	}
	return lr[0]>0;
}
static int solve(int m)
{
	int l, r, mid;
	l = m;
	r = max_item()*3;
	while (l<r) {
		mid = (l+r)/2;
		if (check(mid)) l = mid+1;
		else r = mid;
	}
	return l;
}
int main()
{
	int i, m;
	while(scanf("%d", &n)) {
		if (!n) break;
		if (n%2) scanf("%d", &gift[0]);
		for(i=n%2; i<n; i += 2) scanf("%d%d", &gift[i], &gift[i+1]);
		m = max_sum();
		if (n == 1) printf("%d\n", gift[0]);
		else if(n%2 == 0) printf("%d\n", m);
		else printf("%d\n", solve(m));
	}
	return 0;
}