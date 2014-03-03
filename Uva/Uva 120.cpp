/*基础题 题目大意：给定一组数，唯一允许的操作f(i)，将从i到n之间的元素逆置。求出最短的操作序列，将数组
  从大到小排序。思路，选择排序。即从大到小将每个元素放到正确的位置。放置第i个元素时，若其已经在正确的位置，
  则继续下一个元素，否则先将其翻转至最后一个元素（f(pos[i])），再将其翻转至正确位置（f(i)）*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char s[700];
int data[35], rank[35],pos[35], n;    //rank[i]表示第i个数的次序，pos[i]表示第i大的数的位置
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p2)-(*p1);
}
void Flip(int k)
{
	int i, j, t;
	i = k;
	j = n;
	while(i<j) {
		pos[rank[i]] = j;
		pos[rank[j]] = i;
		t = rank[i];
		rank[i] = rank[j];
		rank[j] = t;
		i++;
		j--;
	}
	return ;
}
int main()
{
	int i,j,l,t;
	while(gets(s)) {
		l=strlen(s);
		s[l]=' ' ;
		i = 0;
		n = 1;
		do {
			sscanf(s+i, "%d",&data[n]);
			n++;
			while(s[i] != ' ') {
				i++;
			}
			i++;
		} while(i<l);
		n--;
		for(i=1; i<=n; i++)
			printf("%d ", data[i]);
		printf("\n");
		for(i=1; i<=(n+1)/2; i++) {
			t = data[i];
			data[i] = data[n+1-i];
			data[n+1-i] = t;
		}
		for(i=1; i<=n; i++)
			pos[i] = data[i];
		qsort(pos+1, n, sizeof(int), comp);
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				if(data[j] == pos[i]) {
					rank[j] = i;
					pos[i] = j;
					break;
				}
			}
		}
		for(i=1;i<=n;i++) {
			if(pos[i] != i) {
				if(pos[i] != n) {
					printf("%d ", pos[i]);
					Flip(pos[i]);
				}
				Flip(i);
				printf("%d ",i);
			}
		}
		printf("0\n");
	}
	return 0;
}






