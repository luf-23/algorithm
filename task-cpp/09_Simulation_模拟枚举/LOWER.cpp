#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string str;
	cin >> str;
	str = ' ' + str;
	int m;
	cin >> m;
	int flag = 0;
	set<int>st;
	while (m--){
		int op,pos;
		char y;
		cin >> op >> pos >> y;
		if (op==1){
			str[pos] = y;
			st.insert(pos);
		}else{
			st.clear();
			if (op==2) flag = -1;
			else flag = 1;
		}
	}
	for (int i=1;i<=n;i++){
		if (!st.count(i)){
			if (flag==-1) cout << (char)tolower(str[i]);
			else if (flag==1) cout << (char)toupper(str[i]);
			else cout << str[i];
		}else{
			cout << str[i];
		}
	}
	return 0;
}
