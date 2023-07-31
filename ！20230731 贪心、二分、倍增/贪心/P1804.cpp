#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 6;
int n;
struct line{
	int l,r;
	friend bool operator < (const line a,const line b){
		return a.r < b.r;
	}
}A[N];
//�������һ���ṹ����ض�������� 
//ʹ�� friend bool operator ����Ҫ�ض��������� 
//���ܹ�����ṹ�����ͱ��������� 
//�����������룬��ʱ A[i] < A[j] �ĺ���ʹ��� A[i].r < A[j].r 
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i += 1)
		scanf("%d%d",&A[i].l,&A[i].r);
	sort(A + 1,A + 1 + n);
	int mr = 0,ans = 0;
	//mr ��¼Ŀǰ�����Ҷ˵�ֵΪ���� 
	for(int i = 1;i <= n;i += 1)
		if(A[i].l >= mr){
			mr = A[i].r;
			ans += 1;
		}
	printf("%d\n",ans);
	return 0;
}
