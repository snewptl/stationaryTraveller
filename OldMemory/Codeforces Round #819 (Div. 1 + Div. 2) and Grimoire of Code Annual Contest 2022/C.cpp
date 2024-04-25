#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int ans,n;
vector<int>vec;
char s[maxn];
int nxt[maxn];
void init(){
    vec.clear();
    ans=0;
}
int solve(int l,int r){
    if(l>r)return 0;
    int cur=l,res=1;
    while(cur<=r){
        res+=solve(cur+1,nxt[cur]-1);
        cur=nxt[cur]+1;
    }
    return res;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d%s",&n,s);
        init();
        for(int i=0;i<n*2;i++){
            if(s[i]=='(')
                vec.push_back(i);
            else {
                nxt[vec.back()]=i;
                vec.pop_back();
            }
        }
        printf("%d\n",solve(0,n*2-1));
	}


	return 0;
}