#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n+=2;
		ll dp[n+1];
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1];
			if((i-2)>=0)
			dp[i]+=dp[i-2];
			if((i-3)>=0)
			dp[i]+=dp[i-3];
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}
