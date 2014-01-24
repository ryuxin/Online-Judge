/*典型题。详见算法导论Young矩阵*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
const long long int int_max = (1<<31)-1;
int young[32][32][32], x, y, z;
long long int pow_2[3][32];
int re[1505];
int comp(int a, int b)
{
	if(a == b)
		return 0;
	if(a>0 && b>0)
		return a-b;
	return b-a;
}
int Mini_next(int a, int b, int c)
{
	int r, t1, t2, t3;
	t1 = young[a+1][b][c];
	t2 = young[a][b+1][c];
	t3 = young[a][b][c+1];
	x = a;
	y = b;
	z = c;
	if(comp(t1, t2)<0) {
		r = t1;
		x= a+1;
	}
	else {
		r = t2;
		y = b+1;
	}
	if(comp(r, t3)>0) {
		r = t3;
		x = a;
		y = b;
		z = c+1;
	}
	return r;
}
void Initi_pow(int k)
{
	long long int p, temp;
	int i;
	p = k*(k+1)/2+2;
	pow_2[k][0] = 1;
	for(i=1; i<32; i++) {
		temp = p*pow_2[k][i-1];
		if(temp-int_max>=0)
			for(; i<32; i++)
				pow_2[k][i] = -1;
		else
			pow_2[k][i] = temp;
	}
	return ;
}
void Initi_young(int a, int b, int c)
{
	int i, j, k;
	long long int temp;
	temp = pow_2[0][a]*pow_2[1][b]*pow_2[2][c];
	if(pow_2[0][a]<0 || pow_2[1][b]<0 || pow_2[2][c]<0 
	   || a+b+2*c>30 || temp-int_max>=0) {
		for(i=a; i<32; i++)
			for(j=b; j<32; j++)
				for(k=c; k<32; k++)
					young[i][j][k] = -1;
		return ;
	}
	young[a][b][c] = temp;
	return ;
}
void Fixup(int a, int b, int c)
{
	int r, temp;
	r = Mini_next(a, b ,c);
	temp = young[a][b][c];
	if(comp(temp, r)>0) {
		young[a][b][c] = r;
		young[x][y][z] = temp;
		Fixup(x, y, z);
	}
	return ;
}
int pop()
{
	int r;
	r = young[0][0][0];
	young[0][0][0] = -1;
	Fixup(0, 0, 0);
	return r;
}
int main()
{
	int i, j, k, n;
	for(i=0; i<3; i++)
		Initi_pow(i);
	for(i=0; i<32; i++)
		for(j=0; j<32; j++)
			for(k=0; k<31; k++)
				young[i][j][k] = 0;
	for(i=0; i<32; i++)
		for(j=0; j<32; j++)
			for(k=0; k<31; k++)
				if(young[i][j][k] == 0)
					Initi_young(i, j, k);

	for(i=0; i<1500; i++)
		re[i] = pop();
	printf("The 1500'th ugly number is %d.\n", re[1500-1]);
	return 0;
}