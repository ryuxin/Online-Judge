/*�����⡣��Ŀ���⣬��һ��è����߶���֪Ϊa����������Է�N��è�������ǵĸ߶�������1/(N+1)���Դ����ƣ�
ÿ��è���涼���Է�N��Сè��ÿ��Сè�ĸ߶�����1/(N+1)��ֱ��Сè�ĸ߶�Ϊ1����֪�߶�Ϊ1��è�ĸ���Ϊb��
��һ����x�㣬��һ��߶�Ϊ1���ڶ��θ߶�Ϊ(N+1),��x��߶�Ϊ(N+1)^x=a���ҵ�1��è�ĸ���ΪN^x=b, ���N��
�߽��������ÿ��è����ֻ�ܷ�һ��èʱ�����ȱ����еĹ���Ϊ1��
���ң������棬��èֻ��һ��ʱ��Ҳ���������*/
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