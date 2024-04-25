#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int maxn=4e5+10;
int n;
map<pll,int>mp;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int last,ans,cnt,dep[maxn],sz[maxn],vis[maxn],fa[maxn],mem[maxn],mk[maxn];
vector<pii>e[maxn];
void dfs1(int u){
	for(auto x:e[u]){
		int v=x.first;
		sz[u]++;
		if(dep[v])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;dfs1(v);
		sz[u]+=sz[v];
		
	}
}
void dfs2(int u){
	mk[u]=1;
	for(auto x:e[u]){
		int v=x.first,num=x.second;
		if(!mk[v]&&dep[v]==dep[u]+1)dfs2(v);
	}
	for(auto x:e[u]){
		int v=x.first,num=x.second;
		if(dep[v]<=dep[u])continue;
		if(vis[num])continue;
		vis[num]=1;
		if(mem[v]){
			printf("%d %d\n",mem[v],num);
			mem[v]=0;
		}
		else if(last){
			printf("%d %d\n",last,num);
			last=0;
		}
		else last=num;
	}
	if(last){
		mem[u]=last;last=0;
	}
}
int main(){
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ll x1=1LL*(a+b)*d,y1=1LL*b*c;
		ll x2=1LL*a*d,y2=1LL*b*(c+d);
		ll d1=gcd(x1,y1),d2=gcd(x2,y2);
		x1/=d1,y1/=d1;x2/=d2,y2/=d2;
		if(!mp.count({x1,y1}))mp[{x1,y1}]=++cnt;
		if(!mp.count({x2,y2}))mp[{x2,y2}]=++cnt;
		int u=mp[{x1,y1}],v=mp[{x2,y2}];
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	for(int i=1;i<=cnt;i++){
		if(dep[i])continue;
		dep[i]=1;dfs1(i);
		ans+=sz[i]/2/2;
	}
	printf("%d\n",ans);
	for(int i=1;i<=cnt;i++){
		if(dep[i]!=1)continue;
		last=0;
		dfs2(i);
	}
    return 0;
}