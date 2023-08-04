#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
const int N=1010;
int n,A[N],len[N],inu[N],B[N];
string s[N];
vector<int>to[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		len[i]=s[i].size();
	}
	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int i=1;i<n;i++){
		int maxn=min(len[A[i]],len[A[i+1]]),j;
		bool ok=true;
		for(j=0;j<maxn;j++)
			if(s[A[i]][j]!=s[A[i+1]][j]){
				ok=false;
				break;
			}
		if(ok&&len[A[i]]>len[A[i+1]]){
			printf("NE\n");
			return 0;
		}
		if(!ok){
			int u=s[A[i]][j]-'a'+1,v=s[A[i+1]][j]-'a'+1;
			to[u].push_back(v);
			inu[v]++;
		}
	}
	for(int i=1;i<=26;i++){
		int u=-1;
		for(int j=1;j<=26;j++){
			if(!B[j]&&!inu[j]){
				u=j;
				break;
			}
		}
		if(u==-1){
			printf("NE\n");
			return 0;
		}
		B[u]=i;
		for(int j=0;j<to[u].size();j++){
			int v=to[u][j];
			inu[v]--;
		}
	}
	printf("DA\n");
	for(int i=1;i<=26;i++)
		printf("%c",B[i]+'a'-1);
	return 0;
}
