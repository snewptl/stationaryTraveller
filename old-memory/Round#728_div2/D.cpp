#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,flag;
int a[15];
map<int,int>vis;
void dfs(int dep,int sum,int k){
	if(k>=2&&vis[abs(sum)])flag=1;
	if(k>=2&&sum==0)flag=1;
	if(dep==n+1)return;
	dfs(dep+1,sum+a[dep],k+1);
	dfs(dep+1,sum,k);
	dfs(dep+1,sum-a[dep],k+1);
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
			vis[a[i]]=1;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])flag=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int k=1;k<=n;k++){
					if(i==k||j==k)continue;
					if(abs(a[j]-a[k])==a[i]||(a[j]+a[k]==a[i]))flag=1;
				}
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}