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
        s+='0';
        ll lst=-1;
        ll mx=0,ans=0;
        for(int i=0;i<=n;i++){
            if(s[i]=='0'){
                mx=max(mx,i-lst-1);
                lst=i;
            }
        }
        if(mx==n)ans=mx*mx;
        else {
            ans=(mx+1)/2*(mx+1-(mx+1)/2);
            
            ll pre=0,nxt=0;
            while(pre<n&&s[pre]=='1')pre++;
            while(nxt<n&&s[n-1-nxt]=='1')nxt++;
            int temp=max(pre,(pre+nxt+1)/2);
            ans=max(ans,temp*(pre+nxt-temp+1));
            if(pre&&nxt){
                ll l=0,r=pre-1;
                ans=max((nxt+1)*(r-l+1),ans);
                ans=max(ans,nxt+pre);
                for(int i=nxt+1;i<n;i++){
                    l++;
                    ans=max(ans,(i+1)*(r-l+1));
                    ans=max(ans,(i-nxt+1)*(pre+nxt-(i-nxt)));
                }
            }
        }
        cout<<ans<<'\n';


    }

    return 0;
}