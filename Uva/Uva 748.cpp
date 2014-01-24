#include "ryx_bignum.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
char data[10],re[200];
BigNum a1,a2;
void sPrint_BigNum(char *o,BigNum *A)
{
	int i;
	if(A->sign==1)
		sprintf(0,"-");
	sprintf(o,"%d\0",A->val[A->length-1]);
	for(i=A->length-2;i>=0;i--)
		sprintf(o+strlen(o),"%04d\0",A->val[i]);
	return ;
}

int main()
{
	int i,exp,l,lr;
	while(scanf("%s",data)>0) {
		scanf("%d",&exp);
		for(i=0;i<6;i++)
			if(data[i]=='.')
				break;
		l=i >5? 5 : i;                           //С�����λ��,����û��С���㣿��
		for(i=i+1;i<7;i++)
			data[i-1]=data[i];
		StingtoBigNum(data,&a1);
		Initial(&a2);
		Unsign_exp(&a1,exp,&a2);
		sPrint_BigNum(re,&a2);
		lr=strlen(re);
		l=(5-l)*exp;                    //С����λ��
		if(l>=lr) {
			int tlr=lr;
			while(re[lr-1]=='0'&&lr>0) {        //ע��ɾ��ĩβ��0����
				lr--;
			}
			if(lr==0)                    //������.0000����
				printf("0");
			else {
				printf(".");
				for(i=0;i<l-tlr;i++)
					printf("0");
				for(i=0;i<lr;i++)
					printf("%c",re[i]);
			}
		}
		else {
			for(i=0;i<lr-l;i++)
				printf("%c",re[i]);
			while(re[lr-1]=='0'&&lr-1>=i) {     
				lr--;
			}
			if(lr>i) {
				printf(".");
				for(;i<lr;i++)
					printf("%c",re[i]);
			}
		}
		printf("\n");
	}
	return 0;
}