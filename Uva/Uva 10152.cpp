/*基础题。贪心。直观想法是先使在底部的乌龟到达指定位置。具体的，找到不满足下面条件的最大的乌龟i，
  在原始排列下，乌龟i+1, i+2, ……n都在i的下面。此后，依次移动乌龟i, i-1, …… 1，即为最优解。
  简要证明：由于i不满足上述条件，所以一定要移动i，否则不可能到达最后的顺序。同理，移动i到栈顶后，
  i-1, i-2, ……1一定也要移动。所以，至少要移动i次。而上面给出的移动方法恰好移动了i次，所以上面
  的方法是最优的。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 205
#define LEN 85
int n, postition[NUM];  //排名为i的乌龟是第p[i]个
char name[NUM][LEN], temp[LEN];
int pos(char *s)
{
	int i;
	for(i=0; i<n; i++)
		if (strcmp(name[i], s) == 0)
			break;
	return i;
}
int main()
{
	int c, i, p;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		gets(temp);
		for(i=0; i<n; i++)
			gets(name[i]);
		for (i=0; i<n; i++) {
			gets(temp);
			postition[i] = pos(temp);
		}
		p = n-1;
		for(i=n-1; i>=0; i--) {
			while(p>=0) {
				if (strcmp(name[p], name[postition[i]]) == 0) 
					break;
				p--;
			}
			if (p<0) break;
			else p--;
		}
		for(; i>=0; i--)
			printf("%s\n", name[postition[i]]);
		printf("\n");
	}
	return 0;
}