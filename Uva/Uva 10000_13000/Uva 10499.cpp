/*入门题。用物体的表面积来计算价格。对球的任意一个部分，其两个侧面
  恰好构成一个圆。最后总的利润就是n个圆的面积。特殊情况，n比较大，
  要用long long类型。当n=1时，显然没有利润*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	long long int n;
	while(cin>>n) {
		if (n<=0)
			break;
		if (n == 1) n = 0;
		else		n = n*25;
		cout<<n<<"%"<<endl;
	}
	return 0;
}