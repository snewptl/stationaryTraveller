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
const int maxn=1e3+5;
const double eps=1e-10;
int n,k,a[maxn][maxn],vis[maxn][maxn];
int inv(int x,int y){
    vis[n-x+1][n-y+1]=1;
    return a[n-x+1][n-y+1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j],vis[i][j]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j])break;
                if(a[i][j]!=inv(i,j))ans++;
            }
        }
        if(k<ans)cout<<"NO\n";
        else if((k-ans)%2&&n%2==0)cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}