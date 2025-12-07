#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int arr[1000];
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i=0;i<n;i++) arr[i] = i+1;
	do{
		for (int i=0;i<n;i++) cout << arr[i] << ' ';
		cout << endl;
		cnt++;
		sleep(1);
	}while(next_permutation(arr,arr+n));
	cout << endl << cnt << endl;
	return 0;
}
