#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn],sum;
int ans[maxn][3];
bool get_ans(){
    for(int i=n-1;i>=1;i--){
        if(a[i]>sum/n){printf("-1\n");return false;}
        ans[i][0]=1,ans[i][1]=i,ans[i][2]=a[i]-sum/n;
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n){printf("-1\n");continue;}
        if(!get_ans())continue;


    }


    return 0;
}