#include <iostream>
#include <cstring>
using namespace std;
const int N=100010, M=2*N;
int first[N],to[M],nxt[M],wht[M],idx;
int n,ans;
void add(int u, int v, int w)
{
	to[idx]=v;
	wht[idx]=w;
	nxt[idx]=first[u];
	first[u]=idx++;
}
//���㾭��u���·���������ֵ
int dfs(int u, int fa)
{
    //dist��ʾ��u�����ߵ���󳤶�
    int dist = 0;
    //��u��������ʹγ�����
    int d1 = 0, d2 = 0;
    for(int i=first[u]; i!=-1; i=nxt[i])
    {
        int v=to[i];
        if(v==fa)//��ֹ����һ������
		{
			continue; 
		}
        //���ӽ��������ߵ���󳤶�
        int d=dfs(v,u)+wht[i]; 
        dist=max(dist,d);
        //���������ʹγ�����
        if(d>=d1) 
		{
			d2=d1;
			d1=d;
		}
        else if(d>d2)
		{
			d2=d;
		}
    }
    //����̨�󾭹�u����·������
    ans=max(ans,d1+d2);
    cout<<u<<":d1="<<d1<<",d2="<<d2<<",dis="<<dist<<",ans="<<ans<<endl;
    return dist;
}
int main()
{
    cin>>n;
    memset(first, -1, sizeof first);
    int u,v,w;
    for(int i=0; i< n-1; i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
		add(v,u,w);
    }
    cout<<first[1]<<endl;
    dfs(1,-1);//dfs(6, -1);������Ч��
    cout << ans << endl;
    return 0;
}

