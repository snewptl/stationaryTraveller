#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int mp[55][55];
int n,m;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(mp,0,sizeof(mp));
		for(int i=2;i<=m;i+=4){
			mp[1][i]=mp[1][i+1]=1;
		}
		for(int i=2;i<=n;i+=4){
			mp[i][1]=mp[i+1][1]=1;
		}
		for(int i=2;i<=n;i+=2){
			int st=0;
			if(i%4)st=4;
			else st=2;
			for(int j=st;j<=m;j+=4){
				mp[i][j]=mp[i][j+1]=1;
				mp[i+1][j]=mp[i+1][j+1]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)printf("%d ",mp[i][j]);
			puts("");
		}
	}


	return 0;
}