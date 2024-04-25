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
int cnt[26];
char to[26];
int main(){
	int T=1;scanf("%d",&T);
	to['R'-'A']='P';
	to['P'-'A']='S';
	to['S'-'A']='R';
	while(T--){
		scanf("%s",s);
		int n=strlen(s);
		for(int i=0;i<26;i++)cnt[i]=0;
		int mx=0,pos;
		for(int i=0;i<n;i++){
			cnt[s[i]-'A']++;
			if(cnt[s[i]-'A']>mx){
				mx=cnt[s[i]-'A'];
				pos=s[i]-'A';
			}
		}
		for(int i=0;i<n;i++)
			printf("%c",to[pos]);
		puts("");
	}


	return 0;
}