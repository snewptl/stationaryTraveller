#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        for(int i=1;i<=4;i++)scanf("%d",&a[i]);
        sort(a+1,a+4);int flag=1;
        int sum=a[1]%2+a[2]%2+a[3]%2+a[4]%2;
        if(a[1]==0){
            if(sum>1)flag=0;
        }
        else {
            if(sum>1&&(a[1]-1)%2+(a[2]-1)%2+(a[3]-1)%2+(a[4]+3)%2>1)flag=0;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}