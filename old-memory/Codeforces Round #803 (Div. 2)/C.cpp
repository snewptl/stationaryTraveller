#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int cnt[3];
ll sum;
bool solve(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ll temp=1ll*a[i]+a[j]+a[k];
				int flag=0;
				for(int t=1;t<=n;t++){
					if(temp==1ll*a[t])flag=1;
				}
				if(!flag)return false;
			}
		}
	}	
	return true;
}

int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt[0]++;
			else if(a[i]<0)cnt[1]++;
			else cnt[2]++;
			sum+=a[i];
		}
		if(cnt[0]){
			if(max(cnt[1],cnt[2])>1)puts("NO");
			else {
				int flag=0;
				for(int i=1;i<=n;i++)if(a[i]==sum)flag=1;
				if(flag)puts("YES");
				else puts("NO");
			}
			
		}
		else {
			if(max(cnt[1],cnt[2])>2)puts("NO");
			else {
				sort(a+1,a+n+1);
				if(solve())puts("YES");
				else puts("NO");			
			}

		}
	}


	return 0;
}