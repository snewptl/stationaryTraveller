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
int cnt[10];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cin>>s;
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'0']++;
        }
        int mx=0,n=s.size();
        for(int i=0;i<10;i++)mx=max(mx,cnt[i]);
        if(n==1)cout<<"1\n";
        else if(n==mx)cout<<"-1\n";
        else if(mx<=n-mx+1)cout<<n<<'\n';
        else {
            int ans=2*(n-mx)+1;
            int temp=mx-(n-mx+1);
            ans+=temp*2;
            if(temp%2)ans++;
            cout<<ans<<'\n';
        }
    }

    return 0;
}