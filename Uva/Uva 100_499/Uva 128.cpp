/*基础题。基础数学。题目大意，将字符串看做一个二进制数，在其后面补上两个byte，使得结果
  可以被34943整除。字符串左边第一位是最高位。
  使用Horner's Rule，对多项式求余。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1030
char data[NUM];
int main()
{
	int i, l, r;
	while(gets(data)) {
		if (data[0] == '#') break;
		l = strlen(data);
		data[l+1] = 0;
		r = 0;
		for(i=0; i<l+2; i++) 
			r = ((0xff&data[i])+(r*256)%34943)%34943;
		r = (34943-r)%34943;
		printf("%02X %02X\n", r>>8, 0xff&r);
	}
	return 0;
}