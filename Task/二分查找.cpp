#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[n];
	int i;
	for (i=0;i<n;i++)
	{
		cin >> num[i];
	}
	int x;
	cin >> x;
	int left = 0;
	int right = n-1;
	int pos = -1;
	while (left<=right)
	{
		int middle = left + (right-left)/2;
		if (x>num[middle])
		{
			left = middle + 1;
		}else if (x<num[middle])
		{
			right = middle - 1;
		}else{
			pos = middle;
			break;
		}
	}
	if (pos==-1)
	{
		cout << "Not found";
	}else{
		cout << pos;
	}
	return 0;
}
