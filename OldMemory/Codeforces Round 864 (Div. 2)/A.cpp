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
int n,m;
int check(int x,int y){
    int res=0;
    if(x+1<=n)res++;
    if(x-1>=1)res++;
    if(y+1<=m)res++;
    if(y-1>=1)res++;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;cin>>T;
    while(T--){
        cin>>n>>m;
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<min(check(x1,y1),check(x2,y2))<<'\n';
    }

    return 0;
}