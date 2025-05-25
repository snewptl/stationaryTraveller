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
int n,a[maxn];
map<int,int>mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=2;j*j<=a[i];j++){
                while(a[i]%j==0)a[i]/=j,mp[j]++;
            }
            if(a[i]!=1)mp[a[i]]++;
        }
        int ans=0,rem=0;
        for(auto it:mp){
            ans+=it.second/2;
            rem+=it.second%2;
        }
        ans+=rem/3;
        cout<<ans<<'\n';

    }

    return 0;
}