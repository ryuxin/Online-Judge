/*基础题。基础数学。先用刷法求出所有素数。然后对输入进行检测。
  若是素数，不符合条件。否则，进行费马测试，通过的则符合条件。
  费马测试用二分法求模。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 65005
bool prime[NUM];
int n;
void Filter_prime(void)
{
	int i, j;
	for(i=2; i<NUM; i++) {
		if (prime[i] == true) {
			j = i+i;
			while(j<NUM) {
				prime[j] = false;
				j += i;
			}
		}
	}
	return ;
}
int Mod(int a, int k)          //calculate (a^k)%k
{
	long long int m;           //Maybe overflow
	if (k == 1) return a%n;
	m = Mod(a, k/2);
	m = m*m;
	if (k%2 == 1) m = m *(a%n);
	return m%n;
}
int Test(void) 
{
	int i;
	if (prime[n] == true) return 0;
	for(i=2; i<n; i++) 
		if (i != Mod(i, n))
			break;
	if (i != n) 
		return 0;
	return 1;
}
int main()
{
	int r;
	for(r = 2; r<NUM; r++) prime[r] = true;
	Filter_prime();
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		r = Test();
		if (r == 1) printf("The number %d is a Carmichael number.\n", n );
		else printf("%d is normal.\n", n);
	}
	return 0;
}
