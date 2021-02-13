#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int superparent(int parent[],int src){
	if(src==parent[src])
	return src;
	return parent[src]=superparent(parent,parent[src]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector <int> arr[n+1];
	int wt[n+1];
	int cnct[n+1];
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>wt[i];
		ans=max(ans,wt[i]);
		cnct[i]=i;
	}
	int e;
	cin>>e;
	for(int i=0;i<e;i++){
		int src,dest;
		cin>>src>>dest;
		int x=superparent(cnct,src);
		int y=superparent(cnct,dest);
		if(x!=y){
			cnct[x]=y;
			wt[y]=wt[x]+wt[y];
			wt[x]=0;
			ans=max(ans,wt[y]);
		}
	}
	cout<<ans;
	return 0;
}
