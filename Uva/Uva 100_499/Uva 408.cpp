/*基础题。数学，数论。由产生式s = (s+k)%m可知，产生的序列为
  s+k, s+2k, s+3k...次序列构成模m的完全剩余系的充要条件为：
  k和m互质。所以辗转相除求k和m最大公约数。*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Gcd(int a, int b)      //a>b
{
	if (b == 0) return a;
	return Gcd(b, a%b);
}
int main()
{
	int k, m, r;
	while(scanf("%d%d", &k, &m)>0) {
		if (k>m) r = Gcd(k, m);
		else r = Gcd(m, k);
		if (r == 1) printf("%10d%10d    Good Choice\n\n", k, m);
		else printf("%10d%10d    Bad Choice\n\n", k, m);
	}
	return 0;
}