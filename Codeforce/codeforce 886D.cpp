/*基础题。字符串。最重要的条件是：如果一个串是最频繁子串，则其所有子串也是
 *最频繁子串。由此，可推出
 *1.一个串不能包含重复字符
 *2.若两个串相交，其相交部分，要么就是某个串自身，
 *要么就是一个的后缀，且是另一个的前缀
 *3.两个串至多有一个相交的子串
 *若不满足上述条件，则答案是NO；否则就可以构造出最终答案。
 *构造时，可将字符出现的顺序表示为一个图，即若“ab”出现，则记为从a到b的一
 *条边。当上述条件都满足时，表示的图即为一些不相交的链，沿着链即可构造结果
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;
#define NUM 100005
#define LEN 26
#define CHAE2NUM(c) ((c) - 'a')
bool vis[LEN];
int pre[LEN], nxt[LEN];
string ret="";
static inline bool
chk_dup(string &s)
{
	int b = 0, i, t;
	for(i=0; i<s.size()-1; i++) {
		if (pre[CHAE2NUM(s[i+1])] == -1) pre[CHAE2NUM(s[i+1])] = CHAE2NUM(s[i]);
		else if (pre[CHAE2NUM(s[i+1])] != CHAE2NUM(s[i])) return false;
		if (nxt[CHAE2NUM(s[i])] == -1) nxt[CHAE2NUM(s[i])] = CHAE2NUM(s[i+1]);
		else if (nxt[CHAE2NUM(s[i])] != CHAE2NUM(s[i+1])) return false;
		t = 1 << (s[i] - 'a');
		if (t&b) return false;
		b |= t;
		vis[CHAE2NUM(s[i])] = true;
	}
	if ((1 << CHAE2NUM(s[i])) & b) return false;
	vis[CHAE2NUM(s[i])] = true;
	return true;
}
static inline bool
proc(void)
{
	int i, n;
	char c;
	string str;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>str;
		if (!chk_dup(str)) return false;
	}
	for(i=0; i<LEN; i++) {
		if (!vis[i] || pre[i] != -1) continue;
		for (n=i; n != -1; n = nxt[n]) {
			ret += 'a'+n;
			vis[n] = false;
		}
	}
	for(i=0; i<LEN; i++) if (vis[i]) return false;
	return true;
}
int main()
{
	memset(pre, -1, sizeof(pre));
	memset(nxt, -1, sizeof(nxt));
	memset(vis, 0, sizeof(vis));
	if (!proc()) cout<<"NO"<<endl;
	else cout<<ret<<endl;
	return 0;
}
