#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
char s[maxn],ans[maxn];
stack<char>st;
int main(){
    int T;T=1;int cnt=0;
    while(T--){
        scanf("%d%d",&n,&m);
		scanf("%s",s);
		int p;p=n;
		for(int i=0;i<n;i++){
			if(s[i]>s[0]){
				p=i;
				break;
			}
		}		
		
		while(cnt<=m){
			for(int i=0;i<p;i++)ans[cnt++]=s[i];
		}
		for(int i=0;i<m;i++)printf("%c",ans[i]);

    }


    return 0;
}