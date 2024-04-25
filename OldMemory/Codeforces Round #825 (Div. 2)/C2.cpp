#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],pre[maxn];
ll res,ans[maxn];
int head,tail,h[maxn*3];
vector<pii>qu[maxn];
int q;
void init(){
    for(int i=1;i<=n;i++)qu[i].clear();
    for(int i=1;i<=n*3;i++)h[i]=0;
    head=1,tail=0;
}
int len(){
    return tail-head+1;
}
void solve(){
    ll sum=0,base=0,cnt=0;
    tail=n+2;
    for(int i=n;i>=1;i--){
        while(len()<n+2){
            h[tail+1]=h[tail]-cnt,tail++;
        }
        sum-=pre[i];
        for(auto it:qu[i]){
            int x=it.first,idx=it.second;
            x=min(pre[i-1]+1,x);
            ans[idx]=h[head+x-1]+sum+cnt*x;
        }
        head++;
        sum+=cnt;
        cnt++;
    }
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        pre[1]=1;
        res=pre[1];
        for(int i=2;i<=n;i++){
            pre[i]=min(pre[i-1]+1,a[i]);
            res+=pre[i];
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int p,x;
            scanf("%d%d",&p,&x);
            qu[p].push_back({x,i});
        }
        solve();
        for(int i=1;i<=q;i++){
            printf("%lld\n",ans[i]+res);
        }
	}


	return 0;
}