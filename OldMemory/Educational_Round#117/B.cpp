#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a,b,flag;
vector<int>le,ri;
int vis[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		ri.clear();le.clear();
		for(int i=1;i<=n;i++)vis[i]=0;
		flag=0;
		vis[a]=vis[b]=1;
		for(int i=1;i<a;i++){
			if(i==b)continue;
			ri.push_back(i);
			vis[i]=1;
		}
		for(int i=n;i>b;i--){
			if(i==a)continue;
			le.push_back(i);
			if(vis[i])flag=1;
			vis[i]=1;
		}
		if(ri.size()>=n/2||le.size()>=n/2||flag){
			printf("-1\n");
		}
		else {
			printf("%d ",a);
			for(auto x:le)printf("%d ",x);
			
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				printf("%d ",i);
			}
			
			for(auto x:ri)printf("%d ",x);
			printf("%d ",b);
			puts("");
		}
		
	}


	return 0;
}