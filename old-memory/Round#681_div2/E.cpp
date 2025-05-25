#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,q;
int opt,xx,l,r,k;
int a[maxn],vis[25];
ll mi[55],sum;
void query(){
    ll ans=0;
    if(r<=k)ans=1LL*(r+l)*(r-l+1)/2;
    else {
        if(l<=k){
            ans+=1LL*(k+l)*(k-l+1)/2;
            for(int i=k+1;i<=r;i++)ans+=1LL*a[i];
        }
        else {
            for(int i=l;i<=r;i++)ans+=1LL*a[i];
        }
    }
    printf("%lld\n",ans);
}
void update(){
    if(sum==1)return;
    int pos=20;ll x=sum;
    priority_queue<int>q;
    for(int i=1;i<=20;i++)q.push(i);
    while(!mi[pos]||x<mi[pos])pos--;
    while(pos){
        if(!pos)break;
        int tmp=x/mi[pos];
        vis[pos]=tmp;
        for()
        x%=mi[pos];
        pos--;
    }
}
int main(){
    // scanf("%d%d",&n,&q);
    // for(int i=1;i<=n;i++)a[i]=i;
    mi[0]=1;
    for(int i=1;i<=50;i++){
        mi[i]=mi[i-1]*i;
        if(mi[i]>2e10)break;
    }
    printf("%lld",mi[15]);
    k=n-20+1;
    for(int i=1;i<=q;i++){
        
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&l,&r);
            query();
        }
        else {
            scanf("%d",&xx);
            sum+=1LL*xx;
            update();
        }
    }


    return 0;
}