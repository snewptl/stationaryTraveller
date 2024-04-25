#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n;
char s[maxn];
int p[maxn],len[maxn],cnt,ans;
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);scanf("%s",s);
        cnt=0,ans=0;int pos=1;
        p[cnt++]=0;
        while(pos<n){
            while(pos<n&&s[pos-1]==s[pos])pos++;
            if(pos==n)break;
            p[cnt++]=pos;pos++;
        }
        p[cnt]=n;
        for(int i=0;i<cnt;i++){
            len[i]=p[i+1]-p[i];
        }
        int i=0,j=0;
        for(i=0;i<cnt;i++){
            if(len[i]>1){
                ans++;
                j=max(j,i+1);
            }
            if(len[i]==1){
                while(j<cnt&&len[j]==1)j++;
                if(j==cnt)break;
                len[j]--;
                ans++;
            }
        }
        ans+=(cnt-i+1)/2;
        printf("%d\n",ans);
    }

    return 0;
}