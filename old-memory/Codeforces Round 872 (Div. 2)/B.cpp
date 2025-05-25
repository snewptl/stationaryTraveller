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
int n,m,a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        if(n<m)swap(n,m);
        for(int i=1;i<=n*m;i++)cin>>a[i];
        sort(a+1,a+n*m+1);
        ll ans=1ll*(a[n*m]-a[1])*(n-1)*m+max((a[n*m-1]-a[1])*(m-1),(a[n*m]-a[2])*(m-1));
        cout<<ans<<'\n';
    }

    return 0;
}