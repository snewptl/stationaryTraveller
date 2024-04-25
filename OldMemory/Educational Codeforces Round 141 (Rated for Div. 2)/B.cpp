#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef double db;
const int maxn=2e5+5;
const ll mod=998244353;
const double eps=1e-10;
int n;
int main(){
	int T=1;scanf("%d",&T);
	while(T--){
        scanf("%d",&n);
        int x=1,y=n*n;
        vector<int>vec;
        for(int i=1;i<=n*n;i++){
            if(i%2)vec.push_back(x++);
            else vec.push_back(y--);
            if(i%n==0){
                if(((i-1)/n)%2)reverse(vec.begin(),vec.end());
                for(auto it:vec)printf("%d ",it);
                puts("");
                vec.clear();
            }
        }
	}


	return 0;
}