#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int cnt[30];
char a[maxn];
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		scanf("%s",a);
		int n=strlen(a);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<n;i++){
			cnt[a[i]-'a']++;
		}
		int pos=0;
		while(pos<n&&cnt[a[pos]-'a']>=2)cnt[a[pos]-'a']--,pos++;
		for(int i=pos;i<n;i++)printf("%c",a[i]);
		puts("");

	}


	return 0;
}