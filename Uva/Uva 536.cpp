//入门题.递归。根据前序遍历的根节点，在中序遍历中确定其位置，并以此划分出左右子树。在根据两子树的长度，
//在前序遍历划分出两个子树，然后递归处理每一个子树
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
	if(len==0)                                //空树，直接返回 
		return ;
	if(len==1)                                //只有一个节点，直接输出
		cout<<pre[sp];
	else {
		for(i=si;i<si+len;i++)                //寻找根节点，划分两个子树
			if(in[i]==pre[sp])
				break;            
		Recover(sp+1,si,i-si);                //处理左子树
		Recover(sp+i-si+1,i+1,len-1-i+si);    //处理右子树
		cout<<pre[sp];                        //处理根节点
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