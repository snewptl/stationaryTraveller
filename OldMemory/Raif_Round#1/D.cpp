#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int lim=n;
int n,a[maxn],cnt1,cnt3,cnt;
int l,r,mid,pos,x,pos1,pos2;
int up=1,dn=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)cnt1++;
        if(a[i]==3)cnt3++;
        if(a[i])cnt++;
    }
    if(cnt1>2||cnt3>1||(cnt3&&cnt1)||(cnt1==0&&cnt3==0)){printf("-1");return 0;}
    if(cnt1==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){pos=i;break;}
            if(a[i])l++;
        }
        r=cnt-l-1;
        if(r%2==0){printf("-1");return 0;}

        printf("%d\n%d %d\n",cnt*2-1,1,pos);

        solve(up,1,pos+1,n);solve(dn,x,1,pos-1);

    }
    if(cnt1==2){
        for(int i=1;i<=n;i++){
            if(a[i]==1){pos1=i;break;}
            if(a[i])l++;
        }
        for(int i=n;i>=1;i--){
            if(a[i]==1){pos2==i;break;}
            if(a[i])r++;
        }
        mid=cnt-l-r-2;
        if(l%2==0||r%2==0){printf("-1");return 0;}
        printf("%d\n%d %d\n",cnt*2-2,1,pos1);

        solve(up,1,pos1+1,pos2-1);
        if(mid%2==0){
            solve(up,x,pos2+1,n);
            solve(dn,x,1,pos1-1);
        }
        printf("%d %d\n",x-1,pos2);
    }
    if(cnt3==1){
        
    }
    return 0;
}