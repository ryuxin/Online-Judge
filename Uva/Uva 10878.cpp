//�����⡣��|����'.'���޶���������֮�⻹�а�λ����ʾһ����λ�Ķ���������������Ϊ�ַ���ascii ��,
//' '����0��'o'����1
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char data[20];
int main()
{
	int i,r,j;
	gets(data);
	while(1)
	{
		gets(data);
		if(strcmp(data,"___________")==0)
			break;
		r=0;
		j=1;
		for(i=9;i>6;i--)
		{
			if(data[i]=='o')
				r=r+j;
			j=j*2;
		}
		for(i=5;i>0;i--)
		{
			if(data[i]=='o')
				r=r+j;
			j=j*2;
		}
		cout<<(char)r;
	}
	return 0;
}
