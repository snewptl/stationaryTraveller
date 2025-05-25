#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l*2<r+1)printf("NO\n");
        else printf("YES\n");
    }


    return 0;
}