/*基础题。数学。扩展的欧几里得算法。设a>b, m = (a, b)。求m和x，y，使得
  ax+by = m。若a = kb+r，(a, b) = (b, r)。若已知
  bx2+ry2 = m， 则有ay2+by = kby2+by+ry2 = bx2+ry2， 
  解得x = y2， y = x2-ky2*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 12
#define LEN 105
int Eulid(int a, int b, int *x, int *y)
{
	int t;
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	t = Eulid(b, a%b, y, x);
	*y = *y-(a/b)*(*x);
	return t;
}
int main()
{
	int t, x, k, a, b, r;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &k);
		if (x%k == 0) {
			printf("%d %d\n", 0, k);
			continue;
		}
		r = x/k;
		k = r+1;
		k = Eulid(k, r, &a, &b);
		printf("%d %d\n", x*b, x*a);
	}
	return 0;
}