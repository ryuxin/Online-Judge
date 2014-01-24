/*ÈëÃÅÌâ*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char data[200];
int Check(int l, int r)
{
    if(l>r)
        return 0;
    if(l == r) {
        if(data[l] == '1' || data[l] == '4')
            return 1;
    }
    if(l+1 == r) {
        if(data[l] == '7' && data[r] == '8')
            return 1;
    }
    if(data[r-1] == '3' && data[r] == '5') {
        if(Check(l, r-2))
            return 1;
    }
    if(data[l] == '9' && data[r] == '4') {
        if(Check(l+1, r-1))
            return 1;
    }
    if(data[l] == '1' && data[l+1] == '9' && data[l+2] == '0') {
        if(Check(l+3, r))
            return 1;
    }
    return 0;
}
int main()
{
    int n, re, l;
	scanf("%d", &n);
    while(n--) {
        scanf("%s", data);
        re = 0;
        l = strlen(data);
        if(l<3) {
            re = 1;
            printf("+\n");
        }
        if(!re && data[l-2] == '3' && data[l-1] == '5') {
            re = Check(0, l-3);
            if(re)   printf("-\n");
        }
        if(!re && data[0] == '9' && data[l-1] == '4') {
            re = Check(1, l-2);
            if(re)  printf("*\n");
        }
        //if(!re && data[0] == '1' && data[1] == '9' && data[2] == '0')
        if(!re)    printf("?\n");
    }
    return 0;
}
