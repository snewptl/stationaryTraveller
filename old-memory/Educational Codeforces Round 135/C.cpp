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
int n;
int a[maxn],b[maxn];
map<int,int>vis;
int check(int x){
    int res=0;
    while(x){
        x/=10;
        res++;
    }
    return res;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        vis.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            vis[b[i]]--;
        }
        int ans=0;
        for(auto it:vis){
            if(it.first>=10){
                ans+=abs(it.second);
                vis[check(it.first)]+=it.second;
            }
        }
        for(auto it:vis){
            if(it.first<10&&it.first>1){
                ans+=abs(it.second);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}