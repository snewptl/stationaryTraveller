#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
int c[1003][25],a[25];
ll hsh(){
    ll res=0;
    for(int i=1;i<=k;i++){
        res=res*3+a[i];
    }
    return res;
}
map<ll,int>mp;
int main(){
	int T=1;//scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                scanf("%d",&c[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int t=1;t<=k;t++){
                    if(c[i][t]!=c[j][t]){
                        a[t]=3-(c[i][t]+c[j][t]);
                    }
                    else a[t]=c[i][t];
                }
                mp[hsh()]++;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++)a[j]=c[i][j];
            ll temp=mp[hsh()];
            ans+=temp*(temp-1)/2;
            // for(int j=i+1;j<=n;j++){
            //     for(int t=1;t<=k;t++){
            //         if(c[i][t]!=c[j][t]){
            //             a[t]=3-(c[i][t]+c[j][t]);
            //         }
            //         else a[t]=c[i][t];
            //     }
            //     mp[hsh()]--;
            // }
        }
        printf("%lld\n",ans);
	}


	return 0;
}