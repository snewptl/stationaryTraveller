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
int n,m,a[maxn],cur[maxn];
vector<pii>vec[maxn*2];
vector<int>vis;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i],vis.push_back(a[i]);
        for(int i=1;i<=n;i++)cur[i]=0;
        for(int i=1;i<=m;i++){
            int p,v;
            cin>>p>>v;
            vis.push_back(v);
            vec[a[p]].push_back({cur[p],i-1});
            cur[p]=i;
            a[p]=v;
        }   
        for(int i=1;i<=n;i++)
            vec[a[i]].push_back({cur[i],m});
        sort(vis.begin(),vis.end());
        vis.resize(unique(vis.begin(),vis.end())-vis.begin());
        ll ans=0;
        for(auto idx:vis){
            int l=0,r=-1,len=0;;
            for(auto it:vec[idx]){
                if(it.first>r+1){
                    if(r>=l){
                        // ans-=1ll*(r-l)*(r-l+1)/2;      
                        // ans+=1ll*m*(r-l+1);
                        len+=r-l+1;
                    }
                    l=it.first;
                    r=it.second;
                }
                else if(it.second>=r)r=it.second;
                // if(l<=it.second)ans+=it.second-l+1,l=it.second+1;
            }
            if(r>=l){
                // ans-=1ll*(r-l)*(r-l+1)/2;   
                // ans+=1ll*m*(r-l+1);
                len+=r-l+1;
            }
            ans+=1ll*len*m-1ll*(len-1)*len/2;
        }
        cout<<ans<<'\n';
        for(auto it:vis)vec[it].clear();
        vis.clear();
    }

    return 0;
}