/*�����⡣Ϊ���ӽ������ű�*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct pos {
    int id;
    int off;
};
struct Invert {
    char key[30];       //����Ϊ��д��ʽ
    int count;
    pos tittles[205];
};
Invert indexes[30005];
char ignore[52][12], tittle[205][300], temp[30];
int t, n, num;
int comp1(const void *a1, const void *a2)
{
    char *p1, *p2;
    p1 = (char *)a1;
    p2 = (char *)a2;
    return strcmp(p1, p2);
}
int comp2(const void *a1, const void *a2)
{
	Invert *p1, *p2;
	p1 = (Invert *)a1;
	p2 = (Invert *)a2;
	return strcmp(p1->key, p2->key);
}
bool Search(int k, int l, int r)       //���õ����Ƿ�Ϊignore��תСд
{
    int i = 0, j, m, re;
    for(j=l; j<r; j++) {
        if(tittle[k][j]>='A' && tittle[k][j]<= 'Z')
            temp[i++] = 'a'+tittle[k][j]-'A';
        else
            temp[i++] = tittle[k][j];
    }
    temp[i] = '\0';
    l = 0;
    r = t-1;
    while(l<=r) {
		m = (l+r)/2;
        re = strcmp(ignore[m], temp);
        if(re == 0)
            return true;
        else if(re>0)
			r = m-1;
		else
			l = m+1;
    }
    return false;
}
void Insert(int k, int l, int r)   //�����ʲ��뵹�ű�ת��д
{
	int i, j;
	i = 0;
    for(j=l; j<r; j++) {
        if(tittle[k][j]>='a' && tittle[k][j]<= 'z')
            temp[i++] = 'A'+tittle[k][j]-'a';
        else
            temp[i++] = tittle[k][j];
    }
    temp[i] = '\0';
	for(i=0; i<num; i++) {
		if(strcmp(indexes[i].key, temp) == 0) {
			indexes[i].tittles[indexes[i].count].id  = k; 
			indexes[i].tittles[indexes[i].count].off = l; 
			indexes[i].count++;
			break;
		}
	}
	if(i == num) {
		strcpy(indexes[i].key, temp);
		indexes[i].tittles[0].id  = k;
		indexes[i].tittles[0].off = l;
		indexes[i].count = 1;
		num++;
	}
    return ;
}
void Parser(int k)         //Ϊ��k�����ӽ������ű�
{
    int i, j, l;
    l = strlen(tittle[k]);
    i = 0;
	tittle[k][l] = ' ';
    for(j=0; j<=l; j++) {
        if(tittle[k][j] == ' ') {
            if(Search(k, i, j) == false)
                Insert(k, i, j);
            i = j+1;
        }
    }
	tittle[k][l] = '\0';
    return ;
}
void Output(int k)         //�����k�����ʶ�Ӧ�ľ���
{
	int len1, len2, i, count, j, id, off;
	len1 = strlen(indexes[k].key);
	count = indexes[k].count;
	for(i=0; i<count; i++) {
		id   = indexes[k].tittles[i].id;
		off  = indexes[k].tittles[i].off;
		len2 = strlen(tittle[id]);
		for(j=0; j<off; j++) {
			if(tittle[id][j]>='A' && tittle[id][j]<='Z')
				printf("%c", tittle[id][j]-'A'+'a');
			else
				printf("%c", tittle[id][j]);
		}
		printf("%s", indexes[k].key);
		for(j = j+len1; j<len2; j++) {
			if(tittle[id][j]>='A' && tittle[id][j]<='Z')
				printf("%c", tittle[id][j]-'A'+'a');
			else
				printf("%c", tittle[id][j]);
		}
		printf("\n");
	}
    return ;
}
int main()
{
    int i;
    t = n = num = 0;
    while(1) {
        scanf("%s", &ignore[t]);
        if(strcmp("::", ignore[t]) == 0)
            break;
        t++;
    }
    qsort(ignore, t, sizeof(ignore[0]), comp1);
	gets(tittle[0]);
    while(gets(tittle[n]) != NULL)      n++;
	for(i=0; i<n; i++)
		Parser(i);
	qsort(indexes, num, sizeof(Invert), comp2);
	for(i=0; i<num; i++)
		Output(i);
    return 0;
}
