#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int head,h[maxn],cnt=1;
struct Edge{
    int v,nxt;
}e[maxn];
void add(int u,int v){
    e[cnt].v=v;
    e[cnt].nxt=h[u];
    h[u]=cnt++;
}
int n,sz[maxn],lf[maxn];
ll a[maxn],num[maxn],ans=1e18;
void dfs(int u){
    int flag=0;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs(v);
        lf[u]+=lf[v];
        num[u]+=num[v];
        flag=1;
    }
    if(!flag)lf[u]=1;
    
}
bool check(ll x,int u){
    if(lf[u]<(num[u]-1)/x+1)return false;
    for(int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!check(x,v))return false;
    }
    return true;
}
void get_ans(){
    ll l=1,r=ans;
    if(!num[1]){ans=0;return;}
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid,1)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
 
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int v;
        scanf("%d",&v);
        add(v,i);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        num[i]=a[i];
    }
    dfs(1);
    get_ans();
    printf("%lld\n",ans);
    return 0;
}