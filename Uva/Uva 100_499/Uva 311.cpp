/*基础题。贪心。先放大的。放不满的时候，尽量放小的。
  要记录2*2的还剩多少，但不必记录1*1的。可以最后统一计算。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 6
#define LEN 25
int data[NUM];
int main()
{
	int i, sum, re, t;
	while(1) {
		sum = re = 0;
		for(i=0; i<NUM; i++) {
			scanf("%d", &data[i]);
			sum += data[i]*(i+1)*(i+1);
		}
		if (sum == 0) break;
		re = re+data[5]+data[4]+data[3];    //6*6   5*5    4*4
		data[1] -= 5*data[3];
		re += (data[2]+3)/4;            //3*3
		data[2] %= 4;
		if      (data[2] == 3) data[1] -= 1;
		else if (data[2] == 2) data[1] -= 3;
		else if (data[2] == 1) data[1] -= 5;
		if (data[1]<0) data[1] = 0;     //2*2
		re += (data[1]+8)/9;
		data[0] = sum-re*36;       //1*1
		if (data[0]>0) re += (data[0]+35)/36;
		printf("%d\n", re);
	}
	return 0;
}