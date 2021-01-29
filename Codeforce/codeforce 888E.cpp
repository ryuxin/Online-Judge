/*基础题。二分。将给定数组均分为两部分，分别求出其子集和的集合，记
 *为S1，S2。所求答案即为Max{(x+y)%m | x∈S1, y∈S2}。对任意x∈S1，
 *令f(x)表示S2中与x相加取最大值的元素，即f(x) = k, k∈S2, 且对任意
 *i∈S2，有(x+k) % m > (x+i) % m。下面求解f(x)。将S2排序后，可得
 *0，1，2，…k… m-1，设x=m-1-k，可得S2与x相加后的序列
 *x，x+1，  m-1，0……x-1
 *由此可以看出f(x)等于S2中最后一个小于等于k的值，这可以用二分查找。
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

#define NUM 40
#define LEN 5
int num[NUM], m;
static inline void
proc(int b, int e, set<int> &s)
{
	int i, n = 1 << (e - b), j, r;
	for(i=0; i<n; i++) {
		for(r=0, j=0; j<e-b; j++) {
			if (i & (1 << j)) r = (r + num[b+j]) % m;
		}
		s.insert(r);
	}
}
static inline int
calc(int b, int e, set<int> &s)
{
	int i, n = 1 << (e - b), j, r, re = 0;
	for(i=0; i<n; i++) {
		for(r=0, j=0; j<e-b; j++) {
			if (i & (1 << j)) r = (r + num[b+j]) % m;
		}
		set<int>::iterator l = --s.upper_bound(m-1-r);
		re = max(re, (r + *l) % m);
	}
	return re;
}
int main()
{
	set<int> s;
	int n, i, r = 0;
	scanf("%d%d", &n, &m);
	for(i=0; i<n; i++) scanf("%d", num+i);
	proc(0, n/2, s); 
	r = calc(n/2, n, s);
	printf("%d\n", r);
	return 0;
}
