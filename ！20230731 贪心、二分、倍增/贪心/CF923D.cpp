#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int x2,ans=1e9,pri[N],mpri[N],cnt;
bool vis[N];
int main(){
	scanf("%d",&x2);
	vis[1]=true;
	for(int i=2;i<=x2;i++){
		if(!vis[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*pri[j]*i<=x2;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	for(int j=1;j<=cnt;j++)
		for(int i=1;pri[j]*i<=x2;i++)
			mpri[pri[j]*i]=pri[j];
	for(int j=1;j<mpri[x2];j++){
		int x1=x2-j;
		if(mpri[x1]==x1) ans=min(ans,x1);
		else ans=min(ans,x1-mpri[x1]+1);
	}
	printf("%d\n",ans);
	return 0;
}
