#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int a[maxn],b[maxn],lst[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n+1;i++)lst[i]=0;
        for(int i=n;i>=2;i--){
            if(a[i]<=b[i-1]){
                lst[i]=max(i,lst[i+1]);
            }
            else lst[i]=0;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",*lower_bound(b+1,b+n+1,a[i])-a[i]);
        }
        puts("");
        for(int i=1;i<n;i++){
            if(lst[i+1]){
                printf("%d ",b[lst[i+1]]-a[i]);
            }
            else printf("%d ",b[i]-a[i]);
        }
        printf("%d\n",b[n]-a[n]);

	}


	return 0;
}