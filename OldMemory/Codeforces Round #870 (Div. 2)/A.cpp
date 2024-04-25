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
int a[maxn];
void solve(){
    for(int i=0;i<=n;i++){
        if(i<n&&a[i+1]<=n-i)continue;
        if(i&&a[i]>n-i)continue;
        cout<<n-i<<'\n';
        return ;
    }    
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        solve();

    }

    return 0;
}