#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn],cnt[maxn];
ll sum,r,l,k,ans;
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=n;i>=1;i--)cnt[i]=cnt[i+1]+(!a[i]);
	if(abs(sum)>cnt[1]*k)puts("-1");
	else{
		for(int i=1;i<=cnt[1];i++){
			if(-sum+1ll*(cnt[1]-i)*k>=r)r+=min(1ll*k,-sum+1ll*(cnt[1]-i)*k-r);
		}
		l=-sum-r;
		for(int t=1;t<=n;t++){
			ll cur=0,mx=0,mn=0,ri=r,le=l;
			for(int i=n;i>=1;i--)cnt[i]=cnt[i+1]+(!a[i]);
			for(int i=1;i<=n;i++){
				if(!a[i]){
					if(ri)b[i]=min(ri,k),ri-=min(ri,k);
					else if(1ll*(-k)*cnt[i+1]>le)b[i]=max(-k,le),le-=max(-k,le);
					else b[i]=0;
				}			
				else b[i]=a[i];
			}
			for(int i=n+1;i<=2*n;i++)b[i]=b[i-n];
			for(int i=n-t+2;i<=n*2-t+1;i++){
				cur+=b[i];
				mn=min(mn,cur);
				mx=max(cur,mx);
			}
			ans=max(mx-mn+1,ans);
			rotate(a+1,a+2,a+n+1);
		}
		printf("%lld\n",ans);

	}


	return 0;
}