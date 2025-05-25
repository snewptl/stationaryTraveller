#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6;
const int maxs=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int pri[maxn],vis[maxn];
int a[maxs];
int tot,n,e;
ll ans;
void get_pri(){
	vis[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!vis[i])pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<=maxn;j++){
			vis[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main(){
	get_pri();
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&e);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		for(int i=1;i<=e;i++){
			int lst=0,cur=0;
			ll res=0;
			for(int j=i;j<=n;j+=e){
				if(a[j]==1){
					cur++;
					if(j+e>n){
						res+=1ll*cur*lst;
					}
				}
				else if(!vis[a[j]]){
					res+=1ll*cur*lst;
					res+=cur;
					cur++;
					lst=cur;
					cur=0;
				}
				else {
					res+=1ll*cur*lst;
					lst=0;
					cur=0;
				}
			}
			ans+=res;
		}
		printf("%lld\n",ans);
	}


	return 0;
}