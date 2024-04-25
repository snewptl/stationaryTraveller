#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=2e5+5;
const double eps=1e-10;
int T,n,a[maxn],b[maxn];
int main(){
    // freopen("gen.in","r",stdin);
    // freopen("gen.out","w",stdout);
    srand(time(0));
    T=rand()%100+1;
    printf("%d\n",T);
    for(int cs=1;cs<=T;cs++){
        n=rand()%100+50;
        printf("%d\n",n);
        for(int i=1;i<=n;i++){
            ll x,y;
            x=1ll*rand()*rand()%mod+1;
            x=1ll*rand()*rand()%mod+1;
            printf("%lld %lld\n",x,y);
        }
    }

    return 0;
}