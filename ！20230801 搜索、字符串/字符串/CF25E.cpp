#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N=1e5+10,mod1=998244353,mod2=1e9+7;
typedef long long ll;
string s[3];
int len[3],h1[3][N],h2[3][N],pow1[N],pow2[N];
bool vis[3],used[3];
int A[3],del[3][3],ans;
int geth1(int k,int st,int ed){
	return (h1[k][ed]-1ll*h1[k][st-1]*pow1[ed-st+1]%mod1+mod1)%mod1;
}
int geth2(int k,int st,int ed){
	return (h2[k][ed]-1ll*h2[k][st-1]*pow2[ed-st+1]%mod2+mod2)%mod2;
}
void calc(int k,int l){
	int maxn=min(len[k],len[l]);
	for(int i=maxn;i>=1;i--)
		if(geth1(k,len[k]-i+1,len[k])==geth1(l,1,i))
			if(geth2(k,len[k]-i+1,len[k])==geth2(l,1,i)){
				del[k][l]=i;
				return;
			}
	//printf("%d %d:%d\n",k,l,del[k][l]);
}
void dfs(int now){
	bool ok=false;
	for(int i=0;i<3;i++){
		if(vis[i]||used[i]) continue;
		used[i]=ok=true;
		A[now]=i;
		dfs(now+1);
		used[i]=false;
	}
	if(!ok){
		int res=0;
		for(int i=0;i<now-1;i++)
			res+=del[A[i]][A[i+1]];
		ans=max(ans,res);
	}
}
int main(){
	pow1[0]=pow2[0]=1;
	for(int i=1;i<N;i++){
		pow1[i]=27ll*pow1[i-1]%mod1;
		pow2[i]=27ll*pow2[i-1]%mod2;
	}
	/*for(int i=1;i<10;i++)
		printf("%d\n",pow1[i]);*/
	cin>>s[0]>>s[1]>>s[2];
	for(int k=0;k<3;k++){
		len[k]=s[k].size();
		for(int i=1;i<=len[k];i++){
			h1[k][i]=(h1[k][i-1]*27ll+s[k][i-1]-'a'+1)%mod1;
			h2[k][i]=(h2[k][i-1]*27ll+s[k][i-1]-'a'+1)%mod2;
		}
	}
	/*for(int i=1;i<10;i++)
		printf("%d\n",pow1[i]);
	printf("%d\n",geth1(0,2,7));*/
	//判断 k 是不是 l 的子串 
	for(int k=0;k<3;k++){
		int hk1=geth1(k,1,len[k]),hk2=geth2(k,1,len[k]);
		for(int l=0;l<3;l++){
			if(k==l||len[l]<len[k]) continue;
			if(len[k]==len[l]&&k>l) continue;
			for(int i=1;i+len[k]-1<=len[l];i++)
				if(hk1==geth1(l,i,i+len[k]-1)&&hk2==geth2(l,i,i+len[k]-1)){
					vis[k]=true;
					break;
				}
			if(vis[k]) break;
		}
	}
	//分别计算两两之间可以节省的字符个数 
	for(int k=0;k<3;k++){
		if(vis[k]) continue;
		for(int l=0;l<3;l++){
			if(vis[l]) continue;
			calc(k,l);
		}
	}
	//dfs搜索答案 
	dfs(0);
	ans=-ans;
	for(int k=0;k<3;k++)
		if(!vis[k]) ans+=len[k];
	printf("%d\n",ans);
	/*for(int k=0;k<3;k++)
		for(int i=1;i<=len[k];i++)
			for(int j=i;j<=len[k];j++)
				printf("%d %d %d:%d\n",k,i,j,geth1(k,i,j));*/
	return 0;
}
