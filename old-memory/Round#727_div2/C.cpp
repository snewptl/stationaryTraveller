#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n;
int a[maxn];
pii b[maxn];
int vis[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]={a[i],i};
		}
		memset(vis,0,sizeof(vis));
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			vis[b[i].first]+=abs(b[i].second-i);
		}
		int flag=1;
		for(int i=1;i<=1e5;i++){
			if(vis[i]%2)flag=0;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}