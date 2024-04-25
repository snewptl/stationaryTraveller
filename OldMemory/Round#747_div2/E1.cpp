#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
ll f[100];
int n;
ll quick_pow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		y/=2;
		x*=x,x%=mod;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	f[1]=6;
	ll inv6=quick_pow(6,mod-2);
	for(int i=2;i<=n;i++){
		f[i]=inv6*inv6%mod*f[i-1]%mod*f[i-1]%mod*(4*6+6*4+24*2)%mod;
		f[i]%=mod;
	}
	printf("%lld\n",f[n]);


	return 0;
}