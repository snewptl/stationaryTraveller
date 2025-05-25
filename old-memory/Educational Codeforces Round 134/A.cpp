#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int cnt[30];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<2;i++){
            char s[10];
            scanf("%s",s);
            for(int j=0;j<2;j++){
                cnt[s[j]-'a']++;
            }
        }
        int tot=0,mx=0;
        for(int i=0;i<26;i++){
            if(cnt[i])tot++,mx=max(cnt[i],mx);
        }
        printf("%d\n",tot-1);
	}


	return 0;
}