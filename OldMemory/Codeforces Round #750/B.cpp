#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		ll ans=0;
		int cnt0=0,cnt1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt0++;
			if(a[i]==1)cnt1++;
		}
		printf("%lld\n",(1ll<<cnt0)*1ll*cnt1);
	}


	return 0;
}