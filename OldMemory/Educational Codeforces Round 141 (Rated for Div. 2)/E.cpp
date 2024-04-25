#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int pre[maxn];
int n,a[maxn],b[maxn];
int vis[maxn];
void solve(){
    // for(int i=1;i*i<=n;i++){
    //     int flag=1;
    //     for(int j=1;j<=n;j++){
    //         if(a[j]/i>b[j]/i)flag=0;
    //     }
    //     if(flag)vis[i]=1;
    // }
    for(int i=1;i<=n;i++){
        if(a[i]<=b[i])pre[1]+=1,pre[n+1]-=1;
        else {
            for(int l=1,r;l<=a[i];l=r+1){
                r=a[i]/(a[i]/l);
                int temp=b[i]/(a[i]/l);
                if(l<=temp){
                    pre[l]+=1,pre[temp+1]-=1;
                }
            }
            pre[a[i]+1]+=1,pre[n+1]-=1;            
        }

    }
    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
        if(pre[i]>=n)vis[i]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(vis[i])cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)if(vis[i])printf("%d ",i);
    puts("");
}
void init(){
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=0;i<=n+1;i++)pre[i]=0;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]--;
        for(int i=1;i<=n;i++)scanf("%d",&b[i]),b[i]--;
        solve();
	}


	return 0;
}