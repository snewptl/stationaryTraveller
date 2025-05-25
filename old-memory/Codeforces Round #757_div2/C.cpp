#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=1e9+7;
const double eps=1e-10;
int n,m;
int val[maxn][35];
int sum[35],lst[35];
ll p2[maxn];
struct opt{
	int l,r,x;
}a[maxn];
bool cmp(opt x,opt y){
	return x.l<y.l;
}
int main(){
	p2[0]=1;
	for(int i=1;i<=2e5;i++)p2[i]=p2[i-1]*2,p2[i]%=mod;
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=0;j<30;j++){
				val[i][j]=1;
			}
		}
		for(int i=0;i<30;i++)lst[i]=0,sum[i]=0;
		for(int i=1;i<=m;i++){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			a[i]={l,r,x};
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int l=a[i].l,r=a[i].r,x=a[i].x;
			for(int j=0;j<30;j++){
				if((x&(1<<j)))continue;
				if(lst[j]>=r)continue;
				for(int k=max(l,lst[j]+1);k<=r;k++)
					val[k][j]=0;
				lst[j]=r;
			}
		}
		for(int i=0;i<30;i++){
			for(int j=1;j<=n;j++){
				sum[i]+=val[j][i];
			}
		}
		ll ans=0;
		for(int i=0;i<30;i++){
			if(!sum[i])continue;
			ll res=0;
			res=p2[sum[i]-1]*p2[n-sum[i]]%mod*p2[i]%mod;
			ans=(ans+res)%mod;
		}
		printf("%lld\n",ans);
	}


	return 0;
}