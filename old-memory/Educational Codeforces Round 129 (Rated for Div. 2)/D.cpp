#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll x,dp[2][2005];
int check(ll cur){
	int res=0;
	while(cur){
		res|=1<<(cur%10);
		cur/=10;
	}
	return res;
}
int getlen(ll cur){
	int res=0;
	while(cur){
		res++;
		cur/=10;
	}
	return res;
}
map<ll,int>mp;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&x);
		int dep=-1;
		mp.clear();
		if(getlen(x)==n)printf("0\n");
		else {
			queue<ll>q;
			q.push(x);
			mp[x]=0;
			while(!q.empty()){
				ll p=q.front();q.pop();
				if(getlen(p)>=n){
					dep=mp[p];
					break;
				}
				int cur=check(p);
				for(int i=0;i<10;i++){
					if(cur&(1<<i)){
						ll temp=p*i;
						if(!mp.count(temp)){
							mp[temp]=mp[p]+1;
							q.push(temp);
						}
					}
				} 
			}
		}
		printf("%d\n",dep);
	}


	return 0;
}