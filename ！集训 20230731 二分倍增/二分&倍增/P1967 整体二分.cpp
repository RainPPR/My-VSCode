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
//����Ϊ���鼯�ĳ������������׸�� 
void solve(){
	//����һ�������ѯ�� 
	for(int i=1;i<=n;i++)
		fa[i]=i;
	//��ʼ�����鼯 
	int now=1;
	//��¼�ӵ�����һ���� 
	bool haveAns=false;
	//�ж��Ƿ���Ҫ�ٵݹ� 
	for(int i=1;i<=q;i++){
		if(ql[i]>qr[i]) continue;
		//���ڵ� i ��ѯ�ʣ����Ķ��ֵ���˵�Ϊ ql[i],�Ҷ˵�Ϊ qr[i] 
		int j=i+1;
		while(ql[j]==ql[i]) j++;
		j--;
		//������ ql[i]��qr[i] ��ȵ�ѯ��һ�鴦�� 
		//������һ����Ҫ�ж��Ķ��� mid �Ƿ���� 
		int nl=i,nr=j,mid=(ql[i]+qr[i])/2;
		while(A[now].z>=mid&&now<=m){
			mergexy(A[now].x,A[now].y);
			now++;
		}
		//�ӱ� 
		for(int k=i;k<=j;k++)
			if(checkxy(qx[k],qy[k])){
				ans[qid[k]]=mid;
				tx[nl]=qx[k];
				ty[nl]=qy[k];
				tid[nl]=qid[k];
				tl[nl]=mid+1;
				tr[nl]=qr[k];
				nl++;
				//������У����ǽ�������Ҫ�������� 
				//�� ql=mid+1 
				//�����������һ�ε� mid Ϊ mid1 
				//�ڶ��������һ�ε� mid Ϊ mid2 
				//���׷��� mid1>mid2 
				//�����������ǰ� mid ���е�ѯ�ʶ������ȥ 
			}else{
				tx[nr]=qx[k];
				ty[nr]=qy[k];
				tid[nr]=qid[k];
				tl[nr]=ql[k];
				tr[nr]=mid-1;
				nr--;
				//mid �����е�ѯ�ʶ����ұ�ȥ  
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
