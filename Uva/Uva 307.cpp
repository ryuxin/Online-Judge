/*�����⡣���ѡ���ľ�����Ƚ������򣬲���������ܺ�s����ƴ�Ӻ�ĳ���l����s%l=0������ö�ٿ��ܵ�l��
DFS(n, r)��ʾ�ڵ�ǰ��l�£� �Ѿ�ƴ�ӳ�n��1�����������յĵ�n����ʣ��r�ĳ��ȡ���n>s/lʱ��˵��ƴ�ӳɹ���
��������ö����δʹ�õ�ľ�������䳤��ǡ�õ���r����ʼƴ����һ��ľ��DFS(n+1, l)����С��r����
��ƴ���Ҽ�������DFS(n, r��x)��������r�����������޷�ƴ�ӳɹ�.
��������Ҫ�����ڼ�֦������ʱ�������и����˾���ļ�֦����*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
int n, data[70], sum, len, pre1, pre2, sub_sum[70];
bool used[70];
bool DFS(int num, int re)
{
	int i,temp1, temp2, t, old=0;
	bool ans;
	//��֦5�����һ��ľ������ȥƴ��
	if(num == sum/len-1)
		return true;
	temp2 = pre2;
	if(re == len) {
		temp1 = pre1;
		//��֦7��ÿ��ľ���ĵ�һ��Ҳ���յݼ�˳������
		for(i=pre1+1;i<=n;i++) {
			if(used[i] == false) {
				pre1 = pre2 = i;
				used[i] = true;
				ans = DFS(num+data[i]/re,re-data[i]+(data[i]/re)*len); 
				used[i] = false;
				pre1 = temp1;
				pre2 = temp2;
				//��֦8����ʱ���Ե���ľ���ĵ�һ�Σ���˴γ���ʧ�ܾͲ����ټ������������ġ�
				//��Ϊ�����ڽ⣬��˴α����Ե�ľ��һ������֣��볢��ʧ��ì��
				return ans;
			}
		}
	}
	//��֦2������ƴ��һ��ľ��ʱ�����ճ��ȵݼ���˳�����γ���
	for(i=pre2+1;i<=n;i++) {
		//��֦3�������ǰľ������һ�γ��Ե�ľ���ȳ����򲻱س��Ը�ľ��
		if(data[i] == data[old] || data[i]>re || used[i])
			continue;
		//��֦4�����ʣ��δ���Ե�ľ���ܺͱ�re��С���򲻿��ܳɹ���ֱ�ӷ���
		if(sub_sum[i]<re)
			return false;
		pre2 = old = i;
		used[i] = true;
		ans = DFS(num+data[i]/re,re-data[i]+(data[i]/re)*len);
		used[i] =false;
		pre2 = temp2;
		//��֦9�����˴γ��Ե�ľ��ǡ�õ���re���˴�ʧ�ܺ󲻱��ٳ��Ժ����ľ������Ϊ�����ڽ⣬
		//��ض����ڼ���ľ���ĳ���֮�͵���re������Щľ���ʹ˴γ��Ե�ľ��data[i]����λ�ú�
		//��Ȼ��һ���⣬��˴γ���ʧ��ì��
		if(ans || data[i] == re)
			return ans;
	}
	return false;
}
int comp(const void *a1, const void*a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p2)-(*p1);
}
int main()
{
	int i;
	data[0] = 1<<29;
	while(1) {
		scanf("%d", &n);
		if(n == 0)
			break;
		for(i=1; i<=n; i++)
			scanf("%d", &data[i]);
		for(i=1; i<=n; i++)
			used[i]= false;
		qsort(data, n+1, sizeof(int), comp);
		pre1 = pre2 = 0;
		sub_sum[n] = data[n];
		for(i=n-1; i>0; i--)
			sub_sum[i] = sub_sum[i+1]+data[i];
		sum = sub_sum[1];
		//��֦1��ƴ�Ӻ�ĳ���һ�����ڵ������ľ�����ұ�������ľ�������ܺ�
		for(len=data[1]; len<=sum; len++)
			if(sum%len == 0 && DFS(0, len))
				break;
		printf("%d\n", len);
	}
	return 0;
}
