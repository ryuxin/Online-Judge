/*入门题。数论。先用筛法求出10000以内的素数，再将m和n！做质因数分解，最后比较分
 * 解的结果，确定最大可以被n！整除的m的幂指数。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10000
#define LEN (NUM/2)
int filter[NUM], prim[LEN], jie[LEN], mm[LEN];
int tot_p;
static inline void
shai(void)
{
    int i, j;
    memset(filter, 0, sizeof(filter));
    tot_p = 0;
    for(i=2; i<NUM; i++) {
        if (!filter[i]) prim[tot_p++] = i;
        for(j=0; j<tot_p; j++) {
            if (prim[j] * i < NUM) filter[prim[j] * i] = 1;
            if (i % prim[j] == 0) break;
        }
    }
}
static inline int
clac(int m, int n)
{
    int r = 0;
    while(n) {
        r += n/m;
        n = n/m;
    }
    return r;
}
static inline void
dispose_n(int n)
{
    int i;
    memset(jie, 0, sizeof(jie));
    for(i=0; i<tot_p; i++) {
        jie[i] = clac(prim[i], n);
    }
}
static inline void
dispose_m(int m)
{
    int i;
    memset(mm, 0, sizeof(mm));
    for(i=0; i<tot_p; i++) {
        if (prim[i] > m) break;
        while (m % prim[i] == 0) {
            mm[i]++;
            m /= prim[i];
        }
    }
}
static inline int
result(int m, int n)
{
    int i, r=NUM, t;
    for(i=0; i<tot_p; i++) {
        if (prim[i] > m) break;
        if (jie[i] == 0 && mm[i]) return 0;
        else if (mm[i] == 0) continue;
        else {
            t = jie[i] / mm[i];
            if (t < r) r = t;
        }
    }
    return r;
}
int main()
{
    int t, m, n, i, r;
    shai();
    scanf("%d", &t);
    for(i=1; i<=t; i++) {
        scanf("%d%d", &m, &n);
        dispose_m(m);
        dispose_n(n);
        r = result(m, n);
        if (r) printf("Case %d:\n%d\n", i, r);
        else printf("Case %d:\nImpossible to divide\n", i);
    }
    return 0;
}