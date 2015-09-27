/*入门题*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 27
#define LEN 30
int sate[NUM];
char input[LEN];
int main()
{
	int t, n, c, i;
	scanf("%d", &t);
	for(c=1; c<=t; c++) {
		scanf("%d%s", &n, input);
		sate[0] = sate[1] = sate[19] = sate[22] = 0;
		for(i=0; i<n; i++) sate[input[i]-'A']++;
		if (sate[0] == n) printf("Case %d: ABANDONED\n", c);
		else if (sate[0]+sate[1] == n) printf("Case %d: BANGLAWASH\n", c);
		else if (sate[0]+sate[22] == n) printf("Case %d: WHITEWASH\n", c);
		else if (sate[1] == sate[22]) printf("Case %d: DRAW %d %d\n", c, sate[22], sate[19]);
		else if (sate[1] > sate[22]) printf("Case %d: BANGLADESH %d - %d\n", c, sate[1], sate[22]);
		else printf("Case %d: WWW %d - %d\n", c, sate[22], sate[1]);
	}
	return 0;
}
