#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Tree{
	int l,r,sum,mul,add;
}t[800020];
int n,q,mod;
int num[100005];
//先乘再加，乘的时候mul和add两个懒标记都要乘
void pushup(int p){
	t[p].sum = (t[2*p].sum + t[2*p+1].sum)%mod;
}
void pushdown_mul(int p){
	if (t[p].mul!=1){
		t[2*p].sum *= t[p].mul;
		t[2*p+1].sum *= t[p].mul;
		t[2*p].mul *= t[p].mul;
		t[2*p+1].mul *= t[p].mul;
		t[2*p].sum %= mod;
		t[2*p+1].sum %= mod;
		t[2*p].mul %= mod;
		t[2*p+1].mul %= mod;
		t[p].mul = 1;
	}
}
void pushdown_add(int p){
	if (t[p].add){
		int mid = (t[p].r+t[p].l)/2;
		t[2*p].sum += (mid-t[2*p].l+1)*t[p].add;
		t[2*p+1].sum += (t[2*p+1].r-mid)*t[p].add;
		t[2*p].add += t[p].add;
		t[2*p+1].add += t[p].add;
		t[2*p].sum %= mod;
		t[2*p+1].sum %= mod;
		t[2*p].add %= mod;
		t[2*p+1].add %= mod;
		t[p].add = 0;
	}
}
void pushdown(int p){
	pushdown_mul(p);
	pushdown_add(p);
}
void PD(int p){
	int mid = (t[p].l+t[p].r)/2;
	t[2*p].sum = (t[p].mul*t[2*p].sum + t[p].add*(mid-t[p].l+1))%mod;
	t[2*p+1].sum = (t[p].mul*t[2*p+1].sum + t[p].add*(t[p].r-mid))%mod;
	t[2*p].mul = (t[2*p].mul*t[p].mul)%mod;
	t[2*p+1].mul = (t[2*p+1].mul*t[p].mul)%mod;
	t[2*p].add = (t[2*p].add*t[p].mul+t[p].add)%mod;
	t[2*p+1].add = (t[2*p+1].add*t[p].mul+t[p].add)%mod;
	t[p].add = 0;
	t[p].mul = 1;
}
void build(int p,int l,int r){
	t[p].l = l;
	t[p].r = r;
	t[p].add = 0;
	t[p].mul = 1;
	if (l==r){
		t[p].sum = num[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
void upd_mul(int p,int l,int r,int L,int R,int x){
	if (l>R||r<L) return;
	if (l>=L&&r<=R){
		t[p].sum *= x;
		t[p].mul *= x;
		t[p].add *= x;
		t[p].sum %= mod;
		t[p].mul %= mod;
		t[p].add %= mod;
		return;
	}
	//pushdown(p);
	PD(p);
	int mid = (l+r)/2;
	upd_mul(2*p,l,mid,L,R,x);
	upd_mul(2*p+1,mid+1,r,L,R,x);
	pushup(p);
}
void upd_add(int p,int l,int r,int L,int R,int x){
	if (l>R||r<L) return;
	if (l>=L&&r<=R){
		//pushdown_mul(p);
		t[p].sum += (r-l+1)*x;
		t[p].add += x;
		t[p].sum %= mod;
		t[p].add %= mod;
		return;
	}
	//pushdown(p);
	PD(p);
	int mid = (l+r)/2;
	upd_add(2*p,l,mid,L,R,x);
	upd_add(2*p+1,mid+1,r,L,R,x);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if (l>R||r<L) return 0;
	if (l>=L&&r<=R) return t[p].sum;
	int mid = (l+r)/2;
	//pushdown(p);
	PD(p);
	int ans = 0;
	ans += query(2*p,l,mid,L,R);
	ans %= mod;
	ans += query(2*p+1,mid+1,r,L,R);
	ans %= mod;
	return ans;
}
signed main(){
	cin >> n >> q >> mod;
	for (int i=1;i<=n;i++) cin >> num[i];
	build(1,1,n);
	//	cout << "begin:\n";
	//	for (int i=1;i<=15;i++) cout << t[i].sum << ' ';
	//	cout << '\n';
	while (q--){
		int op;
		cin >> op;
		if (op==1){
			int L,R,x;
			cin >> L >> R >> x;
			upd_mul(1,1,n,L,R,x);
		}else if (op==2){
			int L,R,x;
			cin >> L >> R >> x;
			upd_add(1,1,n,L,R,x);
		}else{
			int L,R;
			cin >> L >> R;
			int ans = query(1,1,n,L,R);
			cout << ans << '\n';
		}
		//		for (int i=1;i<=15;i++) cout << t[i].sum << ' ';
		//		cout << '\n';
	}
}
