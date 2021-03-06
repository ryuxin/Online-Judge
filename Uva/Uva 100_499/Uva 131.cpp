/*
  基础题。枚举。题目大意：手里有5张牌，桌面上有5张牌。选手决定
  一次性丢弃手里的某些牌，换取桌面上对应数目的牌。最后比较替换
  后的手里5张牌的大小。
  首先枚举丢弃的牌的数量，此时，桌面上被替换的牌就已固定，再枚
  举丢弃哪些牌，最后找出手里牌的最大值。牌面大小详见
  http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=3238&messageid=1&deep=0
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int poker[4][13]; //C-0, D-1, H-2, S-3
char hand[35];
int same_nme[13]; //每个数字出现的次数
int same_face[4]; //每个花色出现的次数 
int best, same[5];  //对，三条等的次数
struct Poker
{
	int x, y;
};
Poker tile[10], result[5];
void init()
{
	int i;
	for(i=0; i<13; i++)
		poker[0][i] = poker[1][i] = poker[2][i] = poker[3][i] = 0;
}
void Convert(int k)
{
	int a, b;
	switch (hand[k]) {
		case 'A':
			a = 0;
			break;
		case 'T':
			a = 9;
			break;
		case 'J':
			a = 10;
			break;
		case 'Q':
			a = 11;
			break;
		case 'K':
			a = 12;
			break;
		default:
			a = hand[k]-'0'-1;
	}
	switch (hand[k+1]) {
		case 'C':
			b = 0;
			break;
		case 'D':
			b = 1;
			break;
		case 'H':
			b = 2;
			break;
		case 'S':
			b = 3;
	}
	tile[k/3].x = b;
	tile[k/3].y = a;
}
void Calc_num(void)
{
	int i, j;
	for(i=0; i<13; i++)
		same_nme[i] = poker[0][i]+poker[1][i]
					+ poker[2][i]+poker[3][i];
	for(i=0; i<4; i++) {
		same_face[i] = 0;
		for(j=0; j<13; j++)
			same_face[i] += poker[i][j];
	}
	for(i=0; i<5; i++)
		same[i] = 0;
	for(i=0; i<13; i++)
		same[same_nme[i]]++;
}
bool Shunzi(int *k)
{
	int i, j;
	for(i=0; i<10; i++) {
		for(j=0; j<5; j++)
			if (k[(i+j)%13] == 0)
				break;
		if (j == 5) return true;
	}
	return false;
}
int Process(void)
{
	int i;
	bool r;
	for(i=0; i<4; i++) {
		if (same_face[i]>=5) {
			r = Shunzi(poker[i]);
			if (r) return 9;
		}
	}
	if (same[4] > 0) return 8;
	if (same[2]>0 && same[3]>0) return 7;
	for(i=0; i<4; i++) {
		if (same_face[i]>4) 
			return 6;
	}
	if (Shunzi(same_nme)) return 5;
	if (same[3]>0) return 4;
	if (same[2]>1) return 3;
	if (same[2]>0) return 2;
	return 1;
}
void DFS(int start, int pos)
{
	int i, r;
	if (pos == 5) {
		init();
		for(i=0; i<5; i++)
			poker[result[i].x][result[i].y] = 1;
		Calc_num();
		r = Process();
		if (r>best) best = r;
		return ;
	}
	for (i=start; i<=pos; i++) {
		result[pos] = tile[i];
		DFS(i+1, pos+1);
		if (best == 9) return ;
	}
}
int main()
{
	int i, j, l;
	while (gets(hand) != NULL) {
		l = strlen(hand);
		for(i=0; i<l; i = i+3)
			Convert(i);
		printf("Hand: ");
		for(i=0; i<15; i++)
			printf("%c", hand[i]);
		printf("Deck: ");
		for(i=15; i<29; i++)
			printf("%c", hand[i]);
		printf(" Best hand: ");
		best = -1;
		for (i=0; i<=5; i++) {
			for(j=0; j<i; j++) 
				result[j] = tile[5+j];
			DFS(0, i);
			if (best == 9) break;
		}
		if (best == 9)      printf("straight-flush\n");
		else if (best == 8) printf("four-of-a-kind\n");
		else if (best == 7) printf("full-house\n");
		else if (best == 6) printf("flush\n");
		else if (best == 5) printf("straight\n");
		else if (best == 4) printf("three-of-a-kind\n");
		else if (best == 3) printf("two-pairs\n");
		else if (best == 2) printf("one-pair\n");
		else if (best == 1) printf("highest-card\n");
	}
	return 0;
}