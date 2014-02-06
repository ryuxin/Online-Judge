/*入门题。A和C构成两个栈，其中A以1,2...n的顺序压栈。依次扫描B中的每一个位置，看A和C栈顶的车是否符合要求，
  如果符合，则弹栈，并扫描下一个位置；否则，从A中弹出一个并压入C中，反复进行，直至A为空或找到符合要求的车*/
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
	while(cin>>n) {
		if(n==0)
			break;
		while(cin>>data[0]) {
			if(data[0]==0) {
				cout<<endl;
				break;
			}
			for(i=1;i<n;i++)
				cin>>data[i];
			for(i=0;i<n;i++)
				sa[i]=n-i;
			topa=n-1;
			topc=-1;
			for(i=0;i<n;) {
				if(topa==-1) {
					if(topc==-1||sc[topc]!=data[i]) {
						cout<<"No"<<endl;
						break;
					}
					else {
						topc--;
						i++;
					}
				}
				else {
					if(sa[topa]==data[i]) {
						topa--;
						i++;
					}
					else {
						if(topc>=0&&sc[topc]==data[i]) {
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
