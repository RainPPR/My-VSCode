#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll t,n,s1,v1,s2,v2,cnt;
void solve(){
	scanf("%lld%lld%lld%lld%lld",&n,&s1,&v1,&s2,&v2);
	ll ans=0;
	if(s1>=n/s1){
		for(int i=0;s1*i<=n;i++)
			ans=max(ans,i*v1+(n-s1*i)/s2*v2);
	}else if(s2>=n/s2){
		for(int i=0;s2*i<=n;i++)
			ans=max(ans,i*v2+(n-s2*i)/s1*v1);
	}else{
		//ȡ s2 �� 1 ��ȡ s1 �� 2 ռ���������ͬ�� 
		//��ô���ǱȽ� s1*v2 �� s2*v1 ����Դ�С��ϵ 
		//��� s1*v2 ����ô 1 ����ȡ s2-1 �� 
		if(s1*v2>s2*v1){
			for(int i=0;i<s2;i++)
				ans=max(ans,v1*i+(n-s1*i)/s2*v2);
		}else{
			for(int i=0;i<s1;i++)
				ans=max(ans,v2*i+(n-s2*i)/s1*v1);
		}
	}
	cnt++;
	printf("Case #%lld: %lld\n",cnt,ans);
}
int main(){
	scanf("%lld",&t);
	cnt=0;
	while(t--) solve();
	return 0;
}
