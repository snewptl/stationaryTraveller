#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int m;
int n;
int a[maxn],vis[maxn];
int ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans=0;
        scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]%=m;
			vis[a[i]]++;
		}
		for(int i=0;i<=m/2;i++){
			if(vis[i]||vis[(m-i)%m]){
				int mx=max(vis[i],vis[(m-i)%m]);
				int mn=min(vis[i],vis[(m-i)%m]);
				ans+=1+max(mx-mn-1,0);				
			}
		}
		printf("%d\n",ans);
    }	


    return 0;
}