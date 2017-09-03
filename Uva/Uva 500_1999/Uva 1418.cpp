/*基础题。贪心+构造。要让梦之队的排名尽量低，它就得赢得少，输的多。但
 *至少要赢两场，如果只赢一场，其他结果必须是平手，梦之队的得分还是最高
 *的。假定赢两场，则最多只能输给其他队一场，其余为平手。这样可得：
 *梦之队： 一胜一负两次，其余都为一负一平，得6+n-3；
 *输给梦之队的两个队：一胜一负一次，其余都是平手，都3+2(n-2)；
 *剩余的对：一胜一平一次，其余是平局，得4+2(n-2)；
 *所以，n>4时，梦之队分数最低，n=4时，三个队并列第二，其余他只能第一了。
 *另外，不用考虑进球和输球数，因为赢一场就能进任意多的球，而且其他
 *对也可以随便输球，使得梦之队输球最少。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 1000005
int main()
{
	int n;
	while(scanf("%d", &n)) {
		if (!n) break;
		if (n>4) printf("%d\n", n);
		else if(n<4) printf("1\n");
		else printf("2\n");
	}
	return 0;
}