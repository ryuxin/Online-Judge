/*基础题。位操作。某一位经历n次操作后，只有四种状态：
 *a-变为1,b-变为0,c-取反，d-不变。a对应于1或，b对应
 *于0与，c对应于1异或，d不需要操作。运行给定的n次操
 *作，根据最后结果和上面的4种情况，即可得出化简后的
 *操作。优化：b可以看做a->c的组合，这样最后只需要两
 *个操作。还有一个问题：怎么区分c和ab？对0和~0（次
 *题是1023）分别都执行n次操作。若两个结果都是1，则
 *是情况a（同理，都为0，是b），若两个都取反，则是c。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 505
#define LEN 3
int p[NUM];
int main()
{
	int n, i, c, r1 = 0, r2 = 1023;
	int d1, d2, n1, n2;
	char op;
	scanf("%d", &n);
	for(i=n; i>0; i--) {
		scanf(" %c %d", &op, &c);
		switch (op) {
		case '|':
			r1 |= c;
			r2 |= c;
			break;
		case '&':
			r1 &= c;
			r2 &= c;
			break;
		case '^':
			r1 ^= c;
			r2 ^= c;
			break;
		default:
			break;
		}
	}
	n1 = n2 = 0;
	for(i=0; i<10; i++) {
		c = (1<<i);
		d1 = (r1 & c);
		d2 = (r2 & c);
		if (d1 && d2) n1 |= c;
		else if (d1 && !d2) n2 ^= c;
		else if (!d1 && !d2) {
			n1 |= c;
			n2 ^= c;
		}
	}
	printf("2\n| %d\n^ %d\n", n1, n2);
	return 0;
}