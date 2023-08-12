#pragma GCC optimize(3,"Ofast","inline")//吸口臭氧 
#include<bits/stdc++.h>
using namespace std;
struct node{//结构体定义树的节点
	double l,r,w;
}a[114514];
double len,ans=-1;
int t,w,cnt=0;
bool b[114514];
void f(int x){
	for(int i=1;i<=x;i++){
		if(b[i]){//枚举左边的 
			for(int j=1;j<=x;j++){
				if(j!=i&&b[j]){ //枚举右边的 
					double R=max(a[i].r-1,a[j].r),L=max(a[i].l,a[j].l-1);
					if(R+L+1<len){ //左边节点的长度加上右边节点的长度再加上第一根木棍的长度比len小 
						if(x==2*w-1){ //直到只剩一个节点时结束 
							ans=max(R+L+1,ans);
							return;
						}
						b[i]=b[j]=0;//将两个节点合并为一个节点,合并为x节点 
						b[x]=1;//新节点x,是可以被枚举的 
						a[x].w=a[i].w+a[j].w;//新节点总重量 
						a[x].l=a[j].w*1.0/a[x].w+L;//新节点左节点的长度等于右边重量除以总重量乘1加上自己的长度 
						a[x].r=a[i].w*1.0/a[x].w+R;//同理 
						f(x+1);//继续往上 
						b[i]=b[j]=1;//回溯 
						b[x]=0;
					}
				}
			}
		}
	}
}
int main(){
	freopen("UVA1354.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		cnt=1,ans=-1;
		memset(a,0,sizeof(a));
		scanf("%lf%d",&len,&w);
		for(int i=1;i<=w;i++){
			scanf("%d",&a[i].w);
			b[cnt++]=1;//可用节点及其数量 
		}
		if(w==1){
			printf("0.0000000000000000\n");
			continue;
		}
		f(cnt);
		printf("%.16lf\n",ans);
	}
	cout<<endl;
	return 0;
}

