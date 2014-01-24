/*»Î√≈Ã‚°£*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define M 205
char a1[M], a2[M], re[M];
void Add(char *s1, char *s2)
{
	int i, j = 0, l1, l2;
	char *t;
	l1 = strlen(s1);
	l2 = strlen(s2);
	for(i=0; i<l2; i++) {
		j = s1[i]-'0'+s2[i]-'0'+j/10;
		re[i] = j%10+'0';
	}
	for(; i<l1; i++) {
		j = s1[i]-'0'+j/10;
		re[i] = j%10+'0';
	}
	if(j/10>0)
		re[i++] = j/10+'0';
	re[i] = '\0';
	return;
}
int main()
{
	int n, i, l, j;
	scanf("%d", &n);
	for(j=0; j<n; j++) {
		scanf("%s %s", a1, a2);
		if(strlen(a1)>strlen(a2))
			Add(a1, a2);
		else
			Add(a2, a1);
		l = strlen(re);
		for(i=0; i<l; i++)
			if(re[i] != '0')
				break;
		for(; i<l; i++)
			printf("%c", re[i]);
		printf("\n");
	}
	return 0;
}