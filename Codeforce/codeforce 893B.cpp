/*入门题。枚举。符合题意的数只有8个，先打表，再逐个判断。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 8
#define LEN 4005
int k2[NUM] = {1, 6, 28, 120, 496, 
			   2016, 8128, 32640};
int main()
{
	int i, n;
	scanf("%d", &n);
	for(i=NUM-1; i>0; i--) if (n%k2[i] == 0) break;
	printf("%d\n", k2[i]);
	return 0;
}