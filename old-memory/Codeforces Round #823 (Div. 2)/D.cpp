#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
char s[maxn],t[maxn];
int n;
int cnt[27][27];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s%s",&n,s+1,t+1);
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                cnt[i][j]=0;
        for(int i=1;i<=n;i++){
            int x=s[i]-'a',y=t[n-i+1]-'a';
            if(x>y)swap(x,y);
            cnt[x][y]++;
        }
        int k=0,flag=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++)if(cnt[i][j]%2!=0){
                if(i==j)flag=1;
                k++;
            }
        }
        if(n%2==0){
            // printf("%d %d\n",k,flag);
            if(k)puts("NO");
            else puts("YES");
        }
        else {
            if(k==1&&flag)puts("YES");
            else puts("NO");
        }
        
	}


	return 0;
}