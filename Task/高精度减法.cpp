#include <bits/stdc++.h>
using namespace std;
int A[11000];
int B[11000];
int C[11000];
int main()
{
	string a,b;
	cin >> a >> b;
	int flag = 1;
	if (a.size()<b.size()||(a.size()==b.size()&&a<b))
	{
		flag = 0;
		swap(a,b);
	}
	int max_v = max(a.size(),b.size());
	for (int i=0;i<a.size();i++) A[i] = a[a.size()-1-i]-'0';
	for (int i=0;i<b.size();i++) B[i] = b[b.size()-i-1]-'0';
	for (int i=0;i<max_v;i++)
	{
		if (A[i]-B[i]<0){
			A[i+1] -= 1;
			A[i] += 10;
		}
		C[i] = A[i] - B[i];
	}
	while (C[max_v-1]==0&&max_v>=0) max_v--;
	if (flag==0) cout << '-';
	for (int i=max_v-1;i>=0;i--) cout << C[i];
	if (max_v==-1) cout << 0;
	return 0;
}
