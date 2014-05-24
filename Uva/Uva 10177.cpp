/*基础题。基础数学。以二维为例，先枚举长度，再枚举宽度。考虑所有的矩形，
  长度可选1,2，……n，共1+2+……+n种选法，同理，宽度仍有这么多方法。总数是
  [n(n+1)/2]^2。
  下面考虑正方形，长度为k时，宽度也只能为k，故方法数是
  1^2+2^2+……+n^2。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 4
int main()
{
	long long int n, n_pow[NUM], t, r;
	long long int t1;
	int i;
	while(cin>>n) {
		n_pow[0] = n*n;
		for(i=1; i<NUM; i++) n_pow[i] = n*n_pow[i-1];
		t1 = n*(n+1)/2;
		t = t1*t1;
		r = t1*(2*n+1)/3;
		cout<<r<<' '<<t-r<<' ';
		r = t;
		t = t*t1;
		cout<<r<<' '<<t-r<<' ';
		t = t*t1;
		r = 6*n_pow[3]+15*n_pow[2]+10*n_pow[1]-n;
		r = r/30;
		cout<<r<<' '<<t-r<<endl;
	}
	return 0;
}