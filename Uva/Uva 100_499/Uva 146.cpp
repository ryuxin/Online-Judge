//递归，原始串的下一个串要么首字符和原来相同，要么比原来大一。
//若和原来相同，则递归求解后面的子串；否则，求以下一个字符开头的最小串
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <algorithm>
using namespace std;
int le[26];
char *s,ts[53];
bool sig;
int l;
void DP(int n)
{
	if(n>l)
	{
		ts[n-1]='\0';
		return ;
	}
	int i,j,k;
	le[s[n-1]-'a']--;
	ts[n-1]=s[n-1];
	DP(n+1);
	if(sig)
		return ;
	le[s[n-1]-'a']++;
	for(i=s[n-1]-'a'+1;i<26;i++)
	{
		if(le[i]>0)
		{
			ts[n-1]='a'+i;
			le[i]--;
			break;
		}
	}
	if(i<26)
	{
		k=n;
		for(i=0;i<26;i++)
			if(le[i]>0)
				for(j=0;j<le[i];j++)
					ts[k++]='a'+i;
		sig=true;
	}
	return ;
}
int main()
{
	int i;
	s=new char[53];
	while(cin>>s)
	{
		if(s[0]=='#')
			break;
		sig=false;
		for(i=0;i<26;i++)
			le[i]=0;
		l=strlen(s);
		for(i=0;i<l;i++)
			le[s[i]-'a']++;
		DP(1);
		if(sig==false)
			cout<<"No Successor"<<endl;
		else
			cout<<ts<<endl;
	}
	return 0;
}