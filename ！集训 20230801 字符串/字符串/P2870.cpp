#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+10,mod1=1e9+7,mod2=1e9+9;
char s[N],ans[N];
int n,cnt,h1[2][N],h2[2][N],pow1[N],pow2[N];
int geth10(int st,int ed){
	return (h1[0][ed]-1ll*h1[0][st-1]*pow1[ed-st+1]%mod1+mod1)%mod1;
}
int geth11(int st,int ed){
	return (h1[1][st]-1ll*h1[1][ed+1]*pow1[ed-st+1]%mod1+mod1)%mod1;
}
int geth20(int st,int ed){
	return (h2[0][ed]-1ll*h2[0][st-1]*pow2[ed-st+1]%mod2+mod2)%mod2;
}
int geth21(int st,int ed){
	return (h2[1][st]-1ll*h2[1][ed+1]*pow2[ed-st+1]%mod2+mod2)%mod2;
}
int main(){
	cin>>n;
	pow1[0]=pow2[0]=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		h1[0][i]=(h1[0][i-1]*27ll+s[i]-'A'+1)%mod1;
		h2[0][i]=(h2[0][i-1]*27ll+s[i]-'A'+1)%mod2;
		pow1[i]=pow1[i-1]*27ll%mod1;
		pow2[i]=pow2[i-1]*27ll%mod2;
	}
	for(int i=n;i>=1;i--){
		h1[1][i]=(h1[1][i+1]*27ll+s[i]-'A'+1)%mod1;
		h2[1][i]=(h2[1][i+1]*27ll+s[i]-'A'+1)%mod2;
	}
	int nl=1,nr=n;
	while(nl<=nr){
		if(s[nl]<s[nr]){
			ans[++cnt]=s[nl];
			nl++;
			continue;
		}
		if(s[nr]<s[nl]){
			ans[++cnt]=s[nr];
			nr--;
			continue;
		}
		int l=1,r=nr-nl,len=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(geth10(nl,nl+mid-1)==geth11(nr-mid+1,nr)){
				if(geth20(nl,nl+mid-1)==geth21(nr-mid+1,nr)){
					len=mid;
					l=mid+1;
				}else r=mid-1;
			}else r=mid-1;
		}
		if(s[nl+len]<=s[nr-len]){
			ans[++cnt]=s[nl];
			nl++;
			continue;
		}
		ans[++cnt]=s[nr];
		nr--;
	}
	for(int i=1;i<=n;i++){
		if(i+79<=n){
			for(int j=0;j<80;j++)
				printf("%c",ans[i+j]);
			i=i+79;
			printf("\n");
		}else printf("%c",ans[i]);
	}
	return 0;
}
