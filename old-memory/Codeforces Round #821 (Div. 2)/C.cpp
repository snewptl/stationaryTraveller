#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",n-1);
        if(n>=2){
            printf("%d %d\n",1,n);
            for(int i=2;i<n;i++){
                if((a[i]+a[1])%2==1)printf("%d %d\n",1,i);
                else printf("%d %d\n",i,n);
            }
        }
	}


	return 0;
}