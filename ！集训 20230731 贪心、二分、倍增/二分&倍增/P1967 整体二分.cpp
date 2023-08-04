#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m,q,maxz,ans[N];
struct node{
	int x,y,z;
	friend bool operator < (node a,node b){
		return a.z>b.z;
	}
}A[N];
int qx[N],qy[N],qid[N],ql[N],qr[N],tx[N],ty[N],tid[N],tl[N],tr[N];
int fa[N];
int getfa(int x){
	if(fa[x]!=x) fa[x]=getfa(fa[x]);
	return fa[x];
}
void mergexy(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x!=y) fa[y]=x;
}
bool checkxy(int x,int y){
	x=getfa(x);
	y=getfa(y);
	return x==y;
}
//以上为并查集的常规操作，不再赘述 
void solve(){
	//处理一层的所有询问 
	for(int i=1;i<=n;i++)
		fa[i]=i;
	//初始化并查集 
	int now=1;
	//记录加到了哪一条边 
	bool haveAns=false;
	//判断是否还需要再递归 
	for(int i=1;i<=q;i++){
		if(ql[i]>qr[i]) continue;
		//对于第 i 个询问，它的二分的左端点为 ql[i],右端点为 qr[i] 
		int j=i+1;
		while(ql[j]==ql[i]) j++;
		j--;
		//把所有 ql[i]、qr[i] 相等的询问一块处理 
		//它们这一次需要判定的都是 mid 是否可行 
		int nl=i,nr=j,mid=(ql[i]+qr[i])/2;
		while(A[now].z>=mid&&now<=m){
			mergexy(A[now].x,A[now].y);
			now++;
		}
		//加边 
		for(int k=i;k<=j;k++)
			if(checkxy(qx[k],qy[k])){
				ans[qid[k]]=mid;
				tx[nl]=qx[k];
				ty[nl]=qy[k];
				tid[nl]=qid[k];
				tl[nl]=mid+1;
				tr[nl]=qr[k];
				nl++;
				//如果可行，我们接下来就要往大了试 
				//令 ql=mid+1 
				//记这种情况下一次的 mid 为 mid1 
				//第二种情况下一次的 mid 为 mid2 
				//容易发现 mid1>mid2 
				//所以这里我们把 mid 可行的询问丢到左边去 
			}else{
				tx[nr]=qx[k];
				ty[nr]=qy[k];
				tid[nr]=qid[k];
				tl[nr]=ql[k];
				tr[nr]=mid-1;
				nr--;
				//mid 不可行的询问丢到右边去  
			}
		for(int k=i;k<=j;k++){
			qx[k]=tx[k];
			qy[k]=ty[k];
			qid[k]=tid[k];
			ql[k]=tl[k];
			qr[k]=tr[k];
			if(ql[k]<=qr[k]) haveAns=true;
		}
		i=j;
	}
	if(haveAns) solve();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].z);
		maxz=max(maxz,A[i].z);
	}
	sort(A+1,A+1+m);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qx[i],&qy[i]);
		qid[i]=i;
		ans[i]=-1;
		ql[i]=1;
		qr[i]=maxz;
	}
	solve();
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
