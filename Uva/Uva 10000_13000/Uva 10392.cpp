/*基础题。数学题。由于题目已知至多只有一个因子大于1000000，所以先
  用筛法求出小于1000000的所有素数，然后依次去除。若最后所剩的数不
  是1，则一定是个素数，可以直接输出。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1000001
#define LEN 35
long long int prime[NUM];
int main()
{
	int i, j, n_p;
	long long int d;
	prime[0] = 2;
	n_p = 1;
	for(i=2; i<NUM; i=i+2) prime[i] = 1;
	for(i=3; i<NUM; i=i+3) prime[i] = 0;
	for(i=3; i<NUM; i++) {
		if (prime[i] == 0) {
			for(j=2*i; j<NUM; j=j+i) prime[j] = 1;
			prime[n_p++] = i;
		}
	}
	while(scanf("%lld", &d)>0) {
		if (d == -1) break;
		if (d == 1) {
			printf("1\n\n");
			continue;
		}
		for(i=0; i<n_p; i++) {
			if (d == 1) break;
			while(d%prime[i] == 0) {
				printf("    %lld\n", prime[i]);
				d /= prime[i];
			}
		}
		if (d != 1) printf("    %lld\n", d);
		printf("\n");
	}
	return 0;
}