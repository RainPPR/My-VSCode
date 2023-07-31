#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int p=8,base=1e8,N=1005;
struct bignum{
	long long num[2005];
	int len;
	
	void r(string s)
	{
		memset(num,0,sizeof(num));
		int a=s.length(),b=1;
		len=(a+p-1)/p;
		for(int i=a-p;b<len;b++)
		{
			for(int j=i;j<i+p;j++)
				num[b]=num[b]*10+s[i]-'0';
			i-=p;
		}
		for(int i=0;i<a-(len-1)*p;i++)
			num[len]=num[len]*10+s[i]-'0';
	}
	
	void w()
	{
		printf("%lld",num[len]);
		for(int i=len-1;i>=1;i--)
			printf("%0*lld",p,num[i]);
		printf("\n");
	}
	
	void work()
	{
		for(int i=1;i<=len;i++)
		{
			if(num[i]>=base)
			{
				num[i+1]+=num[i]/base;
				num[i]=num[i]%base;
				if(i==len&&num[i+1]) len++;
			}
			if(num[i]<0)
			{
				int tmp=(-num[i]-1)/base+1;
				num[i+1]-=tmp;
				num[i]+=tmp*base;
			}
		}
		while(len>1&&num[len]==0) len--;
	}
}tmp,ans;

bignum operator * (const bignum &a,int b)
{
	bignum c;
	memset(c.num,0,sizeof(c.num));
	c.len=a.len;
	for(int i=1;i<=c.len;i++)
		c.num[i]=a.num[i]*b;
	c.work();
	return c;
}

bignum operator / (const bignum &a,int b)
{
	bignum c;
	memset(c.num,0,sizeof(c.num));
	c.len=a.len;
	long long x=0;
	for(int i=c.len;i>=1;i--)
	{
		c.num[i]=(x*base+a.num[i])/b;
		x=(x*base+a.num[i])%b;
	}
	c.work();
	return c;
}

struct node{
	int ai;
	int bi;
}mini[N];

bool cmp(node a,node b)
{
	return a.ai*a.bi<b.ai*b.bi;
}

bignum maxn(bignum a,bignum b)
{
	if(a.len<b.len) return b;
	if(a.len>b.len) return a;
	for(int i=a.len;i>=1;i--)
	{
		if(a.num[i]<b.num[i]) return b;
		if(a.num[i]>b.num[i]) return a; 
	}
	return b;
}

int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d%d",&mini[i].ai,&mini[i].bi);
	sort(mini+1,mini+1+n,cmp);
	ans.len=0;
	tmp.len=1,tmp.num[1]=1;
	for(int i=1;i<=n;i++)
	{
		tmp=tmp*mini[i-1].ai;
		ans=maxn(ans,tmp/mini[i].bi);
	}
	ans.w();
	return 0;
}
