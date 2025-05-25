#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[n+1]=0;
        int pos=1,cnt=0,t=-1e9-10;
        long long  sum=0;
        while(pos<=n){
            t=a[pos];
            while((a[pos]>0&&a[pos+1]>0)){
                t=max(t,a[pos+1]);
                pos++;
            }
            while(a[pos]<0&&a[pos+1]<0){
                t=max(t,a[pos+1]);
                pos++;
            }
            pos++;
            sum+=(long long )t;
        }
        printf("%lld\n",sum);
    }

    return 0;
}