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
vector<int>res;
void init(){
    for(int i=1;i<=max(n,m);i++){
        shop[i].clear();
        seg[i]={0,0};
        pre[i]=0;
        zero[i]=0;
        pos[i]=0;
    }
}
int ans=0,mx=0;
void solve(){
    ans=mx=0;
    for(int i=n;i>=1;i--){
        for(auto it:shop[i]){
            if(!seg[it].second)seg[it].second=it,ans++,ans=min(m,ans);
            else {
                // cout<<mx<<'\n';
                res.push_back(mx);
                return;
            }
        }
        if(shop[i].empty())ans=m;
        if(ans>mx&&zero[i-1])mx=ans;

    }
    // cout<<mx<<'\n';
    res.push_back(mx);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    for(int cs=1;cs<=T;cs++){
        cin>>n>>m;
        init();
        for(int i=1;i<=n;i++){
            int sz;cin>>sz;
            for(int j=1;j<=sz;j++){
                int x;cin>>x;
                shop[i].push_back(x);
            }
        }
        for(int i=1;i<=n;i++){
            if(shop[i].empty())pre[i]=i;
            else pre[i]=pre[i-1];
        }
        int lst=0,le=1;
        zero[0]=1;
        for(int i=1;i<=n;i++){
            if(shop[i].empty())zero[i]=1;
            else {
                int ri=0;
                for(auto it:shop[i]){
                    ri=max(ri,seg[it].second);
                }       
                if(ri>=le){
                    if(pos[ri-1]>=le-1)
                        zero[i]=1;
                }
                if(pre[i]){
                    int x=n;
                    for(auto it:shop[i]){
                        x=min(x,seg[it].second);
                    }
                    if(pos[pre[i]]>=x&&pos[pre[i]]>=le-1)
                    zero[i]=1;                    
                }
                for(auto it:shop[i]){
                    seg[it].first=seg[it].second;
                    seg[it].second=i;
                    le=max(le,seg[it].first+1);
                }
            }
            if(zero[i])lst=i;
            pos[i]=lst;
        }
        // cout<<"\n-------\n";
        // for(int i=1;i<=n;i++){
        //     cout<<i<<" "<<zero[i]<<'\n';
        // }
        // cout<<"\n-----------\n";
        for(int i=1;i<=n;i++)seg[i]={0,0};
        solve();
        // if(cs==157&&res[1]==2){
        //     cout<<n<<" "<<m<<'\n';
        //     for(int i=1;i<=n;i++){
        //         cout<<shop[i].size()<<' ';
        //         for(auto it:shop[i])cout<<it<<' ';
        //         cout<<'\n';
        //     }
        // }

    }
    for(auto it:res)cout<<it<<'\n';

    return 0;
}
/*
1
10 2
0 
1 1 
0 
0 
0 
0 
1 1 
1 1 
1 2 
2 1 2 
*/