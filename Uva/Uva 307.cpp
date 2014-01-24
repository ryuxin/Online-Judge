/*经典题。深搜。对木棍长度进行排序，并求出长度总和s。则拼接后的长度l满足s%l=0。依次枚举可能的l。
DFS(n, r)表示在当前的l下， 已经拼接出n－1个，且正在拚的第n个还剩余r的长度。当n>s/l时，说明拼接成功。
否则，依次枚举尚未使用的木棍，若其长度恰好等于r，开始拼接下一个木棍DFS(n+1, l)；若小于r，将
其拼上且继续搜索DFS(n, r－x)；若大于r，则怎样都无法拼接成功.
此题最主要的在于剪枝，否则超时，代码中给出了具体的剪枝策略*/
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
	//剪枝5：最后一个木棍不用去拼接
	if(num == sum/len-1)
		return true;
	temp2 = pre2;
	if(re == len) {
		temp1 = pre1;
		//剪枝7：每个木棍的第一段也按照递减顺序排序
		for(i=pre1+1;i<=n;i++) {
			if(used[i] == false) {
				pre1 = pre2 = i;
				used[i] = true;
				ans = DFS(num+data[i]/re,re-data[i]+(data[i]/re)*len); 
				used[i] = false;
				pre1 = temp1;
				pre2 = temp2;
				//剪枝8：此时尝试的是木棍的第一段，则此次尝试失败就不必再继续尝试其他的。
				//因为若存在解，则此次被尝试的木棍一定会出现，与尝试失败矛盾
				return ans;
			}
		}
	}
	//剪枝2：尝试拼接一个木棍时，按照长度递减的顺序依次尝试
	for(i=pre2+1;i<=n;i++) {
		//剪枝3：如果当前木棍和上一次尝试的木棍等长，则不必尝试该木棍
		if(data[i] == data[old] || data[i]>re || used[i])
			continue;
		//剪枝4：如果剩下未尝试的木棍总和比re还小，则不可能成功，直接返回
		if(sub_sum[i]<re)
			return false;
		pre2 = old = i;
		used[i] = true;
		ans = DFS(num+data[i]/re,re-data[i]+(data[i]/re)*len);
		used[i] =false;
		pre2 = temp2;
		//剪枝9：若此次尝试的木棍恰好等于re，此次失败后不必再尝试后面的木棍。因为若存在解，
		//则必定存在几个木棍的长度之和等于re，把这些木棍和此次尝试的木棍data[i]调换位置后，
		//仍然是一个解，与此次尝试失败矛盾
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
		//剪枝1：拼接后的长度一定大于等于最长的木棍，且必须整除木棍长度总和
		for(len=data[1]; len<=sum; len++)
			if(sum%len == 0 && DFS(0, len))
				break;
		printf("%d\n", len);
	}
	return 0;
}
