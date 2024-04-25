#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int n;
char s[maxn];
int a[maxn],b[maxn];
int sgn=0;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        sgn=0;
        scanf("%d%s",&n,s+1);
        a[1]=b[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i]=='2'){
                if(!sgn)a[i]=1,b[i]=1;
                else {
                    a[i]=0,b[i]=2;
                }
            }
            if(s[i]=='1'){
                if(!sgn)a[i]=1,b[i]=0,sgn=1;
                else a[i]=0,b[i]=1;
            }
            if(s[i]=='0'){a[i]=b[i]=0;}
        }
        for(int i=1;i<=n;i++)printf("%d",a[i]);
        printf("\n");
        for(int i=1;i<=n;i++)printf("%d",b[i]);
        printf("\n");
    }
    return 0;
}