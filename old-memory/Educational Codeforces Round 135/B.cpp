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
int main(){
    int T=1;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n%2){
            n-=2;
            printf("1 ");
            for(int i=1;i<=n/2;i++){
                printf("%d %d ",i+n/2+1,i+1);
            }
            printf("%d %d\n",n+1,n+2);
        }
        else {
            n-=2;
            for(int i=1;i<=n/2;i++){
                printf("%d %d ",i+n/2,i);
            }
            printf("%d %d\n",n+1,n+2);
        }
    }

    return 0;
}