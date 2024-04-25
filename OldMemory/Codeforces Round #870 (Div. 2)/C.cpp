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
int n,m;
void solve(){
    for(int i=2;i*i<=n;i++){
        if(n%i==0&&i<=m){
            cout<<"NO\n";
            return;
        }
    }    
    if(n!=1&&n<=m){
        cout<<"NO\n";
        return;        
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        solve();

    }

    return 0;
}