#pragma GCC optimize(3,"Ofast","inline")//���ڳ��� 
#include<bits/stdc++.h>
using namespace std;
struct node{//�ṹ�嶨�����Ľڵ�
	double l,r,w;
}a[114514];
double len,ans=-1;
int t,w,cnt=0;
bool b[114514];
void f(int x){
	for(int i=1;i<=x;i++){
		if(b[i]){//ö����ߵ� 
			for(int j=1;j<=x;j++){
				if(j!=i&&b[j]){ //ö���ұߵ� 
					double R=max(a[i].r-1,a[j].r),L=max(a[i].l,a[j].l-1);
					if(R+L+1<len){ //��߽ڵ�ĳ��ȼ����ұ߽ڵ�ĳ����ټ��ϵ�һ��ľ���ĳ��ȱ�lenС 
						if(x==2*w-1){ //ֱ��ֻʣһ���ڵ�ʱ���� 
							ans=max(R+L+1,ans);
							return;
						}
						b[i]=b[j]=0;//�������ڵ�ϲ�Ϊһ���ڵ�,�ϲ�Ϊx�ڵ� 
						b[x]=1;//�½ڵ�x,�ǿ��Ա�ö�ٵ� 
						a[x].w=a[i].w+a[j].w;//�½ڵ������� 
						a[x].l=a[j].w*1.0/a[x].w+L;//�½ڵ���ڵ�ĳ��ȵ����ұ�����������������1�����Լ��ĳ��� 
						a[x].r=a[i].w*1.0/a[x].w+R;//ͬ�� 
						f(x+1);//�������� 
						b[i]=b[j]=1;//���� 
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
			b[cnt++]=1;//���ýڵ㼰������ 
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

