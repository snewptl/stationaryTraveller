#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
ll d[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d",&n);int flag=1;
		ll sum=0,tot=0;
		for(int i=1;i<=2*n;i++){
			scanf("%lld",&d[i]);
		}
		sort(d+1,d+n*2+1);
		for(int i=1;i<=n*2-1;i+=2){
			if(d[i]!=d[i+1])flag=0;
		}
		for(int i=3;i<=n*2-1;i+=2){
			if(((d[i]-d[i-2]))%(2*(i/2))!=0)flag=0;
			if(d[i]==d[i-2])flag=0;
			sum+=(d[i]-d[i-2])/(i/2);
			tot+=sum;
			if(tot>=d[1]){flag=0;break;}
		}
		if(tot>=d[1])flag=0;
		if((d[1]-tot)%(2*n)!=0)flag=0;
		if(d[1]==0)flag=0;
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}