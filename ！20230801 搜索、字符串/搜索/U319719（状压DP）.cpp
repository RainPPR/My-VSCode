#include<iostream>
#include<cstdio>
using namespace std;
const int N=1<<20;
int dp[21][N],bar[21],n,m;
char ch;
bool solve(){
	scanf("%d%d",&n,&m);
	if(n==0&&m==0) return false;
	for(int i=1;i<=n;i++){
		bar[i]=0;
		for(int j=1;j<=n;j++){
			cin>>ch;
			bar[i]+=(ch=='H'?0:(1<<(j-1)));
		}
	}
	for(int i=1;i<=n;i++)
		for(int s=0;s<(1<<n);s++)
			dp[i][s]=0;
	dp[1][0]=1;
	for(int i=1;i<=n;i++)
		if(((1<<(i-1))&bar[1])==0)
			dp[1][1<<(i-1)]=1;
	for(int i=1;i<n;i++){
		for(int s=0;s<(1<<n);s++){
			if(dp[i][s]==0) continue;
			dp[i+1][s]+=dp[i][s];
			int s0=(s|bar[i+1]);
			for(int j=1;j<=n;j++)
				if((s0&(1<<(j-1)))==0)
					dp[i+1][s|(1<<(j-1))]+=dp[i][s];
		}
	}
	int ans=0;
	for(int s=0;s<(1<<n);s++){
		int tmp=s,cnt=0;
		while(tmp){
			cnt+=tmp%2;
			tmp/=2;
		}
		if(cnt==m) ans+=dp[n][s];
	}
	printf("%d\n",ans);
	return true;
}
int main(){
	freopen("U319719.txt","r",stdin);
	while(solve());
	return 0;
}
