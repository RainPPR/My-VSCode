#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e6+10;
char s[N];
int m,n;
int f[N];
int fa[N][21],dep[N];
vector<int>son[N];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0]; 
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	dep[0]=1,dep[1]=2;
	son[0].push_back(1);
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];
		while(s[f[i]+1]!=s[i]&&f[i]) f[i]=f[f[i]];
		if(s[f[i]+1]==s[i]) f[i]++;
		son[f[i]].push_back(i);
		fa[i][0]=f[i];
		dep[i]=dep[f[i]]+1;
	}
	for(int j=1;j<21;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&m);
	int p,q;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p,&q);
		int ans=lca(p,q);
		if(ans==p) ans=fa[p][0];
		if(ans==q) ans=fa[q][0];
		printf("%d\n",ans);
	}
	return 0;
}
