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
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        cin>>a>>b;
        int ans=0;
        a=abs(a),b=abs(b);
        ans+=min(a,b)*2;
        if(a!=b)ans+=(max(a,b)-min(a,b))*2-1;
        cout<<ans<<'\n';
    }

    return 0;
}