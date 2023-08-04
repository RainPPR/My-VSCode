#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=510;
struct node{
	int x,y;
}a[N*N],q[N*N];
int h[N][N],n,m,tmp,cnt,ans;
int dx[4]={ 1,-1, 0, 0};
int dy[4]={ 0, 0, 1,-1};
bool vis[N][N];
inline int r(){
	int x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*w;
}
inline bool check(int mid){
	memset(vis,false,sizeof(vis));
	q[1].x=a[1].x,q[1].y=a[1].y,vis[q[1].x][q[1].y]=true;
	int head=1,tail=1;
	while(head<=tail){
		int fx=q[head].x,fy=q[head].y;
		for(int i=0;i<4;i++)
		{
			int nx=fx+dx[i],ny=fy+dy[i];
			if(nx>n||nx<1||ny>m||ny<1||vis[nx][ny]||abs(h[fx][fy]-h[nx][ny])>mid) continue;
			vis[nx][ny]=true;
			tail++,q[tail].x=nx,q[tail].y=ny;
		}
		head++;
	}
	for(int i=1;i<=cnt;i++)
		if(!vis[a[i].x][a[i].y]) return false;
	return true;
}
int main()
{
	n=r(),m=r();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			h[i][j]=r();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			tmp=r();
			if(tmp==1) cnt++,a[cnt].x=i,a[cnt].y=j;
		}
	int l=-1,r=2e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
