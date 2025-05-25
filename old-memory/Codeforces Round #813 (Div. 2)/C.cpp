#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn];
int ri[maxn],flag[maxn];
int ans;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++){
            ri[i]=0;
            flag[i]=0;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ri[a[i]]=i;
        }
        flag[n]=flag[n+1]=1;
        for(int i=n-1;i>=1;i--){
            if(flag[i+1]&&a[i]<=a[i+1])flag[i]=1;
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(ri[a[i]],mx);
            if(ri[a[i]]==i)ans++;
            if(flag[i+1]&&mx==i)break;
        }
        if(flag[1])ans=0;
        printf("%d\n",ans);        

    }


	return 0;
}