#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,flag;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        flag=1;int num[3]={0,0,0};
        for(int i=0;i<k;i++){
            int a[3]={0,0,0};
            for(int j=i;j<n;j+=k){
                if(s[j]=='0')a[0]=1;
                if(s[j]=='1')a[1]=1;
                if(s[j]=='?')a[2]=1;
            }
            if(a[0]||a[1]){
                if(a[0]&&a[1])flag=0;
                if(a[0])num[0]++;
                if(a[1])num[1]++;
            }
            else num[2]++;
        }
        if(num[0]>k/2||num[1]>k/2)flag=0;
        if(!flag)printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}