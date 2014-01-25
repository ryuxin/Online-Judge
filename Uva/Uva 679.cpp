//入门题。当在某个结点进行选择时，因为每经过一个小球，开关的状态都会改变，所以奇数次通过的小球往左走，偶数
//次经过的小球往右走。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int n,d,k,i,r,leave;
	cin>>n;
	while(n--) {
		cin>>d>>k;
		leave=pow(2.0,d-1);
		r=0;
		for(i=1;i<d;i++) {
			if(k%2==0) {
				r=r+leave/2;
				k=k/2;
			}
			else
				k=(k+1)/2;
			leave=leave/2;
		}
		cout<<(int)pow(2.0,d-1)+r<<endl;
	}
	cin>>n;
	return 0;
}