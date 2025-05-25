#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=2e2+10;
int n;
char s[maxn];
int cnt[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
		scanf("%d%s",&n,s);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<n;i++){
			cnt[s[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			for(int j=1;j<=cnt[i];j++)
			printf("%c",i+'a');
		}
		printf("\n");
    }
    return 0;
}