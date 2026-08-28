#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct Tree{
	int l,r,sum;
	int lazy = 0;
}tree[400005];
int num[100005];
void pushdown(int node)
{
	if (tree[node].lazy!=0){
		tree[2*node].lazy += tree[node].lazy;
		tree[2*node+1].lazy += tree[node].lazy;
		int mid = (tree[node].l+tree[node].r)/2;
		tree[2*node].sum += tree[node].lazy*(mid-tree[2*node].l+1);
		tree[2*node+1].sum += tree[node].lazy*(tree[2*node+1].r-mid);
		tree[node].lazy = 0;
	}
	return;
}
void build(int node,int l,int r)
{
	tree[node].l = l;
	tree[node].r = r;
	if (l==r){
		tree[node].sum = num[l];
		return;
	}
	build(2*node,l,(l+r)/2);
	build(2*node+1,(l+r)/2+1,r);
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}
void add(int node,int l,int r,int k)
{
	if (tree[node].l>=l&&tree[node].r<=r){
		tree[node].sum += k*(tree[node].r-tree[node].l+1);
		tree[node].lazy += k;
		return;
	}
	pushdown(node);
	if (tree[2*node].r>=l) add(2*node,l,r,k);
	if (tree[2*node+1].l<=r) add(2*node+1,l,r,k);
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}
int query(int node,int l,int r)
{
	if (tree[node].l>=l&&tree[node].r<=r) return tree[node].sum;
	if (tree[node].r<l||tree[node].l>r) return 0;
	pushdown(node);
	int ans = 0;
	if (tree[node*2].r>=l) ans += query(2*node,l,r);
	if (tree[node*2].l<=r) ans += query(2*node+1,l,r);
	return ans;
}
signed main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> num[i];
	build(1,1,n);
	//	for (int i=1;i<=9;i++) cout << tree[i].sum << ' ';
	//	cout << endl;
	while (m--){
		int op,x,y;
		cin >> op;
		if (op==1){
			int k;
			cin >> x >> y >> k;
			add(1,x,y,k);
		}else{
			cin >> x >> y;
			int ans = query(1,x,y);
			cout << ans << '\n';
		}
	}
	//	for (int i=1;i<=9;i++) cout << tree[i].sum << ' ';
	//	cout << endl;
	return 0;
}
