/*入门题. look and say 序列的长度是指数增长的，所以不能保存一个序列的所有元素。题目中之要求前1000位，所以每次只保存决定下一个序列前1000位的元素就好 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char s[10005],t1[10],t2[10005];
int main()
{      
     int a,b,c,i,r,l;
     while(cin>>a>>b>>c)
     {
	  if(a==0&&b==0&&c==0)
	       break;
	  sprintf(s,"%d\0",a);
	  while(--b)
	  {
	       l=strlen(s);
	       r=1;
	       t2[0]='\0';
	       for(i=1;i<=l;i++)
	       {
		    if(s[i]==s[i-1])
		    r++;
		    else
		    {
			 sprintf(t1,"%d%c\0",r,s[i-1]);
			 strcat(t2,t1);
			 if(i>1000)
			   break;
			 r=1;
		    }
	       }
	       strcpy(s,t2);
	  }
	  cout<<s[c-1]<<endl;
     }
     return 0;
}


