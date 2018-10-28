/*基础题。模拟。只需按照题目要求，每次对牌堆模
 *拟相应的变换即可。输入输出的格式需要注意。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>   
#include <vector>
using namespace std;

#define NUM 105
#define LEN 55
#define N_CARD 52
int shuf[NUM][LEN];
static inline void
output(int k)
{
	switch (k%13) {
		case 9:
			printf("Jack");
			break;
		case 10:
			printf("Queen");
			break;
		case 11:
			printf("King");
			break;
		case 12:
			printf("Ace");
			break;
		default:
			printf("%d", (k % 13)+2);
	}
	printf(" of ");
	switch (k/13) {
		case 0:
			printf("Clubs\n");
			break;
		case 1:
			printf("Diamonds\n");
			break;
		case 2:
			printf("Hearts\n");
			break;
		case 3:
			printf("Spades\n");
			break;
	}
}
static inline void
proc(int *p1, int *p2, int sn)
{
	int i;
	for(i=1; i<=N_CARD; i++) {
		p2[i] = p1[shuf[sn][i]];
	}
}
int main()
{
	int i, kase, ns, j, shufle;
	int c1[LEN], c2[LEN], *p1, *p2, *pt;
	char line[LEN];
	scanf("%d", &kase);
	while (kase--){
		scanf("%d ", &ns);
		for(i=1; i<=ns; i++) {
			for(j=1; j<=N_CARD; j++) {
				scanf("%d ", &shuf[i][j]);
			}
		}
		p1 = c1;
		p2 = c2;
		for(i=1; i<=N_CARD; i++) c1[i] = i;
		while (fgets(line, LEN, stdin)) {
			if(line[0] == '\n' || !line[0]) break;
			sscanf(line, "%d", &shufle);
			proc(p1, p2, shufle);
			pt = p1;
			p1 = p2;
			p2 = pt;
		}
		for(i=1; i<=N_CARD; i++) output(p1[i]-1);
		if (kase) printf("\n");
	}
	return 0;
}