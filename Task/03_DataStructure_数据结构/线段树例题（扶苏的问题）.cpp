#include <bits/stdc++.h>
#define int long long
using namespace std;
int ttt = 1145141919810;
int n,q;
struct Tree{
	int l,r,lz1,lz2,mx;
}t[5000020];
int num[1000005];
void pushup(int p){
	t[p].mx = max(t[2*p].mx,t[2*p+1].mx);
}
void pushdown1(int p){
	if (t[p].lz1!=ttt){
		t[2*p].mx = t[p].lz1;
		t[2*p+1].mx = t[p].lz1;
		t[2*p].lz2 = t[2*p+1].lz2 = 0;
		t[2*p].lz1 = t[p].lz1;
		t[2*p+1].lz1 = t[p].lz1;
		t[p].lz1 = ttt;
	}
}
void pushdown2(int p){
	if (t[p].lz2){
		pushdown1(p);
		t[2*p].mx += t[p].lz2;
		t[2*p+1].mx += t[p].lz2;
		t[2*p].lz2 += t[p].lz2;
		t[2*p+1].lz2 += t[p].lz2;
		t[p].lz2 = 0;
	}
}
void pushdown(int p){
	pushdown1(p);
	pushdown2(p);
}
void build(int p,int l,int r){
	t[p].l = l;
	t[p].r = r;
	t[p].lz1 = ttt;
	t[p].lz2 = 0;
	if (l==r){
		t[p].mx = num[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
void upd1(int p,int l,int r,int L,int R,int x){
	if (l>R||r<L) return;
	if (l>=L&&r<=R){
		t[p].lz2 = 0;
		t[p].mx = x;
		t[p].lz1 = x;
		return;
	}
	pushdown(p);
	int mid = (l+r)/2;
	upd1(2*p,l,mid,L,R,x);
	upd1(2*p+1,mid+1,r,L,R,x);
	pushup(p);
}
void upd2(int p,int l,int r,int L,int R,int x){
	if (l>R||r<L) return;
	if (l>=L&&r<=R){
		pushdown1(p);
		t[p].mx += x;
		t[p].lz2 += x;
		return;
	}
	pushdown(p);
	int mid = (l+r)/2;
	upd2(2*p,l,mid,L,R,x);
	upd2(2*p+1,mid+1,r,L,R,x);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if (l>R||r<L) return -(LONG_LONG_MAX-1e10);
	if (l>=L&&r<=R) return t[p].mx;
	int mid = (l+r)/2;
	pushdown(p);
	int ans = query(2*p,l,mid,L,R);
	ans = max(ans,query(2*p+1,mid+1,r,L,R));
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> num[i];
	build(1,1,n);
	while (q--){
		int op;
		cin >> op;
		if (op==1){
			int L,R,x;
			cin >> L >> R >> x;
			upd1(1,1,n,L,R,x);
		}else if (op==2){
			int L,R,x;
			cin >> L >> R >> x;
			upd2(1,1,n,L,R,x);
		}else if (op==3){
			int L,R;
			cin >> L >> R;
			int ans = query(1,1,n,L,R);
			cout << ans << '\n';
		}
	}
}
