/*入门题。分为两个步骤。先将立方体v2旋转，使得其正面颜色和立方体v1一样。再将其绕y轴
  旋转，检验是否旋转成v1*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char current[7], test[7], temp[7], se[9], sub[5];
int num_c[3], num_t[3];
void Rotate(int k)         //将test旋转，使得第k面成为正面，即第2面，将结果存入temp里
{
	strcpy(temp, test);
	switch (k) {
        case 0:
		temp[1] = test[0]; temp[0] = test[4];
		temp[4] = test[5]; temp[5] = test[1];
		break;
        case 2:
		temp[1] = test[2]; temp[3] = test[1];
		temp[4] = test[3]; temp[2] = test[4];
		break;
        case 3:
		temp[1] = test[3]; temp[3] = test[4];
		temp[4] = test[2]; temp[2] = test[1];
		break;
        case 4:
		temp[1] = test[4]; temp[0] = test[5];
		temp[4] = test[1]; temp[5] = test[0];
		break;
        case 5:
		temp[1] = test[5]; temp[0] = test[1];
		temp[4] = test[0]; temp[5] = test[4];
	}
	return ;
}
bool Check(void)        //检验temp构成的立方体，是否可以通过绕y轴旋转得到前一个立方体
{
	sub[0] = temp[2]; sub[1] = temp[0];
	sub[2] = temp[3]; sub[3] = temp[5];
	if(NULL == strstr(se, sub))
		return false;
	return true;
}
int main()
{
	int i;
	current[6] = test[6] = se[8] = sub[5] = '\0';
	while(scanf("%c", &current[0])>0) {
		for(i=0; i<3; i++) {
			num_c[i] = 0;
			num_t[i] = 0;
		}
		for(i=1; i<6; i++)
			scanf("%c", &current[i]);
		for(i=0; i<6; i++)
			scanf("%c", &test[i]);
		scanf("%c", &temp[0]);
		for(i=0; i<6; i++) {
			if(current[i] == 'r')
				num_c[0]++;
			if(current[i] == 'g')
				num_c[1]++;
			if(current[i] == 'b')
				num_c[2]++;
		}
		for(i=0; i<6; i++) {
			if(test[i] == 'r')
				num_t[0]++;
			if(test[i] == 'g')
				num_t[1]++;
			if(test[i] == 'b')
				num_t[2]++;
		}
		//若两个立方体对应颜色数目不一样，一定不可能
		if(num_c[0] != num_t[0] || num_c[1] != num_t[1] || num_c[2] != num_t[2]) {
			printf("FALSE\n");
			continue;
		}
		se[0] = current[2]; se[1] = current[0];
		se[2] = current[3]; se[3] = current[5];
		for(i=4; i<8; i++)
			se[i] = se[i-4];
		for(i=0; i<6; i++) {
			if(test[i] == current[1]) {
				Rotate(i);
				if(Check()) {
					printf("TRUE\n");
					break;
				}
			}
		}
		if(i == 6)
			printf("FALSE\n");
	}
	return 0;
}

