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
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>s;
        int n=s.size();
        int flag=1;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i])flag=0;
        }
        int eq=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1])eq=0;
        }
        int ans=n;
        if(flag)ans=n-1;
        if(eq)ans=-1;
        cout<<ans<<'\n';
    }

    return 0;
}