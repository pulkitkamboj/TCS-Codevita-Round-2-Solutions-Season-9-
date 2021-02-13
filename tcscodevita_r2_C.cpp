#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	set <pair<int,int>> sett;
	set <pair<int,int>> sett1;
	int count=0;
	for(int i=0;i<n;i++){
		int j=0;
		sett=sett1;
		sett1.clear();
		while(j<m){
			if(arr[i][j]==6){
				int st=j;
				while(j<m && arr[i][j]==6){
					j++;
				}
				if(sett.count({st,j-1})==0)
				count++;
				sett1.insert({st,j-1});
				//cout<<st<<" "<<j-1<<"p\n";
			}
			j++;
		}
	}
	int count1=0;
	sett1.clear();
	for(int j=0;j<m;j++){
		int i=0;
		sett=sett1;
		sett1.clear();
		while(i<n){
			if(arr[i][j]==6){
				int st=i;
				while(i<n && arr[i][j]==6){
					i++;
				}
				if(sett.count({st,i-1})==0)
				count1++;
				sett1.insert({st,i-1});
				//cout<<st<<" "<<i-1<<"q\n";
			}
			i++;
		}
	}
	cout<<min(count,count1);
	return 0;
}
