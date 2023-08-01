#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
int n,l,res=0,len;
char ans[N];
void dfs(int st){
	bool flag=false;
	int now=st-1;
	for(int cur=1;cur<=now/2;cur++){
		bool tf=true;
		for(int i=1;i<=cur;i++){
			tf=(tf&&ans[now-i+1]==ans[now-cur-i+1]);
			if(!tf) break;
		}
		if(tf){
			flag=true;
			break;
		}
	}
	if(flag) return;
	if(st>1){
		res++;
		if(res==n){
			len=now;
			return;
		}
	}
	for(int i=1;i<=l;i++){
		ans[st]='A'+i-1;
		dfs(st+1);
		if(res==n) return;
	}
}
int main(){
	scanf("%d%d",&n,&l);
	while(n!=0){
		res=0;
		dfs(1);
		for(int i=1;i<=len;i++){
			if(i+64<len){
				for(int j=1;j<=16;j++){
					for(int k=1;k<=4;k++)
						printf("%c",ans[i+j*4-4+k-1]);
					if(j!=16) printf(" ");
				}
				i=i+63;
			}else{
				for(int j=1,k=0;i+j-1<=len;j++){
					if(k==4){
						printf(" ");
						k=0;
					}
					printf("%c",ans[i+j-1]);
					k++;
				}
				i=len;
			}
			printf("\n");
		}
		printf("%d\n",len);
		scanf("%d%d",&n,&l);
	}
	return 0;
}
