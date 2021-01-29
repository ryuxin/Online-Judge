/*入门题。模拟。重点是理解题意。若机器人最终位置
 *是(x, y)，由于每次只能移动一格，|x|+|y|就是多余
 *出来的移动步数，减掉其就是答案。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 105
char str[NUM];
int main()
{
	int n, i, x = 0, y = 0;
	scanf("%d%s", &n, str);
	for(i=n-1; i>=0; i--) {
		switch (str[i]) {
		case 'U':
			y++;
			break;
		case 'D':
			y--;
			break;
		case 'L':
			x++;
			break;
		case 'R':
			x--;
			break;
		}
	}
	printf("%d\n", n-abs(x)-abs(y));
	return 0;
}