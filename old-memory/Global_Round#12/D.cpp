#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,ans,a[60];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n/2;i++){
        int x,y;
        for(int j=i;j<=n-i+1;j++){
            if(a[j]==i)x=j;
            if(a[j]==n-i+1)y=j;
        }
        if(x<y){
            printf("%d ",(i-1)*2+3);
            for(int j=1;j<i;j++)printf("1 ");
            printf("%d %d %d\n",x-i+1,y-x-1,n-i+1-y+1);
            for(int j=1;j<i;j++)printf("1 ");
            printf("%d\n",n);
            for(int j=1;j<=n;j++)printf("1 ");
        }
        else {
            
        }
    }
    return 0;
}