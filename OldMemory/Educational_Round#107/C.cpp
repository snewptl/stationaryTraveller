#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,q;
int a[maxn];
int vis[55];
int main(){
        scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!vis[a[i]])vis[a[i]]=i;
		}
		while(q--){
			int t;scanf("%d",&t);
			printf("%d ",vis[t]);
			for(int i=1;i<=50;i++){
				if(i==t)continue;
				if(vis[i]<vis[t])vis[i]++;
			}vis[t]=1;
		}
		printf("\n");


    return 0;
}