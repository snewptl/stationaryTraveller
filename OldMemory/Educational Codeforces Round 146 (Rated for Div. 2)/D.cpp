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
const int maxn=3e3+5;
const double eps=1e-10;
int n,k;
vector<ll>vec;
struct node{
    ll f,d,ht;
    node(){}
    node(ll x,ll y):f(x),d(y){ht=x*y;}
}a[maxn];
int f[maxn],d[maxn];
ll ht[maxn];
set<pli>s;
int main(){
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        s.clear();
        vec.clear();
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>f[i];
        for(int i=1;i<=n;i++)cin>>d[i];
        // int res=0;
        for(int i=1;i<=n;i++){
            a[i]=node(f[i],d[i]);
            ht[i]=a[i].ht;
            for(ll j=max(a[i].ht-k,1ll);j<=a[i].ht;j++)
                vec.push_back(j);
            s.insert({f[i],i});    
            // if(f[i]!=a[i].ht)res++;            
        }
        sort(ht+1,ht+n+1);
        sort(all(vec));
        vec.resize(unique(all(vec))-vec.begin());
        int ans=n;
        int pre=1,nxt=1;
        for(auto i:vec){
            ll j=i+k;
            while(s.begin()->first<i){
                auto it=s.begin();
                // cout<<it->first<<'\n';
                pll temp={max(1ll,(j-it->first)/a[it->second].f)*a[it->second].f+it->first,it->second};
                // if(a[it->second].ht<=j&&a[it->second].ht>=i)temp.first=a[it->second].ht;
                s.insert(temp);
                s.erase(it);
            }
            while(nxt<=n&&ht[nxt]<=j)nxt++;
            while(pre<=n&&ht[pre]<i)pre++;
            if(s.rbegin()->first<=j)
                ans=min(ans,n-nxt+pre);
        }
        cout<<ans<<'\n';
    }

    return 0;
}