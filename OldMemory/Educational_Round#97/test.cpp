#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,a[maxn],k,b[maxn],ans;
int dp[maxn];
int main(){
    a[1]={1};
    int j=upper_bound(a,a+1,1)-a;
    printf("%d\n",j);
    return 0;
}