#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 15000;
vector<int> G[maxn];

int cnt=0,x,y,N,s[maxn],w[maxn],centroid[maxn] = {0}; 

void dfs(int cur,int fa) {
	int siz = G[cur].size();
	s[cur] = 1;
	w[cur] = 0;
	for(int i=0;i<siz;i++){
		int v = G[cur][i];
		if(v != fa) {
			dfs(v,cur);
			s[cur] += s[v];
			w[cur] = max(w[cur], s[v]);
		}
	}
	w[cur] = max(w[cur], N - s[cur]);
	if( w[cur] <= N/2 ) 
		centroid[cnt++] = cur;
	return;
}

int main() {
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,-1);
	sort(centroid,centroid+cnt);
	if(cnt == 0)cout<<"NONE"<<endl;
	else 
		for(int i=0;i<cnt;i++) 
			cout<<centroid[i]<<endl;
	return 0;
}
