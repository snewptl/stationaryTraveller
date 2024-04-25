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
int n,m;
vector<int>day[maxn];
int vis[maxn],lst[maxn];
void clear(){
    for(int i=1;i<=m;i++){
        vis[i]=0;
        for(auto it:day[i]){
            lst[it]=0;
        }
        day[i].clear();
    }
}
bool solve(){
    for(int i=1;i<=m;i++)if(!vis[i])return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>m;
        for(int i=1;i<=m;i++){
            int x;cin>>x;
            for(int j=1;j<=x;j++){
                int a;cin>>a;
                day[i].push_back(a);
                lst[a]=i;
            }
        }
        for(int i=1;i<=m;i++){
            for(auto it:day[i]){
                if(lst[it]==i)vis[i]=it;
            }
        }
        if(solve()){
            for(int i=1;i<=m;i++)cout<<vis[i]<<' ';
            cout<<'\n';
        }
        else cout<<"-1\n";


        clear();
    }

    return 0;
}