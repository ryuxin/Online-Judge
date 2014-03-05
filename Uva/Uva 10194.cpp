/*入门题。注意最后的字符串排序是不区分大小写的，最好全部转为小写。最后一行
不能有空行*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Team {
	char name[33];
	char sort_name[33];
	int points;
	int wins, ties, loss;
	int goals, lostg;
};
Team teams[32];
char torrent[105], temp[100];
int n, t, g;
int comp1(const void *a1, const void *a2)
{
	Team *p1, *p2;
	p1 = (Team *)a1;
	p2 = (Team *)a2;
	return strcmp(p1->name, p2->name);
}
int comp2(const void *a1, const void *a2)
{
	Team *p1, *p2;
	int d1, d2, g1, g2;
	p1 = (Team *)a2;
	p2 = (Team *)a1;
	if (p1->points != p2->points)
		return p1->points-p2->points;
	if (p1->wins != p2->wins)
		return p1->wins-p2->wins;
	d1 = p1->goals-p1->lostg;
	d2 = p2->goals-p2->lostg;
	if (d1 != d2)
		return d1-d2;
	if (p1->goals != p2->goals)
		return p1->goals-p2->goals;
	g1 = p1->wins+p1->loss+p1->ties;
	g2 = p2->wins+p2->loss+p2->ties;
	if (g1 != g2)
		return g2-g1;
	return strcmp(p2->sort_name, p1->sort_name);
}
int Index(char *s)
{
	int l = 0, r = t, m, i;
	while(l<=r) {
		m = (l+r)/2;
		i = strcmp(teams[m].name, s);
		if (i == 0)
			return m;
		if (i>0)
			r = m-1;
		else
			l = m+1;
	}
	return -1;
}
int Atoi(char *s, int l, int r)
{
	int sum = 0, i;
	for(i=l; i<=r; i++) 
		sum = s[i]-'0'+10*sum;
	return sum;
}
int main()
{
	int i, j, ss, sm, se, l;
	int t1, g1, t2, g2;
	int first = 1;
	scanf("%d", &n);
	gets(temp);
	while(n--) {
		gets(torrent);
		scanf("%d", &t);
		gets(temp);
		memset(teams, 0, t*sizeof(struct Team));
		for(i=0; i<t; i++) {
			gets(teams[i].name);
			l = strlen(teams[i].name);
			for (j=0; j<=l; j++) 
				teams[i].sort_name[j] = tolower(teams[i].name[j]);
		}
		scanf("%d", &g);
		gets(temp);
		qsort(teams, t, sizeof(struct Team), comp1);
		for(i=0; i<g; i++) {
			gets(temp);
			l = strlen(temp);
			for(j=0; j<l; j++) {
				if (temp[j] == '#') {
					ss = j;
					temp[j] = '\0';
				}
				if (temp[j] == '@') {
					sm = j;
					break;
				}
			}
			for(; j<l; j++) {
				if (temp[j] == '#') {
					se = j;
					break;
				}
			}
			t1 = Index(temp);
			g1 = Atoi(temp, ss+1, sm-1);
			t2 = Index(temp+se+1);
			g2 = Atoi(temp, sm+1, se-1);
			teams[t1].goals += g1;
			teams[t2].goals += g2;
			teams[t1].lostg += g2;
			teams[t2].lostg += g1;
			if (g1>g2) {
				teams[t1].points += 3;
				teams[t1].wins   += 1;
				teams[t2].loss   += 1;
			}
			else if (g1 == g2) {
				teams[t1].points += 1;
				teams[t2].points += 1;
				teams[t1].ties   += 1;
				teams[t2].ties   += 1;
			}
			else {
				teams[t2].points += 3;
				teams[t2].wins   += 1;
				teams[t1].loss   += 1;
			}
		}
		qsort(teams, t, sizeof(struct Team), comp2);
		if (first)
			first = 0;
		else
			printf("\n");
		printf("%s\n", torrent);
		for(i=0; i<t; i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
				i+1, teams[i].name, teams[i].points, 
				teams[i].wins+teams[i].ties+teams[i].loss, 
				teams[i].wins, teams[i].ties, teams[i].loss, 
				teams[i].goals-teams[i].lostg, teams[i].goals, 
				teams[i].lostg);
		}
	}
		return 0;
}