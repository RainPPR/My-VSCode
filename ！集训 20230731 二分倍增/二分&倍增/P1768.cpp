#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
typedef double db;
struct edge{
	int to,pre;
	db vi,pi;
}e[N];
int n,m,cnt=0,head[N];
void add(int a,int b,db v,db p){
	e[++cnt].to=b;
	e[cnt].pre=head[a];
	e[cnt].vi=v;
	e[cnt].pi=p;
	head[a]=cnt;
}
db dis[N];
bool vis[N];
bool haveAns;
void dfs(int u,db mid){
	if(vis[u]){
		haveAns=true;
		return;
	}
	vis[u]=true;
	for(int i=head[u];i;i=e[i].pre){
		int v=e[i].to;
		db w=e[i].pi*mid-e[i].vi;
		if(dis[v]>dis[u]+w){
			dis[v]=dis[u]+w;
			dfs(v,mid);
			if(haveAns) return;
		}
	}
	vis[u]=false;
}
bool check(db mid){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		vis[i]=false;
	}
	haveAns=false;
	dis[0]=0;
	vis[0]=false;
	dfs(0,mid);
	return haveAns;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		db v,p;
		scanf("%d%d%lf%lf",&a,&b,&v,&p);
		add(a,b,v,p);
	}
	for(int i=1;i<=n;i++)
		add(0,i,0,0);
	db l=0,r=200,ans=-1;
	while(l+0.0001<r){
		db mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	if(l==0) printf("-1\n");
	else printf("%.1lf\n",r);
	return 0;
}
