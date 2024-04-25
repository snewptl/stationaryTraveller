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
int p[maxn];
int vis[maxn];
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=vis[i];
    if(cnt==2)cnt=1;
    else if(cnt>2)cnt=-1;
    cout<<cnt<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>p[i];
        for(int i=1;i<=n;i++)vis[i]=1;
        for(int i=1;i<=k;i++){
            for(int j=i;j<=n;j+=k)
                if((p[j]-1)%k+1==i)vis[p[j]]=0;
        }
        solve();

    }

    return 0;
}