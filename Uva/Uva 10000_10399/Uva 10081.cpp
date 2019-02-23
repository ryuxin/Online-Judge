/* 入门题。递推.对于给定的k，f(i, j)表示以i开头，长度为j的字符串的比例，则最后结果即为Sum{f(i, n) | 0<=i<=k}。
 * 计算f(i, j)，首先取到i的概率为1/(k+1)，第二位的取法只能是i，i－1和i+1，且他们对应的概率为f(i-1, n-1)，代入即可。
 * 边界情况，当i等于0或k时，i－1或i+1不存在
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 102
#define LEN 10
double dp[LEN][NUM];
static inline double
Calc(int k, int n)
{
    int i, j;
    double dk = (double)k, r=0;
    for(i=0; i<=k; i++) dp[i][1] = 100.0/(dk+1);
    for(j=2; j<=n; j++) {
        for(i=0; i<=k; i++) {
            if (i>0 && i<k) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1] + dp[i+1][j-1]) / (dk+1);
            } else if (i==0 && i<k) {
                dp[i][j] = (dp[i][j-1] + dp[i+1][j-1]) / (dk+1);
            } else if (i == k && i>0){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) / (dk+1);
            } else dp[i][j] = dp[i][j-1] / (dk+1);
        }
    }
    for(i=0; i<=k; i++) r += dp[i][n];
    return r;
}
int main()
{
    int n, k;
    while (scanf("%d%d", &k, &n) != -1) {
        double r = Calc(k, n);
        printf("%.5lf\n", r);
    }
    return 0;
}
