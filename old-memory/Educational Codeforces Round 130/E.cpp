#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=105;
const ll mod=998244353;
const double eps=1e-10;
int n,fa[maxn],vis[maxn],used[maxn];
ll fac[maxn],dp[2][maxn];
pii a[maxn];
vector<pii>dis[maxn];
vector<int>cur,vec;
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
}
int getlen(int i,int j){
	return abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]={x,y};
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i].push_back({getlen(i,j),j});
		}
		sort(dis[i].begin(),dis[i].end());
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		memset(vis,0,sizeof(vis));
		queue<int>q;
		q.push(i);
		vis[i]=1;
		while(!q.empty()){
			int p=q.front();q.pop();
			int mn=dis[p][0].first;
			for(int j=0;j<dis[p].size();j++){
				int v=dis[p][j].second;
				if(dis[p][j].first==mn&&!vis[v])q.push(v),vis[v]=1;
			}			
		}
		int flag=1,cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				cnt++;
				for(int k=1;k<=n;k++){
					if(vis[k]){
						if(k!=j&&getlen(k,j)!=dis[j][0].first)flag=0;
					}
				}
				
			}
		}
		if(flag){
			for(int j=1;j<=n;j++){
				if(vis[j])used[j]=1;
			}
			vec.push_back(cnt);
		}
		else {
			vec.push_back(1);
		}
	}
	dp[0][0]=1;
	for(auto x:vec){
		for(int j=0;j<n;j++){
			if(j+x<=n)dp[1][j+x]+=dp[0][j];
			if(x!=1)dp[1][j+1]+=dp[0][j];
		}
		for(int j=0;j<=n;j++)dp[0][j]=dp[1][j]%mod,dp[1][j]=0;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll temp=1;
		for(int j=n;j>n-i;j--)
			temp*=j,temp%=mod;
		ans+=temp*dp[0][i],ans%=mod;
	}
	printf("%lld\n",ans);

	return 0;
}