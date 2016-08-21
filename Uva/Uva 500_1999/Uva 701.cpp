/*入门题。数学+枚举。题目大意：已知x，求一个E，使得2^E的前几位数字恰好是x，且2^E的位数要大于x的位数的
 *2倍。假设x的后面还有y位，则E应该满足x <= (2^E)/(10^y) < x+1，两边取对数后，枚举所有的y，直到找到符
 *合条件的E。本题中，对于所有的x，都有解。但没有找到正式的数学证明？？？！！！*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 15
#define LEN 35
int main()
{
	unsigned int n;
	int y, r1, r2;
	double c = log(10.0)/log(2.0), t1, t2;
	while(scanf("%u", &n) != EOF) {
		t1 = log((double)n)/log(2.0);
		t2 = log((double)(n+1))/log(2.0);
		y = 2+(int)log10((double)n);
		while(1) {
			r1 = (int)(t1+y*c);
			r2 = (int)(t2+y*c);
			if (r1 != r2) {
				printf("%d\n", r2);
				break;
			}
			y++;
		}
	}
	return 0;
}