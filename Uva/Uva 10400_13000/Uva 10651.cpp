/*基础题。动规。可用一个二进制数表示当前的状态。1表示有
 *棋子。枚举当前所有可能的移动方法，递归处理新的状态。由
 *于每次移动都会减少1的个数，迭代处理是要按照二进制1的个
 *数来遍历所有状态，这就需要一个算法，根据当前的数，找到
 *二进制中和它具有相同数目的1，且比它大的下一个数。这个算
 *法来自MIT的书HAKMEM中的item 175，详细讲解参见下面链接
 *http://code.stephenmorley.org/articles/hakmem-item-175/ */
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 12
#define LEN (1<<12)

int dp[LEN];
static inline int NEXT_SAME_BIT(int i)
{
	//取i的最低为的1
	int a = i&(-i);			   
	//和最低位的1相加，可以将低位连
	//续的1清零，并将紧接着的0置1
	int b = a+i;
	//除以最低为的1，可以移除所有低位的0
	int c = ((b^i)/a)>>2;
	return b|c;
}
int Calc(int m, int k)
{
	int i, t;
	//从低位向高位扫描
	for(i=0; i<10; ) {
		//当前位是1
		if (k&(1<<i)) {
			//下一位也是1
			if (k&(1<<(i+1))) {
				//再一位仍然是1
				if (k&(1<<(i+2))) i++;
				else {
					t = k&(~(1<<i));
					t = t&(~(1<<(i+1)));
					t = t|(1<<(i+2));
					if (dp[t]<m) m = dp[t];
					i += 3;
				}
			}
			else i += 2;
		}
		else i++;
	}
	//反向扫描
	for(i=11; i>1; ) {
		if (k&(1<<i)) {
			if (k&(1<<(i-1))) {
				if (k&(1<<(i-2))) i--;
				else {
					t = k&(~(1<<i));
					t = t&(~(1<<(i-1)));
					t = t|(1<<(i-2));
					if (dp[t]<m) m = dp[t];
					i -= 3;
				}
			}
			else i -= 2;
		}
		else i--;
	}
	return m;
}
static inline void DP()
{
	int i, j;
	for(i=0; i<3080; i++) dp[i] = 2;
	for(i=0; i<NUM; i++) dp[1<<i] = 1;
	for(i=0; i<NUM-1; i++) dp[3<<i] = 1;
	dp[0] = 0;
	for(i=3; i<=12; i++) {
		for(j=(1<<i)-1; j<LEN; ) {
			dp[j] = Calc(i, j);
			j = NEXT_SAME_BIT(j);
		}
	}
}
int main()
{
	int c, n, i;
	char s[NUM];
	DP();
	scanf("%d", &c);
	while(c--) {
		n = 0;
		scanf("%s", s);
		for(i=0; i<NUM; i++) {
			if (s[i] == 'o')
				n |= (1<<i);
		}
		printf("%d\n", dp[n]);
	}
}