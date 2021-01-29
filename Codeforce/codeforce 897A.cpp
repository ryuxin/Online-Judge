/*入门题。模拟。按题意直接模拟即可。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

#define NUM 105
#define LEN 27
char str[NUM];
int main()
{
	int n, m, i, l, r;
	char c1, c2;
	scanf("%d%d%s", &n, &m, str);
	while (m--) {
		scanf("%d%d %c %c", &l, &r, &c1, &c2);
		for(i=l-1; i<r; i++) {
			if (str[i] == c1) str[i] = c2;
		}
	}
	printf("%s\n", str);
	return 0;
}