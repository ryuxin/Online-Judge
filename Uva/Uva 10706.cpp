/*�����⡣����+���ơ���Ŀ���⣺SkΪ123��k������.��Pi=10^i-1.
sk[i]��ʾ��1��Pi���ж���λ.re[i]��ʾ��S1��S(Pi)���ж���λ.
���ڸ����ĳ���n������ȷ���������ĸ�Sk������Sk�е��ĸ����������������Ӧλ�ϵ�����*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define M 6
long long int re[M], sk[M];
char temp[M+2];
int Find(int k, int l)          //������k�У���l������
{
	int i = 0;
	while(k>0) {
		temp[i++] = '0'+k%10;
		k = k/10;
	}
	return temp[i-l]-'0';
}
int Calc(int l)                //�ҵ�������Sk�е��ĸ�����
{
	int i, t, j;
	for(i=0; i<M; i++)
		if(sk[i]>=l)
			break;
	t = l-sk[i-1];
	j = (t+i-1)/i;
	t = t-(j-1)*i;
	return Find(pow(10, i-1)-1+j, t);
}
int Proc(int k)                //ȷ���������ĸ�Sk
{
	int i, s = 0, t, j;
	for(i=0; i<M; i++) 
		if(re[i]>=k)
			break;
	t = k-re[i-1];
	s = 0;
	for(j=1; ; j++) {
		s = s+sk[i-1]+i*j;
		if(s>=t)
			break;
	}
	t = t-(s-sk[i-1]-j*i);
	return Calc(t);
}
int main()
{
	int i, k_10, t;
	sk[0] = 0;
	k_10 = 1;
	for(i=1; i<7;i++) {
		t = 10*k_10-k_10;
		sk[i] = sk[i-1] +i*t;
		k_10 = k_10*10;
	}
	re[0] = 0;
	k_10 = 1;
	for(i=1; i<6;i++) {
		t = 10*k_10-k_10;
		re[i] = t*sk[i-1]+(t+1)*t/2*i;
		k_10 = k_10*10;
	}
	for(i=1; i<6;i++) 
		re[i] = re[i]+re[i-1];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &i);
		i = Proc(i);
		printf("%d\n", i);
	}
	return 0;
}