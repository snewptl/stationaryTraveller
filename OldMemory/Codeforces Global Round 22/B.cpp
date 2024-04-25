#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,s[maxn];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++)scanf("%d",&s[i]);
        int lst=2e9,flag=1;
        for(int i=k;i>=2;i--){
            if(lst<s[i]-s[i-1])flag=0;
            lst=min(lst,s[i]-s[i-1]);
        }
        if(1ll*(n-k+1)*lst<s[1])flag=0;
        if(flag)puts("YES");
        else puts("NO");
	}


	return 0;
}