/*��ѧ�⡣ö��ȫ������.��ԭʼ��������󣬼�¼ÿ��Ԫ�س��ֵĴ�������ɾ���ظ���Ԫ�ء����ᳬʱ��
����n��Ԫ�صĿ��ظ����ϣ��ֱ���r1��t1...rk��tk����r1+r2+��+rk=n���������½��ۣ�
1.�ü��ϵ�����������ΪP=n!/(r1!*r2!*��*rk!);
2.����һ��Ԫ��r��λ��i��j���ֵĴ�����ͬ����˶�������һ�У����ֵ�Ԫ�غͶ�Ӧ�Ĵ���������ͬ�ģ�
����ÿһ������Ԫ��֮��S������ͬ�ġ�S<9*12!������int�ķ�Χ��*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define relen 15
using namespace std; 
int num[15],jiec[13];
char data[relen],nore[15];   //ע�⣬���Ҫ��n��������ӣ�������������10^10��
int main()
{
	int i,j,temp,n;
	char t;
	jiec[1]=1;
	for(i=2;i<13;i++)
		jiec[i]=i*jiec[i-1];
	while(cin>>n) {
		if(n==0)
			break;
		for(i=0;i<n;i++)
			cin>>data[i];
		for(i=1;i<n;i++) {              //��������
			t=data[i];
			for(j=i-1;j>=0;j--) {
				if(data[j]>t)
					data[j+1]=data[j];
				else
					break;
			}
			data[j+1]=t;
		}
		for(i=0;i<15;i++)
			num[i]=0;
		nore[0]=data[0];
		num[0]=1;
		j=1;
		for(i=1;i<n;i++) {
			if(data[i]!=data[i-1])
				nore[j++]=data[i];
			num[j-1]++;
		}
		/*����ÿ��Ԫ����ÿһ�г��ֵĴ���*/
		temp=1;
		for(i=0;i<j;i++)
			temp=temp*jiec[num[i]];
		temp=jiec[n]/temp;
		for(i=0;i<j;i++)
			num[i]=temp*num[i]/n;
		/*ÿһ��Ԫ�ص��ܺ�*/
		temp=0;
		for(i=0;i<j;i++)
			temp=temp+num[i]*(nore[i]-'0');
		j=0;
		for(i=0;i<n;i++) {
			num[i]=temp+j;
			j=num[i]/10;
			num[i]=num[i]%10;
		}
		i=n-1;
		if(j>0)
			cout<<j;
		else {
			for(i=n-1;i>=1;i--)
				if(num[i]!=0)
					break;
		}
		for(;i>=0;i--)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}
