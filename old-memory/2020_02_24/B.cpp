#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int T,n,m;
int a[maxn],p[maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&p[i]);
        int t=1;
        while(t){
            t=0;
            for(int i=1;i<=m;i++){
                if(a[p[i]]>a[p[i]+1]){
                    swap(a[p[i]],a[p[i]+1]);
                    t=1;
                }
            }      
        }
        int flag=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1])flag=1;
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}