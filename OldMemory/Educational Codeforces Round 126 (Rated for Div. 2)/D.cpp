#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=3e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
ll a[maxn];
ll vis[maxn];
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ll pre=0,sum=0,ans=0;
		for(int i=n;i>=1;i--){
			a[i]-=sum;
			if(i>=k){
				ll t=0;
				if(a[i]>0)t=(a[i]-1)/k+1;
				
				vis[i]=t;
				ans+=t;
				sum+=t*k;

				pre+=t;				
			}
			else {
				ll t=0;
				if(a[i]>0)t=(a[i]-1)/i+1;

				vis[i]=t;
				ans+=t;
				sum+=t*i;

				pre+=t;
			}
			if(i+k<=n)pre-=vis[i+k];
			sum-=pre;
		}	
		printf("%lld\n",ans);
	}


	return 0;
}