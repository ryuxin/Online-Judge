/*基础题。动规。因为最短的两个筷子决定了最后的结果，所以最短的两个筷子确定后，最长的筷子就可以随便选。
 *将筷子从短到长排序后为a0<=a1<= ...<= an。若a0被选，则a1一定和它配对。
 *证明：反证，假设a0和ai配对，若a1没有被用，则将ai换为a1，可以得到一个更好的结果，因为a1<=ai。
 *若a1被选，且和aj配对，则交换a1和ai，所得结果更好。因为(ai-a0)^2+(aj-a1)^2-(a0-a1)^2-(ai-aj)^2
 *= 2(a0a1+aiaj-a0ai-a1aj) = 2a0(a1-ai)+2aj(ai-a1) = 2(ai-a1)(aj-a0) >= 0
 *这样可得动规方程，dp[i][j]表示从ai到an中选取j双筷子的最优值。则有，
 *当j=0，  dp[i][j] = 0
 *当i>=3j, dp[i][j] = min{dp[i+1][j], (a[i+1]-a[i])^2+dp[i+2][j-1]}
 *否则，   dp[i][j] = 无穷大
 *有一个可能的边界情况是，选完（ai，ai+1）后，从剩余的筷子中不仅要选出剩余j-1双筷子，还要为每一对
 *包括（ai，ai+1）留出最长的筷子。但这不会引起问题，剩余筷子中任何没有使用的筷子都可以作为（ai，ai+1）
 *的最长的那个，且i>=3j保证一定会有未使用的筷子。
 *有动规方程可知，可以用滚动数组进行优化。*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define NUM 5050
#define LEN 1050
#define MYM 1000000000
int dp[2][LEN], len[NUM];
static inline int mymin(int a, int b) {return a < b ? a : b;}
int main()
{
	int t, n, k, i, j, t1, t2, c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &k, &n);
		for(i=0; i<n; i++) scanf("%d", &len[i]);
		for(i=2; i<k+9; i++) dp[0][i] = dp[1][i] = MYM;
		dp[0][0] =dp[1][0] = 0;
		c = (n-3)%2;
		dp[c][1] = (len[n-2] - len[n-3])*(len[n-2] - len[n-3]);
		dp[1-c][1] = MYM;
		for(i=n-4; i>=0; i--) {
			c = 1-c;
			j = mymin(k+8, (n-i)/3);
			for(; j>0; j--) {
				t1 = (len[i+1]-len[i])*(len[i+1]-len[i]) + dp[c][j-1];
				t2 = dp[1-c][j];
				dp[c][j] = mymin(t1, t2);
			}
		}
		printf("%d\n", dp[c][8+k]);
	}
	return 0;
}