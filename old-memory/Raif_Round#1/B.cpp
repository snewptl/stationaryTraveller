#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,flag,ans,vis[maxn];
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
        flag=2,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='<'){flag--;break;}
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='>'){flag--;break;}
        }
        if(flag)ans=n;
        else {
            for(int i=0;i<n;i++){
                if(s[i]=='-'){
                    if(!vis[i])vis[i]=1,ans++;
                    if(!vis[(i+1)%n])vis[(i+1)%n]=1,ans++;
                }
            }

        }
        for(int i=0;i<n;i++)vis[i]=0;
        printf("%d\n",ans);
    }

    return 0;
}