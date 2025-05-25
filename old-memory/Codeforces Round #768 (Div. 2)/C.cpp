#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,flag;
int ans[maxn][2];
int p2[maxn],cnt[maxn];
int main(){
	int T=1;scanf("%d",&T);
	p2[0]=1;
	for(int i=1;i<=30;i++){
		p2[i]=p2[i-1]*2;
	}
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<=30;i++)cnt[i]=0;
		int ad=n/4;
		flag=0;
		for(int i=30;i>=0;i--){
			if(p2[i]>=n)continue;
			cnt[i]=min(k/p2[i],ad);
			k-=cnt[i]*p2[i];
		}
		if(k)flag=1;
		else {
			for(int i=30;i>=0;i--){
				if(p2[i]>=n)continue;
				for(int j=1;j<=cnt[i];j++){
					ans[j][0]+=p2[i];
					ans[j][1]+=p2[i];
				}
				for(int j=cnt[i]*2+1;j<=n/2;j++){
					ans[j][0]+=p2[i];
				}
			}
		}
		if(flag)puts("-1");
		else {
			for(int j=1;j<=n/2;j++){
				printf("%d %d\n",ans[j][0],ans[j][1]);
				ans[j][0]=ans[j][1]=0;
			}
		}

	}


	return 0;
}