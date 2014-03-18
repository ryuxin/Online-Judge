/*入门题。双向循环链表。注意每次删除元素后，要正确更新头尾指针*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define Num_p 22
struct People {
	int id;
	People *next, *prev;
};
People person[Num_p];
People *h, *t;
int first, n, total;
void Remove(People *p)
{
	if (p == h)
		h = p->next;
	if (p == t)
		t = p->prev;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	return ; 
}
int Deque(int k, int m)
{
	int i, ret;
	People *left = t, *right = h;
	k = (k-1)%(n-total);
	m = (m-1)%(n-total);
	for(i=0; i<k; i++)
		right = right->next;
	h = right->next;
	for(i=0; i<m; i++)
		left = left->prev;
	t = left->prev;
	if (first) 	first = 0;
	else 		printf(",");
	if (left == right) {
		ret = 1;
		Remove(left);
		printf("%3d", left->id);
	}
	else {
		ret = 2;
		Remove(left);
		Remove(right);
		printf("%3d%3d",right->id, left->id);
	}
	return ret;
}
int main()
{
	int k, m, i;
	for(i=0; i<Num_p; i++)
		person[i].id = i+1;
	while(scanf("%d%d%d", &n, &k, &m)>0) {
		if (n == 0)
			break;
		for(i=0; i<n; i++) {
			person[i].next = &person[(i+1)%n];
			person[i].prev = &person[(i-1+n)%n];
		}
		h = &person[0];
		t = &person[n-1];
		total = 0;
		first = 1;
		while (total<n) {
			total = total+Deque(k, m);
		}
		printf("\n");
	}
	return 0;
}