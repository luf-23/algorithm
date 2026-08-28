#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[5020];
int pp = 13331;
int hs1[5020];
int hs2[5020];
signed main(){
	//freopen("test.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string str;
	cin >> str;
	p[0] = 1;
	for (int i=1;i<str.length();i++){
		p[i] = p[i-1]*pp;
	}
	int ans = 1;
	for (int len=0;len<str.length()-1;len++){
		string lst = str;
		string pre = str.substr(0,len);
		string bk = str.substr(len);
		str = bk + pre;
		//cout << "str=" << str << '\n';
		int l,r,mid;
		str = ' ' + str;
		l = 1,r = str.length();
		hs1[0] = hs2[str.length()] = 0;
		for (int i=1;i<str.length();i++) hs1[i] = hs1[i-1]*pp + str[i];
		for (int i=str.length()-1;i>=1;i--) hs2[i] = hs2[i+1]*pp + str[i];
		while (l+1<r){
			int mid = (l+r)/2;
			//cout << "mid:" << mid;
			int f = 0;
			for (int i=1;i+mid-1<str.length();i++){
				int now1 = hs1[i+mid-1] - hs1[i-1]*p[mid];
				int now2 = hs2[i] - hs2[i+mid]*p[mid];
				if (now1==now2){ 
					f = 1;
					break;
				}
			}
			for (int i=1;i+mid<str.length();i++){
				int now1 = hs1[i+mid] - hs1[i-1]*p[mid+1];
				int now2 = hs2[i] - hs2[i+mid+1]*p[mid+1];
				if (now1==now2){ 
					f = 1;
					break;
				}
			}
			//f ? cout << " YES\n" : cout << " NO\n";
			if (f) l = mid;
			else r = mid;
		}
		ans = max(ans,l);
		str = lst;
	}
	cout << ans;
	//	cout << "right answer:";
	//	int mx = 1;
	//	for (int len=2;len<str.length();len++){
	//		int f = 0;
	//		for (int i=1;i+len-1<str.length();i++){
	//			string a = str.substr(i,len);
	//			string b = a;
	//			reverse(b.begin(),b.end());
	//			if (a==b) f = 1;
	//		}
	//		if (f) mx = len;
	//	}
	//	cout << mx << '\n';
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
