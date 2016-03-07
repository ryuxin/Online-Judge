#include "ryx_bignum.h"
/*数学题，基础几何。设有n个顶点时，土地总数为S(n)。我们考察从S(n)到S(n+1)土地增加的个数。
  设原有顶点依次为P0,P1…Pn-1，新加的顶点为Pn。此时增加的土地分为三部分：
  1、多边形与外部椭圆围成的部分，即线段P0Pn、PnPn-1分别与椭圆围成的部分，此处增加的数目为1；
  2、三角形P0PnPn-1是新增加的，且被Pn与其它顶点的连线所分割，此处增加的数目为n-1；
  3、Pn与其它顶点的连线和原来对角线相交所产生的新部分。具体的讲，线段PnPk将原多边形分为两个部分，
  左边共有k个顶点P0…Pk-1，右边共有n-1-k个顶点Pk+1…Pn-1，所以PnPk最多与k(n-1-k)条对角线相交，即
  由于PnPk所产生的新部分有Tk=k(n-1-k)个，此处总共增加的数目为T0+…+Tn-1；
  综上可得S(n+1)-Sn=1+n-1+T0+…+Tn-1，S1=1，S2=2，S3=4……
  1+2^2+……+n^2=n(n+1)(2n+1)/6
  1+2^3+……+n^3=(n(n+1)/2)^2
  T0+…+Tn-1=(n-2)(n-1)n/6
  Sn=S1+(n^4-6n^3+23n^2-18n)/24
*/
/*优化。如果直接按上面给出的公式进行大整数运算会超时，因为会进行6次乘除，4次加减.
  因式分解后：Sn=(n^2-n)(n^2-n-4n+18)/24+1
  这时需要3次乘除，4次加减，但仍然超时。注意n<2^32,所以n^2在long long范围内，可先用整数运算计算出两个乘数，
  再进行大整数运算。这时需要1次乘法，1次除法，1次加法。进一步，对24进行因数分解，可将除法也用整数运算完成。
  最终需要2次乘法和1次加法*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
BigNum n1,n2,n3;
int main()
{
	long long int s,r,r1,r2;
	scanf("%lld",&s);
	while(s--) {
		scanf("%lld",&r);
		r1=(r*r-r)/2;
		r2=(r*r-5*r+18)/2;
		if(r2%6==0) {
			r2=r2/6;
		}
		else if(r2%3==0) {
			r2=r2/3;
			r1=r1/2;
		}
		else if(r2%2==0) {
			r2=r2/2;
			r1=r1/3;
		}
		else 
			r1=r1/6;
		LinttoBigNum(r1,&n1);
		LinttoBigNum(r2,&n2);
		Initial(&n3);
		Unsign_mul(&n1,&n2,&n3);
		LinttoBigNum(1,&n2);
		Unsign_plus(&n3,&n2,&n2);
		Print_BigNum(&n2);
		printf("\n");
	}
	return 0;
}
