//�����⡣����ĳ��������ѡ��ʱ����Ϊÿ����һ��С�򣬿��ص�״̬����ı䣬����������ͨ����С�������ߣ�ż��
//�ξ�����С�������ߡ�
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int n,d,k,i,r,leave;
	cin>>n;
	while(n--) {
		cin>>d>>k;
		leave=pow(2.0,d-1);
		r=0;
		for(i=1;i<d;i++) {
			if(k%2==0) {
				r=r+leave/2;
				k=k/2;
			}
			else
				k=(k+1)/2;
			leave=leave/2;
		}
		cout<<(int)pow(2.0,d-1)+r<<endl;
	}
	cin>>n;
	return 0;
}