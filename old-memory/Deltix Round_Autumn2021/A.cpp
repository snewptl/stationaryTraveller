#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[20];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int mx=0,cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			while(a[i]%2==0){
				cnt++;
				a[i]/=2;
			}
			mx=max(mx,a[i]);
		}
		ll res=mx*(1ll<<cnt);
		for(int i=1;i<=n;i++){
			if(a[i]==mx){
				mx=0;
				continue;
			}
			res+=a[i];
		}
		printf("%lld\n",res);
	}


	return 0;
}