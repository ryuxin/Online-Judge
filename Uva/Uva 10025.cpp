/*数学题。同poj 2844. 注意输入是0的情况*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int t, n, r, temp, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &r);
        if(r>0)
            temp = r;
        else
            temp = -1*r;
        n = (-1+sqrt(1.0+8.0*temp))/2;
		if(n*(n+1)/2<temp || n<1)
			n++;
		j = n*(n+1)/2;
        while(1) {
            if((j-temp)%2 == 0)
                break;
            n++;
			j = j+n;
        }
		if(t != 0)
	        printf("%d\n\n", n);
		else
			printf("%d\n", n);
    }
    return 0;
}

