#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e4+10;
int n;
int a[maxn];
void solve(){
    int d=a[1];a[n+1]=1e9,a[1]=0;
    for(int i=1;i<=n;i++){
        if(a[i+1]<a[i]){
            printf("NO\n");return;
        }
        else {
            if(a[i+1]-d<a[i]){
                d=a[i+1]-a[i],a[i+1]=a[i];
            }
            else a[i+1]-=d;
        }
    }    
    printf("YES\n");
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }


    return 0;
}