#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
char s[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",s);int ans=0;
		int len=strlen(s);
		int cnt1=0,cnt2=0;
		for(int i=0;i<len;i++){
			if(s[i]=='(')cnt1++;
			if(s[i]=='[')cnt2++;
			if(s[i]==']'){
				if(cnt2)ans++;
				cnt2--;
			}
			if(s[i]==')'){
				if(cnt1)ans++;
				cnt1--;
			}
			if(cnt1<0)cnt1=0;
			if(cnt2<0)cnt2=0;
		}
		printf("%d\n",ans);
    }


    return 0;
}