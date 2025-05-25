#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=1e9+7;
const double eps=1e-10;
ll f[100];
unordered_map<ll,int>mp;
int sz[maxn];
priority_queue<ll,vector<ll>,less<ll>>q;
int n,k,tot,vis[maxn];
ll mi[65],inv6;
ll dp[maxn][10];
ll quick_pow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		y/=2;
		x*=x,x%=mod;
	}
	return res;
}
void init(){
	f[1]=6;
	inv6=quick_pow(6,mod-2);
	for(int i=2;i<=60;i++){
		f[i]=inv6*inv6%mod*f[i-1]%mod*f[i-1]%mod*(4*6+6*4+24*2)%mod;
		f[i]%=mod;
	}	
	mi[0]=1;
	for(int i=1;i<=60;i++)mi[i]=mi[i-1]*2;
}
int find(ll x){
	for(int i=1;i<=60;i++){
		ll l=mi[i-1],r=mi[i]-1;
		if(x>=l&&x<=r)return i;
	}
	return k;
}
int main(){
	init();
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++){
		char s[10];ll cur;
		scanf("%lld%s",&cur,s);
		mp[cur]=++tot;
		q.push(cur);
		if(s[0]=='w')vis[tot]=1;
		if(s[0]=='y')vis[tot]=6;
		if(s[0]=='g')vis[tot]=2;	
		if(s[0]=='b')vis[tot]=5;
		if(s[0]=='r')vis[tot]=3;
		if(s[0]=='o')vis[tot]=4;
	}
	while(!q.empty()){
		ll p=q.top();
		q.pop();
		int dep=find(p),rk=mp[p];
		if(dep==k){
			dp[rk][vis[rk]]=1;
		}
		else {
			if(!mp[p*2+1]){
				mp[p*2+1]=++tot;
				vis[tot]=7;
				for(int i=1;i<=6;i++){
					dp[tot][i]=inv6*f[k-dep]%mod;

				}						
			}		
			if(!mp[p*2]){
				mp[p*2]=++tot;
				vis[tot]=7;
				for(int i=1;i<=6;i++){
					dp[tot][i]=inv6*f[k-dep]%mod;
				}						
			}			
			int le=mp[p*2+1],ri=mp[p*2];
			if(vis[le]==7)swap(le,ri);
			if(vis[rk]){
				for(int i=1;i<=6;i++){
					if(i==vis[rk]||i==7-vis[rk])continue;
					for(int j=1;j<=6;j++){
						if(j==vis[rk]||j==7-vis[rk])continue;
						dp[rk][vis[rk]]+=dp[le][i]*dp[ri][j]%mod;
						dp[rk][vis[rk]]%=mod;
					}
				}
			}
			else {
				for(int t=1;t<=6;t++){
					for(int i=1;i<=6;i++){
						if(i==t||i==7-t)continue;
						if(vis[ri]==7){
							dp[rk][t]+=dp[le][i]*4%mod*dp[ri][1]%mod;
						}
						else {
							for(int j=1;j<=6;j++){
								if(j==t||j==7-t)continue;
								dp[rk][t]+=dp[le][i]*dp[ri][j]%mod;
								dp[rk][t]%=mod;
							}
						}
						
					}						
				}
			}					
		}

		ll nxt=p/2;
		if(!mp[nxt]){
			mp[nxt]=++tot;
			q.push(nxt);
		}
	}
	ll ans=0;
	for(int i=1;i<=6;i++)ans+=dp[mp[1]][i],ans%=mod;
	printf("%lld\n",ans);


	return 0;
}
