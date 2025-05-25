#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
        int ans1=0,ans2=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'&&s[i+1]=='1')ans1++;
            if(s[i]=='0'&&s[i+1]=='0')ans2++;
        }
        printf("%d\n",max(ans1,ans2));
    }


    return 0;
}