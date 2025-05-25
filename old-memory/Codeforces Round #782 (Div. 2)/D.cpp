#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,c[maxn],ans[maxn];
int nxt[maxn][30];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&c[i]);
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
		}
		int cnt=sum/n,pos=n+1;
		for(int i=0;i<=20;i++)nxt[n+1][i]=n+1;
		for(int i=n;i>=1;i--){
			if(cnt>=i)cnt--,ans[i]=1;
			else if(!cnt)ans[i]=0;
			else{
				nxt[i][0]=pos;
				for(int j=1;j<=20;j++){
					nxt[i][j]=nxt[nxt[i][j-1]][j-1];
				}
				int cur=i;
				for(int j=20;j>=0;j--){
					if((1<<j)&cnt)cur=nxt[cur][j];
				}
				cur--;
				if(cur!=c[i])ans[i]=0,pos=i;
				else ans[i]=1,cnt--;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}


	return 0;
}