#include <bits/stdc++.h>
using namespace std;
bool isprime[1000005];
int main()
{
	for (int i=1;i<=100000;i++) isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for (int i=2;i<=1000000;i++){
		if (isprime[i]){
			for (int j=2*i;j<=100000;j+=i){
				isprime[j] = 0;
			}
		}
	}
	for (int i=1;i<=100000;i++) cout << i << ":" << isprime[i] << "  ";
	return 0;
}
