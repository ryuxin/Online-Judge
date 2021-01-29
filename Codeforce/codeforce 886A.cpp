/*入门题。枚举。题目大意：给出6个数，问是否可以将其平均分为两
 *组，使得两组的和相同。只需三重循环，枚举哪三个数分在一组即可
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;
#define NUM 6
#define LEN 1005
int num[NUM];
int main()
{
	int i, j, k, s = 0;
	for(i=0; i<NUM; i++) scanf("%d", &num[i]);
	for(i=0; i<NUM; i++) s += num[i];
	for(i=0; s%2 == 0 && i<NUM; i++) {
		for(j=i+1; j<NUM; j++) {
			for(k=j+1; k<NUM; k++) {
				if ((num[i]+num[j]+num[k])*2 == s) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}