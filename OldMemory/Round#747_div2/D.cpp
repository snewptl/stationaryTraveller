#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
char s[20];
struct node{
	int v,opt,tp;
};
vector<node>e[maxn];
int mk[maxn],vis[maxn],cnt,ans,flag[2];
stack<int>st;
void init(){
	for(int i=1;i<=n;i++){
		e[i].clear();
		vis[i]=0;
		mk[i]=0;
	}
	ans=flag[0]=flag[1]=0;
	while(!st.empty()){
		st.pop();
	}
}
void dfs(int u,int sgn){
	if(flag[sgn])return;
	st.push(u);vis[u]=1;
	if(!mk[u])cnt++;
	for(auto p:e[u]){
		int v=p.v,opt=p.opt,tp=p.tp;
		int temp;
		if(!tp){
			if(!mk[u]){
				temp=opt^1;
			}
			else temp=opt;
			if(vis[v]&&temp!=mk[v]){
				flag[sgn]=1;return;
			}			
		}
		else {
			if(mk[u]==opt)temp=1;
			else temp=0;
			if(vis[v]&&temp!=mk[v]){
				flag[sgn]=1;return;
			}
		}
		if(!vis[v]){
			mk[v]=temp;
			dfs(v,sgn);
		}
		
	}
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v,opt;
			scanf("%d%d%s",&u,&v,s);
			if(s[0]=='i')opt=0;
			else opt=1;
			e[u].push_back({v,opt,0});
			e[v].push_back({u,opt,1});
		}
		for(int i=1;i<=n;i++){
			if(flag[0]&&flag[1])break;
			flag[0]=flag[1]=0;
			if(vis[i])continue;
			int mx=0;
			mk[i]=0;cnt=0;
			dfs(i,0);
			if(!flag[0])mx=max(cnt,mx);
			while(!st.empty()){
				vis[st.top()]=0;st.pop();
			}
			mk[i]=1;cnt=0;
			dfs(i,1);
			if(!flag[1])mx=max(cnt,mx);
			ans+=mx;
			while(!st.empty()){
				st.pop();
			}
		}
		if(flag[0]&&flag[1])printf("-1\n");
		else printf("%d\n",ans);
	}


	return 0;
}