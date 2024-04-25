#include<bits/stdc++.h>
using namespace std;
const int maxn=5003;
int n,a[maxn];
int b[maxn];
int c[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]]++;
            if(b[a[i]])c[a[i]]=i;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(b[i]>2)flag=1;
            if(b[i]==2){
                if(a[c[i]-1]!=a[c[i]]&&a[c[i]]!=a[c[i]+1])flag=1;
            }
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}