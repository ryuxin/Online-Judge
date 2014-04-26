/*基础题。递推。上面的点依次为T1, ……, Ta, 下面的点为B1, ……, Bb。将所有交点分为两类，与从Ta出发的线
  相交的点，和其余的点。其余的点为P(a-1, b), 与TaB1相交的点为(a-1)(b-1)，与TaB2相交的点为(a-1)(b-2)。
  加总后有P(a, b) = P(a-1, b) + (a-1)(b-1+……+1）;
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define LEN 20005
//long long int P[LEN];
int main()
{
	int i, c = 0;
	long long int a, b;
	//P[0] = P[1] = 0;
	while (cin>>a>>b) {
		if (a == 0 && b == 0) break;
		c++;
		/*for (i=2; i<=a; i++)
			P[i] = P[i-1]+b*(b-1)/2*(i-1);
		cout<<"Case "<<c<<": "<<P[a]<<endl;*/
		a = a*(a-1)/2*b*(b-1)/2;
		cout<<"Case "<<c<<": "<<a<<endl;
	}
	return 0;
}