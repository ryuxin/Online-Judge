/*ɸ������������ö��ÿ�������ж����Ƿ�������������Ŀ�����ݷ�Χ�ڣ�����̫����Ӧ��ɸ�����������������
Ȼ���¼���е�����������������ѯ����O(1)��ʱ�䡣
ɸ����������˼·��ÿ�ҵ�һ������������������������϶�����������ֱ��ɸȥ��ʵ��ʱ����һ��������ÿ��
���Ƿ�Ϊ������Ȼ��ÿ���ҵ���һ��δ��ǵ����������һ����������
�㷨֤��������������Ϊ���࣬������������δȷ������ʼʱ����Ϊδȷ���������һ��Ԫ��Ϊ2������С��δȷ����
��һ����������������һ���и�����С����������p������֮ǰ����pʱ���ѽ���������������������Ϊ����������
��δȷ����ì��*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define Max_int 20000000
int sushu[100000+10];
bool num[Max_int+1]={0};
int selectout[1300000],len;
void Shaifa(void)
{
	int i=2,j;
	len=0;
	while(i<=Max_int)
	{
		if(num[i]==false)
		{
			selectout[len++]=i;
			for(j=i;j<=Max_int;j=j+i)
				num[j]=true;
		}
		i++;
	}
	return ;
}
void Process(void)
{
	int i,j=0;
	for(i=0;i<len-1;i++)
	{
		if(selectout[i]==selectout[i+1]-2)
		{
			sushu[j++]=selectout[i];             //�����ҳ������������Կ��ܳ���
			if(j>100000)                         //��Ŀ��Լ���������ڳ�������ķ�Χ
				break;
		}
	}
	return ;
}
int main()
{
	int s;
	Shaifa();
	Process();
	while(cin>>s)
	{
		printf("(%d, %d)\n",sushu[s-1],sushu[s-1]+2);
	}
	return 0;
}