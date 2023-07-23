#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int l,r,v;
}tree[1001];
int flag[101];
int f[101][101];
int n,q;
int gen;
void buildtree()
{
    int i,x,y,m;
    for (i=1;i<n;i++)
    {
        int p=0;
        scanf("%d%d%d",&x,&y,&m);
        for (int j=1;j<=n;j++)
        {
        	//��Ϊ��������������֮��ǰ��˳���ǲ�һ���ģ����������ж�����һ��
            //�ǲ��������ڵ���ӽڵ㣬���ǣ�������Ϊ��һ�ڵ�ĸ��ף���֮��Ϊ���ӽڵ㡣 
        	if (tree[j].l==y||tree[j].r==y) 
				p=1;   
        }
        if (p==0) 
        {
            if (tree[x].l==0) //���������� 
			{
				tree[x].l=y;
			}
            else if (tree[x].r==0)
			{
				tree[x].r=y;
			} 
            tree[y].v=m; 
            flag[y]=1;
        }
        else 
        {
            if (tree[y].l==0) 
			{
				tree[y].l=x;
			}
            else if (tree[y].r==0) 
			{
				tree[y].r=x;
			}
            tree[x].v=m;
            flag[x]=1;
        }
    }
    for (i=1;i<=n;i++)
    {
    	if (flag[i]==0) 
		{
			gen=i;break;
		}
    }        
}
void dfs(int i,int j)//����dp�����仯���� 
{
	if(f[i][j]>0)
	{
		return;
	}
    int k;
    if (j==0) 
	{
		f[i][j]=0;
	}
    else if (tree[i].r==0&&tree[i].l==0)//Ҷ�ӽڵ� 
	{
		f[i][j]=tree[i].v;
	} 
    else 
    {
        f[i][j]=0;
        for (k=0;k<j;k++)
        {
            if (f[tree[i].l][k]==0)
			{
				dfs(tree[i].l,k);
			}
            if (f[tree[i].r][j-k-1]==0)
			{
				dfs(tree[i].r,j-k-1);
			}
            f[i][j]=max(f[i][j],f[tree[i].l][k]+f[tree[i].r][j-k-1]+tree[i].v);
        }
    }
}
int main()
{
    int ans;
    scanf("%d%d",&n,&q);
    buildtree(); 
    dfs(gen,q+1);
    printf("%d",f[gen][q+1]);//q+1����Ϊ����ֵ��ֵ���˸��ڵ����ӽڵ���ӽڵ㣬���������q+1 
}
