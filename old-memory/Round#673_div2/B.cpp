#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
map<int,int>mp;
int n,t;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        mp.clear();
        for(int i=1;i<=n;i++){
            if(!mp[a[i]]){
                mp[a[i]]=1;
                mp[t-a[i]]=2;
            }
            
        }
        int st=0;
        for(int i=1;i<=n;i++){
            if(t%2==0&&a[i]==t/2)printf("%d ",st),st=st^1;
            else if(mp[a[i]]==1)printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }


    return 0;
}