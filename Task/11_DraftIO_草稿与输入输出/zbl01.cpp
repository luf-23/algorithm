#include <bits/stdc++.h>
#define int long long
using namespace std;
//template <typename T>
//inline void read(T &f) {
//	f = 0; T fu = 1; char c = getchar();
//	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
//	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
//	f *= fu;
//}
//template <typename T>
//void print(T x) {
//	if (x < 0) putchar('-'), x = -x;
//	if (x < 10) putchar(x + 48);
//	else print(x / 10), putchar(x % 10 + 48);
//}
//
//template <typename T>
//void print(T x, char t) {
//	print(x); putchar(t);
//}
struct Node{
	int x,y;
};
double dist(Node a,Node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
signed main(){
	//freopen("e.in","r",stdin);
	int n;
	cin >> n;
	Node node[n+1];
	Node ans[10];
	for (int i=1;i<=n;i++){
		cin >> node[i].x >> node[i].y;
	}
	int mnx,mxx,mny,mxy;
	mnx = mny = INT_MAX;
	mxx = mxy = -INT_MAX;
	for (int i=1;i<=n;i++){
		mnx = min(mnx,node[i].x);
		mny = min(mny,node[i].y);
		mxx = max(mxx,node[i].x);
		mxy = max(mxy,node[i].y);
	}
	mnx--;
	mny--;
	mxx++;
	mxy++;
	int l,r,mid;
	l = mny;
	r = mxy;
	//左下
	while (l+1<r){
		mid = (l+r)/2;
		int f = 1;
		for (int i=1;i<=n;i++){
			pair<int,int> a,b;
			a = make_pair(1,-1);
			b = make_pair(node[i].x-mnx,node[i].y-mid);
			if (a.first*b.second-a.second*b.first<=0){
				f = 0;
				break;
			}
		}
		if (f) l = mid;
		else r = mid;
	}
	ans[1] = {mnx,l};
	ans[2] = {mnx+(l-mny),mny};
	//右下
	l = mnx;
	r = mxx;
	while (l+1<r){
		mid = (l+r)/2;
		int f = 1;
		for (int i=1;i<=n;i++){
			pair<int,int> a,b;
			a = make_pair(1,1);
			b = make_pair(node[i].x-mid,node[i].y-mny);
			if (a.first*b.second-a.second*b.first<=0){
				f = 0;
				break;
			}
		}
		if (f) r = mid;
		else l = mid;
	}
	ans[3] = {r,mny};
	ans[4] = {mxx,mny+(mxx-r)};
	//右上
	l = mny;
	r = mxy;
	while (l+1<r){
		mid = (l+r)/2;
		int f = 1;
		for (int i=1;i<=n;i++){
			pair<int,int> a,b;
			a = make_pair(-1,1);
			b = make_pair(node[i].x-mxx,node[i].y-mid);
			if (a.first*b.second-a.second*b.first<=0){
				f = 0;
				break;
			}
		}
		if (f) r = mid;
		else l = mid;
	}
	ans[5] = {mxx,r};
	ans[6] = {mxx-(mxy-r),mxy};
	//左上
	l = mnx;
	r = mxx;
	while (l+1<r){
		mid = (l+r)/2;
		int f = 1;
		for (int i=1;i<=n;i++){
			pair<int,int> a,b;
			a = make_pair(-1,-1);
			b = make_pair(node[i].x-mid,node[i].y-mxy);
			if (a.first*b.second-a.second*b.first<=0){
				f = 0;
				break;
			}
		}
		if (f) l = mid;
		else r = mid;
	}
	ans[7] = {l,mxy};
	ans[8] = {mnx,mxy-(l-mnx)};
	double ret = 0;
	for (int i=1;i<=8;i++){
		if (i!=8){
			ret += dist(node[i],node[i+1]);
		}else{
			ret += dist(node[8],node[1]);
		}
	}
	cout << ret;
	return 0;
}
