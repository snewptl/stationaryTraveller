#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn],sum;
int vis[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
		sum=0;
		for(int i=0;i<=100;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			vis[a[i]]++;
		}
		int p=0;
		while(vis[p])p++;
		for(int i=0;i<p;i++){
			printf("%d ",i);
			vis[i]--;
		}
		for(int i=0;i<=100;i++){
			while(vis[i]){
				vis[i]--;
				printf("%d ",i);
			}
		}
		printf("\n");
    }


    return 0;
}