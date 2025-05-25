#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define endl        '\n'
#define mii         map<ll,ll>
#define msi         map<string,ll>
#define mis         map<ll, string>
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)
#define trav(a, x)  for(auto& a : x)
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pair<ll, ll>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define DEBUG       cerr<<"/n>>>I'm Here<<</n"<<endl;
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl;
#define what_is(x)  cerr << #x << " is " << x << endl;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
#define PI 3.141592653589793
#define MAXN  35005
int tree1[4*MAXN];
int lazy[4*MAXN];
int s[MAXN];
void build(int node, int start, int end)
{
    lazy[node]=0;
    if(start == end)
    {
        // Leaf node will have a single element
        tree1[node] = s[start];
        //cout << tree1[node] << " ";
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree1[node] = min(tree1[2*node],tree1[2*node+1]);
    }
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if (l>r) return;
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree1[node] = tree1[node]+lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree1[node] = tree1[node]+val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree1[node] = min(tree1[node*2],tree1[node*2+1]);        // Updating root with max value 
}

ll queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return hell;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree1[node] = tree1[node]+lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree1[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return min(p1,p2);
}
void solve()
{
    ll n,k;
    cin >> n >> k;
    int a[n];
    rep(i,0,n) cin >> a[i];
    int lastoc[n];
    map <int,int> m1;
    rep(i,0,n){
        if (m1.find(a[i])==m1.end()) lastoc[i]=-1;
        else lastoc[i]=m1[a[i]];
        m1[a[i]]=i;
    }
    int dp[n][k+1];
    dp[0][1]=0;
    rep(i,1,n){
        dp[i][1]=dp[i-1][1];
        if (lastoc[i]!=-1) dp[i][1]+=i-lastoc[i];
    }
    rep(i,2,k+1){
        rep(j,0,n) s[j]=dp[j][i-1];
        build(1,0,n-1);
        rep(j,0,i-1) dp[j][i]=hell;
        dp[i-1][i]=0;
        rep(j,i,n)
        {
            int lastj=lastoc[j];
            if (lastj>0 and (i-2)<(lastj)) {
                updateRange(1,0,n-1,i-2,lastj-1,j-lastj);
            } 
            dp[j][i] = queryRange(1,0,n-1,i-2,j-1);
        }
    }
    cout << dp[n-1][k] << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    #endif
    ll int TEST=1;
    //cin >> TEST;
    //init();
    while(TEST--)
    {
        solve();
    }
}

}