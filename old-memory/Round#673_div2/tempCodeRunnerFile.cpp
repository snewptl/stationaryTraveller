#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int n;int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        
        scanf("%d",&n);
        int flag=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(i>=2&&a[i-1]<=a[i])flag=0;
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }


    return 0;
}