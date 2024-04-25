#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
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
int n;
ll a[maxn],b[maxn];
int ans;
void solve(){
    ans=1;
    int lst=1;
    ll cost=b[1],num=a[1];
    for(int i=2;i<=n;i++){
        ll lcm=cost*b[i]/__gcd(cost,b[i]);
        if(num%(lcm/cost)==0&&a[i]%(lcm/b[i])==0){
            num=__gcd(num/(lcm/cost),a[i]/(lcm/b[i]));
            cost=lcm;
        }
        else {
            ans++;
            cost=b[i];
            num=a[i];
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
        solve();
    }

    return 0;
}