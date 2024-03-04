#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define ll long long
#define int signed long long
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define pb emplace_back
#define ppb push_back
#define pp pop_back
#define mod 1000000007
#define inf 1e18
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pi 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define uall(x) (x).rbegin(), (x).rend()
#define loop(i,a,n,b) for(long long i=a;i<n;i+=b)
#define reloop(i,a,n,b) for(long long i=a;i>=n;i-=b)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sp ' '
#define sz(x) ((int)(x).size())
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // find_by_order, order_of_key
//oset A;
//A.insert()  --To insert values into the set
//*A.find_by_order(k)  -- finding Kth element
//A.order_of_key(X)  -- number of elements less than X
//A.erase(X)  --Removes element from the set
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<sp<<x<<endl;
#else
#define debug(x)
#endif
 
#define in(n) int n;cin>>n;
#define inp(v,n) vector<int>v(n); loop(i,0,n,1){cin>>v[i];}
#define vi(v,n,x) vector<int>v(n,x);
#define vvi(v,n,m,x) vector<vector<int>>v(n,vector<int>(m,x));
#define str(s) string s; cin>>s;
#define print(x) cout<<x<<endl;
void printvec(vector<int>v){
    for(auto it: v) cout<<it<<sp;
        cout<<endl;
}
 
typedef unsigned long long ull;
typedef long double lld;
 
//void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { _print(p.ff); cerr << sp; _print(p.ss); }
template <class T> void _print(vector <T> v) { for (T i : v) {_print(i); cerr << sp;} }
template <class T> void _print(set <T> v) { for (T i : v) {_print(i); cerr << sp;}  }
template <class T> void _print(multiset <T> v) { for (T i : v) {_print(i); cerr << sp;} }
template <class T, class V> void _print(map <T, V> v) {for (auto i : v) {_print(i); cerr << sp;} }
 
vector<int> seg, lazy;
 
void build(ll ind, ll l, ll r, vector<int> &v) {
    if (l == r) {seg[ind] = v[l]; return ;}
    ll m = (l + r) / 2;
    build(2 * ind + 1, l, m, v);
    build(2 * ind + 2, m + 1, r, v);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
 
ll query(ll ind, ll low, ll high, ll l, ll r) {
    if (lazy[ind] != 0) {
        seg[ind]+= (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high) {
        return 0;
    }
    if (low >= l && high <= r) {
        return seg[ind];
    }
    ll mid = (low + high) / 2;
    ll lft = query(2 * ind + 1, low, mid, l, r);
    ll rgt = query(2 * ind + 2, mid + 1, high, l, r);
    return lft+rgt;
}
 
void update(ll ind, ll low, ll high, ll l, ll r, ll val) {
    //update previous remaining updates
    if (lazy[ind] != 0) {
        seg[ind]+= (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (high < l || r < low) return;
    if (low >= l && high <= r) {
        seg[ind] += (high - low + 1) * val;
        if (low != high) {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return ;
    }
    ll mid = (low + high) / 2;
    update(2 * ind + 1, low, mid, l, r, val);
    update(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind]+= seg[2 * ind + 1] + seg[2 * ind + 2];
}
 
void solve(){
    in(n);
    in(q);
    inp(v,n);
    seg.resize(4*n);
    lazy.resize(4*n);
    build(0,0,n-1,v);
    while(q--){
        in(type);
        if(type&1){
            in(l);
            in(r);
            in(val);
            l--;
            r--;
            update(0,0,n-1,l,r,val);
        }
        else{
            in(l);
            l--;
            cout<<query(0,0,n-1,l,l)<<"\n";
        }
    }
}
 
signed main(){
    fast;
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}