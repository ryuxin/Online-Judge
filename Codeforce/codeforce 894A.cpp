/*入门题。字符串。先求出关于Q的前缀和S。S(i)代表
 *0到i闭区间内Q的个数。然后扫描字符串，对于每一
 *个A，由它构成的QAQ的数目为S(i)*(S(len) - S(i))
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

#define NUM 105
#define LEN 105
int qn[NUM];
char str[NUM];
int main()
{	
	int i, l, r = 0, j;
	scanf("%s", str);
	l = strlen(str);
	qn[0] = (str[0] == 'Q');
	for(i=1; i<l; i++) {
		qn[i] = (str[i] == 'Q') + qn[i-1];
	}
	for(i=0; i<l; i++) {
		if (str[i] == 'A') {
			r += qn[i] * (qn[l-1] - qn[i]);
		}
	}
	printf("%d\n", r);
	return 0;
}