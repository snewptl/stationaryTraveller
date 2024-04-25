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
const int inf=1e9;
int n,m;
int ask(int x,int y){
    cout<<"? "<<x<<" "<<y<<'\n';
    cout.flush();
    int res;
    cin>>res;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        int mx=ask(1,1);
        int a=inf,b=inf;
        if(mx+1<=n)a=ask(mx+1,1);
        if(mx+1<=m)b=ask(1,mx+1);
        if(a<mx)cout<<"! "<<mx+1<<" "<<a+1<<'\n';
        else cout<<"! "<<b+1<<" "<<mx+1<<'\n';
        cout.flush();
    }

    return 0;
}