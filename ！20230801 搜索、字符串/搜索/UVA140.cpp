#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
const int N=100;
int A[N],n,ans,pos[N];
bool vis[N];
char B[N];
vector<int>G[N];
string s;
int h(int now){
	int res=0;
	for(int i=1;i<=now;i++){
		int u=A[i];
		for(int j=0;j<G[u].size();j++){
			int v=G[u][j];
			if(!pos[v]) res=max(res,now-i+1);
		}
	}
	return res;
}
void dfs(int now,int cost){
	if(now==n){
		if(cost<ans){
			ans=cost;
			for(int i=1;i<=n;i++) B[i]='A'+A[i]-1;
		}
		return;
	}
	if(max(cost,h(now))>=ans) return;
	for(int i=1;i<=26;i++)
		if(vis[i]&&!pos[i]){
			A[now+1]=i;
			pos[i]=now+1;
			int res=0;
			for(int j=0;j<G[i].size();j++){
				int v=G[i][j];
				if(pos[v]) res=max(res,now+1-pos[v]);
			}
			dfs(now+1,max(cost,res));
			pos[i]=0;
		}
}
int main(){
	cin>>s;
	while(s!="#"){
		s=s+';';
		int len=s.size();
		ans=7;
		n=0;
		for(int i=1;i<N;i++){
			G[i].clear();
			vis[i]=false;
		}
		for(int i=0;i<len;i++){
			int j=i+2,u=s[i]-'A'+1;
			if(!vis[u]) n++;
			vis[u]=true;
			while(s[j]!=';'){
				int v=s[j]-'A'+1;
				if(!vis[v]) n++; 
				vis[v]=true;
				G[u].push_back(v);
				G[v].push_back(u);
				j++;
			}
			i=j;
		}
		for(int i=1;i<=n;i++) B[i]=i+'A'-1;
		dfs(0,0);
		for(int i=1;i<=n;i++)
			printf("%c ",B[i]);
		printf("-> ");
		printf("%d\n",ans);
		cin>>s;
	}
	return 0;
}
