#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int pos=2,cnt1=1,cnt2=0,ans=0;
        while(pos<=n){
            int st=pos;
            while(pos<n&&a[pos]<a[pos+1])pos++;
            cnt2+=pos-st+1;
            cnt1--;
            if(!cnt1){
                cnt1=cnt2,cnt2=0,ans++;
            }
            pos++;
        }
        if(cnt2)ans++;
        printf("%d\n",ans);
    }


    return 0;
}