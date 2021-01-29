/*基础题。数组，Sliding windowing。维护区间[l, r)
 *部分和S，则剩余的部分和为360-S。若S>360-S，则继续
 *扩大区间，只会使差值更大，因此尝试右移l，减小区间。
 *否则，尝试增加r，扩大区间。
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

#define NUM 365
#define LEN 360
int ang[NUM];
int main()
{
	int i, n, s=0, l=0, m;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &ang[i]);
	for(m=LEN, i=0; i<n; i++) {
		while(s >= LEN - s) {
			m = min(m, abs(s-LEN+s));
			s -= ang[l++];
		}
		m = min(m, abs(s-LEN+s));
		s += ang[i];
	}
	printf("%d\n", m);
	return 0;
}