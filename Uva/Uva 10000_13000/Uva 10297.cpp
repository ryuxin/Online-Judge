/*入门题。基础数学题。运用相似性得出*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
int main()
{
	double d,v,r,p;
	p=3.1415926536;
	while(1)
	{
		cin>>d>>v;
		if(d==0)
			break;
		r=pow((pow(d,3.0)-6.0*v/p),1.0/3.0);
		printf("%.3f\n",r);
	}
	return 0;
}