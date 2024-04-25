#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e6+5;
const ll mod=998244353;
const double eps=1e-10;
int vis[maxn],in[maxn];
ll ans;
char s[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        ans=0;
        scanf("%d%s",&n,s);
        for(int i=1;i<=n;i++)vis[i]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')in[i+1]=1;
            else in[i+1]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                if(in[j])break;
                if(vis[j]){
                    vis[j]=0;
                    ans+=i;
                }
            }
        }
        printf("%lld\n",ans);
	}


	return 0;
}