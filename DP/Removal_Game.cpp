#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0)

void solve(){
	int n;
	cin>>n;
	vector<int>arr(n);
	vector<ll>pre(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0){
			pre[i] = arr[i];
		}else{
			pre[i] = arr[i]+pre[i-1];
		}
	}

	vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(n,{0,0}));
	
	//gap straighty --> move diagonal

	for(int g=0;g<n;g++){
		//i-->array first element, j--> last element
		for(int i=0,j=g;j<n;j++,i++){
			if(g==0){
				//this is first diagonal we have only one element
				dp[i][j].first = arr[i];
				dp[i][j].second = 0;
			}
			else if(g==1){
				//this is second diagonal, we have two element
				dp[i][j].first = max(arr[i],arr[j]);
				dp[i][j].second = min(arr[i],arr[j]);
			}
			else{
				ll val = arr[i]+min(dp[i+2][j].first,dp[i+1][j-1].first);
				ll val1 = arr[j]+min(dp[i][j-2].first,dp[i+1][j-1].first);
				dp[i][j].first = max(val1,val);
				if(i==0){
					dp[i][j].second = pre[j]-dp[i][j].first;
				}else{
					dp[i][j].second = (pre[j]-pre[i])-dp[i][j].first;
				}
			}
		}
	}
	cout<<(dp[0][n-1].first - 0)<<endl;
}

signed main() {
	
	ll t=1;
	while(t--){
		solve();
	}

	return 0;
}