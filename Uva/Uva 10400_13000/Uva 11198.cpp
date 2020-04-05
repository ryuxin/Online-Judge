/*基础题。BFS。把数组中的数字排列看作一个节点，若存在一个合法的移动，将一个
 *排列变换到另一个排列，则视为两个对应节点中存在一条边。则原题可看作求解从给
 *定节点到目标节点（1，2，... 8）的最短路径。可用BFS直接求解。利用康托展开
 *对排列进行编解码。以下给出几种实现：
 *1.BFS的队列节点直接存储排列，这样空间开销很大；
 *2.BFS的队列节点存储排列的编码，这需要从编码中反向解码出原排列。其时间效率
 *和1是一样的，但节省了空间；
 *3.提前存储和编码对应的原排列，省去了2中解码的过程，但空间开销和1一样。
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

#define NUM 50000
#define LEN 8
#define CC_LEN 40000
//#define USE_STATE
#ifdef USE_STATE
struct Digit {
	int num[LEN];
};
#define Q_DEF queue<Digit>
#else
#define Q_DEF queue<int>
bool use[LEN+2];
int codec[CC_LEN][LEN];
#endif
int jiecheng[LEN+2], sign[LEN+2], num[LEN];
bool zhisu[3*LEN], flag[NUM];
static inline void
init_jiecheng(int *arr, int len)
{
	int i;
	arr[0] = arr[1] = 1;
	for(i=2; i<=len; i++) arr[i] = i*arr[i-1];
}
static inline void
init_zhisu(bool *arr, int len)
{
	int i, j;
	memset(arr, 0, sizeof(bool)*len);
	for(i=2; i<len; i++) {
		for(j=2; j<=i; j++) {
			if (i*j>=len) break;
			arr[i*j] = 1;
		}
	}
}
static inline int
arry2code(int *arr, int len)
{
	int i, tot = 0, n, t, j;
	//memset(use, 0, sizeof(use));
	for(i=0; i<len; i++) {
		t      = arr[i];
		//use[t] = 1;
		//for(n=0, j=1; j<t; j++) if (!use[j]) n++;
		for(n=0, j=i+1; j<len; j++) if (arr[j]<t) n++;
		tot += (n*jiecheng[len-i-1]);
	}
	return tot;
}
#ifndef USE_STATE
static inline void
code2arry_slow(int *arr, int len, int n)
{
	int i, t, j;
	memset(use, 0, sizeof(use));
	for(i=len-1; i>=0; i--) {
		t = n/jiecheng[i];
		n = n%jiecheng[i];
		for(j=1; t>=0; j++) if (!use[j]) t--;
		use[j-1]     = 1;
		arr[len-1-i] = j-1;
	}
}
static inline void
code2arry(int *arr, int len, int n)
{
	
	if (n<CC_LEN) memcpy(arr, codec[n], sizeof(int)*len);
	else code2arry_slow(arr, len, n);
}
static inline void 
nextPermutation(int* nums, int numsSize)
{
	int i, j, l, r;
	for(i=numsSize-1; i>0; i--) {
		if (nums[i-1] < nums[i]) {
			for(j=numsSize-1; j>=i; j--) {
				if (nums[j] > nums[i-1]) break;
			}
			swap(nums[i-1], nums[j]);
			l = i, r = numsSize-1;
			while (l<r) {
				swap(nums[l++], nums[r--]);
			}
			break;
		}
	}
}
static inline void
init_codec(int l, int len)
{
	int i;
	//for(i=0; i<l; i++) {
	//	code2arry_slow(codec[i], len, i);
	//}
	for(i=1; i<=len; i++) codec[0][i-1] = i;
	for(i=1; i<l; i++) {
		memcpy(codec[i], codec[i-1], sizeof(int)*len);
		nextPermutation(codec[i], len);
	}
}
#else
void init_codec(int l, int len) { ; }
#endif
static inline bool
movl(int *arr, int idx, int val)
{
	if(idx == 0) return false;
	if (sign[arr[idx-1]]*sign[val]>0 || zhisu[arr[idx-1]+val]) return false;
	return true;
}
static inline bool
movr(int *arr, int idx, int val, int len)
{
	if(idx >= len) return false;
	if (sign[arr[idx]]*sign[val]>0 || zhisu[arr[idx]+val]) return false;
	return true;
}
static inline bool
chk_mov(int *arr, int idxf, int idxt, int len)
{
	return movl(arr, idxt, arr[idxf]) || movr(arr, idxt, arr[idxf], len);
}
static inline void
mov_arr(int *src, int *dst, int idxf, int idxt, int len)
{
	int i, t = src[idxf];
	memcpy(dst, src, sizeof(int)*len);
	if (idxf > idxt) {
		for(i=idxf-1; i>=idxt; i--) dst[i+1] = dst[i];
		dst[i+1] = t;
	} else {
		for(i=idxf+1; i<idxt; i++) dst[i-1] = dst[i];
		dst[i-1] = t;
	}
}
static inline void
fanout(int *arr, int len, Q_DEF &q)
{
	int i, j, t;
#ifdef USE_STATE
	Digit tg;
#else
	int ta[LEN+2];
#endif
	for(i=0; i<len; i++) {
		for(j=0; j<=len; j++) {
			if (j == i || j == i+1) continue;
			if (chk_mov(arr, i, j, len)) {
#ifdef USE_STATE
				mov_arr(arr, tg.num, i, j, len);
				t = arry2code(tg.num, len);
				if (!flag[t]) {
					q.push(tg);
#else
				mov_arr(arr, ta, i, j, len);
				t = arry2code(ta, len);
				if (!flag[t]) {
					q.push(t);
#endif
					flag[t] = 1;
				}
			}
		}
	}
}
static inline int
BFS(int *arr, int len)
{
	int i, r = 0, l, t;
	Q_DEF myqueue;
	t = arry2code(arr, len);
#ifdef USE_STATE
	Digit tg, ta;
	memcpy(tg.num, arr, sizeof(int)*len);
	myqueue.push(tg);
#else
	myqueue.push(t);
#endif
	flag[t] = 1;
	while(!myqueue.empty()) {
		l = myqueue.size();
		for(i=0; i<l; i++) {
#ifdef USE_STATE
			ta = myqueue.front();
			t = arry2code(ta.num, len);
			if (t == 0) return r;
			fanout(ta.num, len, myqueue);
#else
			t = myqueue.front();
			if (t == 0) return r;
			code2arry(arr, len, t);
			fanout(arr, len, myqueue);
#endif
			myqueue.pop();
		}
		r++;
	}
	return -1;
}
int main()
{
	int i, kase = 1, t;
	init_jiecheng(jiecheng, LEN);
	init_zhisu(zhisu, 3*LEN);
	init_codec(CC_LEN, LEN);
	while (1) {
		scanf("%d", &num[0]);
		if (num[0] == 0) break;
		for(i=1; i<LEN; i++) scanf("%d", &num[i]);
		for(i=0; i<LEN; i++) {
			t       = abs(num[i]);
			sign[t] = num[i]/t;
			num[i]  = t;
		}
		memset(flag, 0, sizeof(flag));
		t = BFS(num, LEN);
		printf("Case %d: %d\n", kase++, t);
	}
	return 0;
}
