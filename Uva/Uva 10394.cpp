/*筛法求素数。若枚举每个数并判断其是否是素数，在题目的数据范围内，明显太慢。应用筛法先求出所有素数，
然后记录所有的孪生素数，这样查询仅需O(1)的时间。
筛法求素数的思路，每找到一个素数，所有其的整数倍都肯定不是素数，直接筛去。实现时，用一个数组标记每个
数是否为素数，然后每次找到第一个未标记的数，这个数一定是素数。
算法证明：将所有数分为三类，素数、合数、未确定。初始时，都为未确定，数组第一个元素为2。则最小的未确定的
数一定是素数。否则，其一定有个比他小的素数因子p，而在之前处理p时，已将其所有整数倍的数都标为合数，与其
是未确定的矛盾*/
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
			sushu[j++]=selectout[i];             //这里找出的孪生素数对可能超过
			if(j>100000)                         //题目的约定，以至于超出数组的范围
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