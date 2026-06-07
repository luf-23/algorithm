#include <bits/stdc++.h>
#define int long long
using namespace std;
//求一个字符串由另一个字符串最小的循环所组成，这个最小的循环是多长
int n;
string str;
int f[1000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> str;
	f[0] = 0;
	for (int i=1;i<str.length();i++){
		int j = f[i-1];
		while (j>0&&str[i]!=str[j]) j = f[j-1];
		if (str[i]==str[j]) j++;
		f[i] = j;
	}
	cout << n-f[n-1];
	return 0;
}
