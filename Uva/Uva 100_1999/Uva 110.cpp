/*基础题。深搜，回溯。采用插入排序的思想。当前元素依次与前面的元素比较并交换。
  若找到插入位置，递归处理下一个元素。否则继续比较前一个元素。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 8
#define LEN 85
char var[NUM];
int n;
void Insert_sort(int cur, int indent)
{
	int i, j;
	char temp;
	for(i=0; i<indent; i++) printf("  ");
	if (cur == n) {
		printf("writeln(");
		for(i=0; i<n-1; i++) printf("%c,", var[i]);
		printf("%c)\n", var[i]);
		return ;
	}
	printf("if %c < %c then\n", var[cur-1], var[cur]);
	Insert_sort(cur+1, indent+1);
	temp = var[cur];
	var[cur] = var[cur-1];
	for(j=2; j<=cur; j++) {
		for(i=0; i<indent; i++) printf("  ");
		printf("else if %c < %c then\n", var[cur-j], temp);
		var[cur-j+1] = temp;
		Insert_sort(cur+1, indent+1);
		var[cur-j+1] = var[cur-j];
	}
	j = cur+1;
	for(i=0; i<indent; i++) printf("  ");
	printf("else\n");
	var[cur-j+1] = temp;
	Insert_sort(cur+1, indent+1);
	//backtrace
	for(i=0; i<cur; i++) var[i] = var[i+1];
	var[cur] = temp;
	return ;
}
int main()
{
	int i, m;
	for(i=0; i<NUM; i++) var[i] = 'a'+i;
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &n);
		printf("program sort(input,output);\nvar\n");
		for(i=0; i<n-1; i++) printf("%c,", var[i]);
		printf("%c : integer;\nbegin\n", var[i]);
		printf("  readln(");
		for(i=0; i<n-1; i++) printf("%c,", var[i]);
		printf("%c);\n", var[i]);
		Insert_sort(1, 1);
		printf("end.\n");
		if (m != 0) printf("\n");
	}
	return 0;
}