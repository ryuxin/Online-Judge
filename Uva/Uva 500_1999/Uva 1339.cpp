/*入门题。经过替换和排列变换后，相应字母出现的次数不变。如果两个
 *字符串中同一个出现次数的字母个数相等，则两个字符串可以互相转换
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 160
char input[2][NUM];
int ocur[26], num[2][NUM], m, l;
static inline void proc(int k)
{
	int i, *t = num[k];
	char *s = input[k];
	memset(ocur, 0, sizeof(ocur));
	memset(t, 0, sizeof(int)*NUM);
	for(i=0; i<l; i++) ocur[s[i]-'A']++;
	for(i=0; i<26; i++) {
		t[ocur[i]]++;
		if (ocur[i] > m) m = ocur[i];
	}
}
int main()
{
	int i, r;
	while(EOF != scanf("%s", input[0])) {
		scanf("%s", input[1]);
		l = strlen(input[0]);
		m = r = 0;
		proc(0);
		proc(1);
		for(i=0; i<=m; i++) {
			if (num[0][i] != num[1][i]) {
				r = 1;
				break;
			}
		}
		if (r) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}