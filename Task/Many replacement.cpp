#include <bits/stdc++.h>
using namespace std;
int fa[26];
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int q;
	cin >> q;
	for (int i=0;i<26;i++) fa[i] = i;
	while (q--){
		int x,y;
		char X,Y;
		cin >> X >> Y;
		x = X - 'a';
		y = Y - 'a';
		for (int i=0;i<26;i++){
			if (fa[i]==x){
				fa[i] = y;
			}
		}
	}
	for (int i=0;i<str.length();i++){
		int x = fa[str[i]-'a'];
		cout << (char)(x+'a');
	}
	return 0;
}
/*#include <bits/stdc++.h>
  using namespace std;
  vector<int>arr[1000005];
  int main()
  {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--){
  int n,m;
  cin >> n >> m;
  int num[n+1];
  set<int>st;
  for (int i=1;i<=n;i++){
  cin >> num[i];
  st.insert(num[i]);
  arr[num[i]].push_back(i);
  }
  while (m--){
  int x,y;
  cin >> x >> y;
  if (x==y) continue;
  if (arr[x].size()>arr[y].size()) swap(arr[x],arr[y]);
  for (auto ele : arr[x]) arr[y].push_back(ele);
  arr[x].clear();
  st.erase(x);
  st.insert(y);
  }
  for (auto E : st){
  for (auto e : arr[E]){
  num[e] = E;
  }
  arr[E].clear();
  }
  for (int i=1;i<=n;i++) cout << num[i] << ' ';
  cout << '\n';
  }
  return 0;
  }*/
