//������.�ݹ顣����ǰ������ĸ��ڵ㣬�����������ȷ����λ�ã����Դ˻��ֳ������������ڸ����������ĳ��ȣ�
//��ǰ��������ֳ�����������Ȼ��ݹ鴦��ÿһ������
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char pre[30],in[30];
void Recover(int sp,int si,int len)
{
	int i,l;
	if(len==0)                                //������ֱ�ӷ��� 
		return ;
	if(len==1)                                //ֻ��һ���ڵ㣬ֱ�����
		cout<<pre[sp];
	else {
		for(i=si;i<si+len;i++)                //Ѱ�Ҹ��ڵ㣬������������
			if(in[i]==pre[sp])
				break;            
		Recover(sp+1,si,i-si);                //����������
		Recover(sp+i-si+1,i+1,len-1-i+si);    //����������
		cout<<pre[sp];                        //������ڵ�
	}
	return ;
}
int main()
{
	int l;
	while(cin>>pre>>in) {
		l=strlen(pre);
		Recover(0,0,l);
		cout<<endl;
	}
	return 0;
}