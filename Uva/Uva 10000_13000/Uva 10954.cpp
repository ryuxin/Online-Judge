/*�����⡣̰�ġ�ȫ���ĺϲ����̹���һ������������һ������󱻼ӵĴ���������
  ���������е���ȣ����������ܺ�ΪS = Sum(d(i)*i)����������ͻ�������
  ��ȼۣ�ÿ��ѡ����С������Ԫ����ӣ��������ߵĺ���Ϊ��Ԫ�ز�ؼ����С�
  ά����Сֵ���Զ�����С��ʵ�֡�*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 5005
#define Max 500000005
int num, data[NUM];
void Down(int k)
{
	int c = 1, t;
	if (2*k+1>=num) return ;
	if ((2*k+2<num) && (data[2*k+2]<data[2*k+1])) c = 2;
	if (data[k]>data[2*k+c]) {
		t = data[k];
		data[k] = data[2*k+c];
		data[2*k+c] = t;
		Down(2*k+c);
	}
	return ;
}
void Build(void)
{
	int i;
	for(i=(num-2)/2; i>=0; i--) Down(i);
	return ;
}
int Pop(void) 
{
	int r;
	r = data[0];
	data[0] = data[--num];
	Down(0);
	return r;
}
int main()
{
	int i, a, b, re, n;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=0; i<n; i++) scanf("%d", &data[i]);
		data[n] = Max;
		num = n;
		re = 0;
		Build();
		for(i=1; i<n; i++) {
			a = Pop();
			a += data[0];
			re += a;
			data[0] = a;
			Down(0);
		}
		printf("%d\n", re);
	}
	return 0;
}