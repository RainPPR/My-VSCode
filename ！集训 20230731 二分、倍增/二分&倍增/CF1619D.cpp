#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int>p[N];
int t,n,m,x,maxx,cnt[N];
bool vis[N];
bool check(int mid){
	bool haveAns=false;
	for(int i=1;i<=n;i++) vis[i]=false;
	for(int i=1;i<=m;i++){
		cnt[i]=0;
		for(int j=1;j<=n;j++){
			//printf("i=%d,j=%d,p[i][j]=%d\n",i,j,p[i][j]);
			if(p[i][j]>=mid){
				vis[j]=true;
				cnt[i]++;
			}
		}
		if(cnt[i]>1) haveAns=true;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) haveAns=false;
	return haveAns;
}
void solve(){
	scanf("%d%d",&m,&n);
	maxx=0;
	for(int i=1;i<=m;i++){
		p[i].clear();
		p[i].push_back(0);
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			p[i].push_back(x);
			maxx=max(maxx,x);
		}
	}
	int l=1,r=maxx,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
