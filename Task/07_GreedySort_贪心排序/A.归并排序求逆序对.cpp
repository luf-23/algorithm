#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[500005];
int pos,n;
int a[500005];
int ans;
void mergesort(int l,int r){
	if (l==r) return;
	int mid = (l+r)/2;
	int l_bg = l;
	int r_bg = mid + 1;
	int pos = l;
	mergesort(l,mid);
	mergesort(mid+1,r);
	while (l_bg<=mid&&r_bg<=r){
		if (a[l_bg]>a[r_bg]) num[pos++]=a[r_bg++],ans+=mid-l_bg+1;
		else num[pos++]=a[l_bg++];
	}
	while (l_bg<=mid) num[pos++] = a[l_bg++];
	while (r_bg<=r) num[pos++] = a[r_bg++];
	for (int i=l;i<=r;i++) a[i] = num[i];
}
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	mergesort(1,n);
	cout << ans << '\n';
	//for (int i=1;i<=n;i++) cout << a[i] << ' ';
	return 0;
}
