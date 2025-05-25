#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,x;
char s[5];
int op[maxn],a[maxn];
int ans[maxn],k;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%s",s);
        if(s[0]=='+')op[i]=0;
        else {
            scanf("%d",&x);
            op[i]=x;
        }
    }
    int flag=1,pos=2*n,cnt=0;
    a[0]=maxn,k=n;
    while(pos){
        if(!flag)break;
        while(pos&&op[pos]){
            a[++cnt]=op[pos];
            pos--;
            if(a[cnt]>a[cnt-1])flag=0;
        }
        while(pos&&!op[pos]){
            if(!cnt){flag=0;break;}
            ans[k--]=a[cnt];
            cnt--,pos--;
        }
    }
    if(flag){
        printf("YES\n");
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    }
    else printf("NO\n");

    return 0;
}