/*������ ��Ŀ���⣺����һ������Ψһ����Ĳ���f(i)������i��n֮���Ԫ�����á������̵Ĳ������У�������
�Ӵ�С����˼·��ѡ�����򡣼��Ӵ�С��ÿ��Ԫ�طŵ���ȷ��λ�á����õ�i��Ԫ��ʱ�������Ѿ�����ȷ��λ�ã�
�������һ��Ԫ�أ������Ƚ��䷭ת�����һ��Ԫ�أ�f(pos[i])�����ٽ��䷭ת����ȷλ�ã�f(i)��*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char s[700];
int data[35], rank[35],pos[35], n;    //rank[i]��ʾ��i�����Ĵ���pos[i]��ʾ��i�������λ��
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






