/*基础题。枚举。由于数据规模很小，直接暴力搜索。由加括号的方式可知，必须
  从后向前，依次搜索每一个操作数。对于每一个操作数，枚举所有可能的数和操作*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 5
#define LEN 105
int data[NUM], used[NUM];
bool DFS(int k, int s)
{
	int i;
	if (k == NUM-1) {
		for(i=0; i<NUM; i++)
			if (used[i] == 0 && data[i] == s) return true;
		return false;
	}
	for(i=0; i<NUM; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		if (DFS(k+1, s-data[i])) return true;       //ai+x = s
		if (DFS(k+1, s+data[i])) return true;       //x-ai = s
		if (s%data[i] == 0)
			if (DFS(k+1, s/data[i])) return true;    //ai*x = s
		used[i] = 0;
	}
	return false;
}
int main()
{
	int i;
	while(1) {
		for(i=0; i<NUM; i++) scanf("%d", &data[i]);
		if (data[0] == 0) break;
		for(i=0; i<NUM; i++) used[i] = 0;
		if (DFS(0, 23)) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}