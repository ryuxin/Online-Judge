/*
  搜索，深搜回溯。记录当前已发现的最少步数best，只有已执行的步数小于bes时，才扩展当前节点。另外，设当前
  栈中有s个元素，则至少还要s-1步才可能获得输出，所以当前节点至少需要cur+s-1步，当此>=best时，也无需扩展
  当前节点。另外，回溯前后要及时保存和回复状态！！
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std; 
#define ADD 0
#define DIV 1
#define DUP 2
#define MUL 3
#define SUB 4
int exe_stack[10][14], stack_top, data_in[12], data_out[12];
int ins[11], best_ins[11], best_step, n;
char opera[5][6]={"ADD","DIV","DUP","MUL","SUB"};
bool Check_finish(void);        //判断当前是否已得到所有输出
bool Check_val(int a);          //判断指令a是否适合所有程序
void Exe_ins(int a);            //对所有程序执行指令a
bool Check_finish(void)
{
	int i;
	if(stack_top==2) {
		for(i=0;i<n;i++)
			if(exe_stack[i][1]!=data_out[i])
				return false;
		return true;
	}
	return false;
}
bool Check_val(int a)
{
	int i,t;
	if(a!=DUP) {
		if(stack_top<3)
			return false;
		for(i=0;i<n;i++)
			if(a==DIV && exe_stack[i][stack_top-1]==0)
				return false;
		switch (a) {
		case ADD:
			for(i=0;i<n;i++) { 
				t=exe_stack[i][stack_top-1]+exe_stack[i][stack_top-2];
				if(t>30000||t<-30000)
					return false;
			}
			break;
		case SUB:
			for(i=0;i<n;i++) { 
				t=exe_stack[i][stack_top-2]-exe_stack[i][stack_top-1];
				if(t>30000||t<-30000)
					return false;
			}
			break;
		case MUL:
			for(i=0;i<n;i++) { 
				t=exe_stack[i][stack_top-1]*exe_stack[i][stack_top-2];
				if(t>30000||t<-30000)
					return false;
			}
			break;
		case DIV:
			for(i=0;i<n;i++) { 
				t=exe_stack[i][stack_top-2]/exe_stack[i][stack_top-1];
				if(t>30000||t<-30000)
					return false;
			}
		}
	}
	return true;
}
void Exe_ins(int a)
{
	int i,t;
	switch (a) {
	case ADD:
		for(i=0;i<n;i++) { 
			t=exe_stack[i][stack_top-1] + exe_stack[i][stack_top-2];
			exe_stack[i][stack_top-2]=t;
		}
		stack_top--;
		break;
	case SUB:
		for(i=0;i<n;i++) { 
			t=exe_stack[i][stack_top-2] - exe_stack[i][stack_top-1];
			exe_stack[i][stack_top-2]=t;
		}
		stack_top--;
		break;
	case MUL:
		for(i=0;i<n;i++) { 
			t=exe_stack[i][stack_top-1] * exe_stack[i][stack_top-2];
			exe_stack[i][stack_top-2]=t;
		}
		stack_top--;
		break;
	case DIV:
		for(i=0;i<n;i++) { 
			t=exe_stack[i][stack_top-2] / exe_stack[i][stack_top-1];
			exe_stack[i][stack_top-2]=t;
		}
		stack_top--;
		break;
	case DUP:
		for(i=0;i<n;i++) 
			exe_stack[i][stack_top]=exe_stack[i][stack_top-1];
		stack_top++;
	}
	return ;
}
void Backtrace(int cur)
{
	int i,j, k,ts,t1[10], t2[10];
	if(cur+1<best_step && cur+stack_top-2<best_step) {
		if(cur==0) {
			if(Check_finish()==true) {
				best_step=0;
				return ;
			}
			Exe_ins(DUP);
			ins[cur]=DUP;
			Backtrace(cur+1);
		}
		else {
			ts=stack_top;
			for(k=0;k<n;k++) {
				t1[k]=exe_stack[k][stack_top-1];
				t2[k]=exe_stack[k][stack_top-2];
			}
			for(i=0;i<5;i++) {
				if(Check_val(i)==true) {
					ins[cur]=i;
					Exe_ins(i);
					if(Check_finish()==true) {
						best_step=cur+1;
						for(j=0;j<=cur;j++)
							best_ins[j]=ins[j];
						Backtrace(cur+1);
						stack_top=ts;
						for(k=0;k<n;k++) {
							exe_stack[k][stack_top-1]=t1[k];
							exe_stack[k][stack_top-2]=t2[k];
						}
						break;
					}
					Backtrace(cur+1);
					stack_top=ts;
					for(k=0;k<n;k++) {
						exe_stack[k][stack_top-1]=t1[k];
						exe_stack[k][stack_top-2]=t2[k];
					}
				}
			}
		}
	}
	return ;
}
int main()
{
	int i,c=0;
	while(scanf("%d",&n)>0) {
		if(n==0)
			break;
		c++;
		printf("Program %d\n",c);
		for(i=0;i<n;i++)
			scanf("%d", &data_in[i]);
		for(i=0;i<n;i++)
			scanf("%d", &data_out[i]);
		stack_top=2;
		for(i=0;i<n;i++)
			exe_stack[i][1]=data_in[i];
		best_step=11;
		Backtrace(0);
		switch (best_step) {
		case 0:
			printf("Empty sequence\n\n");
			break;
		case 11:
			printf("Impossible\n\n");
			break;
		default :
			for(i=0;i<best_step-1;i++)
				printf("%s ", opera[best_ins[i]]);
			printf("%s\n\n", opera[best_ins[i]]);
		}
	}
	return 0;
}



