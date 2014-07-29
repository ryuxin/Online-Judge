/*基础题。枚举。枚举所有可能的周期长度，依次进行比较。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1000005
#define LEN 25
char data[NUM];
bool Check(int p, int l)
{
	int i, j;
	for(i=p; i<l; i+=p)
		for(j=i; j<i+p; j++)
			if(data[j] != data[j%p])
				return false;
	return true;
}
int main()
{
	int l, i;
	while(gets(data)) {
		if (data[0] == '.') break;
		l = strlen(data);
		for(i=1; i<l; i++) {
			if (l%i != 0) continue;
			if (Check(i, l)) break;
		}
		printf("%d\n", l/i);
	}
	return 0;
}