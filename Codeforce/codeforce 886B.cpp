/*入门题。数据结构，数组。题目大意：给出一个数组，找到一个元素，
 *其最后出现的位置最小。从后向前扫描数组，记录当前元素是否出现过，
 *若没有，当前位置即其最后出现的位置，且是已出现的元素中位置最小的
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
int num[NUM];
bool vis[NUM];
int main()
{
	int i, n, r;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", num+i);
	memset(vis, 0, sizeof(vis));
	for(i=n-1; i>=0; i--) {
		if (!vis[num[i]]) {
			vis[num[i]] = 1;
			r = num[i];
		}
	}
	printf("%d\n", r);
	return 0;
}
