#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],b[maxn],mx,num,ans;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);mx=0,num=0,ans=0;
        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]]++;mx=max(mx,b[a[i]]);
        }
        for(int i=1;i<=maxn-10;i++){
            if(b[i]==mx)num++;
        }
        ans=(n-num*mx)/(mx-1)+num-1;
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)b[a[i]]=0;
    }
    return 0;
}