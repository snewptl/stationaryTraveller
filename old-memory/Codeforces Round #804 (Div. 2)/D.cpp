#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=5e3+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int dp[maxn][maxn],pre[maxn][maxn];
int ans;
int lst[maxn],pos[maxn],nxt[maxn];
int f[maxn];
int tot;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;tot=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				pre[i][j]=pre[i][j-1]+(a[j]==i);
			}
		}

		for(int i=1;i<=n;i++)pos[i]=nxt[i]=0;
		for(int i=n;i>=1;i--)nxt[i]=pos[a[i]],pos[a[i]]=i;

		for(int i=1;i<=n;i++)pos[i]=lst[i]=0;
		for(int i=1;i<=n;i++)lst[i]=pos[a[i]],pos[a[i]]=i;

		for(int i=1;i<=n;i++)dp[i][i]=a[i];

		for(int k=2;k<=n;k++){
			for(int i=1;i+k-1<=n;i++){
				int j=i+k-1;
				int mid=i+j>>1;
				dp[i][j]=0;
				int idx=dp[i][mid];
				if((pre[idx][j]-pre[idx][i-1])*2>k)dp[i][j]=idx;
				idx=dp[mid+1][j];
				if((pre[idx][j]-pre[idx][i-1])*2>k)dp[i][j]=idx;
			}
		}

		for(int i=1;i<=n;i++){
			a[n+1]=i;
			lst[n+1]=pos[i];
			nxt[pos[i]]=n+1;
			int st=0;
			for(st=n+1;;st=lst[st]){
				f[st]=-1e9;
				if(!lst[st])break;
			}
			// if(tot>=5e7)break;
			for(int j=st;;j=nxt[j]){
				// if(++tot>=5e7)break;
				for(int k=lst[j];;k=lst[k]){
					int temp=0;
					if(k<j-1){
						if(dp[k+1][j-1]){
							int idx=dp[k+1][j-1];
							temp=2*(pre[idx][j-1]-pre[idx][k])-(j-1-k);
						}
						else temp=(j-1-k)%2;
					}
					f[j]=max(f[k]+1-temp,f[j]);
					if(k==0)break;
					
				}						
				if(j==n+1)break;
			}
			ans=max(ans,f[n+1]-1);
		}
		printf("%d\n",ans);
	}


	return 0;
}