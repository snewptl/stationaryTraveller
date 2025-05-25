#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
ll a[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int flag=1;
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++)if(a[i]==a[i+1])flag=0;
        for(int i=2;i<=n;i++){
            int cnt[105];
            for(int j=0;j<i;j++)cnt[j]=0;
            for(int j=1;j<=n;j++)cnt[a[j]%i]++;
            int res=0;
            for(int j=0;j<i;j++)if(cnt[j]<=1)res=1;
            if(!res)flag=0;
            // puts("^^");
            // for(int j=0;j<i;j++)printf("%d ",cnt[j]);
            // puts("");
        }
        if(flag)puts("YES");
        else puts("NO");
	}


	return 0;
}