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
int pre[maxn],zero[maxn],pos[maxn];
pii seg[maxn];
vector<int>shop[maxn];
void init(){
    for(int i=1;i<=n;i++){
        shop[i].clear();
        seg[i]={0,0};
        pre[i]=0;
        zero[i]=0;
        pos[i]=0;
    }
}
void solve(){
    int ans=0,mx=0;
    for(int i=n;i>=1;i--){
        for(auto it:shop[i]){
            if(!seg[it].second)seg[it].second=it,ans++,ans=min(m,ans);
            else {
                cout<<mx<<'\n';
                return;
            }
        }
        if(shop[i].empty())ans=m;
        if(ans>mx&&zero[i-1])mx=ans;

    }
    cout<<mx<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=1;i<=n;i++){
            int sz;cin>>sz;
            for(int j=1;j<=sz;j++){
                int x;cin>>x;
                shop[i].push_back(x);
            }
        }
        for(int i=1;i)
    }

    return 0;
}
/*
1
3 4
2 1 2
2 4 1
2 1 2
*/