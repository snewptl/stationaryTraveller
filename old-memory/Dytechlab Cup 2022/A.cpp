#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,k;
char s[205];
int cnt[30];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){ 
        scanf("%d%d%s",&n,&k,s);
        for(int i=0;i<26;i++)cnt[i]=0;
        for(int i=0;i<n;i++)cnt[s[i]-'a']++;
        for(int i=1;i<=k;i++){
            int cur=0;
            for(int j=0;j<min(26,n/k);j++){
                if(cnt[j])cur++,cnt[j]--;
                else break;
            }
            printf("%c",cur+'a');
        }
        puts("");
	}


	return 0;
}