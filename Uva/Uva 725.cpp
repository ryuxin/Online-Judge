/*ö�٣����ö���������У��ᳬʱ��ֻ��ö�ٷ��ӡ������ӿ�������n���ҷ��ӷ�ĸ����һ��ȫ����ʱ,
�������⡣���û�ж���Ŀ���*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
bool used[10];
bool Check(int a,int b)
{
	int i;
	for(i=0;i<10;i++)
		used[i]=false;
	while(a>0)
	{
		if(used[a%10]==true)
			return false;               //���ظ�
		used[a%10]=true;
		a=a/10;
	}
	while(b>0)
	{
		if(used[b%10]==true)
			return false;
		used[b%10]=true;
		b=b/10;
	}
	for(i=1;i<10;i++)
		if(used[i]==false)
			return false;               //����©
	return true;
}
int main()
{
	int i,n;
	bool re,first=true;
	while(cin>>n)
	{
		if(n==0)
			break;
		if(first==true)
			first=false;
		else
			cout<<endl;
		re=false;
		for(i=10234;i<=98765;i++)
		{
			if(i%n==0)
			{
				if(Check(i,i/n))
				{
					printf("%d / %05d = %d\n",i,i/n,n);
					re=true;
				}
			}
		}
		if(re==false)
			cout<<"There are no solutions for "<<n<<'.'<<endl;;
	}
	return 0;
}