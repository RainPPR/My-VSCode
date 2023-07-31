#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long ll;
int n,len;
string s;
ll ans,fp[61],fpn[61];
int main(){
	cin>>n>>s;
	len=s.size();
	fp[0]=fpn[0]=1;
	for(int i=1;i<len;i++){
		fp[i]=fp[i-1]*10;
		fpn[i]=fpn[i-1]*n;
	}
	for(int i=len-1,cnt=0;i>=0;i--){
		int j=i-1;
		ll cur=s[i]-'0';
		while(j>=0){
			if((s[j]-'0')*fp[i-j]+cur>=n||i-j+1>=10) break;
			cur=(s[j]-'0')*fp[i-j]+cur;
			j--;
		}
		j++;
		while(s[j]=='0'&&j<i) j++;
		ans+=cur*fpn[cnt];
		cnt++;
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}
