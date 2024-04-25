#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int f[maxn][2],g[maxn][2],vis[maxn][2],lst[maxn][2];
char s[maxn],t[maxn];
int main(){
    scanf("%d%s%s",&n,s+1,t+1);
    for(int i=n;i>=1;i--){
        lst[i][0]=lst[i+1][0];
        lst[i][1]
        if(s[i]=='1')lst[i][0]=i;
        if(s[j]=='')
    }
    // memset(dp,0x3f,sizeof(dp));



	return 0;
}