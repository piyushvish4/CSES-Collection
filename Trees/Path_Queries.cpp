#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z)                                                       \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define dbp(x) \
  cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define dbv(v)                         \
  {                                    \
    cout << #v << " : ";               \
    for (auto x : v) cout << x << ' '; \
    cout << endl;                      \
  }
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;
 
using namespace __gnu_pbds;
using namespace std;
 
// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
int n;
vi val, cnt, arr, pos;
vvi adj;
 
void dfs(int node, int par) {
  arr.pb(node);
  cnt[node] = 1;
  for (auto t : adj[node]) {
    if (t != par) {
      dfs(t, node);
      cnt[node] += cnt[t];
    }
  }
}
 
class BIT {
  // 1-based indexing
  vector<int> bit;
  int n;
 
 public:
  BIT(int sz) {
    n = sz;
    bit.assign(n + 1, 0);
  }
  void update(int x, int del) {
    // queries are 1-based
    while (x <= n) {
      bit[x] += del;
      x += x & (-x);
    }
  }
  int query(int x) {
    int ans = 0;
    while (x > 0) {
      ans += bit[x];
      x -= x & (-x);
    }
    return ans;
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
};
 
int32_t main() {
  fastio;
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  int testcases;
  testcases = 1;
  // cin >> testcases;
 
  while (testcases--) {
    int q;
    cin >> n >> q;
    val.resize(n);
    cnt.resize(n);
    adj.resize(n);
    rep(i, 0, n - 1) { cin >> val[i]; }
    int u, v;
    rep(i, 0, n - 2) {
      cin >> u >> v;
      u--;
      v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dfs(0, 0);
    pos.resize(n);
    BIT b(n);
    rep(i, 0, n - 1) {
      pos[arr[i]] = i;
      b.update(i + 1, val[arr[i]]);
      if (i + 1 + cnt[arr[i]] <= n) b.update(i + 1 + cnt[arr[i]], -val[arr[i]]);
    }
    int a, p;
    while (q--) {
      int type;
      cin >> type;
      if (type == 1) {
        cin >> a >> p;
        a--;
        b.update(pos[a] + 1, p - val[a]);
        if (pos[a] + cnt[a] + 1 <= n)
          b.update(pos[a] + cnt[a] + 1, -(p - val[a]));
        val[a] = p;
      } else {
        cin >> a;
        a--;
        cout << b.query(pos[a] + 1) << '\n';
      }
    }
  }
 
  return 0;
}