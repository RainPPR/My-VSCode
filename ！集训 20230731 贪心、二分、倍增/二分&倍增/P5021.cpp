#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=1e5+5;
int n,m,val,res,ans,p,d;
int cnt,h[N],ai,bi,li;
multiset<int>s[N];
struct edge{int to,nex,len;}e[N*2];
void add(int x,int y,int z){e[++cnt].nex=h[x];e[cnt].to=y;e[cnt].len=z;h[x]=cnt;}
void Dfs(int u,int fa,int sum){
	if(sum>d){d=sum;p=u;}
	for(int i=h[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v==fa) continue;
		Dfs(v,u,sum+e[i].len);
	}
}
int dfs(int u,int fa){
	s[u].clear();
	for(int i=h[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v==fa) continue;
		int w=dfs(v,u)+e[i].len;
		if(w>=val) res++;
		else s[u].insert(w);
	}
	multiset<int>::iterator it;
	int maxn=0;
	while(!s[u].empty()){
		it=s[u].begin();
		if(s[u].size()==1) return max(maxn,*it);
		multiset<int>::iterator t=s[u].lower_bound(val-*it);
		if(t==it&&s[u].count(*it)==1) t++;
		if(t==s[u].end()){maxn=max(maxn,*it);s[u].erase(s[u].find(*it));}
		else{res++;s[u].erase(s[u].find(*t));s[u].erase(s[u].find(*it));}
	}
	return maxn;
}
int r(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
	return x;
}
int main(){
	n=r(),m=r();
	for(int i=1;i<n;i++) ai=r(),bi=r(),li=r(),add(ai,bi,li),add(bi,ai,li);
	Dfs(1,0,0);Dfs(p,0,0);
	int l=1,r=d+1;
	while(l<r){
		val=(l+r)>>1;res=0;
		dfs(1,0);
		if(res>=m){ans=max(ans,val);l=val+1;}
		else r=val;
	}
	printf("%d\n",ans);
	return 0; 
}
