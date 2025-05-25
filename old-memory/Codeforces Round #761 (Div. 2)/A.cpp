#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=1e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
string s,t,ans;
int cnt[50];
int vis[3][505];
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
		cin>>s>>t;
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;i<s.size();i++){
			cnt[s[i]-'a']++;
		}
		ans.clear();
		if(t=="abc"&&cnt[0]&&cnt[1]&&cnt[2]){
			for(int i=0;i<26;i++){
				if(i==1){
					while(cnt[2]--){
						ans+=2+'a';
					}
				}
				else if(i==2){
					while(cnt[1]--){
						ans+=1+'a';
					}
				}
				else while(cnt[i]--)ans+=i+'a';
			}
		}
		else {
			for(int i=0;i<26;i++){
				while(cnt[i]--){
					ans+=i+'a';
				}
			}
		}
		cout<<ans<<'\n';
	}


	return 0;
}