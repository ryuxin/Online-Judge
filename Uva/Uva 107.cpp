/*入门题。题目大意，有一个猫，其高度已知为a，他里面可以放N个猫，但他们的高度是他的1/(N+1)，以此类推，
每个猫里面都可以放N个小猫，每个小猫的高度是其1/(N+1)，直到小猫的高度为1，已知高度为1的猫的个数为b。
设一共有x层，第一层高度为1，第二次高度为(N+1),第x层高度为(N+1)^x=a，且第1层猫的个数为N^x=b, 解出N。
边界情况，当每个猫里面只能放一个猫时，即等比数列的公比为1。
而且，这里面，当猫只有一层时，也是特殊情况*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int Pow(int a, int b)
{
    int r = 1, s = b;
    while(s<=a) {
        if(a == s)
            return r;
        s=s*b;
        r++;
    }
    return -1;
}
int main()
{
    int a, b, i, p, q;
    while(scanf("%d %d", &a, &b)>0) {
        if(a == 0 && b == 0)
            break;
		if(b == 1) {
			if(a == 1)
				printf("0 1\n");
			else {
				p = Pow(a, 2);
				printf("%d %d\n", p, 2*a-1);
			}
		}
		else {
			for(i=2; i<b; i++) {
				if(b%i == 0 && a%(i+1) == 0) {
					p = Pow(b, i);
					q = Pow(a, i+1);
					if(p != -1 && p == q)
						break;
				}
			}
			printf("%d %d\n", (b-1)/(i-1), i*(a-b)+a);
		}
    }
    return 0;
}