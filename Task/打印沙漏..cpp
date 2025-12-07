#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	char ch;
	cin >> ch;
	vector<int>arr;
	arr.push_back(1);
	for (int i=1;i<=500;i++){
		arr.push_back(arr.back()+2*(3+2*(i-1)));
	}
	int pos = lower_bound(arr.begin(),arr.end(),n)-arr.begin();
	int height;
	int lft;
	if (arr[pos]==n){
		lft = 0;
		height = 1 + 2*pos;
	}else{
		lft = n-arr[pos-1];
		height = 1 + 2*(pos-1);
	}
	int cnt = height;
	for (int i=1;i<=height/2;i++){
		for (int j=1;j<=i-1;j++) cout << ' ';
		for (int j=1;j<=cnt;j++) cout << ch;
		cout << '\n';
		cnt -= 2;
	}
	cnt = height/2;
	int ans = 1;
	for (int i=1;i<=height/2+1;i++){
		for (int j=1;j<=cnt;j++) cout << ' ';
		cnt--;
		for (int j=1;j<=ans;j++) cout << ch;
		ans += 2;
		cout << '\n';
	}
	cout << lft;
	return 0;
}
