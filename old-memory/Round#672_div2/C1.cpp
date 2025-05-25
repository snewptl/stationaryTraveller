#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const ll inf=9e10;
int n,q;
ll a[maxn];
ll dfs(int l,int r,int p,int sgn){
    int mid=l+r>>1;
    if(sgn==1){
        ll ans=-inf;
        if(p==0)ans=0;
        if(l==r){
            if(p==0)return -2*inf;
            else return a[l];
        }
        for(int i=0;i<=1;i++){
            int k=sgn;if(i%2)k=-sgn;
            ans=max(ans,dfs(l,mid,i,sgn)+dfs(mid+1,r,(p-i+2)%2,k));
        }
    }
    if(sgn==-1){
        ll ans=inf;
        if(p==0)ans=0;
        if(l==r){
            if(p==0)return 2*inf;
            else return -a[l];
        }
        for(int i=0;i<=1;i++){
            int k=sgn;if(i%2)k=-sgn;
            ans=max(ans,-dfs(l,mid,i,sgn)-dfs(mid+1,r,(p-i+2)%2,k));
        }        
    }
    return ans;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        printf("%lld\n",max(dfs(1,n,0,1),dfs(1,n,1,-1));
    }


    return 0;
}