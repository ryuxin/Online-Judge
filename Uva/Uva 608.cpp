/*基础题。枚举。题目大意：1。题目保证通过给出的三大测量，一定能找到假币。
2。天平两边的个数一定相等，但不一定放几个，可能都只放1个，或都放6个。
基本思路就是枚举每个硬币可能是轻或重。然后和测量结果比较，看看是否矛盾.
在本题的具体实现中，采用根据当前的结果去猜测一个硬币是真是假，并验证以前的猜测。
若结果为even， 则出现的硬币一定是真的。否则， 没出现的硬币一定是真的。
当出现不平衡时，例如up，则左边的硬币可能是重的，右边的硬币可能是轻的。
但要保证这种猜测不和以前的猜测矛盾，若矛盾，说明此硬币是真的*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Result {	
	char lr[2][7];
	char re[6];
};
Result data[3];
int re[12], temp[12];
void Process(int k)
{
	int i, j, l, t, f;
	if(data[k].re[0] == 'e') {        //出现的硬币一定是真的
		for(j=0; j<2; j++) {
			l = strlen(data[k].lr[j]);
			for(i=0; i<l; i++)
				re[data[k].lr[j][i]-'A'] = 1;
		}
		return;
	}
	for(j=0; j<2; j++) {             //没出现的硬币一定是真的
		l = strlen(data[k].lr[j]);
		for(i=0; i<l; i++)
			temp[data[k].lr[j][i]-'A'] = 1;
	}
	for(i=0; i<12; i++) {
		if(temp[i] == 0)
			re[i] = 1;
		else
			temp[i] = 0;
	}
	if(data[k].re[0] == 'd') 
		f = 2;
	else
		f = 0;
	l = strlen(data[k].lr[0]);
	for(i=0; i<l; i++) {
		t = data[k].lr[0][i]-'A';
		if(re[t] == -1)
			re[t] = 2-f;
		if(re[t] == f)          //和以前的猜测矛盾,是真的
			re[t] = 1;
	}
	l = strlen(data[k].lr[1]);
	for(i=0; i<l; i++) {
		t = data[k].lr[1][i]-'A';
		if(re[t] == -1)
			re[t] = f;
		if(re[t] == 2-f)
			re[t] = 1;
	}
	return;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	while(n--) {
		for(i=0; i<12; i++) {
			re[i] = -1;
			temp[i] = 0;
		}
		for(i=0; i<3; i++)
			scanf("%s %s %s", data[i].lr[0], data[i].lr[1], data[i].re);
		for(i=0; i<3; i++)
			Process(i);
		for(i=0; i<12; i++) {
			if(re[i] != 1) {
				if(re[i] == 0)
					printf("%c is the counterfeit coin and it is light.\n", i+'A');
				else
					printf("%c is the counterfeit coin and it is heavy.\n", i+'A');
			}
		}
	}
	return 0;
}