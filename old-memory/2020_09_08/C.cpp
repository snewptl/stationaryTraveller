#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,p,xp,yp;
int ans[maxn];
int mx;
int main(){
    scanf("%d",&n);        
    int x,y;
    if(n==1){
        ans[1]=1;
    }
    else {
        for(int i=1;i<=n/2*2;i+=2){
            printf("? %d %d\n",i,i+1);
            fflush(stdout);
            scanf("%d",&x);
            printf("? %d %d\n",i+1,i);
            fflush(stdout);
            scanf("%d",&y);
            if(x<y){
                ans[i+1]=y;
                if(mx<y){
                    mx=y;
                    p=i+1;
                }
            }
            else {
                ans[i]=x;
                if(mx<x){
                    mx=x;
                    p=i;
                }
            }

        }
        if(!ans[1])xp=1;else xp=2;
        if(!ans[3])yp=3;else yp=4;
        if(mx<(n-1)/2+1){
            printf("? %d %d\n",xp,p);
            fflush(stdout);
            scanf("%d",&x);
            printf("? %d %d\n",yp,p);
            fflush(stdout);
            scanf("%d",&y);
            if(x==y){
                printf("? %d %d\n",xp,yp);
                fflush(stdout);
                scanf("%d",&x);
                printf("? %d %d\n",yp,xp);
                fflush(stdout);
                scanf("%d",&y);
                if(x<y){
                    ans[xp]=n;ans[yp]=n/2+1;
                    p=yp;
                }
                else {
                    ans[xp]=n/2+1;ans[yp]=n;
                    p=xp;
                }
                
            }
            else if(x!=1){
                if(x==0)x=n/2;
                ans[xp]=n/2+x;
                p=xp;
            }
            else {
                if(y==0)y=n/2;
                ans[yp]=n/2+y;
                p=yp;
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i])continue;
            printf("? %d %d\n",i,p);
            fflush(stdout);
            scanf("%d",&x);     
            printf("? %d %d\n",p,i);
            fflush(stdout);
            scanf("%d",&y); 
            if(x>y){
                ans[i]=x;
            }
            else {
                if(x==0)x=ans[p];
                ans[i]=x+ans[p];
            }
        }        
    }

    printf("! ");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}