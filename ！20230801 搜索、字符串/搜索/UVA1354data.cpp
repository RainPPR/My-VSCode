#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	freopen("UVA1354.txt","w",stdout);
	srand(time(0));
	cout<<"10\n";
	for(int i=1;i<=10;i++){
		cout<<(300+rand()%301)/100.0<<"\n";
		cout<<"6\n";
		for(int j=1;j<=6;j++)
			cout<<rand()%20+1<<"\n";
	}
	return 0;
}
