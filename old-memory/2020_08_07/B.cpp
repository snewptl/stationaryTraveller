#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int n,q;int a[maxn*2],b[maxn];
int cnt2,cnt4;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);b[a[i]]++;
    }
    for(int i=1;i<=maxn-10;i++){
        if(b[i]>=4)cnt4++;
        cnt2+=b[i]/2;
    }
    scanf("%d",&q);
    while(q--){
        char ch[2];int x;
        scanf("%s%d",ch,&x);
        if(ch[0]=='+'){
            if(b[x]%2!=0){
                if(b[x]==3)cnt4++;
                cnt2++;
            }
            b[x]++;
        }else {
            if(b[x]%2==0){
                if(b[x]==4)cnt4--;
                cnt2--;
            }
            b[x]--;
        }
        if(cnt4<=0)printf("NO\n");
        else {
            if(cnt2<4)printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}