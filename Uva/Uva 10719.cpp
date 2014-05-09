/*入门题。基础数学。多项式。将右边展开，比较对应项系数即可。
  注意处理输入。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 10
#define LEN 1010
int k, an, bn;
char num[NUM];
int main()
{
	int l;
	while(scanf("%d", &k)>0) {
		scanf("%c", &num[0]);
		bn = l = 0;
		printf("q(x):");
		while(1) {
			scanf("%c", &num[l]);
			if (num[l] == ' ') {
				sscanf(num, "%d", &an);
				bn = an+k*bn;
				printf(" %d", bn);
				l = 0;
			}
			else if (num[l] == '\n') {
				sscanf(num, "%d", &an);
				bn = an+k*bn;
				printf("\nr = %d\n\n", bn);
				break;
			}
			else l++;
		}
	}
	return 0;
}	