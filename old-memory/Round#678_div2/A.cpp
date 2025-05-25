#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101];
int main(){
    int T;scanf("%d",&T);
    int n,m;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            m-=a[i];
        }
        if(m!=0)printf("NO\n");
        else printf("YES\n");
    }


    return 0;
}