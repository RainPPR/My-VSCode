#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+20,M=5e4+20;
struct edge1{
	int to,nex,len;
}e[M<<1];
struct edge2{
	int from,to,len;
	bool operator < (edge2 x) const{
		return len>x.len;
	}
}E[M<<1];
int n,m,ui,vi,wi,q,cnt;
int head[N],dad[N],dis[N],dep[N],fa[N][20],maxn[N][20];
int ff[N]; 
void add(int x,int y,int z){
	e[++cnt].to=y;
	e[cnt].nex=head[x];
	e[cnt].len=z;
	head[x]=cnt;
}
int getf(int x){
	return x==ff[x]?ff[x]:ff[x]=getf(ff[x]);
}
bool uni(int x,int y){
	int xi=getf(x),yi=getf(y);
	if(xi==yi) return 0;
	ff[yi]=xi;
	return 1;
}
void dfs(int x,int f){
	dad[x]=f;
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=e[i].nex)
		if(e[i].to!=f){
			dfs(e[i].to,x);
			dis[e[i].to]=e[i].len;
		}
}
void init(){
	for(int i=1;i<=n;i++){
		maxn[i][1]=dis[i];
		fa[i][1]=dad[i];
	}
	for(int j=2;j<=20;j++)
		for(int i=1;i<=n;i++){
			int t1=maxn[i][j-1],t2=maxn[fa[i][j-1]][j-1];
			maxn[i][j]=min(t1,t2);
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
}
int lca(int x,int y){
	int maxx=1e9;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=1;i--)
		if(dep[fa[x][i]]>=dep[y]){
			maxx=min(maxx,maxn[x][i]);
			x=fa[x][i];
		}
	if(x==y) return maxx;
	for(int i=20;i>=1;i--)
		if(fa[x][i]!=fa[y][i]){
			maxx=min(maxx,min(maxn[x][i],maxn[y][i]));
			x=fa[x][i];
			y=fa[y][i];
		}
	return min(maxx,min(maxn[x][1],maxn[y][1]));
}
int main(){
	memset(maxn,0x3f,sizeof(maxn));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		ff[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].len);
	sort(E+1,E+1+m);
	int tmp=0;
	for(int i=1;i<=m;i++){
		if(uni(E[i].from,E[i].to)){
			tmp++;
			add(E[i].from,E[i].to,E[i].len);
			add(E[i].to,E[i].from,E[i].len);
		}
		if(tmp==n-1) break;
	}
	for(int i=1;i<=n;i++)
		if(!dad[i]) dfs(i,0),dis[i]=1e9;
	init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&ui,&vi);
		if(getf(ui)==getf(vi)) printf("%d\n",lca(ui,vi));
		else printf("-1\n");
	}
	return 0;
}
