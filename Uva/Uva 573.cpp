/*�����⡣������������ö��η�����⣬�����ھ������⣬̫�����ˣ�������ʵʵ��ģ���ˡ�
���⣬Ҫ������Ŀ����˼���Լ����������
1.ֻ�е��߶��ϸ���ھ��ĸ߶�ʱ������ɹ���ͬ�����½���ĸ߶��ϸ�С��0ʱ������ʧ�ܡ�
2.��ÿ�������ĸ߶ȼ�С��0�Ժ󣬾�һֱ��0.����˵������������һ��������*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    double h, u, d, f, c;
	int t;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f)>0) {
        if(h == 0)
            break;
        f = u*f/100;
		t = 1;
		c = 0;
		while(1) {
			c = c+u;
			if(c>h) {
				printf("success on day %d\n", t);
				break;
			}
			c = c-d;
			if(c<0) {
				printf("failure on day %d\n", t);
				break;
			}
			u = u-f;
			if(u<0)
				u = 0;
			t++;
		}
    }
    return 0;
}

