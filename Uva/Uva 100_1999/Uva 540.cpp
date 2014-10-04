/*基础题。数据结构。链表。由于需要知道给定的元素属于哪个组，所以用一个数组保存
  每个元素的组号。为了快速找到当前队列中是否有同一个组的元素，再用一个数组保存
  每个组在队列中的最后一个元素的位置。
  插入时，查看当前元素所在的组在队列中是否有元素，有则插在其后面，并更新该组的
  最后一个元素的位置。否则，直接插在队尾。边界情况，当前组的最后一个元素恰好是
  队尾元素，要更新队尾。
  删除时，直接删掉队首的元素，若其是当前组的最后一个元素，更新其组的最后一个
  元素的位置。若其是队尾，更新队尾。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1005
#define LEN 1000005
struct Ele {
	int t_v; // 低21位是value，高10位是team value, team;
	Ele *next;
};
int team[LEN];
Ele *tail, *freelist, *last[NUM];
Ele queue[LEN];
char command[10];
void Enqueue(int a)
{
	int t;
	Ele *old = freelist, *f;
	freelist = freelist->next;
	t = team[a];
	old->t_v  = a;
	old->t_v |= (t<<21);
	f = last[t];
	if (f == &queue[0]) {
		tail->next = old;
		tail = old;
	}
	else {
		old->next = f->next;
		f->next = old;
		if (tail == f) tail = old;
	}
	last[t] = old;
}
int Dequeue(void)
{
	Ele *del = queue[0].next;
	int r = del->t_v&0x1fffff, t = del->t_v>>21;
	if (del == tail) tail = &queue[0];
	if (del == last[t]) last[t] = &queue[0];
	queue[0].next = del->next;
	del->next = freelist;
	freelist = del;
	return r;
}
int main()
{
	int i, j, t, m, a, c = 0, s;
	while(scanf("%d", &t)>0) {
		if (t == 0) break;
		c++;
		s = 0;
		for(i=0; i<t; ++i) {
			scanf("%d", &m);
			s += m;
			last[i] = &queue[0];
			for(j=0; j<m; ++j) {
				scanf("%d", &a);
				team[a] = i;
			}
		}
		tail = &queue[0];
		freelist = &queue[1];
		for(i=1; i<s; ++i) queue[i].next = &queue[i+1];
		printf("Scenario #%d\n", c);
		while(scanf("%s", command)>0) {
			if (command[0] == 'E') {
				scanf("%d", &a);
				Enqueue(a);
			}
			else if (command[0] == 'D') {
				a = Dequeue();
				printf("%d\n", a);
			}
			else {
				printf("\n");
				break;
			}
		}
	}
	return 0;
}