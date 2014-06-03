/*基础题。搜索。 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 35
#define LEN 85
char data[NUM][LEN], c;
int o1[4] = {-1, 0, 1, 0}, o2[4] = {0, 1, 0, -1};
void DFS(int a, int b)
{
	int i;
	data[a][b] = '#';
	for(i=0; i<4; i++) 
		if (data[a+o1[i]][b+o2[i]] != c && data[a+o1[i]][b+o2[i]] != '#')
			DFS(a+o1[i], b+o2[i]);
	return ;
}
int main()
{
	int t, n, i, j, l;
	scanf("%d", &t);
	gets(data[0]);
	while (t--) {
		i = 0;
		while (1) {
			gets(data[i++]);
			if (data[i-1][0] == '_') break;
		}
		n = i;
		c = data[0][0];
		for(i=0; i<n-1; i++) {
			l = strlen(data[i]);
			for(j=0; j<l; j++)
				if (data[i][j] == '*')
					goto work;
		}
work:
		DFS(i, j);
		for(i=0; i<n; i++)
			printf("%s\n", data[i]);
	}
	return 0;
}