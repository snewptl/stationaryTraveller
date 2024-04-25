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
const int maxn=3e5+5;
const double eps=1e-10;
int n,a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        int ans=1;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int pre=0;
        for(int i=1;i<n;i++){
            if(a[i+1]>a[i]){
                if(pre==0)pre=1,ans++;
                else if(pre==-1)pre=1,ans+=1;
            }
            else if(a[i+1]<a[i]){
                if(pre==0)pre=-1,ans++;
                else if(pre==1)pre=-1,ans+=1;
            }
        }
        cout<<ans<<'\n';
    }   

    return 0;
}