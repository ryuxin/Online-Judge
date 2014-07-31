/*基础题。数据结构，树。用左子右兄表示。先建树，然后判断结点之间是否满足约束。
  维护当前结点和空节点，依次读入数据，若是负数，分配新节点，加入父亲的儿子列
  表，将当前结点设为此节点。若是正数，检查是否匹配，将当前结点设为父节点。
  特殊情况，输入不止一个树，如-1 1 -1 1。加一个空的父节点，若当前结点为此节
  点，说明有多个树。
  只输入一个数，如-1。先将一个树的容量赋为负值，得到一个完整的树后，将其改为
  正值。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 100000
#define LEN 25
struct Matri {
	int cap, parent, child, sibling;
};
Matri mas[NUM/10];
int cur_node, cur_num;
char data[NUM];
bool Construct(void)
{
	int c, i, l;
	cur_num = 0;
	sscanf(data, "%d", &c);
	if (c>=0) return false;
	cur_node = cur_num;
	mas[cur_num].cap = c;
	mas[cur_num].child = mas[cur_num].parent = -1;
	cur_num++;
	l = strlen(data);
	for(i=0; i<l; i++) {
		if (data[i] != ' ') continue;
		if (cur_node == -1) return false;
		sscanf(data+i, "%d", &c);
		if (c>=0) {
			if (mas[cur_node].cap != -1*c) 
				return false;
			mas[cur_node].cap = c;
			cur_node = mas[cur_node].parent;
		}
		else {
			mas[cur_num].cap     = c;
			mas[cur_num].parent  = cur_node;
			mas[cur_num].child   = -1;
			mas[cur_num].sibling = mas[cur_node].child;
			mas[cur_node].child  = cur_num;
			cur_node = cur_num;
			cur_num++;
		}
	}
	return true;
}
bool Check(int k)
{
	int c = 0, i;
	if (mas[k].cap <= 0) return false;
	for(i=mas[k].child; i!=-1; i = mas[i].sibling) 
		c += mas[i].cap;
	if (c>=mas[k].cap) return false;
	for(i=mas[k].child; i!=-1; i = mas[i].sibling) 
		if (!Check(i)) return false;
	return true;
}
int main()
{
	while(gets(data)) {
		if(Construct()) {
			if (Check(0)) {
				printf(":-) Matrioshka!\n");
				goto nop;
			}
		}
		printf(":-( Try again.\n"); 
		nop: ;
	}
	return 0;
}
