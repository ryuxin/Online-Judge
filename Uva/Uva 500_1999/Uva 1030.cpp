/*入门题。迭代，模拟。当一个位置是'.'的时候，这个位置肯定不存
 *在方块。当从不同方向去看一个位置时，如果看到的颜色不同，这
 *个位置也一定不存在方块。一直循环扫描这个立方体，直到上述两
 *种情况都不发生，则剩余的位置都可以存在方块，得到最大可能重量。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 12
#define LEN 6
char views[LEN][NUM][NUM];  //front, left, back, right, top, bottom
char re[NUM][NUM][NUM];  //0-没有颜色，'.'空的，其他-暂时确定的颜色
int n, tot;
bool process_frone()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[0][i][j];
			for(k=0; k<n; k++) {
				if (re[k][i][j] == '.') continue;
				if (!re[k][i][j]) re[k][i][j] = c;
				if (re[k][i][j] != c || c == '.') {
					tot--;
					ret &= false;
					re[k][i][j] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
bool process_left()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[1][i][j];
			for(k=0; k<n; k++) {
				if (re[n-1-j][i][k] == '.') continue;
				if (!re[n-1-j][i][k]) re[n-1-j][i][k] = c;
				if (re[n-1-j][i][k] != c || c == '.') {
					tot--;
					ret &= false;
					re[n-1-j][i][k] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
bool process_back()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[2][i][j];
			for(k=n-1; k>=0; k--) {
				if (re[k][i][n-1-j] == '.') continue;
				if (!re[k][i][n-1-j]) re[k][i][n-1-j] = c;
				if (re[k][i][n-1-j] != c || c == '.') {
					tot--;
					ret &= false;
					re[k][i][n-1-j] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
bool process_right()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[3][i][j];
			for(k=n-1; k>=0; k--) {
				if (re[j][i][k] == '.') continue;
				if (!re[j][i][k]) re[j][i][k] = c;
				if (re[j][i][k] != c || c == '.') {
					tot--;
					ret &= false;
					re[j][i][k] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
bool process_top()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[4][i][j];
			for(k=0; k<n; k++) {
				if (re[n-1-i][k][j] == '.') continue;
				if (!re[n-1-i][k][j]) re[n-1-i][k][j] = c;
				if (re[n-1-i][k][j] != c || c == '.') {
					tot--;
					ret &= false;
					re[n-1-i][k][j] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
bool process_bottom()
{
	bool ret = true;
	int i, j, k;
	char c;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			c = views[5][i][j];
			for(k=n-1; k>=0; k--) {
				if (re[i][k][j] == '.') continue;
				if (!re[i][k][j]) re[i][k][j] = c;
				if (re[i][k][j] != c || c == '.') {
					tot--;
					ret &= false;
					re[i][k][j] = '.';
				}
				if (c != '.') break;
			}
		}
	}
	return ret;
}
int main()
{
	int i, j, r;
	char input[1+NUM];
	while(scanf("%d", &n)) {
		if (!n) break;
		for(j=0; j<n; j++) {
			for(i=0; i<LEN; i++) {
				scanf("%s", input);
				memcpy(views[i][j], input, n);
			}
		}
		tot = n*n*n;
		r = 0;
		memset(re, 0, sizeof(re));
		while(tot && !r) {
			r = process_frone();
			r &= process_left();
			r &= process_back();
			r &= process_right();
			r &= process_top();
			r &= process_bottom();
		}
		printf("Maximum weight: %d gram(s)\n", tot);
	}
	return 0;
}