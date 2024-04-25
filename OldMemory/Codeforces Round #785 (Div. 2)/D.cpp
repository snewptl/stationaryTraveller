#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
map<ll,int>mp;
struct seq{
	ll bg,dif,n;
};
ll ans;
int flag;
void init(){
	flag=1;
	ans=0;
	mp.clear();
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		seq b={x,y,z-1};
		scanf("%lld%lld%lld",&x,&y,&z);
		seq c={x,y,z-1};		
		init();
		seq a={0,0,0};
		if(c.dif%b.dif!=0);
		else {
			if(c.bg<b.bg);
			else if(c.bg+c.n*c.dif>b.bg+b.n*b.dif);
			else {
				if((c.bg-b.bg)%b.dif!=0);
				else {
					for(ll i=1;i*i<=b.dif;i++){
						if(b.dif%i!=0)continue;
						a.dif=c.dif/b.dif*i;
						if(mp[a.dif])continue;
						mp[a.dif]=1;
						if(i==__gcd(a.dif,b.dif)){
							ll com=c.dif;
							if(c.bg-com<b.bg)flag=0;
							if(c.bg+c.n*c.dif+com>b.bg+b.n*b.dif)flag=0;
							ans+=(com/a.dif)*(com/a.dif);
							ans%=mod;									
						}
						a.dif=c.dif/i;
						if(mp[a.dif])continue;
						mp[a.dif]=1;
						if(b.dif/i==__gcd(a.dif,b.dif)){
							ll com=c.dif;
							if(c.bg-com<b.bg)flag=0;
							if(c.bg+c.n*c.dif+com>b.bg+b.n*b.dif)flag=0;
							ans+=(com/a.dif)*(com/a.dif);
							ans%=mod;									
						}
					}

				}
			}
		}
		if(flag)printf("%lld\n",ans);
		else printf("-1\n");
	}


	return 0;
}