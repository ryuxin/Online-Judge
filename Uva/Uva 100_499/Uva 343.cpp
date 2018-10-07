/*入门题。进制转换，排序。预先将输入转换到所有可能的进制（2－36），然后比较转换后是否有相同的值。
 *注意: 1. 不能转换到1进制;
 *2. 被转换的进制一定要大于输入中的最大值，比如123就不可以转换到2进制;
 *3. 进制越大，转换值也越大，所以转换后值的数组是有序的，只需O(n)就可以确定是否有相同元素
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 40
#define LEN 36
int a1[NUM], a2[NUM];
char s1[NUM], s2[NUM];
static inline int
mmax(int a, int b)
{ return a>b? a : b; }
static inline int
char2int(char c)
{
    if (c>='0' && c <= '9') return c - '0';
    if (c>='A' && c <= 'Z') return 10 + c - 'A';
    return -1;
}
static inline int
strmax(char *s, int l)
{
    int i, r = 1;
    for(i=0; i<l; i++) r = mmax(r, char2int(s[i]));
    return r;
}
static inline int
str2int_base(char *s, int begin, int end, int base)
{
    int r=0, i;
    for(i=begin; i<end; i++) {
        r = r*base + char2int(s[i]);
    }
    return r;
}
int main()
{
    int m1, m2, l1, l2, i, l, r, b;
    while (-1 != scanf("%s %s", s1, s2)) {
        memset(a1, -1, sizeof(a1));
        memset(a2, -1, sizeof(a2));
        l1 = strlen(s1);
        l2 = strlen(s2);
        m1 = strmax(s1, l1)+1;
        m2 = strmax(s2, l2)+1;
        for(i=m1; i<=LEN; i++) a1[i] = str2int_base(s1, 0, l1, i);
        for(i=m2; i<=LEN; i++) a2[i] = str2int_base(s2, 0, l2, i);
        l = m1, r = m2, b = 0;
        while (l<=LEN && r<=LEN) {
            if (a1[l] == a2[r]) {
                printf("%s (base %d) = %s (base %d)\n", s1, l, s2, r);
                b = 1;
                break;
            } else if (a1[l] > a2[r]) r++;
            else l++;
        }
        if (b == 0) printf("%s is not equal to %s in any base 2..36\n", s1, s2);
    }
	return 0;
}
