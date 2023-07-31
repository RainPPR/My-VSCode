#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+100;
int n,m,q,a[N],b[N],op[N],li[N],ri[N];
int ans;
struct node{
	int num,tag;
}tr[N*4];
void update(int u){
	tr[u].num=tr[u*2].num+tr[u*2+1].num;
}
void build(int u,int l,int r){
	tr[u].tag=0;
	if(l==r){
		tr[u].num=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	update(u);
}
void change(int u,int l,int r,int k){
	if(k==1){
		tr[u].num=0;
		tr[u].tag=1;
	}
	if(k==2){
		tr[u].num=(r-l+1);
		tr[u].tag=2;
	}
}
void pushdown(int u,int l,int r){
	int mid=(l+r)>>1;
	change(u*2,l,mid,tr[u].tag);
	change(u*2+1,mid+1,r,tr[u].tag);
	tr[u].tag=0;
}
int query(int u,int l,int r,int x,int y){
	if(x>y) return 0;
	if(l>=x&&r<=y) return tr[u].num;
	pushdown(u,l,r);
	int mid=(l+r)>>1,res=0;
	if(mid>=x) res+=query(u*2,l,mid,x,y);
	if(mid<y) res+=query(u*2+1,mid+1,r,x,y);
	return res;
}
void modify(int u,int l,int r,int x,int y,int k){
	if(x>y) return;	
	if(l>=x&&r<=y){
		change(u,l,r,k);
		return;
	}
	pushdown(u,l,r);
	int mid=(l+r)>>1;
	if(mid>=x) modify(u*2,l,mid,x,y,k);
	if(mid<y) modify(u*2+1,mid+1,r,x,y,k);
	update(u);
}
bool check(int mid){
	for(int i=1;i<=n;i++) b[i]=a[i]<=mid;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int len=query(1,1,n,li[i],ri[i]);
		if(op[i]==0){
			modify(1,1,n,li[i],li[i]+len-1,2);
			modify(1,1,n,li[i]+len,ri[i],1);
		}else{
			modify(1,1,n,ri[i]-len+1,ri[i],2);
			modify(1,1,n,li[i],ri[i]-len,1);
		}
	}
	return query(1,1,n,q,q);
}
int rd(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	n=rd(),m=rd();
	for(int i=1;i<=n;i++) a[i]=rd();
	for(int i=1;i<=m;i++)
		op[i]=rd(),li[i]=rd(),ri[i]=rd();
	q=rd();
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
