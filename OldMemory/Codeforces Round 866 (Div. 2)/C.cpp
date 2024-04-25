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
int n,a[maxn];        
int m;
map<int,int>mp;
bool solve(){
    if(mp.count(m+1)){
        int pre=1,nxt=n;
        for(int i=1;i<=n;i++)if(a[i]==m+1){
            pre=i;break;
        }
        for(int i=n;i>=1;i--)if(a[i]==m+1){
            nxt=i;break;
        }
        for(int i=pre;i<=nxt;i++){
            if(mp[a[i]]==1&&a[i]<m)return false;
            else mp[a[i]]--;
        }
        return true;
    }    
    else {
        for(auto it:mp){
            if(it.second>=2||it.first>m)return true;
        }
        
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(int i=0;i<=n+1;i++)if(!mp.count(i)){
            m=i;break;
        }
        if(solve())cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}