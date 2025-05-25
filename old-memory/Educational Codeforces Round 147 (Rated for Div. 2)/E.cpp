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
int k;
string s;
vector<int>stk;
ll ans;
void solve(){
    stk.clear();
    ans=0;
    int n=s.size();
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<n;i++){
        if(s[i]=='(')stk.push_back(i);
        else {
            int temp=(i-stk.back()-1)/2;
            q.push(temp);
            if(q.size()>k)q.pop();
            stk.pop_back();
            ans+=temp;
        }
    }
    while(!q.empty()){
        ans-=q.top();
        q.pop();
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>k>>s;
        solve();
        
    }

    return 0;
}