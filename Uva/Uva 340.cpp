/*贪心。题目大意：给出一组明文s和密文g，（i，j）形成一个匹配，若si=gj，当i=j时，称该匹配为一个强匹配。
  当两个匹配没有公共部分，即i1！=i2且j1！=j2时，称这两个匹配为独立的。让求出一个匹配的集合，其中的匹配是
  两两独立的，且该集合包含的匹配数目和强匹配数目同时达到最大值。题目的关键在于理解为什么这样的集合存在，
  即为什么这两个值可以同时达到最大。设独立匹配的最大值是mt，强匹配的最大值是ms。下面证明，存在这样一个独
  立匹配构成的集合，其匹配的数目为ms，且包含mt个强匹配。
  证明：1、独立匹配至少有0个，且最多有n个，所以独立匹配的最大值mt存在且可达。同理，强匹配最大值也可达。
  2、设强匹配共有ms个，依次为s1，s2...对任意一个含有mt的独立匹配的集合，若其包含所有ms个强匹配，则命题得证。
  否则，设其不包含强匹配（i，i），则该集合一定包含形如（x，i）或（i，x）的匹配，否则可以将匹配（i，i）加入
  到该集合中，与该集合具有最大独立匹配矛盾。且每种形式最多只包含一个，否则与匹配的独立性矛盾。若只包含一种
  类型，则可将其中的x改为i，此时的集合仍满足独立性且独立匹配的数目不变；若同时包含两种类型，（i，x）和（y，i）
  ，则si=gx=sy=gi，可将两个匹配交换为（i，i）和（x，y），仍保持独立性和最大独立匹配数目，如上，就将不包含在
  原集合的强匹配加入到该集合中。依次类推，最终可以将全部的强匹配加入到最大独立匹配的集合中。##
  明白上述的证明过程后，不难得出一个贪心算法。首先找到所有的强匹配，对于剩下的位置，在g中顺序搜索，找到的第
  一个匹配一定在最终的集合里，理由同上*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define Len 1005
int m[Len],g[Len];
bool mfin[Len],gfin[Len];
int main()
{
	int rt,rs,i,j,n,c=0;
	while(cin>>n) {
		if(n==0)
			break;
		c++;
		for(i=0;i<n;i++)
			cin>>m[i];
		cout<<"Game "<<c<<":"<<endl;
		while(1) {
			rs=rt=0;
			for(i=0;i<n;i++)
				cin>>g[i];
			for(i=0;i<n;i++)
				mfin[i]=gfin[i]=false;
			if(g[0]==0)
				break;
			for(i=0;i<n;i++)                //找出所强匹配
			{
				if(m[i]==g[i])
				{
					rs++;
					mfin[i]=gfin[i]=true;
				}
			}
			for(i=0;i<n;i++)
				if(mfin[i]==false)
					for(j=0;j<n;j++)
						if(gfin[j]==false&&g[j]==m[i]) {
							rt++;
							gfin[j]=mfin[i]=true;
							break;
						}
			cout<<"    ("<<rs<<","<<rt<<")"<<endl;
		}
	}
	return 0;
}
