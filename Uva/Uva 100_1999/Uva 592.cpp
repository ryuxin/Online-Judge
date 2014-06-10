/*基础题。搜索+模拟。这种题有些繁琐，但是很好基础练习题。
  基本思路，枚举所有人及黑白天的状态，然后在该状态下，是不是
  所有的句子都成立。若没有可行状态，则是impossible，若有多个
  可行状态，则要提取可行状态的公共部分，这个由commit函数完成。
  判断一个句子是否成立时，由说话的人可知该句子的真假，并且从
  该句子所描述的信息，也可推断该句子的真假。这两个若相符，
  则该句子成立。
  commit函数将两个可行状态合并，若前一个状态仍是unknown的，
  则直接将新状态赋给他。
  若前一个状态值和新状态值不一样，说明有多个可行状态，此时
  将状态值设为invalid。
  最终的状态若都是unknown，则是impossible；若都是invalid，
  则是no fact，否则输出对应的状态。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 5
#define LEN 50
enum Role {
	divine  = 0,
	evil    = 1,
	human   = 2,
	unknown = 3,
	invaild = 4
};
struct People {
	int day_or_night;
	Role role[NUM];
};
People state, best;
char data[55][LEN];
int n;
void Outcome(int k)
{
	switch(best.role[k]) {
	case divine:
		printf("%c is divine.\n", k+'A');
		break;
	case evil:
		printf("%c is evil.\n", k+'A');
		break;
	case human:
		printf("%c is human.\n", k+'A');
		break;
	}
	return ;
}
bool Calc_role(int k)
{
	switch(state.role[k]) {
	case divine:
		return true;
	case evil:
		return false;
	case human:
		if (state.day_or_night == 0)
			return true;
		else
			return false;
	}
}
bool Match_y(int i, char c)
{
	switch(c) {
	case 'd':
		return state.role[i] == divine;
	case 'e':
		return state.role[i] == evil;
	case 'h':
		return state.role[i] == human;
	case 'l':
		if (state.role[i] == evil)
			return true;
		if (state.role[i] == human && state.day_or_night == 1)
			return true;
		return false;
	}
}
bool Match_n(int i, char c)
{
	switch(c) {
	case 'd':
		return state.role[i] != divine;
	case 'e':
		return state.role[i] != evil;
	case 'h':
		return state.role[i] != human;
	case 'l':
		if (state.role[i] == divine)
			return true;
		if (state.role[i] == human && state.day_or_night == 0)
			return true;
		return false;
	}
}
bool Calc_sens(int k)
{
	int r, i;
	// day or night
	if (data[k][4] == 't') {
		if (data[k][9] == 'd') r = 0;
		else r = 1;
		return r == state.day_or_night;
	}
	// is it myself
	if (data[k][3] == 'I') i = data[k][0]-'A';
	else i = data[k][3]-'A';
	if (data[k][8] == 'n') return Match_n(i, data[k][12]);
	else return Match_y(i, data[k][8]);
}
bool check()      //检查当前的状态是否可行
{
	int i;
	bool left, right;
	for(i=0; i<n; i++) {
		left  = Calc_role(data[i][0]-'A');
		right = Calc_sens(i);
		if (left != right) return false;
	}
	return true;
}
void commit(void)     //合并两个可行的状态
{
	if (best.day_or_night == unknown)
		best.day_or_night = state.day_or_night;
	else if (best.day_or_night != state.day_or_night)
		best.day_or_night = invaild;
	int i;
	for(i=0; i<NUM; i++) {
		if (best.role[i] == unknown)
			best.role[i] = state.role[i];
		else if (best.role[i] != state.role[i])
			best.role[i] = invaild;
	}
	return ;
}
void DFS(int k)
{
	Role i;
	if (k == NUM) {
		if (check())
			commit();
		return ;
	}
	for(i=divine; i<unknown; i = (Role)(i+1)) {
		state.role[k] = i;
		DFS(k+1);
	}
	return ;
}
int main()
{
	int i, j, c = 0, t;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		c++;
		gets(data[0]);
		for(i=0; i<n; i++) gets(data[i]);
		best.day_or_night = unknown;
		for(i=0; i<NUM; i++) best.role[i] = unknown;
		state.day_or_night = 0;
		DFS(0);
		state.day_or_night = 1;
		DFS(0);
		printf("Conversation #%d\n", c);
		t = j = 0;
		for(i=0; i<NUM; i++) {
			if (best.role[i] < unknown) {
				j = t = 1;
				Outcome(i);
			}
			else if (best.role[i] == invaild) t = 1;
		}
		switch(best.day_or_night) {
		case 0:
			printf("It is day.\n");
			t = j =1;
			break;
		case 1:
			printf("It is night.\n");
			t = j =1;
			break;
		case invaild:
			t = 1;
		}
		if (t == 0) printf("This is impossible.\n");
		else if (j == 0) printf("No facts are deducible.\n");
		printf("\n");
	}
	return 0;
}