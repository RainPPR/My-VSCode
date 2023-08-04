#include<iostream>
#include<cstdio>
using namespace std;
const int N=210;
int t,a,b,c,d;
int dis[N][N];
bool vis[N][N];
void solve(){
	int n1=min(a,c),n2=min(b,c);
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++){
			dis[i][j]=1e9;
			vis[i][j]=false;
		}
	dis[0][0]=0;
	for(int i=1;;i++){
		int w=1e9,ui,uj,vi,vj;
		for(int j=0;j<=n1;j++)
			for(int k=0;k<=n2&&j+k<=c;k++)
				if(dis[j][k]<w&&!vis[j][k]){
					ui=j;
					uj=k;
					w=dis[j][k];
				}
		if(w==1e9) break;
		vis[ui][uj]=true;
		//a->b 
		if(ui&&uj<b){
			int del=min(ui,b-uj);
			vi=ui-del;
			vj=uj+del;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
		//b->a 
		if(uj&&ui<a){
			int del=min(uj,a-ui);
			vi=ui+del;
			vj=uj-del;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
		int uk=c-ui-uj;
		//a->c 
		if(ui&&uk<c){
			int del=min(ui,c-uk);
			vi=ui-del;
			vj=uj;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
		if(uk&&ui<a){
			int del=min(uk,a-ui);
			vi=ui+del;
			vj=uj;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
		//b->c 
		if(uj&&uk<c){
			int del=min(uj,c-uk);
			vi=ui;
			vj=uj-del;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
		if(uk&&uj<b){
			int del=min(uk,b-uj);
			vi=ui;
			vj=uj+del;
			dis[vi][vj]=min(dis[vi][vj],w+del);
		}
	}
	int now=-1,ans;
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2&&i+j<=c;j++){
			int k=c-i-j,cur=-1;
			if(dis[i][j]==1e9) continue;
			if(i<=d) cur=i;
			if(j<=d) cur=max(cur,j);
			if(k<=d) cur=max(cur,k);
			if(cur>now){
				now=cur;
				ans=dis[i][j];
			}else if(cur==now) ans=min(ans,dis[i][j]);
		}
	printf("%d %d",ans,now);
}
int main(){
	freopen("test.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		solve();
	}
}
