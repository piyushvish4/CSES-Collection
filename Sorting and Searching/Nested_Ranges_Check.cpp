#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // find_by_order, order_of_key
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

bool comp(pair<int,int>p1,pair<int,int>p2){
    if(p1.F<p2.F) return true;
    if(p1.F==p2.F&&p1.S>p2.S)return true;
    return false;
}

void solve(){
    in(n);
    vector<pair<int,int>>vp(n),temp;
    loop(i,0,n,1)cin>>vp[i].F>>vp[i].S;
    temp=vp;
    sort(uall(temp),comp);
    multimap<pair<int,int>,int>mp;
    loop(i,0,n,1){
        mp.insert({{vp[i].F,vp[i].S},i});
    }
    vi(res1,n,0);
    vi(res2,n,0);
    oset a;
    vi(order,n,0);
    loop(i,0,n,1){
        auto it=mp.find({temp[i].F,temp[i].S});
        order[i]=(*it).S;
        mp.erase(it);
    }
    loop(i,0,n,1){
        int ans=a.order_of_key(temp[i].S+1);
        res1[order[i]]=ans;
        a.insert(temp[i].S);
    }
    a.clear();
    debug(sz(a))
    loop(i,0,n,1) temp[i].S*=-1;
    rrep(i,n-1,0){
        int ans=a.order_of_key(temp[i].S+1);
        res2[order[i]]=ans;
        a.insert(temp[i].S);
    }
    printvec(res1);
    printvec(res2);
}
 
signed main(){
    fast;
    solve();
    return 0;
}