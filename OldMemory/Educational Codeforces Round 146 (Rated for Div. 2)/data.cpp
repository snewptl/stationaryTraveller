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
int n,k,T;
int f[maxn],d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    T=rand()%100+1;
    n=rand()%3000+1,k=rand()%1500;
    for(int i=1;i<=n;i++)f[i]=rand()%2000+1;
    for(int i=1;i<=n;i++)d[i]=rand()+1;
    cout<<T<<'\n';
    cout<<n<<" "<<k<<'\n';
    for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    return 0;
}