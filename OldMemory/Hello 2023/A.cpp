#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
char s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s",&n,s+1);
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='L')cnt0++;
            else cnt1++;
        }
        if(cnt0==0||cnt1==0)puts("-1");
        else { 
            int flag=0;
            for(int i=1;i<n;i++){
                if(s[i]=='L'&&s[i+1]=='R'){
                    printf("%d\n",i);
                    flag=1;
                    break;
                }
            }
            if(!flag)puts("0");
        }
	}


	return 0;
}