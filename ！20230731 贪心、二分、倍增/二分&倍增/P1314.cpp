#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=2e6+5;
long long test(long long mid);
long long abss(long long now);
long long s1[N],sv[N],li[N],ri[N],s,wi[N],vi[N],ans=2e18,n,m;
int main()
{
	scanf("%lld%lld%lld",&n,&m,&s);
	long long l=0,r=2e18;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&wi[i],&vi[i]);
		l=min(l,wi[i]);
		r=max(r,wi[i]);
	}
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&li[i],&ri[i]);
	
	while(l<r)
	{
		long long mid=(l+r)>>1;
		long long cnt=test(mid);
		if(abs(s-cnt)<ans) ans=abs(s-cnt);
		if(cnt>s) l=mid+1;
		else r=mid;
	}
	printf("%lld",ans);
	return 0;
}
long long test(long long mid)
{
	memset(s1,0,sizeof(s1));
	memset(sv,0,sizeof(sv));
	for(int i=1;i<=n;i++)
	{
		s1[i]=s1[i-1];
		sv[i]=sv[i-1];
		if(wi[i]>=mid)
		{
			s1[i]+=1;
			sv[i]+=vi[i];
		}
	}
	long long cnt=0;
	for(int i=1;i<=m;i++)
		cnt+=(s1[ri[i]]-s1[li[i]-1])*(sv[ri[i]]-sv[li[i]-1]);
	return cnt;
}
