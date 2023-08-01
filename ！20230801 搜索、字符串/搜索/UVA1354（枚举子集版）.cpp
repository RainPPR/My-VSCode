#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=(1<<6);
typedef double db;
struct tree{
	db l,r;
};
int t,n,w[N],v[N];
vector<tree>f[N];
db rmax;
void solve(){
	scanf("%lf",&rmax);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	for(int s=0;s<(1<<n);s++){
		f[s].clear();
		w[s]=0;
		for(int i=0;i<n;i++)
			if(s&(1<<i)) w[s]+=v[i];
	}
	for(int s=1;s<(1<<n);s++){
		int cur=s,cnt=0;
		while(cur){
			cnt+=cur%2;
			cur/=2;
		}
		if(cnt==1){
			tree tmp;
			tmp.l=0,tmp.r=0;
			f[s].push_back(tmp);
		}
		for(int s0=(s-1)&s;s0;s0=(s0-1)&s){
			int ls=s0,rs=(s^s0);
			db li=1.0*w[rs]/w[s],ri=1.0*w[ls]/w[s];
			for(int i=0;i<f[ls].size();i++)
				for(int j=0;j<f[rs].size();j++){
					tree lf=f[ls][i],rf=f[rs][j];
					db lx=max(lf.l+li,rf.l-ri);
					db rx=max(rf.r+ri,lf.r-li);
					if(rx+lx<rmax){
						tree tmp;
						tmp.l=lx,tmp.r=rx;
						f[s].push_back(tmp);
					}
				}
		}
	}
	int s=(1<<n)-1;
	db ans=-1;
	for(int i=0;i<f[s].size();i++){
		tree uf=f[s][i];
		if(uf.l+uf.r>ans) ans=uf.l+uf.r;
	}
	if(ans!=-1) printf("%.12lf\n",ans);
	else printf("-1\n");
}
int main(){
	//freopen("UVA1354.txt","r",stdin);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
