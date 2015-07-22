/*基础题。字符串处理。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 26
#define LEN 120
int v[NUM], tag[NUM];
char expre[LEN], use[LEN];
int main()
{
	int i, j, l, value;
	while(gets(expre)) {
		for(i=25; i>=0; i--) v[i] = i+1;
		memset(tag, 0, sizeof(tag));
		l = strlen(expre);
		//删除空格
		for(i=0, j=0; i<l; i++) {
			if (expre[i] != ' ')
				use[j++] = expre[i];
		}
		use[j++] = '\0';
		l = strlen(use);
		//处理++和--
		for(i=0; i<l; i++) {
			if (use[i] == '+' || use[i] == '-') {
				if (use[i] == use[i+1]) {
					//出现++或--时，若其后面是字母，就一定和其
					//配对，否则去前面一定是字母，且能配对
					if (use[i+2]>='a' && use[i+2]<='z') {
						if (use[i] == '+') tag[use[i+2]-'a'] = 1;
						else tag[use[i+2]-'a'] = 3;
					} else {
						if (use[i] == '+') tag[use[i-1]-'a'] = 2;
						else tag[use[i-1]-'a'] = 4;
					}
					use[i] = use[i+1] = ' ';
					i += 2;
				}
			}
			else tag[use[i]-'a'] = 5;
		}
		for(i=0; i<NUM; i++) {
			if (tag[i] == 1) v[i]++;
			else if (tag[i] == 3) v[i]--;
		}
		//维护当前值和当前的符号
		value = 0;
		j = 1;
		for(i=0; i<l; i++) {
			switch (use[i]) {
				case ' ': 
					continue;
				case '+': 
					j = 1;
					break;
				case '-': 
					j = -1;
					break;
				default: 
					value += j*v[use[i]-'a'];
			}				
		}
		for(i=0; i<NUM; i++) {
			if (tag[i] == 2) v[i]++;
			else if (tag[i] == 4) v[i]--;
		}
		printf("Expression: %s\n", expre);
		printf("    value = %d\n", value);
		for(i=0; i<NUM; i++) {
			if (tag[i]) printf("    %c = %d\n", 'a'+i, v[i]);
		}
	}
	return 0;
}