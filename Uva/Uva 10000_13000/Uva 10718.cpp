/*入门题。位运算。从高位向低位逐位考察。若当前位为1，若l和的r当前位相同，则当前为不会对
  结果产生影响，在l或r中随便选取一个补位即可。若不一样，由于r>=l，且从l到r是连续的，则
  r的当前位为1，l是0，且在l和r之间，必然存在01111..的数。当前位补0，l向前推一位，r设为1111。
  若当前位是0，l和r当前位相同时，和上面一样。不同时，当前位补1，r向前推一位，l设为0。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1000 
#define LEN 15
int main()
{
	unsigned int n, l, r, i, re, mask;
	while(scanf("%u %u %u", &n, &l, &r)>0) {
		i = 32;
		re = 0;
		while(i--) {
			mask = 1<<i;
			if ((n&mask) != 0) {
				re |= (l&mask);
				if ((l&mask) == (r&mask)) r &= (~mask);
				else r = mask-1;
				l &= (~mask);
			}
			else {
				re |= (r&mask);
				if ((l&mask) == (r&mask)) l &= (~mask);
				else l = 0;
				r &= (~mask);
			}
		}
		printf("%u\n", re);
	}
	return 0;
}