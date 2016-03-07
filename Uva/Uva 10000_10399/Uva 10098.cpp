/*基础题。回溯生成所有排列。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 13
char data[NUM], cur[NUM];
int order[NUM], num, l;
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return (*p1)-(*p2);
}
void backtrace(int k)
{
	int i;
	if (k == l ) {
		printf("%s\n", cur);
		return ;
	}
	for(i=0; i<num; i++) {
		if (order[i] == 0) continue;
		cur[k] = data[i];
		order[i]--;
		backtrace(k+1);
		order[i]++;
	}
}
int main()
{
	int i, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", data);
		l = strlen(data);
		qsort(data, l, sizeof(char), comp);
		order[0] = num = 1;
		for(i=1; i<l; i++) {
			if (data[i] != data[i-1]) {
				data[num] = data[i];
				order[num++] = 1;
			}
			else order[num-1]++;
		}
		data[num] = '\0';
		cur[l] = '\0';
		backtrace(0);
		printf("\n");
	}
	return 0;
}	