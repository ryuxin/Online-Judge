//模拟。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
#define len 48
#define hashsize 58
char data[len]={'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G',
		'H','J','K','L',';','\'','Z','X','C','V','B','N','M',',','.','/'};
int hashtable[1000]={0};
char s[1000];
int main()
{
	int i,l;
	for(i=1;i<len;i++)
		hashtable[data[i]%hashsize]=i-1;
	while(cin.getline(s,1000))
	{
		l=strlen(s);
		for(i=0;i<l;i++)
			if(s[i]!=' ')
				s[i]=data[hashtable[s[i]%hashsize]];
		cout<<s<<endl;
	}
	return 0;
}
	