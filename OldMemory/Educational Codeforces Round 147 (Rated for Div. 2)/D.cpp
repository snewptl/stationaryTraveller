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
int le[maxn],ri[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        int ans=2e9,sum=0;
        for(int i=1;i<=n;i++)cin>>le[i];
        for(int i=1;i<=n;i++)cin>>ri[i];
        for(int i=1;i<=n;i++){
            int l=le[i],r=ri[i];
            int len=r-l+1;
            int res=0;
            if(sum+len<k){
                q.push(len);
                sum+=len;                
            }
            else {
                if(sum<k){
                    res=(q.size()+1)*2+k-sum-1+l;
                    ans=min(ans,res);                    
                }
                while(!q.empty()&&sum-q.top()+len>=k){
                    sum-=q.top();
                    q.pop();
                    res=(q.size()+1)*2+k-sum+l-1;
                    ans=min(ans,res);
                }
                if(sum<k){
                    res=(q.size()+1)*2+k-sum-1+l;
                    ans=min(ans,res);
                    q.push(len);
                    sum+=len;                    
                }
            }
        }
        if(ans==2e9)ans=-1;
        cout<<ans<<'\n';
        while(!q.empty())q.pop();
    }

    return 0;
}