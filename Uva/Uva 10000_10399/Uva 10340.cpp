/*入门题。扫描字符串t，查看是否包含s中的所有字符*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char s[100005], t[100005];
int main()
{
    int i, j, l1, l2;
    while(scanf("%s %s",s,t)>0) {
        l1 = strlen(s);
        l2 = strlen(t);
        j  = 0;
        for(i=0; i<l2; i++) {
            if(t[i] == s[j]) {
                j++;
                if(j == l1)
                    break;
            }
        }
        if(j== l1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}