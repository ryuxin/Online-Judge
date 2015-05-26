/*入门题*/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
char data[50];
int p2[33];
int main()
{
     int l,i,r;
     p2[1]=1;
     for(i=2;i<32;i++)
	  p2[i]=2*p2[i-1]+1;
     while(1) {
	  scanf("%s",data);
	  if(strcmp(data,"0")==0)
	       break;
	  l=strlen(data);
	  r=0;
	  for(i=0;i<l;i++) 
	       r=r+(data[l-1-i]-'0')*p2[i+1];
	  printf("%d\n",r);
     }
     return 0;
}