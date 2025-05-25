#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll n,x;
ll lowbit(ll x){
    return x&(-x);
}
ll highbit(ll x){
    for(int i=0;;i++){
        if((1ll<<i)>x)return 1ll<<i;
    }
    return 0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%lld%lld",&n,&x);
        if(n==x)printf("%lld\n",n);
        else if(x==0)printf("%lld\n",highbit(n));
        else {
            int flag=1;
            if((n^x)!=n-x||n<x)flag=0;
            if(lowbit(x)<=highbit(n-x))flag=0;
            // if(highbit(n-x)==lowbit(x))flag=0;
            if(!flag)puts("-1");
            else {
                ull cur=1;
                cout<<x+cur*highbit(n-x)<<'\n';
                // printf("%lld %lld %lld\n",x,n-x,highbit(2));
            }            
        }

	}


	return 0;
}