#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int n,c;
int a[maxn],vis[maxn];
int pre[maxn];
int res[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(int i=1;i<=c;i++)vis[i]=0,res[i]=0;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			vis[x]=1;
		}
		for(int i=1;i<=c;i++)pre[i]=pre[i-1]+vis[i];
		int flag=1;
		for(int i=1;i<=c;i++){
			if(!vis[i])continue;
			int k=sqrt(i+1);
			if(k*k>i)k--;
			if(!flag)break;
			for(int j=1;j<=k+1;j++){
				while(j*(res[j]+1)<=i)res[j]++;
			}
			for(int j=1;j<=k;j++){
				if(vis[j]){
					if(!vis[res[j]])flag=0;
				}
				else if(pre[res[j]]-pre[res[j+1]]){
					flag=0;
				}
			}
		}
		
		if(!flag)puts("NO");
		else puts("YES");
	}


	return 0;
}

