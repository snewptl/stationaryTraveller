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
priority_queue<int,vector<int>,greater<int>>q;
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        ll ans=1e18,sum=0;
        for(int i=1;i<=n;i++){
            int l,r;
            cin>>l>>r;
            int len=r-l+1;
            ll res=0;
            if(sum+len<k){
                q.push(len);
                sum+=len;                
            }
            else {
                int fst=0;
                if(!q.empty())fst=q.top();
                while(sum-fst+len>=k){
                    sum-=fst;
                    if(!q.empty())q.pop();
                    res=(q.size()+1)*2+k-sum+l-1;
                    ans=min(ans,res);
                    if(!fst)break;
                    if(!q.empty())fst=q.top();
                    else fst=0;
                }
                res=(q.size()+1)*2+max(k-sum-1,0ll)+l;
                ans=min(ans,res);
                q.push(len);
                sum+=len;
            }
        }
        if(ans==1e18)ans=-1;
        cout<<ans<<'\n';
        while(!q.empty())q.pop();
    }

    return 0;
}