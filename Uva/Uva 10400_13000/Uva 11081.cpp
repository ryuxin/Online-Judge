/* 中等题。动规。状态很明显，f(i, j, k)表示用s1[0, i]和s2[0, j]构造出s3[0, k]的方法数。
 * 状态转移取决于s3[k]的取法。关键在于转移方程。
 * 1. 错误思路。s3[k]取自s1[i]和s2[j]中的一个，或者二者都不是，可得方程
 * f(i, j, k) = f(i-1, j, k-1) + f(i, j-1, k-1) + f(i-1, j-1, k)
 * 错误之处在于第三项没有包含所有情况，例如f(i-1, j, k)中，s2[j]可能在s3中间，而s3[k]取自s1[i-1]。
 * 2. O(n^4)思路。s3[k]的所有可能取法是，s1[0, i]和s2[0, j]中所有等于s3[k]的，则方程
 * f(i, j, k) = Sum{f(x-1, j, k-1) | s1[x] = s3[k]} + Sum{f(i, x-1, k-1) | s2[x] = s3[k]}
 * 计算时需要O(n)来扫描s1和s2以确定x的取值。
 * 3. O(n^3)思路。s3[k]只可能来自s1或s2。令f1，f2分别两种情况下的方法数，则有
 * f(i, j, k) = f1(i, j, k) + f2(i, j, k)
 * 计算f1时，s3[k]也只有两种可能的取法，要么来自s1[0, i-1]，要么就是s1[i]；同理可得f2，即
 * f1(i, j, k) = f1(i-1, j, k) + f(i-1, j, k-1) (if s1[i] = s3[k])
 * 注意f1的第二部分，由于并不能确定s3[k-1]的来源，所以要用f，而不是f1来计算。
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 65
#define LEN 10007
int dp[NUM][NUM][NUM], dp1[NUM][NUM][NUM], dp2[NUM][NUM][NUM];
char s1[NUM], s2[NUM], s3[NUM];
static inline void
__dp_init(int l1, int l2, int l3)
{
    int i, j;
    for(i=1; i<=l3; i++) {
        dp1[0][0][i] = dp2[0][0][i] = dp[0][0][i] = 0;
    }
    for(i=0; i<=l1; i++) {
        for(j=0; j<=l2; j++) {
            dp[i][j][0] = 1;
            dp1[i][j][0] = 1;
            dp2[i][j][0] = 1;
        }
    }
    for(i=1; i<=l1; i++) {
        for(j=1; j<=l3; j++) {
            dp2[i][0][j] = 0;
            dp1[i][0][j] = dp1[i-1][0][j];
            if (s1[i-1] == s3[j-1]) {
                dp1[i][0][j] += dp1[i-1][0][j-1];
                dp1[i][0][j] %= LEN;
            }
            dp[i][0][j] = dp1[i][0][j];
        }
    }
    for(i=1; i<=l2; i++) {
        for(j=1; j<=l3; j++) {
            dp1[0][i][j] = 0;
            dp2[0][i][j] = dp2[0][i-1][j];
            if (s2[i-1] == s3[j-1]) {
                dp2[0][i][j] += dp2[0][i-1][j-1];
                dp2[0][i][j] %= LEN;
            }
            dp[0][i][j] = dp2[0][i][j];
        }
    }
}
static inline int
__calc_dp(int a, int b, int c)
{
    dp1[a][b][c] = dp1[a-1][b][c];
    if (s1[a-1] == s3[c-1]) {
        dp1[a][b][c] += dp[a-1][b][c-1];
        dp1[a][b][c] %= LEN;
    }
    dp2[a][b][c] = dp2[a][b-1][c];
    if (s2[b-1] == s3[c-1]) {
        dp2[a][b][c] += dp[a][b-1][c-1];
        dp2[a][b][c] %= LEN;
    }
    dp[a][b][c] = (dp1[a][b][c] + dp2[a][b][c]) % LEN;
    return dp[a][b][c];
}
static inline void
calc_dp(int l1, int l2, int l3)
{
    int i, j, k;
    __dp_init(l1, l2, l3);
    for(i=1; i<=l1; i++) {
        for(j=1; j<=l2; j++) {
            for(k=1; k<=l3; k++) {
                __calc_dp(i, j, k);
            }
        }
    }
}
int main()
{
    int kase, l1, l2, l3;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%s%s%s", s1, s2, s3);
        l1 = strlen(s1);
        l2 = strlen(s2);
        l3 = strlen(s3);
        calc_dp(l1, l2, l3);
        printf("%d\n", dp[l1][l2][l3]);
    }
    return 0;
}