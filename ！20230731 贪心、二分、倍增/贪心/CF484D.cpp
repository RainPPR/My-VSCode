#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int n,A[N];
ll dp[N];
//dp(i)表示到了第i个位置时，划分的最大值为多少 
ll myabs(ll x){return x<0?-x:x;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	dp[1]=0;
	dp[2]=myabs(A[2]-A[1]);
	for(int i=3;i<=n;i++)
		if(A[i]>=A[i-1]&&A[i-1]>=A[i-2])
			dp[i]=dp[i-1]+myabs(A[i]-A[i-1]);
		else if(A[i]<=A[i-1]&&A[i-1]<=A[i-2])
			dp[i]=dp[i-1]+myabs(A[i]-A[i-1]);
		else dp[i]=max(dp[i-1],dp[i-2]+myabs(A[i]-A[i-1]));
	printf("%lld\n",dp[n]);
	return 0;
}
