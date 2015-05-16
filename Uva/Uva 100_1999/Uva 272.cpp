//入门题。
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
char s[1000];
int main()
{
	int i,l,c=0;
	while(cin.getline(s,1000))
	{
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='"')
			{
				c++;
				if(c%2==1)
					cout<<"``";
				else
					cout<<"''";
			}
			else
				cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
