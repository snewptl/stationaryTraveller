#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int a[55],n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        if(a[1]==a[n])puts("NO");
        else {
            puts("YES");
            printf("%d ",a[1]);
            for(int i=n;i>=2;i--)printf("%d ",a[i]);
            puts("");
        }
	}


	return 0;
}