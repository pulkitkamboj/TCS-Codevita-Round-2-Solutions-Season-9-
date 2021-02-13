#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<int,bool>,string> p;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int pfreq[100001]={0};
	queue <int> qu;
	unordered_map <string,int> mp;
	vector <p> v;
	for(int i=0;i<n;i++){
		int a,l;
		string t;
		cin>>t>>a>>l;
		v.push_back({{a,false},t});
		v.push_back({{a+l,true},t});
	}
	sort(v.begin(),v.end());
	int mxm=0;
	int nxt=1;
	for(int i=0;i<(int)v.size();i++){
		if(v[i].first.second){
			vector <int> xx;
			int tm=v[i].first.first;
			while(i<(int)v.size() && v[i].first.second && tm==v[i].first.first){
				xx.push_back(mp[v[i].second]);
				i++;
			}
			i--;
			sort(xx.begin(),xx.end());
			for(int j=0;j<(int)xx.size();j++)
			qu.push(xx[j]);
		}
		else{
			int pno;
			if(qu.empty())
			pno=nxt++;
			else{
				pno=qu.front();
				qu.pop();
			}
			mp[v[i].second]=pno;
			pfreq[pno]++;
			mxm=max(mxm,pfreq[pno]);
		}
	}
	string x;
	cin>>x;
	cout<<mp[x]<<"\n";
	for(int i=1;i<=100000;i++){
		if(pfreq[i]==mxm)
		cout<<i<<"\n";
	}
	return 0;
}
