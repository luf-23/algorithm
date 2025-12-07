#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int b[100005];
int f[100005];//f[len]为长度为len的公共子序列最后一个元素在b中的下标（尽量要让f[len]小才有可能有更长的子序列
int len;
map<int,int>mp;
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	int len1,len2;
	len1 = len2 = 0;
	set<int>s1,s2;
	for (int i=1;i<=n;i++){
		s1.insert(a[i]);
		s2.insert(b[i]);
	}
	for (int i=1;i<=n;i++){
		if (s2.count(a[i])) a[++len1] = a[i];
		if (s1.count(b[i])) b[++len2] = b[i];
	}
	for (int i=1;i<=len2;i++) mp[b[i]] = i;
	if (len1>0){
		len = 1;
		f[len] = mp[a[1]];
	}
	for (int i=2;i<=len1;i++){
		int pos = upper_bound(f+1,f+len+1,mp[a[i]])-f;
		f[pos] = mp[a[i]];
		if (pos>len) ++len;
	}
	cout << len;
	return 0;
}
