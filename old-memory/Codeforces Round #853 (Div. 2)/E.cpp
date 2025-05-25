#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef double db;
typedef long double ldb;
const ll mod=998244353;
const int maxs=1e7+5;
const int maxn=1e6+5;
const double eps=1e-10;
int n,s[maxn],d[maxs],pre[maxs];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++)cin>>s[i],pre[s[i]]++;
        for(int i=1;i<=n;i++)d[s[n]/__gcd(s[i],s[n])]++;
        for(int i=1;i*i<=s[n];i++){
            if(s[n]%i)continue;
            for(int j=1;j*j<=i;j++){
                if(i%j)continue;
                ans+=1ll*d[j]*i;
                if(j*j!=i)ans+=1ll*d[i/j]*i;
                ans%=mod;
            }
            if(s[n]/i==i)continue;
            for(int j=1;j*j<=s[n]/i;j++){
                if(s[n]/i%j)continue;
                ans+=1ll*d[j]*s[n]/i;
                if(j*j!=s[n]/i)ans+=1ll*d[s[n]/i/j]*s[n]/i;
                ans%=mod;
            }
        }
        for(int i=1;i<=s[n];i++)pre[i]+=pre[i-1];
        for(int i=1,j;i<=s[n];i=j+1){
            j=s[n]/(s[n]/i);
            ll sum=1ll*(i+j)*(j-i+1)/2%mod;
            if(s[n]%j==0)(sum-=j)%=mod;
            int k=s[n]/i;
            for(int t=1;t<=min(k-1,s[n]/k);t++){
                ans+=sum*(pre[min(t*k+t,s[n])]-pre[t*k-1])%mod;
                // cout<<i<<" "<<j<<" "<<k<<" "<<t*k+t<<" "<<t*k-1<<"#\n";
                ans%=mod;
            }
            if(k-1<s[n]/k){
                ans+=sum*(pre[s[n]]-pre[(k-1)*k+(k-1)]);
                ans%=mod;
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=s[n];i++)pre[i]=0,d[i]=0;
    }

    return 0;
}
/*
1
4
1 2 7 9
*/