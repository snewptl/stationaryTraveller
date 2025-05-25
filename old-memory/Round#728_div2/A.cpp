#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn],t[maxn];
int n;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s);
		for(int i=0;i<n;i++)t[i]=s[i];
		sort(s,s+n);
		int ans=n;
		for(int i=0;i<n;i++){
			if(t[i]==s[i])ans--;
		}
		printf("%d\n",ans);
    }


    return 0;
}