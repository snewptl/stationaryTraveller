#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxn=3e5+5;
const double eps=1e-10;
string s;
int pre[maxn],nxt[maxn],n;
int lst0[maxn],lst1[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>s;
        n=s.size();
        for(int i=0;i<n;i++)pre[i]=nxt[i]=0;
        for(int i=0;i<n;i++){
            if(i)pre[i]=pre[i-1];
            if(s[i]=='1')pre[i]++;
        }
        for(int i=n-1;i>=0;i--){
            if(i<n-1)nxt[i]=nxt[i+1];
            if(s[i]=='0')nxt[i]++;
        }
        int pos=-1;
        for(int i=0;i<n;i++){
            lst0[i]=pos;
            if(s[i]=='0')pos=i;
        }
        pos=n;
        for(int i=n-1;i>=0;i--){
            lst1[i]=pos;
            if(s[i]=='1')pos=i;
        }
        ll ans=1e18,inf=1e12;
        for(int i=-1;i<n;i++){
            ll temp=0,k=0;
            int le=-1,ri=-1;
            if(i>-1){
                le=lst0[i];
                if(s[i]=='0')le=i;
                if(le!=-1)
                    k=max(1ll*le-lst0[le]-1,k);
                temp+=pre[i]*(inf+1);                
            }
            if(i<n-1){
                ri=lst1[i+1];
                if(s[i+1]=='1')ri=i+1;
                if(ri!=n)
                    k=max(1ll*lst1[ri]-ri-1,k);
                temp+=nxt[i+1]*(inf+1);                
            }
            // cout<<i<<" "<<" "<<le<<" "<<lst0[le]<<'\n';
            ans=min(ans,temp-k);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
