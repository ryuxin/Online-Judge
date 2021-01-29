/*入门题。模拟。按题意直接模拟即可。维护当前未
 *参加比赛的人，并根据输入进行判断和更新。
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

#define NUM 105
#define LEN 4005
int win[NUM];
int main()
{
	int i, n, s, p[2] = {1, 2};
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &win[i]);
	for(s=3, i=0; i<n; i++) {
		if (s == win[i]) break;
		p[0] = s;
		p[1] = win[i];
		s = 6-p[0]-p[1];
	}
	if (i>=n) printf("YES\n");
	else printf("NO\n");
	return 0;
}