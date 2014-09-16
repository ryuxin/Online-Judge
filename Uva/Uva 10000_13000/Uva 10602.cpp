/*基础题。贪心。设两个字符串的公共前缀长度为con(s1, s2)。
  贪心选择性质：当前的字符串为s，则他下一个一定是使con(s, x)最大的字符串x。
  |  a1 |                    |     a     |
  s_____|____                s___________|__
  |     |                    |           |
  |     |                    r_______|___|__
  |     |                    |   a2  |
 s1_____|____               s1_______|_________
  
  | b1 |                     |           |
 s2____|______              s2___________|_____
  |    |                     |           |
  r____|__|____              |     b     |
  |     b2|                  |           |
 s3_______|__               s3___________|______
 证明：如上图所示，设当前字符串为s，与其具有最长公共前缀的字符串是r，且
 con(s, r) = a。若存在一种最优方案，s后面的字符串不是r（如左图），则可以
 将r插入在s后面，构造另一个最优解。这样只有与r相邻的接触面的公共前缀长度
 会变化，我们只关注这些变化。
 我们先假设con(s2, s)<con(s, r), con(s3, s)<con(s, r)
 左图中，变化前的公共前缀长度之和为S1 = a1+b1+b2
 右图中，变化后的公共前缀长度之和为S2 = a+a2+b
 显然，b至少大于等于b1，再由假设可知，a>b2。
 因为r与s具有最长的公共前缀，所以a1<a,这也说明r与s1的公共前缀长度至少是a1，
 即 a2>=a1。综上有，S2>S1，即变化后是一个更优的解。
 再来看con(s2, s)=con(s, r)或con(s3, s)=con(s, r)的情况，
 这时可将他们与r合并为一组，作为整体插到s后面，接触面的变化同上。
 确定贪心策略以后，就是怎么寻找具有最长公共前缀的字符串。
 朴素的解法是每次搜索一遍剩余的字符串，找到与当前的字符串具有最长公共前
 缀的那个，复杂度O(n^2)。
 优化：可先将所有字符串按字典序排序，则与相邻的两个字符串一定具有最长的
 公共前缀。找到第一个字符串在排序以后的位置，对它的左右两段进行归并，
 复杂度为O(nlgn+n) = O(n)*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 105
char data[LEN][NUM], first[NUM];
int n, len[NUM], re[NUM];
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return strcmp(p1, p2);
}
int Calc(int a, int b)
{
	int i;
	for(i=0; i<len[a] && i<len[b]; i++)
		if (data[a][i] != data[b][i])
			break;
	return i;
}
int main()
{
	int t, i, l, r, s, c, w;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) 	scanf("%s", data[i]);
		s = c = 0;
		strcpy(first, data[0]);
		qsort(data, n, sizeof(data[0]), comp);
		for(i=0; i<n; i++) {
			len[i] = strlen(data[i]);
			s += len[i];
		}
		for(i=0; i<n; i++) if (strcmp(data[i], first) == 0) break;
		re[0] = i;
		l = i-1;
		r = i+1;
		while(l>=0 && r<n) {
			i = Calc(re[c], l);
			w = Calc(re[c], r);
			if (i == 0) for(; r<n; r++) re[++c] = r;
			else if (w == 0) for(; l>=0; l--) re[++c] = l;
			else if (i>w) re[++c] = l--;
			else re[++c] = r++;
		}
		if (r<n) for(; r<n; r++) re[++c] = r;
		else if(l>=0) for(; l>=0; l--) re[++c] = l;
		r = 0;
		for(i=1; i<n; i++) r += Calc(re[i-1], re[i]);
		printf("%d\n", s-r);
		for(i=0; i<n; i++) printf("%s\n", data[re[i]]);
	}
	return 0;
}