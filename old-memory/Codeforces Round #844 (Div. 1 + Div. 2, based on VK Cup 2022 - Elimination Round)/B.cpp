#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],cnt[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        int mx=0;
        for(int i=0;i<=n;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,mx=max(mx,a[i]);
        int ans=0,cur=0,pre=-1;
        for(int i=0;i<n;i++){
            if(cnt[i]){
                if(cur<i) {
                    if(pre+1<=cur)ans++;
                    pre=i;
                }
                cur+=cnt[i];                
            }

        }
        printf("%d\n",ans+1);
	}


	return 0;
}