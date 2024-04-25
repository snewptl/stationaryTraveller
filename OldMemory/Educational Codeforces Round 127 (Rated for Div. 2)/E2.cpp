#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,len;
char s[maxn];
ll sz[maxn];
string dfs(int x){
	if(x>len){
		sz[x]=1;
		return "";
	}
	string pre="",nxt="";
	pre=dfs(x*2);
	nxt=dfs(x*2+1);
	if(pre>nxt)swap(pre,nxt);
	if(pre==nxt)sz[x]=sz[x*2]*sz[x*2+1]%mod;
	else sz[x]=sz[x*2]*sz[x*2+1]*2%mod;
	return s[x]+pre+nxt;
}
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		len=(1<<n)-1;
		dfs(1);
		printf("%lld\n",sz[1]);
	}


	return 0;
}