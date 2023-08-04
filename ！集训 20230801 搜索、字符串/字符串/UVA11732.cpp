#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N=4e3+10,M=1e3+10;
typedef long long ll;
int n,now,cnt,len,son[N*M][62],sum[N*M],ed[N*M];
ll ans;
string s;
void init(){
	for(int i=0;i<=cnt;i++){
		sum[i]=ed[i]=0;
		for(int j=0;j<62;j++) son[i][j]=0;
	}
	cnt=ans=0;
}
int getid(char ch){
	if(ch>='a'&&ch<='z') return ch-'a';
	if(ch>='A'&&ch<='Z') return ch-'A'+26;
	if(ch>='0'&&ch<='9') return ch-'0'+52;
}
void ins(){
	int u=0;
	for(int pos=0;pos<len;pos++){
		int ch=getid(s[pos]);
		if(!son[u][ch]) son[u][ch]=++cnt;
		ans=ans+1ll*(sum[u]-sum[son[u][ch]])*(pos+pos+1);
		sum[u]++;
		u=son[u][ch];
	}
	ans=ans+1ll*(sum[u]-ed[u])*(len+len+1);
	ans=ans+1ll*ed[u]*(len+len+2);
	sum[u]++;
	ed[u]++;
}
int main(){
	scanf("%d",&n);
	while(n!=0){
		now++;
		init();
		for(int i=1;i<=n;i++){
			cin>>s;
			len=s.size();
			ins();
		}
		printf("Case %d: %lld\n",now,ans);
		scanf("%d",&n);
	}
	return 0;
}
