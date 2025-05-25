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
int n,a[maxn];
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int mx=0,pos=0;
        for(int i=1;i<=n;i++){
            if(mx<a[i])pos=i;
            mx=max(mx,a[i]);

        }
        printf("%d\n",pos);
        
    }

    return 0;
}