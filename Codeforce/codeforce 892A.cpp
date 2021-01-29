/*入门题。找到容量最大的两个杯子，判断它们
 *的容量和是否大于等于所有的可乐体积和。
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
int main()
{
	int n, i;
	long long int m1, m2, r_tot = 0, a;
	scanf("%d", &n);
	for(i=n-1; i>=0; i--) {
		scanf("%lld", &a);
		r_tot += a;
	}
	scanf("%lld %lld", &m1, &m2);
	if (m2 > m1) {
		a = m1;
		m1 = m2;
		m2 = a;
	}
	for(i=n-3; i>=0; i--) {
		scanf("%lld", &a);
		if (a >= m1) {
			m2 = m1;
			m1 = a;
		} else if (a > m2) m2 = a;
	}
	if (m1+m2 >= r_tot) printf("YES\n");
	else printf("NO\n");
	return 0;
}
