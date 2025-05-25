#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e4;
const ll mod=1<<32;
ll n,a,b,c,d;
ll pri[maxn];
ll vis[maxn];
int cnt;
void init() {
  for (int i=2;i<maxn;++i){
    if(!vis[i]){
      pri[cnt++]=i;
    }
    for(int j=0;j<cnt;++j) {
		if (1ll*i*pri[j]>=maxn)break;
		vis[i*pri[j]]=1;
		if(i%pri[i]==0)break;
    }
  }
  memset(vis,0,sizeof(vis));
}
void solve(){
	for(int i=1;i*maxn<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=0;j<=maxn;j++){
			if(i*maxn+j>n)break;
			for(int k=0;k<cnt;k++){
				if()
			}
		}
	}
}
int main(){
	init();
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	solve();
    return 0;
}