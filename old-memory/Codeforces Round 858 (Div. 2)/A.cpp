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
int a,b,c,d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        int ans=0;
        cin>>a>>b>>c>>d;
        if(d<b)cout<<"-1\n";
        else {
            ans+=d-b,a+=d-b;
            if(a<c)cout<<"-1\n";
            else {
                ans+=a-c;
                cout<<ans<<'\n';
            }
        }
    }

    return 0;
}