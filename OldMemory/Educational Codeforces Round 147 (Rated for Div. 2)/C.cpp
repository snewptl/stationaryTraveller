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
int n;
int query(int x){
    int res=0;
    while(x){
        x/=2;
        res++;
    }
    return res;
}
int solve(char ch){
    int lst=-1,res=0;
    for(int i=0;i<n;i++){
        if(s[i]==ch){
            res=max(query(i-lst-1),res);
            lst=i;
        }
    }
    res=max(query(n-lst-1),res);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>s;
        n=s.size();
        int ans=n;
        for(int i=0;i<26;i++){
            ans=min(ans,solve(i+'a'));
        }
        cout<<ans<<'\n';
    }

    return 0;
}