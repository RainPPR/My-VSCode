#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,t;
struct node{
	int Ai,Ti,id;
	friend bool operator < (const node x,const node y){
		return x.Ti<y.Ti;
	}//priority_queue 默认维护大根堆，这里重定义了一下 < 运算 
}B[N];
bool cmp(node x,node y){
	return x.Ai>y.Ai;
}//按照 Ai 排序 
priority_queue<node>q;
bool vis[N];
//输出方案的辅助数组 
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&B[i].Ai,&B[i].Ti);
		B[i].id=i;
	}
	sort(B+1,B+1+n,cmp);//排序 
	int cnt=0,sum=0,ans=0;
	//cnt记录目前在 q 中的数据总个数，sum记录 Ti 之和 
	for(int i=n,j=1;i>ans;i--){
		while(B[j].Ai>=i&&j<=n){
			bool used=false;
			//记录第 j 个数据是否被使用，因为每个数据最多使用一次 
			if(q.empty()&&B[j].Ti<=t){
				q.push(B[j]);
				cnt++;
				sum+=B[j].Ti;
				used=true;
			}//假如 q 是空的，并且第 j 个数据加进去不会超时 
			if(!used&&cnt<i&&sum+B[j].Ti<=t){
				q.push(B[j]);
				cnt++;
				sum+=B[j].Ti;
				used=true;
			}//假如第 j 个数据可以加入答案，那么直接扩展即可 
			if(!used&&!q.empty()){
				node cur=q.top();
				if(cur.Ti>B[j].Ti){
					q.pop();
					sum-=cur.Ti;
					q.push(B[j]);
					sum+=B[j].Ti;
				}
			}//假如第 j 个数据可以替换堆顶元素，那么替换即可 
			j++;
		}
		if(cnt>ans) ans=cnt;
	}
	while(!q.empty()){
		node cur=q.top();
		q.pop();
		vis[cur.id]=true;
	}
	printf("%d\n%d\n",ans,ans);
	for(int i=1;i<=n;i++)
		if(vis[i]) printf("%d ",i);
	return 0;
}
