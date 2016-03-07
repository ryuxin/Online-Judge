/*基础题。数学。门的总数是N = ncow+ncar。当打开nshow个门之后，剩余
 *的数目是n = N-nshow-1，要减去首选的第一个。若首选的是cow，则从剩
 *余中选取car的概率是c1 = ncar/n，若首选的car，则从剩余中选取car的
 *概率是c2 = (ncar - 1)/n，所以总概率是ncow/N*c1+ncar/N*c2。
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 302
int main()
{
	double ncow, ncar, nshow, n;
	while (-1 != scanf("%lf%lf%lf", &ncow, &ncar, &nshow)) {
		ncow += ncar;
		n     = ncow-1;
		nshow = n-nshow;
		printf("%.5lf\n", ncar*n/ncow/nshow);
	}
	return 0;
}
