#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn];
int link[maxn],nxt[maxn],pre[maxn];
int vis[maxn],len[maxn],ri[maxn],le[maxn];
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
			ri[i]=(i+1)%n;
			le[i]=(i-1+n)%n;
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
				len[i]=1;
				for(int j=i-1;;j--){
					if(j<0)j+=n;
					if(!link[j])break;
					if(nxt[j])break;
					nxt[j]=nxt[(j+1)%n]+1;
					len[j]=nxt[j];
				}
			}
		}
		for(int i=n-1;i>=0;i--){
			if(!link[(i-1+n)%n]){
				pre[i]=1;
				for(int j=i+1;;j++){
					if(j>=n)j-=n;
					if(!link[(j-1+n)%n])break;
					if(pre[j])break;
					pre[j]=pre[(j-1+n)%n]+1;
				}
			}
		}
		// for(int i=0;i<n;i++)printf("%d ",nxt[i]);
		// printf("\n");
		int i,pos;
		for(i=0;;){
			int p=(nxt[i]+i)%n;
			p=(vis[p]+p)%n;
			if((nxt[p]+p)%n==(nxt[i]+i)%n){
				break;
			}
			ans[++tot]=p;
			vis[(nxt[i]+i)%n]++;
			if(vis[(p+1)%n])i=((nxt[p]+p)%n+vis[(nxt[p]+p)%n])%n;
			else i=(p+1)%n;
		}
		// for(int i=0;;){
		// 	int temp=(nxt[i]+i)%n;
		// 	ans[++tot]=temp;
		// 	vis[temp]=1;
		// 	// int p=(temp+1)%n;
		// 	int fro=(i-pre[i]+1+n)%n;
		// 	while(gcd(a[(temp-le[temp]+n)%n],a[(temp+ri[temp])%n])!=1){
		// 		nxt[fro]=(nxt[fro]+ri[temp]+nxt[(temp+ri[temp])%n])%n;
		// 		if(nxt[fro]==fro)break;
		// 	}				
			
		// }
		pos=(nxt[i]+i-1+n)%n;
		// printf("%d\n",pos);
		for(int j=i;;j++){
			if(j>=n)j-=n;
			if(j==pos)break;
			if(gcd(a[j],a[pos])==1)ans[++tot]=j;
			else break;
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