#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n;
ll a[101][101],b[101];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        ll ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=1;i<=n/2;i++){
            int vi=n-i+1;
            for(int j=1;j<=m/2;j++){
                int vj=m-j+1;
                b[1]=a[i][j],b[2]=a[i][vj],b[3]=a[vi][j],b[4]=a[vi][vj];
                sort(b+1,b+5);
                ans+=b[4]+b[3]-b[2]-b[1];
            }
            if(m%2){
                ans+=abs(a[i][m/2+1]-a[vi][m/2+1]);
            }
        }
        if(n%2){
            for(int j=1;j<=m/2;j++){
                ans+=abs(a[n/2+1][j]-a[n/2+1][m-j+1]);
            }
        }
        printf("%lld\n",ans);
    }


    return 0;
}