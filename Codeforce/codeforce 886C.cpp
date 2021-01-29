/*基础题。贪心。官方题解相对简单，但说的不甚清楚。这里再稍微解释一下。
 *若ai = aj，则至少有一个房间是前面从没出现过的。反证：令x = ai < i，
 *则在时间i，访问的房间即是在时间x访问的房间，设其为K。由于aj = x，且
 *也是当时访问的房间，即K。但此时，最后访问K的时间已变为i（由于ai的访
 *问），可得i = x，矛盾。
 *同理，若一个数出现了n次，其中至少n-1次访问的都是新房间。
 *
 *下面介绍另外一种贪心的思路。
 *设数组vis, 其记录的访问房间的信息。具体地：
 *vis[t] = X，表示t时刻访问的是房间X，且这是最后一次访问X。
 *否则，vis[t] = -1。
 *贪心策略：对任意i，若有vis[ai] != -1，则当前访问的房间曾经出现过；
 *否则访问的是从未出现的新房间。
 *证明：设vis[ai] = K，假设当前访问的是一个新房间M。
 *情况1：若K后续没有被访问过，则令M = K，仍然是合法的，且房
 *间数变少，得到一个更优的解。情况2：若K后续被访问，且时刻为
 *k1, k2, ..则将后面的K和M访问对换，仍然是合法的，且房间数目不变，
 *还是最优解。
 *综上：一定存在一个最优策略，其中当前访问的是旧房间。
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
#define LEN 1005
int vis[NUM];
int main()
{
	int i, n, tot=1, t;
	scanf("%d", &n);
	memset(vis, -1, sizeof(vis));
	for(vis[0] = 1, i=1; i<=n; i++) {
		scanf("%d", &t);
		if (vis[t] == -1) {
			vis[i] = tot+1;
			tot++;
		} else {
			vis[i] = vis[t];
			vis[t] = -1;
		}
	}
	printf("%d\n", tot);
	return 0;
}
