#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],cnt[105],mx;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(!sum){
			for(int i=1;i<=n;i++){
				printf("%d ",i);
			}
			printf("\n");
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		mx=0;
		for(int i=1;i<=n;i++){
			int cur=0,x=a[i];
			while(x){
				if(x&1)cnt[cur]++;
				cur++;
				mx=max(cur,mx);
				x/=2;
			}
		}
		int ans=cnt[mx-1];
		for(int i=0;i<mx-1;i++){
			if(!cnt[i])continue;
			ans=gcd(ans,cnt[i]);
		}
		for(int i=1;i<=ans;i++){
			if(ans%i==0)
			printf("%d ",i);
		}
		printf("\n");
		
	}


	return 0;
}