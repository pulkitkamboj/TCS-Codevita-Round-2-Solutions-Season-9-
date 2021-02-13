#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int psday[5];
	int cost[5];
	for(int i=0;i<5;i++)
	cin>>psday[i];
	for(int i=0;i<5;i++)
	cin>>cost[i];
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		s.append(x);
	}
	n=s.size();
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0')
		dp[i]=dp[i-1];
		else
		dp[i]=INT_MAX;
		for(int j=0;j<5;j++){
			dp[i]=min(dp[i],dp[max(0,i-psday[j])]+cost[j]);
		}
	}
	//for(int i=0;i<=n;i++)
	cout<<dp[n];
	return 0;
}
