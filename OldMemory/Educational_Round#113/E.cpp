#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;
ll k,a,h;
int cur[35][35];
int vis[35];
int flag;
ll mia[35],mi2[35];
void dfs(int rd,int dep,ll sum){
	if(flag)return;
	if(k<rd){
		sum=(sum+cur[rd-1][1]*a)%mod;
		if(sum==h){
			for(int i=1;i<=mi2[k];i++)printf("%d ",vis[i]);
			flag=1;
		}
		return ;
	}
	ll rk=mi2[k-rd]+1;
	if(dep>=rk){
		dfs(rd+1,1,sum);
		return;
	}
	ll temp1=cur[rd-1][dep*2-1],temp2=cur[rd-1][dep*2];
	cur[rd][dep]=temp1;
	vis[temp2]=rk;
	dfs(rd,dep+1,(sum+temp2*mia[rk])%mod);
	cur[rd][dep]=temp2;
	vis[temp1]=rk;
	dfs(rd,dep+1,(sum+temp1*mia[rk])%mod);
}
int main(){
    int T=1;
	mia[0]=mi2[0]=1;
	for(int i=1;i<=32;i++)mia[i]=mia[i-1]*a,mia[i]%=mod;
	for(int i=1;i<=32;i++)mi2[i]=mi2[i-1]*2,mi2[i]%=mod;
    while(T--){
		scanf("%lld%lld%lld",&k,&a,&h);
		for(int i=1;i<=(1<<k);i++)cur[0][i]=i;
		dfs(1,1,0);
		if(!flag)printf("-1");
    }

    return 0;
}