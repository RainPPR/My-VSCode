#include <stdio.h>
int main(){
int n,a=0,b=0,c=0,d=0;
int N[n][n];scanf("%d",&n);
for(int i=0;i<n;i++)for(int j=0;j<n;j++)N[i][j]=0;
N[0][n/2]=1;int p=n/2;int q=0;
for(int k=2;k<=n*n;k++){
for(int i=0;i<n;i++)if(N[0][i]==k-1) a=1;
for(int i=0;i<n;i++)if(N[i][0]==k-1) b=1;
for(int i=0;i<n;i++)if(N[n-1][i]==k-1) c=1;
for(int i=0;i<n;i++)if(N[i][n-1]==k-1) d=1;
if(a==1&&d==0){N[n-1][p+1]=k;p=p+1,q=n-1;goto end;}
if(d==1&&a==0){N[q-1][0]=k,p=0,q=q-1;goto end;}
if(a==1&&d==1){N[q+1][p]=k,q=q+1;goto end;}
if(a==0&&d==0)if(N[q-1][p+1]==0)N[q-1][p+1]=k,q=q-1,p=p+1; else N[q+1][p]=k,q=q+1;
end:a=b=c=d=0;}
for(int i=0;i<n;i++,printf("\n"))for(int j=0;j<n;j++)printf("%d ",N[i][j]);
return 0;
}