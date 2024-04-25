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
string s;
void solve(){
    for(int i=0;i<s.size()/2-1;i++){
        if(s[i]!=s[i+1]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>s;
        solve();
    }

    return 0;
}