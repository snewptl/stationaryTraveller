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
map<int,int>mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        mp.clear();
        int n,c,d;
        cin>>n>>c>>d;
        ll cnt=n,res=0;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            mp[x]++;
        }
        ll ans=2e18;
        for(int i=1;i<=n;i++){
            if(mp.count(i))cnt--;
            else res++;
            ans=min(ans,cnt*c+res*d);
        }
        cnt=n;
        res=0;
        int lst=0;
        for(auto it:mp){
            res+=it.first-lst-1;
            cnt--;
            lst=it.first;
            ans=min(ans,res*d+cnt*c);
        }
        cout<<ans<<'\n';
    }

    return 0;
}