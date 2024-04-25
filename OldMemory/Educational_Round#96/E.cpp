#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char s[maxn],vis[maxn];
int nxt[maxn],r[27];
ll ans;
int t[maxn*4],lazy[maxn*4];
void push_down(int rt){
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
}
void update(int rt,int l,int r,int xl,int xr){
    int mid=l+r>>1;
    if(l>=xl&&r<=xr){
        lazy[rt]++;return;
    }
    if(lazy[rt])push_down(rt);
    update(rt<<1,l,mid,xl,xr);
    update(rt<<1|1,mid+1,r,xl,xr);
}
int main(){
    scanf("%d%s",&n,s);
    for(int i=0;i<=26;i++)r[i]=n;
    for(int i=n-1;i>=0;i--){
        nxt[i]=r[s[i]-'a'];
        r[s[i]-'a']=i;
    }
    for(int i=0,j=n-1;i<n;i++,j--){
        vis[i]=s[j];
    }
    for(int i=0;i<n;i++){
        int xl=i,xr=r[vis[i]-'a'];
        ans+=1LL*(r[vis[i]-'a']-i);
        if(vis[i]!=s[i]){
            r[s[i]]++;
            
        }
        // if(r[vis[i]-'a']>i)
        //     update(0,0,n-1,i,r[vis[i]-'a']-1);
        r[vis[i]-'a']=nxt[r[vis[i]-'a']];
    }
    // printf("%lld\n",ans);
    return 0;
}