/*�����⡣�������������ϳ��������ֳ���һ��������������ֵĴ�С
  ��ͬ�����ַ����Ĵ�С�������ַ���a��b���������Ӻ�õ������µ��ַ�
  ��ab��ba������a>=b, ���ҽ���ab>=ba(����Ϊ�ַ����Ƚϲ���)������֤
  ���ù�ϵ���㴫���ԣ���a>=b��b>=c, ����a>=c.
  ֤�������䳤�ȷֱ�Ϊla, lb, lc��ab���Ա�ʾΪ����
  �����������֪�Ĳ���ʽ����
  a*10^lb+b>=b*10^la+a => a(10^lb-1)>=b(10^la-1)
  b*10^lc+c>=c*10^lb+b => b(10^lc-1)>=c(10^lb-1)
  ������ʽ��ˣ������
  a(10^lc-1)>=c(10^la-1) => a*10^lc+c>=c*10^la+a��
  ��ac>=ca, ��a>=c��
  ����n������һ�����У�A=a1a2����an�������������ĳ�Ҫ�����ǣ�
  a1>=a2>=����>=an����Ҫ�Կ��ɴ�����ֱ�ӵó�����Ϊ������i����ai>=ai+1��
  ����ԡ��������B����һ�����У�����ð�������ҵ�a1��λ�ã���������
  ��ǰ���������������a1����������������ÿ�ν���������ʹ�����С����
  ��������н�����õ�A>=B����ΪB�����ģ�����A=B��Ҳ������*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define LEN 100
char data[55][LEN], mid1[2*LEN], mid2[2*LEN];
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	strcpy(mid1, p1);
	strcat(mid1, p2);
	strcpy(mid2, p2);
	strcat(mid2, p1);
	return strcmp(mid2, mid1);
}
int main()
{
	int i, n;
	while(cin>>n) {
		if (n == 0) break;
		for (i=0; i<n; i++) 
			cin>>data[i];
		qsort(data, n, sizeof(data[0]), comp);
		for(i=0; i<n; i++)
			cout<<data[i];
		cout<<endl;
	}
	return 0;
}