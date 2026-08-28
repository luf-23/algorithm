#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int p1 = 13331;
int p2 = 13;
int mod1 = 1e9 + 7;
int mod2 = 1e7 + 9;
int pp1[1000020];
int pp2[1000020];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	pp1[0] = pp2[0] = 1;
	for (int i=1;i<=1e6+5;i++) pp1[i] = pp1[i-1]*p1%mod1;
	for (int i=1;i<=1e6+5;i++) pp2[i] = pp2[i-1]*p2%mod2;
	while (t--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		int tar1,tar2;
		tar1 = tar2 = 0;
		int hash_pre1[n+1];
		int hash_pre2[n+1];
		int hash_suf1[n+2];
		int hash_suf2[n+2];
		int hash_tar1[n+1];
		int hash_tar2[n+1];
		for (int i=1;i<=n;i++) tar1 = (tar1*p1 + t[i])%mod1;
		for (int i=1;i<=n;i++) tar2 = (tar2*p2 + t[i])%mod2;
		hash_pre1[0] = hash_pre2[0] = 0;
		for (int i=1;i<=n;i++) hash_pre1[i] = (hash_pre1[i-1]*p1 + s[i])%mod1;
		for (int i=1;i<=n;i++) hash_pre2[i] = (hash_pre2[i-1]*p2 + s[i])%mod2;
		hash_suf1[n+1] = hash_suf2[n+1] = 0;
		for (int i=n;i>=1;i--) hash_suf1[i] = (hash_suf1[i+1]*p1 + s[i])%mod1;
		for (int i=n;i>=1;i--) hash_suf2[i] = (hash_suf2[i+1]*p2 + s[i])%mod2;
		hash_tar1[0] = hash_tar2[0] = 0;
		for (int i=1;i<=n;i++) hash_tar1[i] = (hash_tar1[i-1]*p1 + t[i])%mod1;
		for (int i=1;i<=n;i++) hash_tar2[i] = (hash_tar2[i-1]*p2 + t[i])%mod2;
		int mx,pos;
		mx = 0;
		pos = 1;
		auto get_pre1 = [&](int bg,int ed){
			return (hash_pre1[ed]-hash_pre1[bg-1]*pp1[ed-bg+1]%mod1+mod1)%mod1;
		};
		auto get_pre2 = [&](int bg,int ed){
			return (hash_pre2[ed]-hash_pre2[bg-1]*pp2[ed-bg+1]%mod2+mod2)%mod2;
		};
		auto get_suf1 = [&](int bg,int ed){
			return (hash_suf1[ed]-hash_suf1[bg+1]*pp1[bg-ed+1]%mod1+mod1)%mod1;
		};
		auto get_suf2 = [&](int bg,int ed){
			return (hash_suf2[ed]-hash_suf2[bg+1]*pp2[bg-ed+1]%mod2+mod2)%mod2;
		};
		//cout << "tar=" << tar << '\n';
		for (int i=1;i<=n;i++){
			//cout << "i,now=" << i << ' ' << get_suf(i,1)*pp[n-i]+get_pre(i+1,n) << '\n';
			if ((get_suf1(i,1)*pp1[n-i]%mod1+get_pre1(i+1,n))%mod1==tar1&&(get_suf2(i,1)*pp2[n-i]%mod2+get_pre2(i+1,n))%mod2==tar2){
				mx = n;
				pos = i;
				break;
			}
			int l,r,mid;
			l = 0,r = n;
			//cout << "i=" << i << '\n';
			while (l+1<r){
				mid = (l+r)/2;
				int now1,now2;
				now1 = now2 = 0;
				if (i>=mid){
					now1 = get_suf1(i,i-mid+1);
					now2 = get_suf2(i,i-mid+1);
				}else{
					now1 = (get_suf1(i,1)*pp1[mid-i]%mod1+get_pre1(i+1,mid))%mod1;
					now2 = (get_suf2(i,1)*pp2[mid-i]%mod2+get_pre2(i+1,mid))%mod2;
				}
				if (now1==hash_tar1[mid]&&now2==hash_tar2[mid]) l = mid;
				else r = mid;
				//cout << now << '\n';
			}
			if (mx<l){
				mx = l;
				pos = i;
			}
		}
		cout << mx << ' ' << pos << '\n';
	}
	return 0;
}
