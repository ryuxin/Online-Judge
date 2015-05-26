/*入门题。最后一列不必用空格补齐。在行数最少的条件下，实际输出是按列输出的，所以输出时
应尽量将列填满，即只可能最后一列是不满的，*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char data[103][62];
int row, col, last_col, maxl;
int comp(const void *a1, const void *a2)
{
    char *p1, *p2;
    p1 = (char *)a1;
    p2 = (char *)a2;
    return strcmp(p1, p2);
}
void Print_row(int k)              //打印第k行
{
    int i, j, l, t, c;
	if(k < last_col)        //每行都有col列
		c = col-1;
    else                    //每行只有col-1列
		c = col-2;     
	for(i=0; i<c; i++) {
		t = k+i*row;
        l = strlen(data[t]);
        printf("%s",data[t]);
        for(j=l; j<maxl+2; j++)
			printf(" ");
    }
    t = k+i*row;
    printf("%s\n",data[t]);
    return ;
}
int main()
{
    int t, n, i, temp;
	while(scanf("%d", &n)>0) {
		for(i=0; i<n; i++) 
			scanf("%s", data[i]);
		qsort(data, n, sizeof(data[0]), comp);
		maxl = strlen(data[0]);
		for(i=1; i<n; i++) {
			temp = strlen(data[i]);
			if(temp > maxl)
				maxl = temp;
		}
		printf("------------------------------------------------------------\n");
		col = 62/(maxl+2);
		row = (n+col-1)/col;
		col = (n+row-1)/row;
		last_col = (n+col-1)%(row+1);
		for(i=0; i<row; i++)
			Print_row(i);
	}
    return 0;
}