#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,k,ans=0;scanf("%d%d",&n,&k);
        int mn=0x3f3f3f3f,p;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(mn>a[i]){
                mn=a[i],p=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(i==p)continue;
            ans+=(k-a[i])/mn;
        }
        printf("%d\n",ans);
    }


    return 0;
}