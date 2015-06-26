/*基础题。数学,筛法求素数。普通的筛法不是O(n)的，而是O(nlglgn)，
 *因为合数会被删掉多次。这里的实现保证每个合数只会被删除一次。每个
 *数n可以表示为n = p1p2...pk,其中(p1<p2<..<pk，且都为素数)。基本思
 *想：每个合数都只被它最小的素数因子删除，即n只能以p1*N的形式删除。
 *当外层循环i=N时，内层循环prime[j] = p1时，n会被滤掉，因为p1是最小
 *的素因子，比p1下的素数都不能被N整除。
 *若假设n可以被另一种形式pi*M过滤掉，则有pi>p1,且p1能整除M，而内层
 *循环到p1时就会跳出，不可能继续循环到pi。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 1500
#define LEN 25
char input[LEN];
int not_prime[NUM], prime[500];
static void inline filter_prime(int upper)
{
	int i, j, n = 0;
	memset(not_prime, 0, sizeof(not_prime));
	for(i=2; i<upper; i++) {
		if (!not_prime[i]) prime[n++] = i;
		for(j=0; j<n; j++) {
			if (i*prime[j]<upper) not_prime[i*prime[j]] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
int main()
{
	int i, l, sum;
	filter_prime(NUM);
	while(gets(input)) {
		l = strlen(input);
		sum = 0;
		for(i=0; i<l; i++) {
			if ('a'<=input[i] && input[i]<='z')
				sum += input[i]-'a'+1;
			else sum += input[i]-'A'+27;
		}
		if (not_prime[sum]) printf("It is not a prime word.\n");
		else printf("It is a prime word.\n");
	}
}