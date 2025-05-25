#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
typedef long long ll;
const ll mod=1e9+7;
int n,b[maxn];
map<ll,ll>mp;
int main(){
    int T;scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
		mp.clear();
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		ll sum=1,k=-b[1]*1LL;mp[0]=1LL;
		for(int i=2;i<=n;i++){
			ll temp=sum;
			sum=sum*2-mp[k],sum%=mod;
			mp[k]=temp;
			k-=b[i];
		}
		printf("%lld\n",(sum+mod)%mod);
    }
    return 0;
}
