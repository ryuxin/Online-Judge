/*入门题。数学，中位数。设每个人的钱数为Ai，均分后为a，第i个人
 *送给第i+1个人（按顺时针方向）的钱数为ai（若ai<0，表示从第i+1
 *个人那里收到钱），对第i个人有Ai+a(i-1)-ai = a，解上述方程，可
 *得ai = a1+Sum(Ak-a)(1<k<=i) = a1+ci，则最终转移的总数是
 *S = |a1|+|a2|+...+|an| = |a1|+|a2+c2|+...+|a1+cn|。至此，将本
 *题转换为求数轴上一点，使得其到所有点{cn}的距离之和最小。而这个
 *点就是点集{cn}的中位数。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1000001
#define LEN 5
long long gold[NUM];
int Findbyrank(int s, int e, int rank)
{
	int i, j;
	long long temp;
again:
	i = s;
	j = e;
	temp = gold[s];
	while(i<j) {
		while(i<j && gold[j]>=temp) {
			j--;
		}
		if (i<j) gold[i++] = gold[j];
		while(i<j && gold[i]<=temp) {
			i++;
		}
		if (i<j) gold[j--] = gold[i];
	}
	gold[i] = temp;
	if(i-s+1 == rank) return i;
	else {
		if(i-s+1 > rank) e = i-1;
		else {
			rank -= (i-s+1);
			s = i+1;
		}
		goto again;
	}
}
int main()
{
	long long int sum, avg;
	int i, n, r;
	while(EOF != scanf("%d", &n)) {
		sum = 0;
		for(i=0; i<n-n%2; i+=2) {
			scanf("%lld%lld", &gold[i], &gold[i+1]);
			sum += (gold[i]+gold[i+1]);
		}
		if(n%2) {
			scanf("%lld", &gold[n-1]);
			sum += gold[n-1];
		}
		avg = sum/n;
		sum = gold[0] = 0;
		for(i=1; i<n; i++) {
			gold[i] = gold[i-1]+gold[i]-avg;
		}
		r   = Findbyrank(0, n-1, n/2);
		avg = gold[r];
		for(i=0; i<r; i++)   sum += (avg-gold[i]);
		for(i=r+1; i<n; i++) sum += (gold[i]-avg);
		printf("%lld\n", sum);
	}
	return 0;
}