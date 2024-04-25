#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k,r,c;
char mp[505][505];
char s[505];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%d%d%d",&n,&k,&r,&c);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)mp[i][j]='.';
        r--,c--;
        s[0]='X';
        for(int i=1;i<k;i++)s[i]='.';
        r%=k,c%=k;
        int st=(r-c+k)%k;
        for(int j=0;j<n;j++){
            for(int i=st;i<n;i+=k)mp[i][j]='X';
            st=(st+1)%k;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%c",mp[i][j]);
            puts("");
        }
	}


	return 0;
}