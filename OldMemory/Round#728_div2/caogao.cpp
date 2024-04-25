#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,flag;
int a[15];
map<int,int>vis;
int used[15];
void dfs(int dep,int sum,int k){
	// if(k&&!sum)flag=1;
	if(k>=2&&vis[abs(sum)]&&!used[vis[abs(sum)]]){
		flag=1;
	}
	if(dep==n+1)return;
	used[dep]=1;
	dfs(dep+1,sum+a[dep],k+1);
	dfs(dep+1,sum-a[dep],k+1);
	used[dep]=0;
	dfs(dep+1,sum,k);
	
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
		flag=0;
		vis.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=abs(a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])flag=1;
			vis[a[i]]=i;
		}
		dfs(1,0,0);
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}