/*入门题。简单计算*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
	int t, m, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		printf("%d\n", (m/3)*(n/3));
	}
	return 0;
}	