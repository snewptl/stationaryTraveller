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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;
        if(n%2){
            if(k%2)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }

    return 0;
}