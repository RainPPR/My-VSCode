#include<stdio.h>
using namespace std;
inline int read(){
	int n=0,x=1;char c;
	for(c=getchar();c<'0'||c>'9';c=getchar())
		if(c=='-')x=-1;else x=1;
	for(;c>='0'&&c<='9';c=getchar())
		n=(n<<3)+(n<<1)-'0'+c;
	return x*n;
}
char getC(){
	char c=getchar();
	while(c!='H'&&c!='L')
		c=getchar();
	return c;
}
int n=read(),m=read(),cnt;
char mp[15][15];
bool vis[15];
void dfs(int s,int p){
	if(s==n){
		if(p==m)
			cnt++;
		return;
	}
	//²»·Å 
	dfs(s+1,p);
	//·Å 
	for(int i=0;i<n;i++){
		if(!vis[i]&&mp[s][i]=='H'){
			vis[i]=true;dfs(s+1,p+1);vis[i]=false;
		}
	}
}
int main(){
	freopen("U319719.txt","r",stdin);
	while(n>0&&m>0){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;mp[i][j++]=getC());
		dfs(0,0);
		printf("%d\n",cnt);
		//end
		n=read(),m=read(),cnt=0;
	}
	return 0;
}
