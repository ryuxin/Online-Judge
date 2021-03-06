/*基础题。数学。欧拉公式。在多边形中，顶点数V，边数E，把
 *平面分成的区域数为F，则有如下关系 V+F-E = 2。两点要注意
 *1、不能有交叉的边，如果有交叉，则交点算作一个顶点，因此
 *一个圆环有一个顶点，一个边。
 *2、多边形外部的无限区域也算作一个区域。但本题中显然不包
 *括次区域，所以要在最后结果中减去一个区域。
 *简单证明：对任意一个多边形，每次收缩一个边。若这条边的
 *两个端点不同，则将这两个端点合并成一个顶点，并删去这条边，
 *收缩后顶点数减少一，边数减少一，区域数不变。若这条边的两个
 *端点相同，则只删去这条边，这样顶点数不变，边数减少一，区域
 *数减少一。但不论哪种收缩后，V+F-E的值保持不变。直到收缩完
 *所有边，只剩下一个顶点，此时有V+F-E = 2。
 *在本题中，圆内的n条线段两两相交时，区域最多。且圆上有2n个
 *边，每个线段都被分成n段，边数E = 2n+n^2。同理，圆上有2n个
 *顶点，每个线段上n-1个顶点，但每个线段上的顶点被通过它的两条
 *线段重复计算过，所有最后顶点数V = 2n+n(n-1)/2，带入欧拉公式，
 *最终区域数为1+n(n+1)/2
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 16
#define LEN 47000

int main()
{
	long long int n;
	while (scanf("%lld", &n)) {
		if (n < 0) break;
		printf("%lld\n", 1+n*(n+1)/2);
	}
	return 0;
}