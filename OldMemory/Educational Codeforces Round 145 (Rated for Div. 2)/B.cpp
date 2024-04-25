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
ll cal0(ll x){
    return x*(x-1)*4+1;
}
ll solve0(ll n){
    ll x=sqrt(max(0ll,(n-1)/4));
    x--;
    while(x<0||cal0(x)<=n)x++;
    x--;
    if(cal0(x)==n)return 2*(x-1);
    else return 2*x;
}
ll cal1(ll x){
    return x*x*4;
}
ll solve1(ll n){
    ll x=sqrt(max(0ll,n/4));
    x--;
    while(x<=0||cal1(x)<=n)x++;
    x--;
    if(cal1(x)==n)return 2*x-1;
    else return 2*x+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        ll n;cin>>n;
        cout<<min(solve0(n),solve1(n))<<'\n';
    }

    return 0;
}