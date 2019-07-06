/*基础题。动规。dp(i, j)表示将字符字串s[i, j]变成回文所需的最少操作数。则有
 *if i>=j dp(i, j) = 0
 *else if s[i] == s[j], dp(i, j) = dp(i+1, j-1)
 *else dp(i, j) = min{dp(i+1, j), dp(i, j-1)}
 *求解出dp数组后，再根据它逆向构造出回文。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>   
#include <vector>
using namespace std;

#define NUM 1005
#define LEN 2005
int dp[NUM][NUM];
char data[NUM], re[LEN];
int main()
{
	int i, l, j, r, li, lj;
	memset(dp, 0, sizeof(dp));
	while (scanf("%s", data) != EOF) {
		l = strlen(data);
		for(i=1; i<l; i++) {
			for(j=0; j+i<l; j++) {
				if (data[j] == data[j+i]) {
					dp[j][j+i] = dp[j+1][j+i-1];
				} else if (dp[j+1][j+i] < dp[j][j+i-1]) {
					dp[j][j+i] = 1+dp[j+1][j+i];
				} else {
					dp[j][j+i] = 1+dp[j][j+i-1];
				}
			}
		}
		r = dp[0][l-1];
		re[l+r] = '\0';
		i=li=0, j=l-1, lj = l+r-1;
		while (i <= j) {
			if (data[i] == data[j]) {
				re[li++] = re[lj--] = data[i];
				i++, j--;
			} else if (dp[i+1][j] < dp[i][j-1]) {
				re[li++] = re[lj--] = data[i];
				i++;
			} else {
				re[li++] = re[lj--] = data[j];
				j--;
			}
		}
		printf("%d %s\n", r, re);
	}
	return 0;
}
