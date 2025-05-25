#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=1e9+7;
int n,q;
int pri[maxn];
void init(){
	for(int i=2;i<maxn;i++){
		if(!pri[i]){
			pri[i]=i;
			if(i>1e3)continue;
			for(int j=i*i;j<maxn;j+=i)
				if(!pri[j])pri[j]=i;
		}
	}
}
map<int,int>mem[maxn];
multiset<int>s[maxn];
int pre[maxn];
ll ans=1;
void add(int p,int x){
	while(x!=1){
		int mn=pri[x],cnt=0;
		while(pri[x]==mn)x/=mn,cnt++;
		if(mem[p][mn]){
			s[mn].erase(s[mn].find(mem[p][mn]));//不能使用erase
		}
		mem[p][mn]+=cnt;
		s[mn].insert(mem[p][mn]);
		int ed=*s[mn].begin();
		if(s[mn].size()==n){
			for(int i=pre[mn]+1;i<=ed;i++)
				ans*=mn,ans%=mod;		
			pre[mn]=ed;	
		}

	}
}
int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(i,x);
	}
	while(q--){
		int p,x;
		scanf("%d%d",&p,&x);
		add(p,x);
		printf("%d\n",ans);
	}
	return 0;
}