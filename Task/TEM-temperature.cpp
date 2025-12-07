#include <bits/stdc++.h>
using namespace std;
struct Node {
	int l;
	int r;
	int pos;
};
int main()
{
	int n;
	cin >> n;
	Node node[n+1];
	deque <Node> dq;
	int ans = 1;
	for (int i=1;i<=n;i++)
	{
		cin >> node[i].l >> node[i].r;
		node[i].pos = i;
		while (!dq.empty()&&node[i].r<dq.front().l) dq.pop_front();
		if (!dq.empty())
		{
			ans = max(ans,node[i].pos-dq.front().pos+1);
		}
		int temp = node[i].pos;
		while (!dq.empty()&&dq.back().l<node[i].l)
		{
			temp = dq.back().pos;
			dq.pop_back();
		}
		dq.push_back(Node{node[i].l,node[i].r,temp});
	}
	cout << ans << endl;
	return 0;
}

