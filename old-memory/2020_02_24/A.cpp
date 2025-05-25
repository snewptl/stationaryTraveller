#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=10005;

int main(){
	int x,y,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(x==y)printf("0\n");
		else{
			if(x<y){
				if((y-x)%2)printf("1\n");
				else printf("2\n");
			}
			else{
				if((x-y)%2==0)printf("1\n");
				else printf("2\n");
			}
		}
	}
	return 0;
}