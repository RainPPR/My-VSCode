#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+10,mod1=1e9+7,mod2=1e9+9;
char t[N],s[N];
int lent,lens,num0,num1,ans;
int pow1[N],pow2[N],h1[N],h2[N];
int geth1(int l,int r){
	return (h1[r]-1ll*h1[l-1]*pow1[r-l+1]%mod1+mod1)%mod1;
}
int geth2(int l,int r){
	return (h2[r]-1ll*h2[l-1]*pow2[r-l+1]%mod2+mod2)%mod2;
}
void check(int len0,int len1){
	bool v0=false,v1=false;
	int hash01,hash02,hash11,hash12;
	for(int i=1,j=1;i<=lent;i++){
		if(t[i]=='0'){
			if(!v0){
				v0=true;
				hash01=geth1(j,j+len0-1);
				hash02=geth2(j,j+len0-1);
			}else{
				bool ok=false;
				if(hash01==geth1(j,j+len0-1))
					if(hash02==geth2(j,j+len0-1))
						ok=true;
				if(!ok) return;
			}
			j=j+len0;
		}else{
			if(!v1){
				v1=true;
				hash11=geth1(j,j+len1-1);
				hash12=geth2(j,j+len1-1);
			}else{
				bool ok=false;
				if(hash11==geth1(j,j+len1-1))
					if(hash12==geth2(j,j+len1-1))
						ok=true;
				if(!ok) return;
			}
			j=j+len1;
		}
	}
	if(hash01==hash11&&hash02==hash12) return;
	ans++;
}
int main(){
	scanf("%s%s",t+1,s+1);
	lent=strlen(t+1);
	lens=strlen(s+1);
	for(int i=1;i<=lent;i++)
		if(t[i]=='0') num0++;
		else num1++;
	pow1[0]=pow2[0]=1;
	for(int i=1;i<=lens;i++){
		pow1[i]=27ll*pow1[i-1]%mod1;
		pow2[i]=27ll*pow2[i-1]%mod2;
		h1[i]=(27ll*h1[i-1]+s[i]-'a'+1)%mod1;
		h2[i]=(27ll*h2[i-1]+s[i]-'a'+1)%mod2;
	}
	for(int l0=1;l0*num0<lens;l0++){
		int tot0=l0*num0,tot1=lens-tot0,l1;
		if(tot1%num1) continue;
		l1=tot1/num1;
		check(l0,l1);
	}
	printf("%d\n",ans); 
	return 0;
}
