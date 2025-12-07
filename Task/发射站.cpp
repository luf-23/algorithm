#include <bits/stdc++.h>
using namespace std;
struct Node{
	int h;
	int v;
	int pos;
};
int main()
{
	int n;
	cin >> n;
	int ans[n+1] = {0};
	stack <Node> stk;
	Node node[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> node[i].h >> node[i].v;
		node[i].pos = i;
	}
	for (int i=1;i<=n;i++)
	{
		while (!stk.empty()&&stk.top().h<node[i].h)
		{
			ans[i] += stk.top().v;
			stk.pop();
		}
		if (!stk.empty()) ans[stk.top().pos] += node[i].v;
		stk.push(node[i]);
	}
	int ret = 0;
	for (int i=1;i<=n;i++)
		ret = max(ret,ans[i]);
	cout << ret << endl;
	return 0;
}
