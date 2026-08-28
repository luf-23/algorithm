#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin >> t;
	while (t--){
		set<int>st;
		int n,y;
		string str;
		cin >> n >> str;
		cin >> y;
		for (int i=0;i<=9;i++){
			for (int j=0;j<=9;j++){
				if (i!=j){
					for (int k=0;k<=9;k++){
						if (k!=i&&k!=j){
							for (int l=0;l<=9;l++){
								if (l!=i&&l!=j&&l!=k){
									for (int m=0;m<=9;m++){
										int ret = 0;
										for (int q=0;q<n;q++){
											if (str[q]=='a') ret = ret*10 + i;
											else if (str[q]=='b') ret = ret*10 + j;
											else if (str[q]=='c') ret = ret*10 + k;
											else if (str[q]=='d') ret = ret*10 + l;
											else if (str[q]=='_') ret = ret*10 + m;
											else ret = ret*10 + str[q]-'0';
											if (n>1&&ret==0){
												ret = -1;
												break;
											}
										}
										if (ret%8==0&&ret<=y) st.insert(ret);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << st.size() << '\n';
	}
	return 0;
}
