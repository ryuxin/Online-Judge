/*模拟。模拟链表。把每堆木块看成一个双链表。再模拟每个指令的操作过程*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct BLOCK {
    int p, n;
};
struct BLOCK blocks[27];
char data1[7], data2[7];
int a1, a2;
void Put_back(int a)    //将a以及其以上的木块放回原位
{	
	int n;
	while (1) {
		n = blocks[a].n;
		blocks[a].p = blocks[a].n = a;
		if (n == a)
			break;
		else
			a = n;
	}
    return ;
}
void M_onto(int a, int b)
{
    int p;
	if (blocks[a].n != a)
	    Put_back(blocks[a].n);
	if (blocks[b].n != b)
	    Put_back(blocks[b].n);
    p = blocks[a].p;
	blocks[p].n = p;
    blocks[b].n = a;
    blocks[a].p = b;
	blocks[a].n = a;
    return ;
}
void M_over(int a, int b)
{
    int p;
    while(b != blocks[b].n) {
        b = blocks[b].n;
    }
	if (blocks[a].n != a)
	    Put_back(blocks[a].n);
    p = blocks[a].p;
	blocks[p].n = p;
    blocks[b].n = a;
    blocks[a].p = b;
	blocks[a].n = a;
    return ;
}
void P_onto(int a, int b)
{
    int p;
	if (blocks[b].n != b)
	    Put_back(blocks[b].n);
    p = blocks[a].p;
    if(p != a)
        blocks[p].n = p;
    blocks[b].n = a;
    blocks[a].p = b;
    return ;
}
void P_over(int a, int b)
{
    int p;
    while(b != blocks[b].n) {
        b = blocks[b].n;
    }
    p = blocks[a].p;
    if(p != a)
        blocks[p].n = p;
    blocks[b].n = a;
    blocks[a].p = b;
    return ;
}
bool check(int a, int b)       //判断输入数据是否有效
{
	int na, nb;
 	if (a == b)
		return false;
	na = a;
	while (blocks[na].n != na) {
		na = blocks[na].n;
	}
	nb = b;
	while (blocks[nb].n != nb) {
		nb = blocks[nb].n;
	}
	if (na == nb)
		return false;
	return true;
}
int main()
{
    int i, t, n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        blocks[i].p = blocks[i].n = i;
    while(cin>>data1) {
        if(data1[0] == 'q')
            break;
		cin>>a1>>data2>>a2;
		if (check(a1, a2) == false)
			continue;
		if (data1[0] == 'm') {
			if (data2[1] == 'n') 
				M_onto(a1, a2);
			else
				M_over(a1, a2);
		}
		else {
			if (data2[1] == 'n')
				P_onto(a1, a2);
			else
				P_over(a1, a2);
		}
    }
    for(i=0; i<n; i++) {
		printf("%d:", i);
        if(blocks[i].p == i) {
            t = i;
            while(1) {
                printf(" %d", t);
                if(blocks[t].n != t)
                    t = blocks[t].n;
                else
                    break;
            }
        }
        printf("\n");
    }
	return 0;
}
  