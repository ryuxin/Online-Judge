/*�����⡣��ѧ�����ۡ���n����ʾΪָ����ʽ����
  n! = p1^a1*p2^a2*����*pn^an������2��5��ʹn!ĩβ����0�����Ҫ��
  ��������ȥ��ʣ���ÿһ��(pk^ak)�ĸ�λ��һ�������n!�����յĸ�λ����*/
#include <stdio.h>
#include <stdlib.h>
#define NUM 10005
#define LEN 1250
struct Log {
	int base,exp;       //exp = (base^exp)10
};
Log logs[LEN];
int re[NUM], cur, exp2, exp5, base2[4] = {6, 2, 4, 8};
int Compute(int k)
{
	int i, r;
	while(k%10 == 0) { k /= 10; }     //ɾ��10
	while(k%11 == 0) { k /= 11; }     //ɾ��11
	while(k%2 == 0) { k /= 2; exp2++; }     //����2��ָ��
	while(k%5 == 0) { k /= 5; exp5++; }     //����5��ָ��
	if (k == 1) goto comp;
	for(i=0; i<cur; i++) {             //��������������ָ��
		while(k%logs[i].base == 0) {
			k /= logs[i].base;
			logs[i].exp = (logs[i].exp*logs[i].base)%10;
		}
	}
	if (k != 1){
		logs[cur].base = k;
		logs[cur++].exp = k%10;
	}
comp:
	if (exp2 > exp5) {
		exp2 = exp2-exp5;
		exp5 = 0;
	}
	else {
		exp5 = exp5-exp2;
		exp2 = 0;
	}
	if (exp2 == 0) r = 1;
	else r = base2[exp2%4];
	if (exp5 != 0) r =(r*5)%10;
	for(i=0; i<cur; i++)
		r = (r*logs[i].exp)%10;
	return r;
}
int main()
{
	int i;
	re[0] = re[1] = 1;
	cur = exp2 = exp5 = 0;
	for(i=2; i<NUM; i++) re[i] = Compute(i);
	while(scanf("%d", &i)>0) {
		printf("%5d -> %d\n", i, re[i]);
	}
	return 0;
}