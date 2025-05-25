#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,m;
char s[505][505];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
        }
        int cnt=0,flag0=0,flag1=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i][j]=='1'){
                    cnt++;
                }
                else {
                    flag0=1;
                    if(i+1<=n&&s[i+1][j]=='0')flag1=1;
                    if(j+1<=m&&s[i][j+1]=='0')flag1=1;
                    if(i+1<=n&&j-1>=1&&s[i+1][j-1]=='0')flag1=1;
                    if(i+1<=n&&j+1<=m&&s[i+1][j+1]=='0')flag1=1;
                }
            }
        }
        int mn=0;
        if(cnt)mn=1;
        if(!flag0)cnt-=2;
        else if(!flag1)cnt-=1;
        printf("%d\n",max(mn,cnt));
	}


	return 0;
}