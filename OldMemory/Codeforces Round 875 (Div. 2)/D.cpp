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
int n,a[maxn],b[maxn];
map<int,int>vis[maxn];
int cnt[maxn];
vector<int>vec;
void clear(){
    for(int i=1;i<=n;i++)vis[i].clear();
    vec.clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            vis[a[i]][b[i]]++;
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(!cnt[i])continue;
            for(int j=1;j*i<=2*n;j++){
                if(!cnt[j])continue;
            }
        }

        
    }

    return 0;
}