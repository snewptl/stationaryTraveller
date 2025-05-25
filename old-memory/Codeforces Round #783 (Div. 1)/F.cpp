#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,flag,rt,pa;
vector<int>e[maxn];
vector<pii>fin;
int dp[maxn],in[maxn],nxt[maxn];
void init(){
	for(int i=1;i<=n;i++){
		e[i].clear();	
		in[i]=0;
		nxt[i]=0;
	}
	fin.clear();
	flag=1;
}
void print(int p,int u){
	fin.push_back({p,u});
	if(nxt[u])print(u,nxt[u]);
}
void dfs(int u,int p){
	int cnt[2],sz=1;
	memset(cnt,0,sizeof(cnt));
	vector<int>opt[2];
	for(auto v:e[u]){
		if(v==p)continue;
		dfs(v,u);
		cnt[dp[v]]++;
		sz++;
		opt[dp[v]].push_back(v);
	}
	int temp=min(cnt[0],cnt[1]);
	cnt[0]-=temp,cnt[1]-=temp;
	if(sz%2){
		for(int i=1;i<=temp;i++){
			for(auto j:vector<int>({0,1})){
				print(u,opt[j].back());
				opt[j].pop_back();
			}
		}		
	}
	else {
		for(int i=1;i<=temp;i++){
			for(auto j:vector<int>({1,0})){
				print(u,opt[j].back());
				opt[j].pop_back();
			}
		}				
	}
	if(cnt[1]){
		if(sz%2==0){
			cnt[1]--;	
			print(u,opt[1].back());
			opt[1].pop_back();		
		}	
		if(cnt[1]>=2)flag=0;
		else if(cnt[1]==1)dp[u]=0,nxt[u]=opt[1].back();
		else dp[u]=0;
	}
	else if(cnt[0]){
		if(sz%2==1){
			cnt[0]--;
			print(u,opt[0].back());
			opt[0].pop_back();
		}			
		if(cnt[0]>=2)flag=0;
		else if(cnt[0]==1)dp[u]=1,nxt[u]=opt[0].back();
		else dp[u]=1;
	}
	else dp[u]=(sz%2)^1;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			in[u]++,in[v]++;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==1){
				pa=i;
				for(auto v:e[i]){
					rt=v;
				}
				break;
			}
		}
		dfs(rt,pa);
		if(dp[rt]==1)flag=0;
		print(pa,rt);
		if(flag){
			puts("YES");
			for(auto it:fin){
				printf("%d %d\n",it.first,it.second);
			}
		}
		else puts("NO");
	}


	return 0;
}

