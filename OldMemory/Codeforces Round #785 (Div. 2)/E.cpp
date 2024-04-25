#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e6+5;
const ll mod=998244353;
const int inf=1<<20;
const double eps=1e-10;
int n,k;
int sum[35][maxn];
int cnt[maxn];
int b[maxn],ans[maxn];
void init(){
	for(int i=1;i<=n;i++){
		int cur=i;
		while(cur%2==0){
			cnt[i]++;
			cur/=2;
		}
	}
	for(int i=0;i<=min(23,n);i++){
		int sz=n-i;
		int res=0;
		sum[sz][0]=1;
		for(int j=1;j<=sz;j++){
			sum[sz][j]=sum[sz][j-1];
			res+=cnt[sz-j+1]-cnt[j];
			if(res)sum[sz][j]++;
			sum[sz][j]%=2;
		}
	}
}

int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++){
			ll cur=1;
			for(int j=i;j<=n;j++){
				if(j==i)cur*=b[j];
				else {
					if(b[j]>=20)break;
					cur*=(1<<b[j]);
				}
				if(cur>=inf)break;
				int len=j-i+2,x=k-2;
				if(i==1)len--,x++;
				if(j==n)len--,x++;
				if(x<=0)continue;
				ans[cur]+=sum[n-len][x-1];
				ans[cur]%=2;
			}
		}
		int pos=inf;
		while(pos>=0&&(!ans[pos]))pos--;
		if(pos<0)puts("0");
		else {
			for(int i=pos;i>=0;i--)printf("%d",ans[pos]);
			puts("");
		}
	}


	return 0;
}