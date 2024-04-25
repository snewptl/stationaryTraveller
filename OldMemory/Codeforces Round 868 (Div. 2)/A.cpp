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
const int inf=1e9;
const double eps=1e-10;
int n,k;
int cal(int x){
    return x*(x-1)/2;
}
void solve(){
    for(int i=0;i<=n;i++){
        if(cal(i)+cal(n-i)==k){
            cout<<"YES\n";
            for(int k=1;k<=i;k++)cout<<"1 ";
            for(int k=1;k<=n-i;k++)cout<<"-1 ";
            cout<<'\n';
            return ;
        }
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        solve();

    }

    return 0;
}