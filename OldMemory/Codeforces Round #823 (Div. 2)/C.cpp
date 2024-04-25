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
int cnt[10],lst[10];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int mn=0;
        memset(lst,0,sizeof(lst));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            lst[s[i]-'0']=i;
        }
        for(int i=1;i<=n;i++){
            while(mn<=9&&lst[mn]<i)mn++;
            if(mn==s[i]-'0')cnt[mn]++;
            else {
                cnt[min(9,s[i]-'0'+1)]++;
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<cnt[i];j++)printf("%d",i);
        }
        puts("");
	}


	return 0;
}