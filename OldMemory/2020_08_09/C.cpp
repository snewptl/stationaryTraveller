#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10;
ll mod=1e9+7;
ll n,mi[maxn],jie[maxn];
void init(){
    mi[0]=1,jie[0]=1;;
    for(ll i=1;i<=maxn-10;i++){
        mi[i]=mi[i-1]*2;
        mi[i]%=mod;
    }
    for(ll i=1;i<=maxn-10;i++){
        jie[i]=i*jie[i-1];
        jie[i]%=mod;
    }
}
int main(){
    init();
    scanf("%lld",&n);
    printf("%lld",(mod+jie[n]-mi[n-1])%mod);
    return 0;
}