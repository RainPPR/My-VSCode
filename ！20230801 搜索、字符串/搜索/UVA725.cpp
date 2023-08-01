#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b;
	friend bool operator < (node x,node y){
		return x.a<y.a;
	}
}A[N];
int n,cnt;
bool vis[10];
void solve(){
	for(int i=1;i*n<100000;i++){
		for(int j=0;j<=9;j++)
			vis[j]=false;
		int tmp=i,sum=0;
		if(i<10000){
			vis[0]=true;
			sum++;
		}
		bool tf=true;
		while(tmp){
			int now=tmp%10;
			if(vis[now]){
				tf=false;
				break;
			}
			sum++;
			vis[now]=true;
			tmp/=10;
		}
		tmp=i*n;
		if(!tf) continue;
		while(tmp){
			int now=tmp%10;
			if(vis[now]){
				tf=false;
				break;
			}
			sum++;
			vis[now]=true;
			tmp/=10;
		}
		if(tf&&sum==10){
			cnt++;
			A[cnt].a=i*n;
			A[cnt].b=i;
		}
	}
}
int main(){
	bool cur=false;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		if(cur) printf("\n");
		cur=true;
		cnt=0;
		solve();
		if(cnt){
			sort(A+1,A+1+cnt);
			for(int i=1;i<=cnt;i++){
				if(A[i].b<10000) printf("%d / 0%d = %d\n",A[i].a,A[i].b,n);
				else printf("%d / %d = %d\n",A[i].a,A[i].b,n);
			}
		}else printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
