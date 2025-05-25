#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int q,n;
char s[105];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
		scanf("%s",s);
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			l--,r--;int flag=0;
			for(int j=0;j<l;j++){
				if(s[j]==s[l])flag=1;
			}
			for(int j=r+1;j<n;j++){
				if(s[j]==s[r])flag=1;
			}
			if(flag)printf("YES\n");
			else printf("NO\n");
		}
    }


    return 0;
}