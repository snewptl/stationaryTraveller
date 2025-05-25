#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn];
int main(){
    int T;scanf("%d",&T);
    while(T--){
		int x;scanf("%d",&x);

        int yv=x%11;
		int shang=x/11;
		if(shang>=yv*10)printf("YES\n");
		else printf("NO\n");
    }


    return 0;
}