//�����⡣�ַ�������,����������������˼·�ǣ�������Ľڵ���н�������ȡ���ڵ�ֵ�������е�·����
//Ȼ�����·�������ڵ���������Ӷ�������������������ͬʱ�����Ƿ����ظ��ڵ㡣�������Ƿ���һ������
//���������ǣ�����������
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
char node[300];
int v[300],leftnode[300],rightnode[300],queue[150];
int value,start,end,root,freelist,head,tail;
bool correct;
void Initial(void);              //�Զ��������г�ʼ��
void Passer(char *);             //��������Ľڵ�
bool Constrct(void);             //���ݽ�����Ľ����������������ͬʱ�����Ƿ����ظ��Ľڵ�
bool Check(void);                //����������Ƿ���һ����������
void Output(bool);               //���п��ѣ����������
void Initial(void)
{
	int i;
	for(i=0;i<300;i++) {
		v[i]=-1;
		leftnode[i]=-1;
		rightnode[i]=-1;
	}
	value=-1;
	start=-1;
	end=-1;
	freelist=1;
	root=0;
	correct=true;
	return ;
}
void Passer(char *s)
{
	int i,l,j=1,re=0;
	l=strlen(s);
	for(i=0;i<l;i++)
		if(s[i]==',')
			break;
	start=i+1;
	end=l-2;
	i--;
	while(i>0) {
		re=re+j*(s[i]-'0');
		i--;
		j=j*10;
	}
	value=re;
	return ;
}
bool Constrct(void)
{
	int current=root,i;
	for(i=start;i<=end;i++) {
		if(node[i]=='L') {
			if(leftnode[current]==-1) {
				leftnode[current]=freelist;
				freelist++;
			}
			current=leftnode[current];
		}
		if(node[i]=='R') {
			if(rightnode[current]==-1) {
				rightnode[current]=freelist;
				freelist++;
			}
			current=rightnode[current];
		}
	}
	if(v[current]==-1) {
		v[current]=value;
		return true;
	}
	else
		return false;
}
bool Check(void)
{
	int i;
	for(i=0;i<freelist;i++)
		if(v[i]==-1)
			return false;
	return true;
}
void Output(bool c)
{
	int t,first=0;
	if(c==false) {
		cout<<"not complete"<<endl;
		return ;
	}
	head=0;
	tail=1;
	queue[head]=root;
	while(head!=tail) {
		t=queue[head];
		head=(head+1)%150;
		if(leftnode[t]!=-1) {
			queue[tail]=leftnode[t];
			tail=(tail+1)%150;
		}
		if(rightnode[t]!=-1) {
			queue[tail]=rightnode[t];
			tail=(tail+1)%150;
		}
		if(first==0) {
			cout<<v[t];
			first++;
		}
		else
			cout<<' '<<v[t];
	}
	cout<<endl;
	return ;
}
int main()
{
	Initial();
	while(cin>>node) {
		if(strcmp(node,"()")==0) {
			if(correct==true)
				correct=Check();
			Output(correct);
			Initial();
			continue;
		}
		if(correct==true) {
			Passer(node);
			correct=Constrct();
		}
		else
			continue;
	}
	return 0;
}