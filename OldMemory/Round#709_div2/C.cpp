#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn];
int link[maxn],nxt[maxn];
int vis[maxn];
int tot,ans[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			
		}
		if(n==1&&a[0]==1){
			printf("1 1\n");
			continue;
		}
		for(int i=0;i<n;i++)
			if(gcd(a[i],a[(i+1)%n])!=1)link[i]=1;
		for(int i=0;i<n;i++){
			if(!link[i]){
				nxt[i]=1;
				for(int j=i-1;;j--){
					if(j<0)j+=n;
					if(!link[j])break;
					if(nxt[j])break;
					nxt[j]=nxt[(j+1)%n]+1;
				}
			}
		}
		// for(int i=0;i<n;i++)printf("%d ",nxt[i]);
		// printf("\n");
		for(int i=0;;){
			int p=(nxt[i]+i)%n;
			p=(vis[p]+p)%n;
			if((nxt[p]+p)%n==(nxt[i]+i)%n)break;
			ans[++tot]=p;
			vis[(nxt[i]+i)%n]++;
			if(nxt[i]==)
		}
		printf("%d ",tot);
		for(int i=1;i<=tot;i++)printf("%d ",ans[i]+1);
		printf("\n");
		for(int i=0;i<n;i++){
			nxt[i]=0;link[i]=0;vis[i]=0;tot=0;
		}
    }


    return 0;
}