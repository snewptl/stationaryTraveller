#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=1e5+10;
int n,k;
int x[maxn],y[maxn];
int ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%d%d",&n,&k);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=1;i<=n;i++){
			int flag=1;
			for(int j=1;j<=n;j++){
				if(abs(x[j]-x[i])+abs(y[j]-y[i])>k)flag=0;
			}
			if(flag)ans++;
		}
		if(ans)printf("%d\n",1);
		else printf("-1\n");
    }

    return 0;
}