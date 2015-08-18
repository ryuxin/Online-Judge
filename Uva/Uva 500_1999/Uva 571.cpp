/*基础题。数学。设两个杯子容量为a，b (a<b)，目标容量为n (n<=b)。
 *a，b的最大公约数是c。下面证明目标容量可达，当且仅当n|c。
 *引理：任意时刻，至少有一个杯子为满或为空。
 *由操作的规定可知，每一个操作必将一个杯子倒满或清空。
 *
 *充分性。用归纳法证明任意时刻，每个杯子里水的量都是c的倍数。
 *初始时，两个杯子都空，满足条件。假设当第k个操作完成后，两个
 *杯子容量分别为a1, b1，满足假设条件。若第k+1个操作是将一个杯子
 *倒满或清空，显然该杯子的容量满足条件，而另一个杯子不变。若将
 *一个杯子的水倒入另一个中，则水的总量不变。若第一个杯子倒空，
 *第二个杯子的水量为a1+b1，可以被c整除。若第二个杯子倒满，第一
 *个杯子剩余水量为a1+b1-b，仍为c的倍数。由数学归纳法，充分性得证。
 *
 *必要性。当n为c的倍数时，可知方程ax+by = n有解。又因为0<n<b，可
 *知存在一组解使得(x0, y0)(x0<0, y0>0)。按照以下算法，即可达到目
 *标容量。当杯子b为空时，将b接满。当杯子a满时，将a清空。其余清空
 *将b的水倒入a中。当a被清空x0次后，b中剩余的水量一定为n。因为此
 *时b恰好被接满y0次。因为若小于y0次，则不能有足够的水量让a能清空
 *x0次，若大于y0次，则剩余的水量会大于b，与a为空矛盾。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 302
#define LEN 45
int main()
{
	int a, b, c1, c2, n;
	//因为a，b互质，任意数量都可达。
	while(-1 != scanf("%d%d%d", &a, &b, &n)) {
		c1 = c2 = 0;
		while(c2 != n) {
			if (!c2) {
				c2 = b;
				printf("fill B\n");
			} else if(c1 == a) {
				c1 = 0;
				printf("empty A\n");
			} else if(!c1) {
				c1 = c2 > a? a : c2;
				c2 -= c1;
				printf("pour B A\n");
			} else {
				c2 = c1+c2-a;
				c1 = a;
				printf("pour B A\n");
			}
		}
		printf("success\n");
	}
	return 0;
}