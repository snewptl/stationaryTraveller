#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=1e9+7;
int n,k;
ll a[1005],b[1005];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
		if(k==1)printf("1\n");
		else if(k==2)printf("%d\n",n+1);
		else {
			ll ans=2,sum[2];
			sum[0]=sum[1]=0;
			k-=2;int sgn=0;
			// for(int i=1;i<n;i++)a[i]=n-i,ans+=a[i],ans%=mod,sum[sgn]+=a[i];
			for(int i=1;i<n;i++)a[i]=1,ans+=a[i],sum[sgn]+=a[i];
			while(k){
				if(sgn)for(int i=n-1;i>=1;i--){
					sum[sgn]-=a[i+1];
					b[i]=sum[sgn];
					b[i]%=mod;
				}
				else for(int i=1;i<n;i++){
					sum[sgn]-=a[i-1];
					b[i]=sum[sgn];
					b[i]%=mod;		
				}
				for(int i=1;i<n;i++){
					a[i]=b[i];ans+=a[i];ans%=mod;sum[sgn^1]+=b[i];
				}
				k--;
				sum[sgn]=0;
				sgn=sgn^1;
			}	
			printf("%lld\n",ans);
			for(int i=1;i<=n;i++)a[i]=b[i]=0;
		}
		
    }


    return 0;
}