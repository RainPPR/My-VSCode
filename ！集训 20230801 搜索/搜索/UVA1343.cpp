#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
int A[N],cnt[4],ans,res,len;
char st[N],ed[N];
int D[8][7]={{1,3,7,12,16,21,23},{2,4,9,13,18,22,24},
{11,10,9,8,7,6,5},{20,19,18,17,16,15,14},
{24,22,18,13,9,4,2},{23,21,16,12,7,3,1},
{14,15,16,17,18,19,20},{5,6,7,8,9,10,11}
};
char pD[8]={'A','B','C','D','E','F','G','H'};
char ni[8]={'F','E','H','G','B','A','D','C'};
int z[8]={7,8,9,12,13,16,17,18};
bool check(){
	bool flag=true;
	for(int i=1;i<8;i++)
		flag=flag&&A[z[i]]==A[z[0]];
	return flag;
}
int h(){
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=0;i<8;i++)
		cnt[A[z[i]]]++;
	return 8-max(cnt[1],max(cnt[2],cnt[3]));
}
void opt(int x){
	int tmp=A[D[x][0]];
	for(int i=0;i<6;i++)
		A[D[x][i]]=A[D[x][i+1]];
	A[D[x][6]]=tmp;
}
void unopt(int x){
	int tmp=A[D[x][6]];
	for(int i=6;i>0;i--)
		A[D[x][i]]=A[D[x][i-1]];
	A[D[x][0]]=tmp;
}
bool dfs(int dep,int step,char lst){
	if(check()){
		res=A[z[0]];
		for(int i=0;i<step;i++)
			ed[i]=st[i];
		len=step;
		return true;
	}
	if(step+h()>dep) return false;
	for(int i=0;i<8;i++){
		if(lst==ni[i]) continue;
		opt(i);
		st[step]=pD[i];
		bool flag=dfs(dep,step+1,pD[i]);
		unopt(i);
		if(flag) return true;
	}
	return false;
}
void solve(){
	if(check()){
		ans=0;
		return;
	}
	for(int d=1;d<ans;d++)
		if(dfs(d,0,'0')){
			ans=d;
			return;
		}
}
int main(){
	scanf("%d",&A[1]); 
	while(A[1]!=0){
		for(int i=2;i<=24;i++) scanf("%d",&A[i]);
		ans=1e9;
		solve();
		if(ans==0){
			printf("No moves needed\n");
			printf("%d\n",A[z[0]]);
		}else{
			for(int i=0;i<len;i++) printf("%c",ed[i]);
			printf("\n");
			printf("%d\n",res);
		}
		scanf("%d",&A[1]);
	}
	return 0;
}
