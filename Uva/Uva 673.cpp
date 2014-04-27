/*典型题。数据结构：栈。最开始我采用动规，用dp[i][j]表示i到j之间
  是否满足要求，复杂度为n^3, 超时。
  当前的做法是从左到右扫描，发现右括号是，往回扫，找到第一个未被
  处理的字符，看其是否匹配，若不匹配，则整个串都不满足要求，否则
  继续扫描。复杂度为n^2.
  但最优解法是用一个栈来保存字符串，左括号入栈，右括号弹栈，若匹
  配就继续处理，否则整个串不满足条件。这样处理过的字符，以后就不
  会重复检查。复杂度为n*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 150
char data[NUM];
int used[NUM];
int main()
{
	int n, i, j, l, len;
	scanf("%d", &n);
	gets(data);
	while (n--) {
		gets(data);
		l = strlen(data);
		if (l%2 == 1) {
			printf("No\n");
			continue;
		}
		memset(used, 0, l*sizeof(int));
		for(i=0; i<l; i++) {
			len = 0;
			if (data[i] == ')') {
				for(j=i-1; j>=0; j--)
					if (used[j] == 0) {
						if(data[j] != '(')
							len = 1;
						else 
							used[i] = used[j] = 1;
						break;
					}
			}
			if (data[i] == ']') {
				for(j=i-1; j>=0; j--)
					if (used[j] == 0) {
						if(data[j] != '[')
							len = 1;
						else 
							used[i] = used[j] = 1;
						break;
					}
			}
			if (len) break;
		}
		for(i=0; i<l; i++)
			if (used[i] == 0)
				break;
		if (i == l) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}