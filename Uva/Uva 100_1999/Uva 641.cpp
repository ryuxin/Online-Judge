/*入门题。若要满足题目中解的唯一性，则函数f(i)=ki%n应是双射。即对i！=j，有f（i）！=f（j）应满足（k，n）=1。
证明：若不是则有n|k*(i－j）,但（k，n）=1。只能n|（i－j）。与i－j<n矛盾*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char data[350];
int cip[350],plain[350],l,k;
void c2n(void)
{
     int i;
     for(i=0;i<l;i++) {
	  switch (data[i]) {
	  case '_':
	       cip[i]=0;
	       break;
	  case '.':
	       cip[i]=27;
	       break;
	  default :
	       cip[i]=data[i]-'a'+1;
	  }
     }
     return ;
}
void n2n(void)
{
     int i;
     for(i=0;i<l;i++)
	  plain[(k*i)%l]=(cip[i]+i)%28;
     return ;
}
void n2c(void)
{
     int i;
     for(i=0;i<l;i++) {
	  switch (plain[i]) {
	  case 0:
		   printf("_");
	       break;
	  case 27:
	       printf(".");
	       break;
	  default :
		   printf("%c",plain[i]+'a'-1);
	  }
     }
     return ;
}
int main()
{     
     while(1)
     {
	  cin>>k;
	  if(k==0)
	       break;
	  cin>>data;
	  l=strlen(data);
	  c2n();
	  n2n();
	  n2c();
	  printf("\n");
     }
     return 0;
}