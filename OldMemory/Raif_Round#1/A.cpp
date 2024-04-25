#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int x1,y1,x2,y2;ans=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2)ans=abs(y1-y2);
        else if(y1==y2)ans=abs(x1-x2);
        else ans=abs(x1-x2)+abs(y1-y2)+2;
        printf("%d\n",ans);
    }


    return 0;
}