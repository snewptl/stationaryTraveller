#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,ans;
int m,cnt=0,a[100010],mx;
int bag[100],box[100];
int b[100],c[100];
bool find(int x){
    int pos=x,tot=0;
    int k=x;
    ll tep=1;
    int i=x-1;
    for(i=x-1;i>=0;i--){
        if(box[i]/tep){
            if(box[i]/tep>=2){box[i]-=2;return true;}
            else {box[i]-=tep;b[++tot]=i,c[tot]=tep;}
        }
        else tep*=2;
    }
    if(i<0)for(int j=1;j<=tot;j++)
        box[b[j]]+=c[j];
    while(!box[pos]&&pos<=mx){
        box[pos]++;
        pos++;
        ans++;
    }
    if(box[pos]){box[pos]--;return true;}
    return false;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        mx=-1;
        memset(bag,0,sizeof(bag));
        memset(box,0,sizeof(box));
        scanf("%lld%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            int t=a[i],sum=0;
            while(t>1){t/=2;sum++;}
            box[sum]++;
            mx=max(sum,mx);
        }
        ll tep=n;int pos=0;cnt=0;
        while(tep){
            if(tep%2)bag[cnt++]=pos;
            tep/=2;pos++;
        }
        int flag=1;ans=0;
        for(int i=0;i<cnt;i++){
            if(!find(bag[i])){flag=0;break;}
        }
        if(flag)printf("%lld\n",ans);
        else printf("-1\n");

    }

    return 0;
}