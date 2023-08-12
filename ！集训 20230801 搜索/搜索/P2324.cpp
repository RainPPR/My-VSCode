#include<iostream>
#include<cstdio>
using namespace std;
const int N=6;
int T;
char A[N][N];
char B[N][N]={{},{'0','1','1','1','1','1'},
{'0','0','1','1','1','1'},{'0','0','0','*','1','1'},
{'0','0','0','0','0','1'},{'0','0','0','0','0','0'}};
int Dx[8]={-2,-2,-1,-1, 1, 1, 2, 2};
int Dy[8]={-1, 1,-2, 2,-2, 2,-1, 1};
int h(){
	int res=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			if(A[i][j]!=B[i][j]&&B[i][j]!='*')
				res++;
	return res;
}
bool dfs(int now,int dep,int cur){
	if(!cur) return true;
	if(now+cur>dep) return false;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
			if(A[i][j]!='*') continue;
			for(int k=0;k<8;k++){
				int nx=i+Dx[k],ny=j+Dy[k];
				if(nx<1||ny<1||nx>5||ny>5) continue;
				int tmp=cur;
				if(A[i][j]!=B[i][j]&&B[i][j]!='*') tmp--;
				if(A[i][j]!=B[nx][ny]&&B[nx][ny]!='*') tmp++;
				if(A[nx][ny]!=B[nx][ny]&&B[nx][ny]!='*') tmp--;
				if(A[nx][ny]!=B[i][j]&&B[i][j]!='*') tmp++;
				swap(A[nx][ny],A[i][j]);
				bool flag=dfs(now+1,dep,tmp);
				swap(A[nx][ny],A[i][j]);
				if(flag) return true;
			}
		}
	return false;
}
void solve(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			cin>>A[i][j];
	int t=h();
	for(int d=t;d<=15;d++)
		if(dfs(0,d,t)){
			printf("%d\n",d);
			return;
		}
	printf("-1\n");
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
