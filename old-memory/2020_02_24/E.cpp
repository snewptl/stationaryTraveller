#include<bits/stdc++.h>
using namespace std;
int T,maxd;
int n,d,cnt,sumx,flag,tot;
const int maxn=5005;
int ans[maxn];
int pa[maxn];
int init[maxn];
void dfs(int dep,int cnt){
    if(sumx==d&&tot==n){flag=1;maxd=max(maxd,dep);return;}
    if(sumx==d||tot==n)return;
    if(init[n-tot+dep]-init[dep]<d-sumx)return;
    for(int i=cnt*2;i>=1;i--){
        if(flag)return;
        if(i+tot>n)continue;
        sumx+=dep*i;
        tot+=i;
        ans[dep+1]=i;
        dfs(dep+1,i);
        sumx-=dep*i;
        tot-=i;
    }
}
int main(){
    scanf("%d",&T);
    for(int i=1;i<=5000;i++)init[i]=i-1;
    for(int i=2;i<=5000;i++)init[i]+=init[i-1];
    while(T--){
        cnt=0;sumx=0;flag=0,tot=1;maxd=1;
        scanf("%d%d",&n,&d);
        ans[1]=1;
        dfs(1,1);
        if(flag){
            printf("YES\n");
            int t=0;int sum=0;
            for(int i=2;i<=maxd;i++){
                int st=sum+1,tmp=0;
                for(int j=1;j<=ans[i];j++){
                    if(tmp==2){st++;tmp-=2;}
                    pa[sum+ans[i-1]+j]=st;
                    tmp++;
                }
                sum+=ans[i-1];
            }
            for(int i=2;i<=n;i++)printf("%d ",pa[i]);
            printf("\n");            
        }
        else printf("NO\n");
    }

    return 0;
}