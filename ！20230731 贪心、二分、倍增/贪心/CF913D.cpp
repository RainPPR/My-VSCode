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
	}//priority_queue Ĭ��ά������ѣ������ض�����һ�� < ���� 
}B[N];
bool cmp(node x,node y){
	return x.Ai>y.Ai;
}//���� Ai ���� 
priority_queue<node>q;
bool vis[N];
//��������ĸ������� 
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&B[i].Ai,&B[i].Ti);
		B[i].id=i;
	}
	sort(B+1,B+1+n,cmp);//���� 
	int cnt=0,sum=0,ans=0;
	//cnt��¼Ŀǰ�� q �е������ܸ�����sum��¼ Ti ֮�� 
	for(int i=n,j=1;i>ans;i--){
		while(B[j].Ai>=i&&j<=n){
			bool used=false;
			//��¼�� j �������Ƿ�ʹ�ã���Ϊÿ���������ʹ��һ�� 
			if(q.empty()&&B[j].Ti<=t){
				q.push(B[j]);
				cnt++;
				sum+=B[j].Ti;
				used=true;
			}//���� q �ǿյģ����ҵ� j �����ݼӽ�ȥ���ᳬʱ 
			if(!used&&cnt<i&&sum+B[j].Ti<=t){
				q.push(B[j]);
				cnt++;
				sum+=B[j].Ti;
				used=true;
			}//����� j �����ݿ��Լ���𰸣���ôֱ����չ���� 
			if(!used&&!q.empty()){
				node cur=q.top();
				if(cur.Ti>B[j].Ti){
					q.pop();
					sum-=cur.Ti;
					q.push(B[j]);
					sum+=B[j].Ti;
				}
			}//����� j �����ݿ����滻�Ѷ�Ԫ�أ���ô�滻���� 
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
