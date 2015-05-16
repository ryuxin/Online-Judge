/*有符号大整数运算。采用压位存储，即10000进制数存储。0-正数，1-负数*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define Max_len 1000            //最大长度
#define Jinzhi 10000            //进制
struct BigNum
{
	int val[Max_len];           //数据
	int sign,length;            //符号，位数
};
void Initial(BigNum *A);                              //初始化
void Unsign_puls(BigNum *A,BigNum *B,BigNum *C);      //无符号加法，C=A+B
void Unsign_sub(BigNum *A,BigNum *B,BigNum *C);       //无符号减法，C=A-B(A>B)
void Unsign_mul(BigNum *A,BigNum *B,BigNum *C);       //无符号乘法，C=A*B
void Unsign_div(BigNum *A,BigNum *B,BigNum *C);       //无符号除法，C=A/8
int Unsign_comp(BigNum *A,BigNum *B);                 //无符号比较，1--A>B
void Sign_plus(BigNum *A,BigNum *B,BigNum *C);        //有符号加法，C=A+B
void Sign_sub(BigNum *A,BigNum *B,BigNum *C);         //有符号减法，C=A-B
void Sign_mul(BigNum *A,BigNum *B,BigNum *C);         //有符号乘法，C=A*B
void Sign_div(BigNum *A,BigNum *B,BigNum *C);         //有符号除法，C=A/8
int Sign_comp(BigNum *A,BigNum *B);                   //有符号比较，1--A>B
void Initial(BigNum *A)
{
	int i;
	for(i=0;i<Max_len;i++)
		A->val[i]=0;
	A->sign=0;
	A->length=0;
	return ;
}
void Unsign_puls(BigNum *A,BigNum *B,BigNum *C)
{
	int i,j=0;
	for(i=0;i<Max_len;i++)
	{
		j=A->val[i]+B->val[i]+j/Jinzhi;
		C->val[i]=j%Jinzhi;
	}
	for(i=Max_len-1;i>=0;i--)
		if(C->val[i]!=0)
			break;
	C->length=i+1;
	return ;
}
/*void Sign_plus(BigNum *A,BigNum *B,BigNum *C)
{
	if(A->sign==B->sign)
	{
		C->sign=A->sign;
		Unsign_puls(A,B,C);
	}
	else if(A->sign==0)
	{
		if(Unsign_comp(A,B)>0)
		{
			C->sign=0;
			Unsign_sub(A,B,C);
		}
		else
		{
			C->sign=1;
			Unsign_sub(B,A,C);
		}
	}
	else
	{
		if(Unsign_comp(A,B)>0)
		{
			C->sign=1;
			Unsign_sub(A,B,C);
		}
		else
		{
			C->sign=0;
			Unsign_sub(B,A,C);
		}
	}
	return ;
}*/
BigNum A1,A2;
char s[105];
void StingtoBigNum(char *p,BigNum *A)
{
	Initial(A);
	int i,l,j=1,k=0;
	l=strlen(p);
	for(i=l-1;i>=0;i--)
	{
		A->val[k]=A->val[k]+(p[i]-'0')*j;
		k=k+j*10/Jinzhi;
		j=(j*10)%(Jinzhi-1);
	}
	if(A->val[k]!=0||k==0)
		A->length=k+1;
	else
		A->length=k;
	return ;
}
int main()
{
	int i;
	StingtoBigNum("0",&A2);
	while(cin>>s)
	{
		if(strcmp("0",s)==0)
			break;
		StingtoBigNum(s,&A1);
		Unsign_puls(&A1,&A2,&A2);
	}
	printf("%d",A2.val[A2.length-1]);
	for(i=A2.length-2;i>=0;i--)
		printf("%04d",A2.val[i]);
	cout<<endl;
	return 0;
}