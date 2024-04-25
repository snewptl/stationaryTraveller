#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,c;
int cnt[105];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&c);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            cnt[x]++;
        }
        int ans=0;
        for(int i=0;i<=100;i++){
            if(cnt[i])ans+=min(c,cnt[i]);
        }
        printf("%d\n",ans);
	}


	return 0;
}