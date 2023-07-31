#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=3e5+10;
typedef long long ll;
struct node{
	int id,C;
	friend bool operator < (const node x,const node y){
		return x.C<y.C;
	}
}B[N];
priority_queue<node>A;
int n,k,D[N];
ll ans,sum;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&B[i].C);
		B[i].id=i;
	}
	for(int i=1;i<=n+k;i++){
		if(i<=n){
			A.push(B[i]);
			sum+=B[i].C;
		}
		if(i>k){
			node cur=A.top();
			A.pop();
			D[cur.id]=i;
			sum-=cur.C;
		}
		ans+=sum;
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",D[i]);
	return 0;
}
