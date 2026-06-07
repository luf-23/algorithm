#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	str = ' ' + str;
	int num[n+1];
	for (int i=1;i<=n;i++) num[i] = str[i] - 'A';
	int low[n+1];
	for (int i=0;i<=n;i++) low[i] = INT_MAX;
	int ans = 1;
	low[1] = num[ans];
	for (int i=2;i<=n;i++){
		if (num[i]>=low[ans]){
			++ans;
			low[ans] = num[i];
		}else{
			int j = upper_bound(low+1,low+ans+1,num[i])-low;
			low[j] = num[i];
		}
	}
	cout << n-ans;
	return 0;
}
