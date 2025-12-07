#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>arr;
int ans = 0;
int n;
bool ishuiwen(vector<int>X)
{
	for (int i=0,j=X.size()-1;i<X.size(),j>=0;i++,j--)
	{
		if (arr[i]!=arr[j]) return false;
	}
	return true;
}
vector<int>add(vector<int>A,vector<int>B)
{
	vector<int>C;
	int t = 0;
	for (int i=0;i<A.size();i++)
	{
		t += A[i]+B[i];
		C.push_back(t%n);
		t /= n;
	}
	while (t)
	{
		C.push_back(t);
		t /= n;
	}
	while (C.back()==0&&C.size()>1) C.pop_back();
	return C;
}
int main()
{
	cin >> n;
	string s;
	cin >> s;
	if (n!=16) for (int i=s.length()-1;i>=0;i--) arr.push_back(s[i]-'0');
	else {
		for (int i=s.length()-1;i>=0;i--)
		{
			if (isdigit(s[i])) arr.push_back(s[i]-'0');
			else if (isalpha(s[i]))
			{
				if (s[i]>='a'&&s[i]<='f') arr.push_back(s[i]-'a'+10);
				else if (s[i]>='A'&&s[i]<='F') arr.push_back(s[i]-'A'+10);
			}
		}
	}
	while (!ishuiwen(arr))
	{
		stack<int>stk;
		for (int i=0;i<arr.size();i++)
		{
			stk.push(arr[i]);
		}
		vector<int>t;
		while (!stk.empty())
		{
			t.push_back(stk.top());
			stk.pop();
		}
		arr = add(arr,t);
		ans++;
		if (ans>30)
		{
			cout << "Impossible!";
			return 0;
		}
	}
	cout << "STEP=" << ans;
	return 0;
}
