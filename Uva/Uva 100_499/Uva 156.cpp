/*基础题。为每个单词定义一个标准型：即所有字符都是小写，且已排好序。则两个单词若是可转换的，则他们
  必有相同的标准型。将每个单词都转换为标准型，并按其排序。扫描排序后序列，只有只出现一次的标准型所对
  应的单词满足题意，将这样的单词找到后，再排序，即为最终结果*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
struct Dic {
	char org[25], trans[25];
};
Dic data[1002];
int comp1(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return (*p1)-(*p2);
}
int comp2(const void *a1, const void *a2)
{
	Dic *p1, *p2;
	p1 = (Dic *)a1;
	p2 = (Dic *)a2;
	return strcmp(p1->trans,p2->trans);
}
int comp3(const void *a1, const void *a2)
{
	Dic *p1, *p2;
	p1 = (Dic *)a1;
	p2 = (Dic *)a2;
	return strcmp(p1->org,p2->org);
}
int main()
{
	int i, n, l, j;
	n = 0;
	while(1) {
		cin>>data[n].org;
		if(strcmp(data[n].org,"#") == 0)
			break;
		strcpy(data[n].trans,data[n].org);
		//trans为标准型
		l = strlen(data[n].trans);
		for(i=0; i<l; i++)
			if(data[n].trans[i]>='A' && data[n].trans[i]<='Z')
				data[n].trans[i] = data[n].trans[i]-'A'+'a';
		qsort(data[n].trans,l,sizeof(char),comp1);
		n++;
	}
	qsort(data,n,sizeof(data[0]),comp2);
	data[n].trans[0]='\0';
	l = 0;
	for(i=0;i<n;) {
		for(j=i+1; j<=n;j++) {
			if(strcmp(data[i].trans, data[j].trans) != 0)
				break;
		}
		if(i == j-1)             //该标准型只出现一次
			data[l++] = data[i];
		i = j;
	}
	qsort(data, l, sizeof(data[0]),comp3);
	for(i=0;i<l;i++)
		printf("%s\n",data[i].org);
	return 0;
}




