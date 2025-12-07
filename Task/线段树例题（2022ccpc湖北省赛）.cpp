#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct Tree{
	int l,r,cnt,sum,lz;
}t[400020];
int a[100005];
int s[100005];
void pushup(int p){
	t[p].sum = t[2*p].sum + t[2*p+1].sum;
	t[p].cnt = t[2*p].cnt + t[2*p+1].cnt;
}
void pushdown(int p){
	if (t[p].lz){
		t[2*p].sum += t[2*p].cnt * t[p].lz;
		t[2*p+1].sum += t[2*p+1].cnt * t[p].lz;
		t[2*p].lz += t[p].lz;
		t[2*p+1].lz += t[p].lz;
		t[p].lz = 0;
	}
}
void build(int p,int l,int r){
	t[p].l = l;
	t[p].r = r;
	t[p].lz = 0;
	if (l==r){
		t[p].cnt = s[l];
		t[p].sum = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
void upd_state(int p,int l,int r,int pos){
	if (pos>r||pos<l) return;
	if (l==r){
		t[p].cnt ^= 1;
		return;
	}
	pushdown(p);
	int mid = (l+r)/2;
	if (pos<=mid) upd_state(2*p,l,mid,pos);
	else upd_state(2*p+1,mid+1,r,pos);
	pushup(p);
}
void upd(int p,int l,int r,int L,int R,int x){
	if (l>R||r<L) return;
	if (l>=L&&r<=R){
		t[p].sum += t[p].cnt * x;
		t[p].lz += x;
		return;
	}
	pushdown(p);
	int mid = (l+r)/2;
	upd(2*p,l,mid,L,R,x);
	upd(2*p+1,mid+1,r,L,R,x);
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
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> s[i];
	build(1,1,n);
	//	cout << "begin:\n";
	//	for (int i=1;i<=7;i++) cout << t[i].sum << ' ';
	//	cout << '\n';
	//	for (int i=1;i<=7;i++) cout << t[i].cnt << ' ';
	//	cout << '\n';
	while (q--){
		int op;
		cin >> op;
		if (op==1||op==2){
			int x;
			cin >> x;
			upd_state(1,1,n,x);
		}else if (op==3){
			int L,R,x;
			cin >> L >> R >> x;
			upd(1,1,n,L,R,x);
		}else if (op==4){
			int L,R;
			cin >> L >> R;
			int ans = query(1,1,n,L,R);
			cout << ans << '\n';
		}
		//		for (int i=1;i<=7;i++) cout << t[i].sum << ' ';
		//		cout << '\n';
		//		for (int i=1;i<=7;i++) cout << t[i].cnt << ' ';
		//		cout << '\n';
	}
}
/*
  4 8
  4 2 5 3
  1 0 0 1
  2 3
  3 1 4 1
  1 3
  4 1 4
  1 1
  2 2
  3 1 3 2
  4 1 4
 */
