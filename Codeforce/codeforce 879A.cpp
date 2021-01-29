/*入门题。贪心。题目要求必须按1,2，..,n的
 *顺序看医生，所以对于当前的医生i，选取最
 *小的满足的条件的日期即可。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 3
int main()
{
	int n, i, si, di, r;
	scanf("%d %d %d", &n, &r, &di);
	for(i=n-1; i>0; i--) {
		scanf("%d %d", &si, &di);
		if (r < si) r = si;
		else r = si + ((r-si)/di+1)*di;
	}
	printf("%d\n", r);
	return 0;
}