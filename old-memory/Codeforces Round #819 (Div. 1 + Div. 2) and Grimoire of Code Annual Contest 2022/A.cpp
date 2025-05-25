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
        int ans=-1e9;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int res=0;
        for(int i=2;i<=n;i++){
            res=max(res,a[i]);
        }
        ans=max(ans,res-a[1]);
        res=1e9;
        for(int i=1;i<n;i++){
            res=min(res,a[i]);
        }
        ans=max(ans,a[n]-res);
        for(int i=1;i<=n;i++){
            int cur=a[i-1];
            if(i==1)cur=a[n];
            ans=max(ans,cur-a[i]);
        }
        printf("%d\n",ans);
	}


	return 0;
}