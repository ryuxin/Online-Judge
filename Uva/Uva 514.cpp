//�����⡣A��C��������ջ������A��1,2...n��˳��ѹջ������ɨ��B�е�ÿһ��λ�ã���A��Cջ���ĳ��Ƿ����Ҫ��
//������ϣ���ջ����ɨ����һ��λ�ã����򣬴�A�е���һ����ѹ��C�У��������У�ֱ��AΪ�ջ��ҵ�����Ҫ��ĳ�
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int sa[2000],sc[2000],topa,topc,data[2000];
int main()
{
	int n,i;	
	while(cin>>n)
	{
		if(n==0)
			break;
		while(cin>>data[0])
		{
			if(data[0]==0)
			{
				cout<<endl;
				break;
			}
			for(i=1;i<n;i++)
				cin>>data[i];
			for(i=0;i<n;i++)
				sa[i]=n-i;
			topa=n-1;
			topc=-1;
			for(i=0;i<n;)
			{
				if(topa==-1)
				{
					if(topc==-1||sc[topc]!=data[i])
					{
						cout<<"No"<<endl;
						break;
					}
					else
					{
						topc--;
						i++;
					}
				}
				else
				{
					if(sa[topa]==data[i])
					{
						topa--;
						i++;
					}
					else
					{
						if(topc>=0&&sc[topc]==data[i])
						{
							topc--;
							i++;
						}
						else
							sc[++topc]=sa[topa--];
					}
				}
			}
			if(i==n)
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}