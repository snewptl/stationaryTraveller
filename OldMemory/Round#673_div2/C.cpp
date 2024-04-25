#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,a[maxn],cnt[maxn],ans[maxn],nxt[maxn],len[maxn],to[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(nxt,0,sizeof(nxt));
        memset(len,0,sizeof(len));
        memset(to,0x3f3f3f3f,sizeof(to));
        memset(ans,-1,sizeof(ans));
        for(int i=1;i<=n;i++){
            len[a[i]]=max(len[a[i]],i-nxt[a[i]]);
            to[a[i]]=min(n+1-i,to[a[i]]);
            nxt[a[i]]=i;
        }
        for(int i=1;i<=n;i++)len[i]=max(len[i],to[i]);
        int ed=n+1;
        for(int i=1;i<=n;i++){
            for(int j=ed-1;j>=len[i];j--){
                ans[j]=i;
            }
            ed=min(len[i],ed);
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }


    return 0;
}