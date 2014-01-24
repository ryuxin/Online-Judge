/*»Î√≈Ã‚°£*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
    int k, n, t, x, y;
    while(1) {
        scanf("%d", &n);
        if(n == 0)
            break;
        t = sqrt((double)n);
        t = t+(1-(t*t)/n);
        x = y = t;
        k = (t-1)*(t-1)+t;
        if(t%2 == 0) {
            if(n<k)
                x = x-(k-n);
            else
                y = y-(n-k);
        }
        else {
            if(n<k)
                y = y-(k-n);
            else
                x = x-(n-k);
        }
        printf("%d %d\n",x, y);
    }
    return 0;
}



