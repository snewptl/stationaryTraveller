#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],vis[maxn];
int cnt[maxn],ans,flag;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		flag=1;ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)cnt[i]=0,vis[i]=0;
		ans=n;
		for(int i=1;i<=n;i++){
			if(a[i]<=n&&(!vis[a[i]])){
				vis[a[i]]=1;
				ans--;
			}
			else {
				if(a[i]>=3)cnt[min(a[i]/2,n)]++;
			}
		}
		for(int i=n;i>=1;i--){			
			if(vis[i]){
				cnt[i-1]+=cnt[i];
				continue;
			}
			if(!cnt[i]){
				flag=0;
				break;
			}
			cnt[i]--;		
			cnt[i-1]+=cnt[i];
		}
		if(!flag)ans=-1;
		printf("%d\n",ans);
	}


	return 0;
}