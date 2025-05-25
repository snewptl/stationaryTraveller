#include<bits/stdc++.h>
using namespace std;
int T,maxd;
const int maxn=200010;
char s[maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        maxd=0;
        int d=0;
        for(int i=0;i<len;i++){
            d++;
            if(s[i]=='R'){
                maxd=max(maxd,d);
                d=0;
            }
        }
        if(d+1>maxd)maxd=d+1;
        printf("%d\n",maxd);
    }
    return 0;
}