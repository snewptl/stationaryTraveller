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
int cnt[maxn];
ll num;
int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(i)cnt[i]=cnt[i-1];
		cnt[i]+=s[i]-'0';
		num*=2;
		num+=s[i]-'0';
	}
	for(int i=n-1;i>=0;i--)

	return 0;
}