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
        int ans=1;
        if(s[0]=='?')ans*=9;
        for(int i=1;i<s.size();i++)if(s[i]=='?')ans*=10;
        if(s[0]=='0')ans=0;
        cout<<ans<<'\n';
    }

    return 0;
}