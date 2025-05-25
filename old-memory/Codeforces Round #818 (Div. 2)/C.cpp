#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n,a[maxn],b[maxn];
bool solve(){
    for(int i=0;i<n;i++)if(a[i]>b[i])return false;
    for(int i=0;i<n;i++){
        if(b[i]>b[(i+1)%n]+1&&a[i]!=b[i])return false;
    }
    return true;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        if(solve())puts("YES");
        else puts("NO");
	}


	return 0;
}