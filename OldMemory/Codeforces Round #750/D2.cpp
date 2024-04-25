#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,tot;
int a[maxn];
int vis[maxn];
int pre[maxn];
int cnt[maxn];
map<int,int>mp;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)vis[i]=0,pre[i]=0;
		for(int i=1;i<=tot;i++)cnt[i]=0;
		tot=0;
		mp.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!mp[a[i]])mp[a[i]]=++tot;
			cnt[mp[a[i]]]++;
		}
		for(int i=1;i<=n;i++){
			int idx=mp[a[i]];
			if(pre[idx]){
				vis[i]=-1;
				cnt[idx]--;
				pre[idx]=0;
			}
			else if(cnt[idx]>3){
				vis[i]=1;
				cnt[idx]--;
				pre[idx]=1;
			}
		}
		ll sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			sum+=a[i];
		}
		int pos=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(sum!=a[i]){
				pos=i;break;
			}
		}
		ll res=1ll*(sum-a[pos])*a[pos];
		ll x,y;
		x=res/(sum-a[pos]);
		y=res/a[pos];
		if(y*a[pos]==x*(sum-a[pos]))y=-y;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				printf("%d ",vis[i]);
				continue;
			}
			if(i==pos)printf("%d ",y);
			else printf("%d ",x);
		}
		printf("\n");
	}


	return 0;
}