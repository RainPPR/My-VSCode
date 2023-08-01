#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int N=20010,M=11;
int n,len,tag[N*M],son[N*M][26],sum[N*M],cnt,ans;
string s,c[N];
void ins(int u,int now){
	//将字符串 s 放入 trie 树中 
	if(now==len){
		sum[u]++;
		return;
	}
	int v=s[now]-'a';
	if(son[u][v]) ins(son[u][v],now+1);
	else{
		son[u][v]=++cnt;
		ins(son[u][v],now+1);
	}
}
void check(int u,int now,int cur){
	if(tag[u]!=cur){
		ans+=sum[u];
		tag[u]=cur;
	}
	if(now==len) return;
	int v=s[now]-'a';
	if(son[u][v]) check(son[u][v],now+1,cur);
}
bool cmp(string a,string b){
	return a.size()<b.size();
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++){
		int j=i+1;
		while(j<=n&&c[j].size()==c[i].size()) j++;
		j--;
		for(int k=i;k<=j;k++){
			s=c[k];
			len=s.size();
			ins(0,0);
		}
		for(int k=i;k<=j;k++){
			s=c[k];
			len=s.size();
			for(int l=0;l<len;l++)
				check(0,l,k);
		}
		ans-=(j-i+1);
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}
