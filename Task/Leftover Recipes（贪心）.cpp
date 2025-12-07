#include <bits/stdc++.h>
using namespace std;
int n;
int num[12];
int A[12];
int B[12];
int ans = 0;
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n;i++) cin >> A[i];
	for (int i=1;i<=n;i++) cin >> B[i];
	int e1,e2;
	e1 = e2 = 1e7;
	for (int i=1;i<=n;i++){
		if (A[i]>0) e1 = min(e1,num[i]/A[i]);
		if (B[i]>0) e2 = min(e2,num[i]/B[i]);
	}
	int ans = 0;
	for (int i=1;i<=e1;i++){
		for (int j=1;j<=n;j++) num[j] -= i*A[j];
		int t = 1e7;
		for (int j=1;j<=n;j++) if (B[j]>0) t = min(t,num[j]/B[j]);
		for (int j=1;j<=n;j++) num[j] += i*A[j];
		ans = max(ans,i+t);
	}
	for (int i=1;i<=e2;i++){
		for (int j=1;j<=n;j++) num[j] -= i*B[j];
		int t = 1e7;
		for (int j=1;j<=n;j++) if (A[j]>0) t = min(t,num[j]/A[j]);
		for (int j=1;j<=n;j++) num[j] += i*B[j];
		ans = max(ans,i+t);
	}
	cout << ans;
	return 0;
}
