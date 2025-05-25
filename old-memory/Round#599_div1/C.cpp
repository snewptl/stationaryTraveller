#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n[20],k;
ll a[20][maxn];
ll ave;
unordered_map<ll,int>mp;
ll sum[20];
int vis[20],to[20];
ll used[20];
vector<pair<ll,int>>opt[maxn];
int f[maxn];
int main(){
    int T=1;
    while(T--){
        scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d",&n[i]);
			for(int j=1;j<=n[i];j++){
				scanf("%lld",&a[i][j]);
				mp[a[i][j]]=i;
				sum[i]+=a[i][j];
				ave+=a[i][j];
			}	
		}
		if(ave%k)printf("NO\n");
		else {
			ave/=k;
			for(int i=1;i<=k;i++){
				if(sum[i]!=ave)continue;
				int now=1<<(i-1);
				f[now]=1;
				opt[now].push_back({a[i][1],i});
			}
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n[i];j++){
					int now=1<<(i-1);
					memset(vis,0,sizeof(vis));
					ll temp=ave-sum[i]+a[i][j];
					vis[i]=1;used[i]=a[i][j];
					int cur=mp[temp],flag=0,pre=i;
					while(!vis[cur]&&cur){
						now+=1<<(cur-1);
						vis[cur]=1;
						used[cur]=temp;
						to[cur]=pre;
						pre=cur;
						if(ave-sum[cur]+temp==a[i][j]){
							to[i]=cur;
							flag=1;break;
						}
						temp=ave-sum[cur]+temp;
						cur=mp[temp];
					}
					if(flag){
						if(f[now])continue;
						for(int t=1;t<=k;t++){
							if(vis[t])opt[now].push_back({used[t],to[t]});
						}
						f[now]=1;
					}
				}
			}	
			// for(int i=0;i<(1<<k);i++){
			// 	if(f[i]){
			// 		for(auto x:opt[i]){
			// 			printf("%lld %d\n",x.first,x.second);
			// 		}
			// 	}
			// }		
		}
    }


    return 0;
}