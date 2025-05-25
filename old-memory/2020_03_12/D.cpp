#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
typedef long long ll;
int n;
ll cnt=0;
int a[maxn],b[maxn],c[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        c[i]=a[i]-b[i];
    sort(c+1,c+n+1);
    ll le=1,ri=n;
    for(int i=1;i<=n;i++){
        while(c[le]+c[ri]<=0&&le<ri)le++;
        if(le>=ri)break;
        cnt+=ri-le;
        ri--;
    }
    printf("%lld",cnt);
    return 0;
}
