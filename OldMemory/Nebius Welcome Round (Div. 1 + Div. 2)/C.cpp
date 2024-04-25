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
int f[maxn],g[maxn];
int n,x,p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>x>>p;
        f[0]=x;
        int flag=0;
        for(int i=1;i<=min(2*n,p);i++){
            f[i]=(f[i-1]+i)%n;   
            if(f[i]==0)flag=1;
        }
        if(flag)cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }

    return 0;
}