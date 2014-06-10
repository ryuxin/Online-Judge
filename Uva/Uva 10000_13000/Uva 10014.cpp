/*基础题。数学。由ai = (ai-1 + ai+1)/2-ci，得ai+1 - ai = ai - ai-1 + 2ci。
  令di = ai - ai-1，则有di+1= di + 2ci，对任意k，解得dk = d1 + 2(c1+c2+……+ck-1),
  又由于an+1 = a0+d1+d2+……+dn+1，因为a0，an+1， c都已知，可求得d1，进而求得a1.
  具体得，an+1 = a0                   --------a0
              + d1                    --------d1
              + d1 + 2 c1             --------d2
			  + d1 + 2(c1+c2)         --------d3
			  .........
			  + d1 + 2(c1+c2+……+cn)   --------dn+1
			  = a0 + (n+1)d1 + 2(nc1 + (n-1)c2 + ……+ cn)*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	int i, t;
	double a0, an, n, r, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf%lf", &n, &a0, &an);
		r = 0;
		for(i=n; i>0; i--) {
			scanf("%lf", &c);
			r += i*c;
		}
		r = (an-a0-2*r)/(n+1)+a0;
		printf("%.2lf\n", r);
		if (t != 0) printf("\n");
	}
	return 0;
}