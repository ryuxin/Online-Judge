/*入门题。枚举，回溯搜索。尝试所有可能的牌，检查加入该牌后，是否能胡。检查
 *函数详见函数注释。枚举前要预处理，排除不可能胡的情况（详见注释）。搜索
 *时，因为加入的牌只会影响它这门花色，所以不必重复计算其他花色的状态。对于
 *每一门花色，要维护的状态包括：是否可以三三组合；是否有一对，其余可以三三
 *组合；是否可以加入其他的牌。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 5
#define LEN 9
#define TBW 3
#define ZFB 7
struct Majiang {
	int tbw[TBW][LEN+3];
	int zfb[ZFB];
	int state[TBW+ZFB][4];  //0-加牌，1-有一对，2-全为三个, 4-只能加牌
	int only;
};
Majiang tiles;
char zfb_name[ZFB][7] = {"DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI"};
char input[7], re[13][7];
int best;
static inline void add_tile(void)
{
	int r = input[0]-'0'-1;
	if (r>=0 && r<9) {
		switch(input[1]) {
		case 'T':
			tiles.tbw[0][r]++;
			break;
		case 'S':
			tiles.tbw[1][r]++;
			break;
		case 'W':
			tiles.tbw[2][r]++;
			break;
		default:
			return;
		}
		return ;
	}
	switch(input[0]) {
	case 'D':
		tiles.zfb[0]++;
		break;
	case 'N':
		tiles.zfb[1]++;
		break;
	case 'X':
		tiles.zfb[2]++;
		break;
	case 'B':
		if (input[1] == 'E') tiles.zfb[3]++;
		else tiles.zfb[6]++;
		break;
	case 'Z':
		tiles.zfb[4]++;
		break;
	case 'F':
		tiles.zfb[5]++;
		break;
	default:
		return ;
	}
}
static bool Check_hu(void)
{
	int i, j;
	/*存在一门有一对，其余牌都可以三三组合时，就胡了*/
	for(i=0; i<TBW+ZFB; i++) {
		if (!tiles.state[i][1]) continue;
		for(j=0; j<TBW+ZFB; j++) {
			if (!(j == i || tiles.state[j][2])) break;
		}
		if (j == TBW+ZFB) return true;
	}
	return false;
}
//DFS判断是否可以三三组合，或者一对+三三组合
static bool Check_three(int *tbw, int k)
{
	int i;
	bool r=false;
	for(i=k; i<LEN; i++) if (tbw[i]) break;
	if(i == LEN) return true;
	if (tbw[i]>=3) {
		tbw[i] -= 3;
		r = Check_three(tbw, k);
		tbw[i] += 3;
	}
	if (!r && tbw[i+1] && tbw[i+2]) {
		tbw[i]--;
		tbw[i+1]--;
		tbw[i+2]--;
		r = Check_three(tbw, k);
		tbw[i]++;
		tbw[i+1]++;
		tbw[i+2]++;
	}
	return r;
}
static bool Check_two(int *tbw)
{
	int i;
	bool r;
	for(i=0; i<LEN; i++) {
		if(tbw[i]>=2) {
			tbw[i] -= 2;
			r = Check_three(tbw, 0);
			tbw[i] += 2;
			if (r) return true;
		}
	}
	return false;
}
/*单牌是指只出现一次，并不与其他相连的牌。有单牌时，这门花色
 *只能加牌。这门花色没有牌，则不能加牌。其他情况都可以加牌。*/
static inline void Pre_tbw(int i)
{
	int t, j;
	t = 0;
	for(j=0; j<LEN; j++) t += tiles.tbw[i][j];
	if (!t) tiles.state[i][2] = 1;
	else {
		tiles.state[i][0] = 1;
		if (Check_two(tiles.tbw[i])) tiles.state[i][1] = 1;
		if (Check_three(tiles.tbw[i], 0)) tiles.state[i][2] = 1;
	}
}
static inline bool Pre_zfb(int i)
{
	switch(tiles.zfb[i]) {
		case 2:
			tiles.state[TBW+i][1] = 1;
		case 1:
			tiles.state[TBW+i][0] = 1;
			break;
		case 0:
		case 3:
			tiles.state[TBW+i][2] = 1;
			break;
		default:
			return false;
	}
	return true;
}
//中发白等若一样的牌出现4次，一定不能胡。超过两门花色只能加牌，也不能胡。
static inline bool Preprocess(void)
{
	int i, r = 0;
	for(i=0; i<TBW; i++) Pre_tbw(i);
	for(i=0; i<ZFB; i++) if (!Pre_zfb(i)) return false;
	for(i=0; i<TBW+ZFB; i++) tiles.state[i][3] = !(tiles.state[i][1]|tiles.state[i][2]);
	for(i=0; i<TBW+ZFB; i++) r += tiles.state[i][3];
	if (r>1) return false;
	tiles.only = r;
	return true;
}
static inline void Try_tbw(int k)
{
	int i, old[4];
	char name[3] = {'T', 'S', 'W'};
	if (!tiles.state[k][0]) return;
	memcpy(old, tiles.state[k], sizeof(old));
	for(i=0; i<LEN; i++) {
		if (tiles.tbw[k][i] == 4) continue;
		memset(tiles.state[k], 0, sizeof(old));
		tiles.tbw[k][i]++;
		Pre_tbw(k);
		if (Check_hu()) {
			re[best][0] = '0'+1+i;
			re[best][1] = name[k];
			re[best][2] = '\0';
			best++;
		}
		tiles.tbw[k][i]--;
	}
	memcpy(tiles.state[k], old, sizeof(old));
}
static inline void Try_zfb(int k)
{
	int i, old[4];
	if (!tiles.state[TBW+k][0]) return;
	memcpy(old, tiles.state[TBW+k], sizeof(old));
	memset(tiles.state[TBW+k], 0, sizeof(old));
	tiles.zfb[k]++;
	Pre_zfb(k);
	if (Check_hu()) {
		strcpy(re[best], zfb_name[k]);
		best++;
	}
	tiles.zfb[k]--;
	memcpy(tiles.state[TBW+k], old, sizeof(old));
}
static void Process(void)
{
	int i, j;
	//只考虑可以加牌的花色，其他花色的状态无需重复计算
	if (tiles.only) {
		for(i=0; i<TBW+ZFB; i++) if(tiles.state[i][3]) break;
		if (i<TBW) Try_tbw(i);
		else Try_zfb(i-TBW);
	} else {
		for(i=0; i<TBW; i++) Try_tbw(i);
		for(i=0; i<ZFB; i++) Try_zfb(i);
	}
}
int main()
{
	int i, c = 0;
	bool r;
	while(1) {
		c++;
		memset(&tiles, 0, sizeof(Majiang));
		scanf("%s", input);
		if (input[0] == '0') break;
		else add_tile();
		for(i=1; i<13; i++) {
			scanf("%s", input);
			add_tile();
		}
		r = Preprocess();
		if (r) {
			best = 0;
			Process();
		}
		if (!r || !best) printf("Case %d: Not ready\n", c);
		else {
			printf("Case %d:", c);
			for(i=0; i<best; i++) printf(" %s", re[i]);
			printf("\n");
		}
	}
	return 0;
}