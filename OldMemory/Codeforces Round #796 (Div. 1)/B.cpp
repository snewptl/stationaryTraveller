#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int fa[maxn],n,m,len[maxn];
pii a[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int ask(string s){
	cout<<"?"<<" "<<s<<'\n';
	cout.flush();
	int res;
	cin>>res;
	return res;
}
int main(){
	cin>>n>>m;
	string s;
	for(int i=1;i<=m;i++)s.push_back('0');
	for(int i=0;i<m;i++){
		s[i]='1';
		len[i]=ask(s);
		a[i]={len[i],i};
		s[i]='0';
	}
	sort(a,a+m);
	int sum=0;
	for(int i=0;i<m;i++){
		int idx=a[i].second,w=a[i].first;
		s[idx]='1';
		int temp=ask(s);
		if(temp==w+sum)sum+=w;
		else {
			s[idx]='0';
		}
	}
	cout<<"! "<<sum<<'\n';
	cout.flush();
	



	return 0;
}