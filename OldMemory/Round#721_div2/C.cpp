#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
map<int,int>mp;
int n,a[maxn],cnt;
int l[maxn],r[maxn],pos[maxn];
ll sum0[maxn],sum1[maxn];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);cnt=0;
		for(int i=1;i<=n;i++)l[i]=0,r[i]=n,sum0[i]=0,sum1[i]=0;
		mp.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!mp.count(a[i])){
				mp[a[i]]=++cnt;
				pos[cnt]=i;
			}
			else l[i]=pos[mp[a[i]]],pos[mp[a[i]]]=i,r[l[i]]=i-1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(!l[i])continue;
			sum0[i]=l[i]+sum0[l[i]];
			sum1[i]=sum1[l[i]]+sum0[i];
			ans+=sum1[i]*(r[i]-i+1);
		}
		printf("%lld\n",ans);		
	}


    return 0;
}