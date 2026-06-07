#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,a,b;
	cin >> n >> a >> b;
	int num[n+1];
	set<int>st;
	for (int i=1;i<=n;i++){
		cin >> num[i];
		int x = (num[i]-1)%(a+b)+1;
		st.insert(x);
	}
	vector<int>arr;
	for (auto ele : st) arr.push_back(ele);
	int f = 0;
	if (arr.size()==1){
		if (a>=1) f = 1;
	}else{
		if (arr.back()-arr[0]+1<=a) f = 1;
		for (int i=1;i<arr.size();i++){
			int x = a + b + arr[i-1] - arr[i];
			if (x+1<=a) f = 1;
		}
	}
	if (f) cout << "Yes";
	else cout << "No";
	return 0;
}
