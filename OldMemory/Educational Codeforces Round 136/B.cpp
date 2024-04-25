#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[maxn],b[maxn],n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int flag=1;
        b[1]=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]<=b[i-1]&&a[i])flag=0;
            b[i]=a[i]+b[i-1];
        }
        if(flag){
            for(int i=1;i<=n;i++)printf("%d ",b[i]);
            puts("");
        }
        else puts("-1");
	}


	return 0;
}