#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=101;
int n;
int a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        if(sum==0){
            printf("NO\n");
        }
        else {
            printf("YES\n");
            if(sum<0){
                for(int i=1;i<=n;i++)printf("%d ",a[i]);
            }
            else for(int i=n;i>=1;i--)printf("%d ",a[i]);
            printf("\n");
        }
    }
    return 0;
}