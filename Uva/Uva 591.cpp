/*�����⡣��ѧ�⡣�������ĸ߶ȣ���ǰ��Щ�ȴ˸߶ȸߵ�ש��һ��Ҫ���ߣ����������Сֵ*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int data[55];
int main()
{
    int n, i, s, r, rs, t=0;
    while(scanf("%d", &n)>0) {
        t++;
        if(n == 0)
            break;
        s = r = 0;
        for(i=0; i<n; i++) {
            scanf("%d", &data[i]);
            s = s+data[i];
        }
        rs = s/n;
        for(i=0; i<n; i++)
            if(data[i]>rs)
                r = r+data[i]-rs;
        printf("Set #%d\n", t);
        printf("The minimum number of moves is %d.\n\n", r);
    }
    return 0;
}
