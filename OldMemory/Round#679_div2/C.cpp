#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+2;
struct Node{
    int num,id;
}b[maxn*6];
int a[maxn],n,cnt,x,ans,tot[maxn],pos,le;
bool cmp(Node a,Node b){
    return a.num==b.num?a.id<b.id:a.num<b.num;
}
int main(){
    for(int i=1;i<=6;i++)scanf("%d",&a[i]);
    cnt=0;ans=1e9+10;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        for(int j=1;j<=6;j++){
            b[++cnt].num=x-a[j];
            b[cnt].id=i;
        }
        tot[i]=6;
    }
    sort(b+1,b+cnt+1,cmp);
    for(pos=cnt;pos;pos--){
        if(tot[b[pos].id]==1)break;
        tot[b[pos].id]--;
    }
    ans=min(ans,b[pos].num-b[1].num);
    for(int i=2;i<=cnt;i++){
        tot[b[i-1].id]--; 
        while(pos<=cnt&&!tot[b[i-1].id])pos++,tot[b[pos].id]++;
        if(pos>cnt)break;
        ans=min(ans,b[pos].num-b[i].num);
    }
    printf("%d\n",ans);

    return 0;
}