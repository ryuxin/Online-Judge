/*�����⡣���kС������Ҫʹ��ÿ����ľ���֮����С��ֻ��ѡȡ��Щ����м�λ�ã����������е���λ����*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int data[502], n;
int Parition(int l, int r)
{
    int t, i, j;
    t = data[r];
    i = l;
    j = r;
    while(i<j) {
        while(i<j && data[i]<=t) {
            i++;
        }
        if(i<j) {
            data[j] = data[i];
            j--;
        }
        while(i<j && data[j]>=t) {
            j--;
        }
        if(i<j) {
            data[i] = data[j];
            i++;
        }
    }
    data[j] = t;
    return j;
}
int Select(int l, int r, int k)      //��l��r�������ڣ��ҵ���kС����
{
    int p;
    p = Parition(l, r);
    if(p == l+k-1)
        return p;
    else if(p>l+k-1)
        return Select(l, p-1, k);
    return Select(p+1, r, k-p+l-1);
}
int main()
{
    int i, t, m, s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &data[i]);
        m = Select(0, n-1, (n+1)/2);
		s = 0;
		for(i=0; i<n; i++) {
			if(data[i]-data[m]<0)
				s = s+data[m]-data[i];
			else
				s = s+data[i]-data[m];
		}
        printf("%d\n", s);
    }
    return 0;
}
