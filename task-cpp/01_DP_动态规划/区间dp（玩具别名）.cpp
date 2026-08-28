#include <bits/stdc++.h>
#define int long long
using namespace std;
map<char,int>mp;
bool can[5][5][5],dp[300][300][5];
//can:i能否由j和k字母合并得到
//dp:【i,j】能否由字母k填满
signed main(){
	int q[5];
	for (int i=1;i<=4;i++) cin >> q[i];
	mp['W'] = 1;
	mp['I'] = 2;
	mp['N'] = 3;
	mp['G'] = 4;
	for (int i=1;i<=4;i++){
		for (int j=1;j<=q[i];j++){
			string str;
			cin >> str;
			can[i][mp[str[0]]][mp[str[1]]] = 1;
		}
	}
	string str;
	cin >> str;
	str = ' ' + str;
	int len = str.length() - 1;
	for (int i=1;i<=len;i++) dp[i][i][mp[str[i]]] = 1;
	for (int length=2;length<=len;length++){
		for (int i=1;i+length-1<=len;i++){
			int j = i + length - 1;
			for (int k=i;k<=j-1;k++){
				for (int z=1;z<=4;z++){
					for (int z1=1;z1<=4;z1++){
						for (int z2=1;z2<=4;z2++){
							dp[i][j][z] |= (dp[i][k][z1]&dp[k+1][j][z2]&can[z][z1][z2]);
						}
					}
				}
			}
		}
	}
	int f = 0;
	for (int i=1;i<=4;i++){
		if (dp[1][len][i]){
			if (i==1) cout << 'W';
			else if (i==2) cout << 'I';
			else if (i==3) cout << 'N';
			else cout << 'G';
			f = 1;
		}
	}
	if (!f) cout << "The name is wrong!";
	return 0;
}
