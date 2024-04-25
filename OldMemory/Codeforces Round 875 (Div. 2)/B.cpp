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
const int maxn=4e5+5;
const double eps=1e-10;
int n;
int mx[2][maxn],a[maxn],b[maxn];
int lst[maxn];
void update(int *mx,int *a){
    for(int i=1;i<=n*2;i++)lst[i]=0,mx[i]=0;
    for(int i=1;i<=n;i++){
        lst[i]=1;
        if(a[i-1]==a[i])lst[i]+=lst[i-1];
        mx[a[i]]=max(mx[a[i]],lst[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        update(mx[0],a);
        update(mx[1],b);
        int ans=0;
        for(int i=1;i<=n*2;i++){
            ans=max(ans,mx[0][i]+mx[1][i]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}