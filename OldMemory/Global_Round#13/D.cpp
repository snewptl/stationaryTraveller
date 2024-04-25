#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll x,y;
int a[50],b[50];
int mx=0;
void init(){
	int p=0;mx=0;
	while(x){
		a[p]=x&1;
		x/=2;p++;
	}
	mx=max(mx,p);
	p=0;
	while(y){
		b[p]=y&1;
		y/=2;p++;
	}
	mx=max(mx,p);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
        scanf("%lld%lld",&x,&y);
		int flag=1;
		if(y<x)flag=0;
		init();
		int cntx=0,cnty=0; 
		for(int i=0;i<mx;i++){
			if(a[i])cntx++;
			if(b[i])cnty++;
			if(cntx<cnty)flag=0;
		}
		
		if(flag)printf("YES\n");
		else printf("NO\n");
    }
	


    return 0;
}