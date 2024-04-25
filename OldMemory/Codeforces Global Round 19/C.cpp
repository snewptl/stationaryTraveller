#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
ll cnt0,cnt1,ans,tot;
int n;
int a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int flag=0;
		ans=0;
		for(int i=2;i<n;i++){
			if(a[i]>=2)flag=1;
			ans+=(a[i]+1)/2;
		}
		if(!flag)ans=-1;
		if(n==3&&(a[2]%2==1))ans=-1;
		printf("%lld\n",ans);
	}


	return 0;
}