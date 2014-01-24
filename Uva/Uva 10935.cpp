//入门题。当n=1时，没有扔掉的卡片，所以输出的第一行中没有数字，但注意，同时最后也不应该有空格
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int queue[55],head,tail,c;
void Inniafia(void)
{
	c=0;
	head=0;
	tail=0;
	return ;
}
void enqueue(int i)
{
	queue[tail]=i;
	tail=(tail+1)%55;
	c++;
	return ;
}
int dequeue()
{
	int t;
	t=queue[head];
	head=(head+1)%55;
	c--;
	return t;
}
int main()
{
	int n,i;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		Inniafia();
		for(i=1;i<=n;i++)
			enqueue(i);
		cout<<"Discarded cards:";
		while(c!=1)
		{
			cout<<' '<<dequeue();
			if(c!=1)
				cout<<",";
			enqueue(dequeue());
		}
		cout<<endl;
		cout<<"Remaining card: "<<dequeue()<<endl;
	}
	return 0;
}