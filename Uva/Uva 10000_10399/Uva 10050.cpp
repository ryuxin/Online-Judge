/*入门题。模拟。枚举出每个党派罢工的所有日期，最后将这些加总，再除去周五周六。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 3700
#define LEN 15
bool re[NUM];
int main()
{
	int T, n, p, i, j, h;
	scanf("%d", &T);
	while(T) {
		scanf("%d%d", &n, &p);
		memset(re, 0, (n+1)*sizeof(bool));
		for(i=p; i>0; --i) {
			scanf("%d", &h);
			for(j=h; j<=n; j+=h) re[j] = true;
		}
		h = 0;
		for(i=n; i>0; --i) {
			if (i%7 == 0 || i%7 == 6) continue;
			if (re[i]) ++h;
		}
		printf("%d\n", h);
		--T;
	}
	return 0;
}