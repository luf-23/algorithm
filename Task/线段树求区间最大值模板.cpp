#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Tree{
	int l,r;
	int max_v;
}tree[400020];
int num[100005];
int n,m;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void build(int node,int l,int r)
{
	tree[node].l = l;
	tree[node].r = r;
	if (l==r){
		tree[node].max_v = num[l];
		return;
	}
	build(2*node,l,(l+r)/2);
	build(2*node+1,(l+r)/2+1,r);
	tree[node].max_v = max(tree[2*node].max_v,tree[2*node+1].max_v);
}
int query(int node,int L,int R,int l,int r)
{
	if (l>=L&&r<=R) return tree[node].max_v;
	int ans = -INT_MAX;
	int mid = (l+r)/2;
	if (L<=mid) ans = max(ans,query(2*node,L,R,l,mid));
	if (R>mid) ans = max(ans,query(2*node+1,L,R,mid+1,r));
	return ans;
}
signed main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	n = read();
	m = read();
	for (int i=1;i<=n;i++) num[i] = read();
	build(1,1,n);
	//	for (int i=1;i<=15;i++) cout << tree[i].max_v << ' ';
	//	cout << '\n';
	for (int i=1;i<=m;i++){
		int x,y;
		x = read();
		y = read();
		int ans = query(1,x,y,1,n);
		//cout << "ans=" << ans << '\n';
		cout << ans << '\n';
	}
	return 0;
}
