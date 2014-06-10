/*入门题。数学。对于m*n的方格，不论怎么切，都需要m*n-1刀。
  易用数学归纳法证明。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	int m, n;
	while(scanf("%d %d", &n, &m) > 0) {
		printf("%d\n", n*m-1);
	}
	return 0;
}