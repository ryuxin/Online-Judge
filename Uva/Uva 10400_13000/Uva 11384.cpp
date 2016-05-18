/*入门题。数学，二分。设f(n)是把1-n全变成0所需的步数。若m>n，则有
 *f(m)>f(n)。因为把对m的操作对n实施一遍，一定可以把n全部变成0。对
 *于n，若一次操作将其分为两段n1, n2，则f(n) = 1+max(f(n1), f(n2))。
 *因此将n平分，可以使操作数最小。这里需要更严格的证明。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 5
#define LEN 9
int main()
{
	int n, r;
	while(-1 != scanf("%d", &n)) {
		r = 0;
		while(n>0) {
			r++;
			n /= 2;
		}
		printf("%d\n", r);
	}
	return 0;
}