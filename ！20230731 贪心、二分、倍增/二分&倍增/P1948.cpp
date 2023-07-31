#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e4+10;
int n,p,k,head[N],cnt;
struct edge{
	int to,len,pre;
}e[N];
int q[N*20],st,ed,dis[N];
void add(int ai,int bi,int li){
	e[++cnt].to=bi;
	e[cnt].len=li;
	e[cnt].pre=head[ai];
	head[ai]=cnt;
}
bool check(int mid){
	q[st=ed=100000]=1;
	for(int i=1;i<=n;i++) dis[i]=1e9;
	dis[1]=0;
	while(st<=ed){
		int u=q[ed];
		ed--;
		for(int i=head[u];i;i=e[i].pre){
			int v=e[i].to,w=e[i].len>mid;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(w==0) q[++ed]=v;
				else q[--st]=v;
			}
		}
	}
	return dis[n]<=k;
}
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=p;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		add(a,b,l);
		add(b,a,l);
	}
	check(4);
	int l=1,r=1e6,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
