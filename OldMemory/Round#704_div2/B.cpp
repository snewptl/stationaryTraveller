#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int rk[maxn];
int cnt,ans[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);cnt=0;
		for(int i=1;i<=n;i++)rk[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			rk[a[i]]=i;
		}
		int mx=n;
		for(int i=n;i>=1;i--){
			if(!rk[i])continue;
			for(int j=rk[i];j<=mx;j++){
				ans[++cnt]=a[j];
				if(j!=rk[i])rk[a[j]]=0;
			}
			mx=rk[i]-1;
		}
		for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
		printf("\n");
    }


    return 0;
}