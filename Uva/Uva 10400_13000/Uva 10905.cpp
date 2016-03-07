/*典型题。排序。由于最后组合出来的数字长度一定，所以最后数字的大小
  等同于其字符串的大小。对于字符串a，b，两个连接后得到两个新的字符
  串ab和ba，定义a>=b, 当且仅当ab>=ba(这里为字符串比较操作)。下面证
  明该关系满足传递性，即a>=b且b>=c, 则有a>=c.
  证明：设其长度分别为la, lb, lc。ab可以表示为数字
  ，将其带人已知的不等式，得
  a*10^lb+b>=b*10^la+a => a(10^lb-1)>=b(10^la-1)
  b*10^lc+c>=c*10^lb+b => b(10^lc-1)>=c(10^lb-1)
  上面两式相乘，化简得
  a(10^lc-1)>=c(10^la-1) => a*10^lc+c>=c*10^la+a，
  即ac>=ca, 得a>=c。
  对于n个数的一个排列，A=a1a2……an，其是最大的数的充要条件是，
  a1>=a2>=……>=an。必要性可由传递性直接得出，因为对任意i都有ai>=ai+1。
  充分性。设最大数B是另一种排列，类似冒泡排序，找到a1的位置，让其依次
  和前面的数交换，由于a1大于所有数，所以每次交换都不会使结果变小，最
  后完成所有交换后得到A>=B，因为B是最大的，所以A=B，也是最大的*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define LEN 100
char data[55][LEN], mid1[2*LEN], mid2[2*LEN];
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	strcpy(mid1, p1);
	strcat(mid1, p2);
	strcpy(mid2, p2);
	strcat(mid2, p1);
	return strcmp(mid2, mid1);
}
int main()
{
	int i, n;
	while(cin>>n) {
		if (n == 0) break;
		for (i=0; i<n; i++) 
			cin>>data[i];
		qsort(data, n, sizeof(data[0]), comp);
		for(i=0; i<n; i++)
			cout<<data[i];
		cout<<endl;
	}
	return 0;
}