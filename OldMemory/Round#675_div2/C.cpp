#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+10;
char s[maxn];
ll pre[maxn],back[maxn],mi[maxn];
int main(){
    mi[0]=0;
    for(int i=1;i<=maxn-10;i++){
        mi[i]=mi[i-1]*10+1;
        mi[i]%=mod;
    }    
    scanf("%s",s);
    int len=strlen(s);
    ll ans=0;
    for(int i=0;i<len;i++)
        pre[i]=back[i]=0;
    for(int i=0;i<len-1;i++){
        pre[i]=pre[i-1]*10;
        pre[i]+=s[i]-'0';
        pre[i]%=mod;
    }
    ll t=10;back[len-1]=s[len-1]-'0';
    for(int i=len-2;i>0;i--){
        back[i]=(s[i]-'0')*t%mod;
        back[i]+=back[i+1];
        back[i]%=mod;
        t*=10,t%=mod;
    }

    for(int i=0;i<len-1;i++){
        ans+=pre[i]*mi[len-1-i]%mod;
        ans%=mod;
    }
    for(int i=len-1;i>0;i--){
        ans+=back[i]*(ll)i;
        ans%=mod;
    }
    printf("%lld",ans);


    return 0;
}