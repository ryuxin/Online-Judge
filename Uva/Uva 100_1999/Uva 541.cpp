// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*�����⡣���ҽ�����ֻ��һ�к�һ�д���ʱ�������ǿɻָ���*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 105
int data[NUM];      //����ÿһ�еĺ�
int main()
{
	int n, i, j, t, r, n1, n2, x, y;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		n1 = n2 = 0;
		for(i=0; i<n; i++) data[i] = 0;
		for(i=0; i<n; i++) {
			r = 0;
			for(j=0; j<n; j++) {
				scanf("%d", &t); 
				r += t;
				data[j] += t;
			}
			if (r%2 != 0) {
				n1++;
				x = i+1;
			}
		}
		for(i=0; i<n; i++)
			if (data[i]%2 != 0) {
				y = i+1;
				n2++;
			}
		if (n1 == 0 && n2 == 0)
			printf("OK\n");
		else if (n1 == 1 && n2 == 1)
			printf("Change bit (%d,%d)\n", x, y);
		else printf("Corrupt\n");
	}
	return 0;
}