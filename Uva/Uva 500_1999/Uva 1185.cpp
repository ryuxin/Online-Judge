/*基础题。数学。用Stirling公式估计位数*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 900
#define LEN 25
#define PI 3.141592653
#define E 2.7182818284 
/*Stirling公式。n！~= sqrt(2npi)*(n/e)^n*/
static int inline totalbits(int n, int b)
{
	if (!n) return 1;
	double dn = (double)n, db = (double)b;
	double r = log(sqrt(2*PI*dn))/log(db);
	r += dn*log(dn/E)/log(db);
	return (int)r+1;
}
int main()
{
	int r1, r2, N, B = 10;
	scanf("%d", &r2);
	while (r2--) {
		scanf("%d", &N);
		r1 = totalbits(N, B);
		printf("%d\n", r1);
	}
}