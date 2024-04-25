#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn],t[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		scanf("%s%s",s,t);
		int len1=strlen(s);
		int len2=strlen(t);
		
		int cur=0,flag=1;
		if((len1&1)!=(len2&1))cur=1;
		for(int i=0;i<len2;i++){
			while(cur<len1&&s[cur]!=t[i]){
				cur+=2;
			}			
			if(cur>=len1)flag=0;
			cur++;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}