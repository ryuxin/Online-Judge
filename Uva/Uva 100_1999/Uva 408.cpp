/*�����⡣��ѧ�����ۡ��ɲ���ʽs = (s+k)%m��֪������������Ϊ
  s+k, s+2k, s+3k...�����й���ģm����ȫʣ��ϵ�ĳ�Ҫ����Ϊ��
  k��m���ʡ�����շת�����k��m���Լ����*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Gcd(int a, int b)      //a>b
{
	if (b == 0) return a;
	return Gcd(b, a%b);
}
int main()
{
	int k, m, r;
	while(scanf("%d%d", &k, &m)>0) {
		if (k>m) r = Gcd(k, m);
		else r = Gcd(m, k);
		if (r == 1) printf("%10d%10d    Good Choice\n\n", k, m);
		else printf("%10d%10d    Bad Choice\n\n", k, m);
	}
	return 0;
}