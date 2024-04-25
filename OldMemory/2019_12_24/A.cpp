#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a,b,c,r;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&r);
        if(a>b){
            int t=a;a=b;b=t;
        }
        int le=c-r,ri=c+r;
        if((le-b)*(ri-a)<0){
            le=max(le,a);
            ri=min(ri,b);
            printf("%d\n",b-a-ri+le);
        }
        else printf("%d\n",b-a);
    }
    return 0;
}