#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int b[100005];
struct Tree{
	int l,r;
	int ans;
	int tag;
}t1[400020],t2[400020],t[400020];
void pushdown(int node,int l,int r){
	int mid = (l+r)/2;
	if (t1[node].tag){
		t1[2*node].tag = t1[2*node+1].tag = 1;
		t1[node].tag = 0;
		t1[2*node].ans = mid-l+1;
		t1[2*node+1].ans = r-mid;
		t[2*node].ans = t2[2*node].ans;
		t[2*node+1].ans = t2[2*node+1].ans;
	}
	if (t2[node].tag){
		t2[2*node].tag = t2[2*node+1].tag = 1;
		t2[node].tag = 0;
		t2[2*node].ans = mid-l+1;
		t2[2*node+1].ans = r-mid;
		t[2*node].ans = t1[2*node].ans;
		t[2*node+1].ans = t1[2*node+1].ans;
	}
}
void build(int node,int l,int r){
	t[node].l = t1[node].l = t2[node].l = l;
	t[node].r = t1[node].r = t2[node].r = r;
	if (l==r){
		t1[node].ans = a[l];
		t2[node].ans = b[l];
		t[node].ans = a[l]&b[l];
		t1[node].tag = t2[node].tag = t[node].tag = 0;
		return;
	}
	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	t[node].ans = t[2*node].ans + t[2*node+1].ans;
	t1[node].ans = t1[2*node].ans + t1[2*node+1].ans;
	t2[node].ans = t2[2*node].ans + t2[2*node+1].ans;
}
void update(int node,int l,int r,int L,int R,int op){
	if (op==1){
		if (l>R||r<L) return;
		if (l>=L&&r<=R){
			t1[node].tag = 1;
			t1[node].ans = r-l+1;
			t[node].ans = t2[node].ans;
			return;
		}
		pushdown(node,l,r);
		int mid = (l+r)/2;
		update(2*node,l,mid,L,R,op);
		update(2*node+1,mid+1,r,L,R,op);
		t[node].ans = t[2*node].ans + t[2*node+1].ans;
		t1[node].ans = t1[2*node].ans + t1[2*node+1].ans;
		t2[node].ans = t2[2*node].ans + t2[2*node+1].ans;
	}
	if (op==2){
		if (l>R||r<L) return;
		if (l>=L&&r<=R){
			t2[node].tag = 1;
			t2[node].ans = r-l+1;
			t[node].ans = t1[node].ans;
			return;
		}
		pushdown(node,l,r);
		int mid = (l+r)/2;
		update(2*node,l,mid,L,R,op);
		update(2*node+1,mid+1,r,L,R,op);
		t[node].ans = t[2*node].ans + t[2*node+1].ans;
		t1[node].ans = t1[2*node].ans + t1[2*node+1].ans;
		t2[node].ans = t2[2*node].ans + t2[2*node+1].ans;
	}
}
int query(int node,int l,int r,int L,int R){
	if (l>R||r<L) return 0;
	if (l>=L&&r<=R) return t[node].ans;
	pushdown(node,l,r);
	int mid = (l+r)/2;
	int ans = query(2*node,l,mid,L,R);
	ans += query(2*node+1,mid+1,r,L,R);
	return ans;
}
signed main(){
	cin >> n;
	char ch;
	getchar();
	for (int i=1;i<=n;i++){
		ch = getchar();
		a[i] = ch-'0';
	}
	getchar();
	for (int i=1;i<=n;i++){
		ch = getchar();
		b[i] = ch-'0';
	}
	build(1,1,n);
	int q;
	cin >> q;
	while (q--){
		char op;
		int x,y;
		cin >> op >> x >> y;
		if (op=='A') update(1,1,n,x,y,1);
		else update(1,1,n,x,y,2);
		//for (int i=1;i<=7;i++) cout << t[i].ans << ' ';
		//cout << endl;
		int ans = query(1,1,n,1,n);
		cout << ans << '\n';
	}
	return 0;
}
