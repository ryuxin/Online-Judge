/*�����⡣ö�١���Ŀ���⣺1����Ŀ��֤ͨ�����������������һ�����ҵ��ٱҡ�
2����ƽ���ߵĸ���һ����ȣ�����һ���ż��������ܶ�ֻ��1�����򶼷�6����
����˼·����ö��ÿ��Ӳ�ҿ���������ء�Ȼ��Ͳ�������Ƚϣ������Ƿ�ì��.
�ڱ���ľ���ʵ���У����ø��ݵ�ǰ�Ľ��ȥ�²�һ��Ӳ�������Ǽ٣�����֤��ǰ�Ĳ²⡣
�����Ϊeven�� ����ֵ�Ӳ��һ������ġ����� û���ֵ�Ӳ��һ������ġ�
�����ֲ�ƽ��ʱ������up������ߵ�Ӳ�ҿ������صģ��ұߵ�Ӳ�ҿ�������ġ�
��Ҫ��֤���ֲ²ⲻ����ǰ�Ĳ²�ì�ܣ���ì�ܣ�˵����Ӳ�������*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Result {	
	char lr[2][7];
	char re[6];
};
Result data[3];
int re[12], temp[12];
void Process(int k)
{
	int i, j, l, t, f;
	if(data[k].re[0] == 'e') {        //���ֵ�Ӳ��һ�������
		for(j=0; j<2; j++) {
			l = strlen(data[k].lr[j]);
			for(i=0; i<l; i++)
				re[data[k].lr[j][i]-'A'] = 1;
		}
		return;
	}
	for(j=0; j<2; j++) {             //û���ֵ�Ӳ��һ�������
		l = strlen(data[k].lr[j]);
		for(i=0; i<l; i++)
			temp[data[k].lr[j][i]-'A'] = 1;
	}
	for(i=0; i<12; i++) {
		if(temp[i] == 0)
			re[i] = 1;
		else
			temp[i] = 0;
	}
	if(data[k].re[0] == 'd') 
		f = 2;
	else
		f = 0;
	l = strlen(data[k].lr[0]);
	for(i=0; i<l; i++) {
		t = data[k].lr[0][i]-'A';
		if(re[t] == -1)
			re[t] = 2-f;
		if(re[t] == f)          //����ǰ�Ĳ²�ì��,�����
			re[t] = 1;
	}
	l = strlen(data[k].lr[1]);
	for(i=0; i<l; i++) {
		t = data[k].lr[1][i]-'A';
		if(re[t] == -1)
			re[t] = f;
		if(re[t] == 2-f)
			re[t] = 1;
	}
	return;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	while(n--) {
		for(i=0; i<12; i++) {
			re[i] = -1;
			temp[i] = 0;
		}
		for(i=0; i<3; i++)
			scanf("%s %s %s", data[i].lr[0], data[i].lr[1], data[i].re);
		for(i=0; i<3; i++)
			Process(i);
		for(i=0; i<12; i++) {
			if(re[i] != 1) {
				if(re[i] == 0)
					printf("%c is the counterfeit coin and it is light.\n", i+'A');
				else
					printf("%c is the counterfeit coin and it is heavy.\n", i+'A');
			}
		}
	}
	return 0;
}