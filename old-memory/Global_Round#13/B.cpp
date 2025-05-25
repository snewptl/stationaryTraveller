#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,u,v;
int ans;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		ans=0;
        scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[0]=a[1],a[n+1]=a[n];
		int i,j;ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){
				ans+=min(u,v);break;
			}
			if(abs(a[i+1]-a[i])>1)break;
		}
		for(int i=n;i>=1;i--){
			if(a[i]==1e6+1){
				ans+=min(u,v);break;
			}
			if(abs(a[i+1]-a[i])>1)break;
		}
		if(!ans){
			int flag=1;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i+1]){
					flag=0;break;
				}
			}
			if(flag)ans=v+min(u,v);
			else {
				int flag1=1;
				for(int i=1;i<=n;i++){
					if(abs(a[i+1]-a[i])>1)flag1=0;
				}
				if(flag1)ans=min(u,v);
			}
		}

		printf("%d\n",ans);
    }


    return 0;
}