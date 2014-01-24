/*
入门题 最后一组没有空行
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char data[100005][500];
char Cast(char c)
{
	if(c>='0' && c<='9')
		return c;
	if(c<='C')
		return '2';
	else if(c<='F')
		return '3';
	else if(c<='I')
		return '4';
	else if(c<='L')
		return '5';
	else if(c<='O')
		return '6';
	else if(c<='S')
		return '7';
	else if(c<='V')
		return '8';
	else 
		return '9';
}
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return strcmp(p1, p2);
}
int main()
{
	int i,n,l,j,k,t,f=0;
	char *s;
	scanf("%d", &t);
	while(t--) {
		if(f == 0)
			f = 1;
		else
			printf("\n");
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%s", &data[i]);
			l = strlen(data[i]);
			k=0;
			for(j=0; j<l; j++) 
				if(data[i][j] != '-')
					data[i][k++] = Cast(data[i][j]);
			data[i][k] = '\0';
		}
		qsort(data, n, sizeof(data[0]), comp);
		s = data[0];
		k = 1;
		data[n][0] = '\0';
		l = 0;
		for(j=1; j<=n;j++) {
			if(strcmp(data[j],s) == 0)
				k++;
			else {
				if(k>1) {
					printf("%c%c%c-%s %d\n", data[j-1][0], data[j-1][1], data[j-1][2], data[j-1]+3, k);
					l = 1;
				}
				k = 1;
			}
			s = data[j];
		}
		if(l == 0)
			printf("No duplicates.\n");
	}
    return 0;
}

