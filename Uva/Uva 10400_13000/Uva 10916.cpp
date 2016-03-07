/*基础题。基础数学。n！<2^m => lg(n!) < m。用double暴力计算lg1+……+lgn*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 30
#define LEN 85
int to[NUM];
int main()
{
	int m, i;
	double n, r;
	to[0] = 1;
	for(i=1; i<NUM; i++) to[i] = 2*to[i-1];
	while (scanf("%d", &m)>0) {
		if (m == 0) break;
		m = (m-1960)/10;
		m = 4*to[m];
		r = 0;
		n = 2.0;
		while(1) {
			r += log(n)/log(2.0);
			if (r>=m) break;
			n = n+1;
		}
		printf("%d\n", (int)(n-1));
	}
	return 0;
}