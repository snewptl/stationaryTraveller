#include<bits/stdc++.h>
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
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        int ans=2e9;
        for(int i=1,j;i<=max(a,b);i=j+1){
            if(a/i==0)j=b/(b/i);
            else j=min(a/(a/i),b/(b/i));
            int temp1=(a+i-1)/i+(b+i-1)/i+i-1;
            int temp2=(a+j-1)/j+(b+j-1)/j+j-1;
            ans=min(min(temp1,temp2),ans);
            // cout<<i<<" "<<temp<<'\n';
            // ans=min((a+i-1)/i+(b+i-1)/i+i-1,ans);
        }
        cout<<ans<<'\n';
    }

    return 0;
}