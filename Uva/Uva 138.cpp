/*入门题。简单数学。由题意可得，2*k*k = n(n+1)，
  枚举n即可*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 300
#define LEN 520
int main()
{
	long long int s = 0, i, t = 8, k;
	printf("%10d%10d\n", 6, 8);
	printf("%10d%10d\n", 35, 49);
	for(i=1; i<50; i++) 
		s += i;
	while(t>0) {
		s += i;
		k = sqrt((double)s);
		if (k*k == s) {
			printf("%10lld%10lld\n", k, i);
			t--;
		}
		i++;
	}
	return 0;
}	