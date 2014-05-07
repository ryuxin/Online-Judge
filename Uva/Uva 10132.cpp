/*基础题。枚举+贪心。
  1、最长的一定和最短的配对，且最短的之多有两种(左右端各一个),
  所以最终合成的文件最多有四种，依次枚举这四种，判断剩余的碎片
  是否可以构成这样的文件。
  2、判断时，可以采用贪心策略。若判定的文件是最终文件，且碎片A，
  B可以构成该文件AB，则一定存在一种配对方案，使得AB配对。
  证明思路，若不存在，可设AC配对，BD配对，且满足(C!=B && A!=D)，
  则配对方式一定是CA，BD，可得B=C，A=D，矛盾。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 300
#define LEN 520
char data[NUM][LEN], cur[LEN*2], temp[2*LEN];
int n, used[NUM], len;
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	int l1, l2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	l1 = strlen(p1);
	l2 = strlen(p2);
	if (l1 == l2) return strcmp(p1, p2);
	return l2-l1;
}
bool check(void)
{
	int i, j, l;
	for(i=0; i<n; i++) {
		if (used[i] == 1) continue;
		l = strlen(data[i]);
		for(j=1; j<n; j++) {
			if (used[j] == 1) continue;
			if (strlen(data[j])+l != len) continue;
			//if (strcmp(data[j], data[j-1]) == 0)
			//	continue;
			strcpy(temp, data[i]);
			strcat(temp, data[j]);
			if (strcmp(temp, cur) == 0) 
				used[i] = used[j] = 1;
		}
	}
	for(i=0; i<n; i++) 
		if (used[i] == 0)
			return false;
	return true;
}
void Process(void)
{
	int i, j;
	used[0] = used[n-1] = 1;
	for(i=1; i<n-1; i++) used[i] = 0;
	strcpy(cur, data[0]);
	strcat(cur, data[n-1]);
	len = strlen(cur);
	if (check()) return ;
	for(i=1; i<n-1; i++) used[i] = 0;
	strcpy(cur, data[n-1]);
	strcat(cur, data[0]);
	if (check()) return ;
	for(i=1; i<n; i++) used[i] = 0;
	i = n-2;
	while(i>=0) {
		if (strcmp(data[i], data[n-1]) != 0)
			break;
	}
	used[i] = 1;
	strcpy(cur, data[0]);
	strcat(cur, data[i]);
	if (check()) return;
	for(j=1; j<n; j++) used[j] = 0;
	used[i] = 1;
	strcpy(cur, data[i]);
	strcat(cur, data[0]);
	check();
	return ;
}
int main()
{
	int t, i, j;
	scanf("%d", &t);
	gets(data[0]);
	gets(data[0]);
	while(t--) {
		n = 0;
		while(gets(data[n]) != NULL) {
			if (strlen(data[n]) == 0)
				break;
			n++;
		}
		qsort(data, n, sizeof(data[0]), comp);
		Process();
		printf("%s\n", cur);
		//最后没有空行
		if (t>0) printf("\n");
	}
	return 0;
}	