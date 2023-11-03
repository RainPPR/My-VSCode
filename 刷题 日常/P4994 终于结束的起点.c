main(){
int m,l=1,r=1,n=1,t;
scanf("%d",&m);
while(l%m!=0||r%m!=1)
t=l,l=r,r=(t+r)%m,++n;
printf("%d\n",n);
}