#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a,b,ans;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%s",&a,&b,s);
        int len=strlen(s);
        int i=len-1;
        ans=0;
        while(i>=0&&s[i]=='0')i--;
        while(i>=0){
            int tmp=0;
            while(i>=0&&s[i]=='1')i--;
            if(i<0){
                ans+=a;break;
            }
            while(i>=0&&s[i]=='0')i--,tmp+=b;
            if(i<0){
                ans+=a;break;
            }
            if(tmp>a)ans+=a;
            else ans+=tmp;
        }
        printf("%d\n",ans);
    }


    return 0;
}