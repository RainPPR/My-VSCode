#include<iostream>
#include<cstdio>
using namespace std;
const int N=21;
typedef double db;
int t,w[N],s,son[N][2],res[N][2];
db r,ans,minn,maxn;
bool vis[N];
void check(int u,db pos){
	if(u<=s){
		minn=min(minn,pos);
		maxn=max(maxn,pos);
		return;
	}
	db li=1.0*w[son[u][1]]/(w[son[u][0]]+w[son[u][1]]);
	db ri=1.0*w[son[u][0]]/(w[son[u][0]]+w[son[u][1]]);
	check(son[u][0],pos-li);
	check(son[u][1],pos+ri);
}
void dfs(int now){
	if(now==s-1){
		minn=maxn=0;
		check(s+now,0);
		if(maxn-minn<=r){
			ans=max(ans,maxn-minn);
			for(int i=1;i<=s+now;i++){
				res[i][0]=son[i][0];
				res[i][1]=son[i][1];
			}
		}
		return;
	}
	for(int i=1;i<=s+now;i++){
		if(vis[i]) continue;
		for(int j=1;j<=s+now;j++){
			if(vis[j]||i==j) continue;
			son[s+now+1][0]=i,son[s+now+1][1]=j;
			vis[i]=true,vis[j]=true;
			w[s+now+1]=w[i]+w[j];
			dfs(now+1);
			vis[i]=false,vis[j]=false;
		}
	}
}
void solve(){
	scanf("%lf%d",&r,&s);
	for(int i=1;i<=s;i++) scanf("%d",&w[i]);
	ans=-1;
	minn=maxn=0;
	/*w[7]=18;
	w[8]=35;
	w[9]=43;
	w[10]=54;
	w[11]=67;
	son[7][0]=6,son[7][1]=5;
	son[8][0]=7,son[8][1]=4;
	son[9][0]=8,son[9][1]=3;
	son[10][0]=9,son[10][1]=2;
	son[11][0]=10,son[11][1]=1;
	check(11,0);*/
	dfs(0);
	/*for(int i=1;i<=s+s-1;i++)
		printf("%d %d %d\n",i,res[i][0],res[i][1]);*/
	if(ans!=-1) printf("%.12lf\n",ans);
	else printf("-1\n");
}
int main(){
	freopen("UVA1354.txt","r",stdin);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
