#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Tree{
	int l,r,sum,lz;
}t[800020];
int n,m;
void pushup(int p){
	t[p].sum = t[2*p].sum + t[2*p+1].sum;
}
void pushdown(int p){
	if (t[p].lz==0) return;
	int mid = (t[p].l+t[p].r)/2;
	t[2*p].sum = (mid-t[p].l+1)-t[2*p].sum;
	t[2*p+1].sum = (t[p].r-mid)-t[2*p+1].sum;
	t[2*p].lz ^= 1;
	t[2*p+1].lz ^= 1;
	t[p].lz = 0;
}
void build(int p,int l,int r){
	t[p].l = l;
	t[p].r = r;
	t[p].lz = 0;
	if (l==r){
		t[p].sum = 0;
		return;
	}
	int mid = (l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
void upd(int p,int l,int r,int L,int R){
	if (l>R||r<L) return;
	//cout << "upd:l,r=" << l << ' ' << r << '\n';
	if (l>=L&&r<=R){
		t[p].sum = (r-l+1) - t[p].sum;
		t[p].lz ^= 1;
		return;
	}
	pushdown(p);
	int mid = (l+r)/2;
	upd(2*p,l,mid,L,R);
	upd(2*p+1,mid+1,r,L,R);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if (l>R||r<L) return 0;
	if (l>=L&&r<=R) return t[p].sum;
	pushdown(p);
	int mid = (l+r)/2;
	int ans = query(2*p,l,mid,L,R);
	ans += query(2*p+1,mid+1,r,L,R);
	return ans;
}
signed main(){
	cin >> n >> m;
	build(1,1,n);
	//	for (int i=1;i<=7;i++) cout << t[i].sum0 << '|' << t[i].sum1 << ' ';
	//	cout << '\n';
	while (m--){
		int op,x,y;
		cin >> op >> x >> y;
		if (op==0){
			upd(1,1,n,x,y);
		}else{
			int ans = query(1,1,n,x,y);
			cout << ans << '\n';
		}
		//		for (int i=1;i<=7;i++) cout << t[i].sum0 << '|' << t[i].sum1 << ' ';
		//		cout << '\n';
	}
}
