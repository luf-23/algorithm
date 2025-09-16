### ACM算法竞赛模板

详见：[C++算法竞赛模板](https://www.cnblogs.com/lightmon5210/p/18183718)

### 高精度

详见：[高精度](https://blog.csdn.net/Sharon_zhugecat/article/details/133414228)

**高精度加法**

```c++
#include<bits/stdc++.h>
using namespace std;

vector<int>add(vector<int>&v1,vector<int>&v2) { // 模拟加法进位
	if(v1.size()<v2.size()) return add(v2,v1);
	vector<int>v3;
	int t=0,sz1=v1.size(),sz2=v2.size();
	v3.reserve(sz1+1);
	for(int i=0; i<sz1; i++) {
		t+=v1[i];
		if(i<sz2)t+=v2[i];
		v3.push_back(t%10);
		t/=10;
	}
	if(t) v3.push_back(t); // 进位
	return v3;
}

string str1,str2;
vector<int>v1,v2;
int main() {
	cin>>str1>>str2;
	int sz1=str1.size(),sz2=str2.size();
	v1.reserve(sz1),v2.reserve(sz2);
	for(int i=sz1-1; i>=0; i--)v1.push_back(str1[i]-'0'); // 逆序
	for(int i=sz2-1; i>=0; i--)v2.push_back(str2[i]-'0'); // 逆序
	vector<int>v3=add(v1,v2);
	for(int i=v3.size()-1; i>=0; i--)cout<<v3[i]; // 逆序输出
}
```

**高精度减法**

```c++
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&v1, vector<int>&v2) { // 比较大小
	if(v1.size()!=v2.size())return v1.size()>v2.size();
	for(int i=v1.size()-1; i>=0; i--) {
		if(v1[i]!=v2[i]) return v1[i]>v2[i];
	}
	return true;
}

vector<int>sub(vector<int>&v1,vector<int>&v2) {
	vector<int>v3;
	int t=0;
	for(int i=0; i<v1.size(); i++) {
		t=v1[i]-t; // 减去借位
		if(i<v2.size()) t-=v2[i];
		v3.push_back((t+10)%10);
		if(t<0) t=1; // 表示借位
		else t=0;
	}
	while(v3.size()>1&&v3.back()==0) v3.pop_back(); //去除大于1位数的首位为0
	return v3;
}

string s1,s2;
vector<int>v1,v2;
int main() {
	cin>>s1>>s2;
	for(int i=s1.size()-1; i>=0; i--) v1.push_back(s1[i]-'0'); // 逆序
	for(int i=s2.size()-1; i>=0; i--) v2.push_back(s2[i]-'0'); // 逆序
	if(cmp(v1,v2)) {
		vector<int>v3=sub(v1,v2);
		for(int i=v3.size()-1; i>=0; i--) cout<<v3[i];
	} else {
		vector<int>v3=sub(v2,v1);
		cout<<"-"; // 输出符号
		for(int i=v3.size()-1; i>=0; i--) cout<<v3[i];
	}
}
```

**高精度乘法（高精度×高精度）**

```c++
#include<bits/stdc++.h>
using namespace std;

vector<int>mul(vector<int>&v1,vector<int>&v2) {
	vector<int>v3(v1.size()+v2.size());
	for(int i=0; i<v1.size(); i++) {
		for(int j=0; j<v2.size(); j++) {
			v3[i+j]+=v1[i]*v2[j];
			v3[i+j+1]+=v3[i+j]/10;
			v3[i+j]%=10;
		}
	}
	while(v3.size()>1&&v3.back()==0)v3.pop_back();
	return v3;
}
int main() {
	string s1,s2;
	vector<int>v1,v2;
	cin>>s1>>s2;
	for(int i=s1.size()-1; i>=0; i--)v1.push_back(s1[i]-'0');
	for(int i=s2.size()-1; i>=0; i--)v2.push_back(s2[i]-'0');
	vector<int>v3=mul(v1,v2);
	for(int i=v3.size()-1; i>=0; i--)cout<<v3[i];
}
```

**高精度除法（高精度÷高精度）**

```c++
#include <bits/stdc++.h>
using namespace std;
// 减法部分
int a[101], b[101], c[101], d, i;
void inp(int a[]) { // 读入 
    string s;
    cin >> s; //读入字符串
    a[0] = s.size(); //a[0]储存字符串的长度
    for (i = 1; i <= a[0]; i++) a[i] = s[a[0] - i] - '0';
}
void pri(int a[]) { // 输出 
    if (a[0] == 0) {
        cout << "0" << endl;
        return;
    }
    for (i = a[0]; i > 0; i--) cout << a[i];
    cout << endl;
    return;
}
int cmp(int a[], int b[]) {//比较a和b的大小关系，若a>b则为1，若a<b则为-1，若a=b则为0
    if (a[0] > b[0]) return 1;  //若a的位数大于b，则a>b
    if (a[0] < b[0]) return -1;  //若a的位数小于b，则a<b
    for (i = a[0]; i > 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}
void jian(int a[], int b[]) {
    int pd = cmp(a, b); // 比较大小 
    if (pd == 0) { // 相等 
        a[0] = 0;
        return;
    }
    else if (pd == 1) {
        for (i = 1; i <= a[0]; i++) {
            if (a[i] < b[i]) a[i + 1]--, a[i] += 10; // 借位 
            if (a[i] >= b[i]) a[i] -= b[i];
        }
        while ((a[a[0]] == 0) && (a[0] > 0)) a[0]--;
        return;
    }
}
void numcpy(int p[], int q[], int det) {
    for (i = 1; i <= p[0]; i++) q[i + det - 1] = p[i];
    q[0] = p[0] + det - 1;
}
void chugao(int a[], int b[], int c[]) {
    int i, tmp[101];
    c[0] = a[0] - b[0] + 1;
    for (i = c[0]; i > 0; i--) {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b, tmp, i);
        while (cmp(a, tmp) >= 0) {
            c[i]++;
            jian(a, tmp);
        }
    }
    while ((c[c[0]] == 0) && (c[0] > 0)) c[0]--;
}

// 应用部分 
int main() {
    inp(a), inp(b);
    chugao(a, b, c);
    pri(c), pri(a);
    return 0;
}
```

**高精度除法（高精度÷低精度）**

```c++
#include<bits/stdc++.h>
using namespace std;

vector<int>div(vector<int>&a,int b,int&r)
{
	vector<int>c;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		r = r * 10 + a[i];
		c.push_back(r/b);
		r %= b;
	}
	reverse(c.begin(), c.end());
	while (c.size() > 1 && c.back() == 0)c.pop_back();
	return c;
}
int main() {
	string str;
	int b,r=0;
	vector<int>a;
	cin >> str >> b;
	for (int i = str.size() - 1; i >= 0; i--)a.push_back(str[i] - '0');
	vector<int>c = div(a, b,r);
	for (int i = c.size() - 1; i >= 0; i--)cout << c[i];
	cout << endl << r;
}
```

### 二分

题单链接：[二分题单](https://leetcode.cn/circle/discuss/SqopEo/)

在排序数组中查找元素的第一个和最后一个元素

```c++
class Solution {
public:
    int findFirst(vector<int>&v,int t){ // 查找第一个
        int n=v.size();
        int l=0,r=n-1,mid,ind=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(v[mid]==t){
                ind=mid;
                r=mid-1; // 关键
            }else if(v[mid]>t){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ind;
    }
    int findLast(vector<int>&v,int t){ // 查找最后一个
        int n=v.size();
        int l=0,r=n-1,ind=-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(v[mid]==t){
                ind=mid;
                l=mid+1; // 关键
            }else if(v[mid]>t){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{findFirst(nums,target),findLast(nums,target)};
    }
};
```

使用内置函数

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1, -1};
        auto index1 = lower_bound(nums.begin(), nums.end(),target); // 返回第一个大于等于迭代器
        auto index2 = upper_bound(nums.begin(), nums.end(),target); // 返回第一个大于tar的迭代器
        if (index1 == nums.end() || *index1 != target) return {-1, -1}; // 这个值根本不存在
        return {(int)distance(nums.begin(), index1),(int)distance(nums.begin(), index2 - 1)}; //转为int
    }
};
```

**浮点数二分**

与整数二分相比，只需找到一个能够满足精度的解就行，没有这么多边界条件，不用考虑比较相等的情况，可以直接把区间分成两侧>和<=这两部分。

```c++
// 求保留6位数字的立方根
void solve() {
	double x;
	cin >> x;
	double l = -100, r = 100, mid;
	while (r - l > 1e-8) {
		mid = l + (r - l) / 2;
		if (mid * mid * mid >x)r = mid;
		else l = mid;
	}
	printf("%.6f", l);
}
```

### 分组循环

题目链接：[最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/description/)

一般来说，模板为

```c++
void solve() {
	int n=arr.size(),i=0,ans=0;
	while(i<n){ // 当条件需要和i+1下标比较时，改成i<n-1 
		/*
		if(不符合条件){
			i++;
			continue;
		}
		*/
		int start=i; // 记录开始的位置
		i++; // 跳到下一个需要判断的位置，不一定是1
		while(i<n&&(符合条件)){
			i++;
		}
		ans=max(ans,i-start); // i不符合条件，所以范围是[start,i-1]
        //i--; // 可能拐点也是下一个数组的起点
	}
}
```

这么写的好处是各个逻辑块分工明确，也不需要特判最后一组（易错点）。

```c++
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]>threshold||nums[i]%2){
                i++;
                continue;
            }
            int start=i;
            i++; // 找下一个
            while(i<n&&nums[i]%2!=nums[i-1]%2&&nums[i]<=threshold){
                i++;
            }
            ans=max(ans,i-start);
        }
        return ans;
    }
};
```

题目链接：[最长交替子数组](https://leetcode.cn/problems/longest-alternating-subarray/description/)

```c++
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size(),ans=-1;
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]!=1){
                i++;
                continue;
            }
            int start=i;
            i+=2; // 前两个都符合条件
            while(i<n&&nums[i]==nums[i-2]){
                i++;
            }
            ans=max(ans,i-start);
            i--; // 可能拐点是下一个子数组的起点
        }
        return ans;
    }
};
```



### 置换环

题目链接：[数列排序](https://ac.nowcoder.com/acm/contest/73799/C)

置换环用来求解数组**排序元素间所需最小交换次数**这类问题，置换环将每个元素指向其排序后应在的位置，最终首尾相连形成一个环**（若数字在最终位置，则其自身成环）**，可知元素之间的交换只会在同一个环内进行，而每个环内的最小交换次数为**环上元素-1**，总和为数组的元素个数-环的个数。

```c++
void solve() {
	int n, ans = 0; // 交换次数
	cin >> n;
	vector<int>arr(n), vis(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int>tmp(arr.begin(), arr.end());
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin(); // 对数组离散化
	}
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		int cnt = 0, j = i; // 统计环内元素个数
		while (!vis[j]) {
			vis[j] = 1;
			j = arr[j];
			cnt++;
		}
		ans += cnt - 1; // 一个环需要交换 cnt-1 次
	}
	cout << ans;
}
```

### ST表

详见：[ST表](https://oi-wiki.org/ds/sparse-table/)

题目链接：[区间极差](https://www.luogu.com.cn/problem/P2880)

$st$表是一种简单的数据结构，主要用来解决$RMQ$（区间最值问题）问题，它主要应用倍增的思想，可以实现$O(nlogn)$预处理、$O(1)$查询。$st$表可以用于解决可重复贡献问题的数据结构，令$f(i,j)$表示区间$[i,i+2^j-1]$的最大值，显然$f(i,0)=a_i$，对于每次询问，我们把它分为两个部分：$[l,l+2^s-1]$和$[r-2^s+1,r]$，其中$s=\lfloor log_2(r-l+1) \rfloor$，由于最大值是可重复贡献问题，重叠并不会对区间最大值产生影响。

```c++
const int N = 5e4 + 5;
int st_max[N][21], st_min[N][21], lg[N], n, h, q, l, r;
int mx, mn, ans;
void solve() {
	cin >> n >> q;
	for (int i = 2; i <= n; i++) { // 预处理 log2 ,从2开始
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> h;
		st_max[i][0] = st_min[i][0] = h;
	}
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
			st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
		}
	}
	while (q--) {
		cin >> l >> r;
		int t = lg[r - l + 1]; // t为区间长度
		mx = max(st_max[l][t], st_max[r - (1 << t) + 1][t]);
		mn = min(st_min[l][t], st_min[r - (1 << t) + 1][t]);
		ans = mx - mn;
		cout << ans << endl;
	}
}
```

### 前缀和

**一维前缀和模板**

```c++
int sum(vector<int>& dp, int left, int right) { // 求从[left,right]区间内的元素和
	return dp[right] - dp[left - 1]; // -1是因为包含left
}
void solve() {
	vector<int>nums{ 1,2,3,4,5 };
	vector<int>dp(nums.size()+1); // 前缀和，dp[i]表示前i个数的和，多开一个元素，不用单独讨论为0的情况
	for (int i = 0; i < nums.size(); i++) {
		dp[i + 1] = dp[i] + nums[i];
	}
	cout << sum(dp, 1, 4); // 10
}
```

**二维前缀和**

$dp[i+1][j+1]$表示以$(i,j)$为右下角的二维前缀和

```c++
class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        dp.resize(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
};
```

**前缀和的前缀和**

题目链接：[巫师的总力量和](https://leetcode.cn/problems/sum-of-total-strength-of-wizards/description/)

### 差分

题目链接：[统计奇数](https://ac.nowcoder.com/acm/problem/209813)

详见：[差分](https://blog.csdn.net/qq_63786973/article/details/127667301)

**一维差分**：
$$
d_n=
\begin{cases}
a_1 & (如果n=1)\\
a_n-a_{n-1}&(如果n>1)
\end{cases}
$$
那么可以通过差分数组求区间每个元素对应的值，当对某个区间（`left`和`right`）进行修改时，我们只需要修改差分区间`d[left]`和`d[right+1]`的值就行（记住要把数组的大小加一，不然可能会数组越界），求$a[i]$，只需要不断累加$d[i]$即可。

```c++
class Solution {
public:
    int oddnumber(int n, int m, vector<int>& l, vector<int>& r) {
        vector<int>d(n+2); // 扩大数组大小
        d[1]=m,d[n+1]=-m;
        for(int i=0;i<l.size();i++){
            int left=l[i],right=r[i];
            d[left]++,d[right+1]--; // left和right+1的值变化
        }
        int sum=0,odd=0;
        for(int i=1;i<=n;i++){
            sum+=d[i]; // 不断累加求 a[i]
            odd+=sum%2;
        }
        return odd;
    }
};
```

**二维差分**

详见：[二维差分](https://blog.csdn.net/2301_77160836/article/details/136824769)

题目链接：[地毯](https://www.luogu.com.cn/problem/P3397)

差分可以看成前缀和的逆运算，这里设$a[i][j]$为以$b[i][j]$为右下角的二维前缀和，由二维前缀和公式得
$$
a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j]
$$
那么反过来看，把$a$看成原数组，$b$就成了差分数组，得出二维差分公式为
$$
b[i][j]=a[i][j]-a[i][j-1]-a[i-1][j]+a[i-1][j-1]
$$
当对一个矩阵范围的元素进行同时加一个元素$c$时，只需要对四个点进行运算
$$
\begin{flalign}
&b[x1][y1]+=c\\
&b[x1][y2 + 1]-=c\\
&b[x2 + 1][y1]-=c\\
&b[x2 + 1][y2 + 1]+=c
\end{flalign}
$$

```c++
const int N = 1005;
int a[N][N], b[N][N], n, m; // a为原矩阵，b为差分矩阵
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b[i][j] = a[i][j] - a[i][j - 1] - a[i - 1][j] + a[i - 1][j - 1]; // 二维差分公式
		}
	}
	while (m--) {
		int  x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; // 对四个点进行运算
		b[x1][y1]++;
		b[x1][y2 + 1]--;
		b[x2 + 1][y1]--;
		b[x2 + 1][y2 + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + b[i][j]) << " "; // 二维前缀和
		}
		cout << endl;
	}
}
```

### 树状数组

详见：[树状数组](https://blog.csdn.net/TheWayForDream/article/details/118436732)

树状数组可以解决大部分区间上面的修改以及查询的问题，例如**1.单点修改，区间查询，2.区间修改，单点查询**，换言之，线段树能解决的问题，树状数组大部分也可以，但是并不一定都能解决，因为线段树的扩展性比树状数组要强，其中$tree[i]$维护的区间为$[i-lowbit(i)+1,i]$。

优点：修改和查询操作复杂度于线段树一样都是$O(logn)$,但是常数比线段树小，并且实现比线段树简单。

缺点：扩展性弱，线段树能解决的问题，树状数组不一定能解决。

1、数组不变，求区间和：「前缀和」、「树状数组」、「线段树」
2、多次修改某个数（单点），求区间和：「树状数组」、「线段树」
3、多次修改某个区间，输出最终结果：「差分」
4、多次修改某个区间，求区间和：「线段树」、「树状数组」（看修改区间范围大小）
5、多次将某个区间变成同一个数，求区间和：「线段树」、「树状数组」（看修改区间范围大小）

**单点修改，区间查询**：

```c++
const int N = 5e5 + 5;
int tree[N], n, m;
int lowbit(int x) { // 求低比特位1
	return x & -x;
}
void update(int x, int k) { // 单点修改
	for (int i = x; i <= n; i += lowbit(i)) {
		tree[i] += k;
	}
}
int query(int x) { // 区间查询(1~x的区间和)
	int sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}
```

**区间修改，单点查询**：

先转化为差分数组，区间更新就变成了$left$和$right+1$的单点修改，求单点值就变成了差分数组的区间和。

```c++
const int N = 5e5 + 5;
int arr[N],tree[N], n, m;
int lowbit(int x) {
	return x & -x;
}
void update(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tree[i] += k;
	}
}
ll query(int x) {
	ll sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
    // 转化为差分数组
	for (int i = 1; i <= n; i++) {
		if (i == 1)update(i, arr[i]);
		else update(i, arr[i] - arr[i - 1]);
	}
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			update(x, k); // left更新
			update(y + 1, -k); // right+1更新
		}
		else {
			int x;
			cin >> x;
			cout << query(x)<<endl;
		}
	}
}
```

**区间最值（不带修改）**

详见：[树状数组求区间最值](https://www.luogu.com.cn/problem/solution/P2880)

建树与求区间和一致，只是换成最大值和最小值，但是求区间最值不能通过相减的方式得到，分为$y-lowbit(y)>x$和$y-lowbit(y)<x$两种情况。

```c++
const int N = 5e4 + 5;
int treex[N], treen[N], arr[N], n, q;
int l, r;
int lowbit(int x) {
	return x & -x;
}
void update(int x, int k) { // 赋初始值，没有修改
	for (int i = x; i <= n; i += lowbit(i)) {
		treex[i] = max(treex[i], k);
		treen[i] = min(treen[i], k);
	}
}
int query_max(int x, int y) { // 求区间最大值
	if (x == y)return arr[x]; // 相等则返回
	if (y - lowbit(y) > x) { // [x,y-lowbit(y)]和[y-lowbit(y)+1,y]即tree[y]
		return max(query_max(x, y - lowbit(y)), treex[y]);
	}
	else { // [x,y-1]和arr[y]
		return max(query_max(x, y - 1), arr[y]);
	}
}
int query_min(int x, int y) { // 求区间最小值
	if (x == y)return arr[x];
	if (y - lowbit(y) > x) {
		return min(query_min(x, y - lowbit(y)), treen[y]);
	}
	else {
		return min(query_min(x, y - 1), arr[y]);
	}
}
void solve() {
	cin >> n >> q;
	memset(treen, 0x3f, sizeof(treen)); // 给treen赋最大值，treex为0可以不用赋值
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	while (q--) {
		cin >> l >> r;
		cout << query_max(l, r) - query_min(l, r) << endl;
	}
}
```

**区间最值（带修改）**

详见：[树状数组](https://oi-wiki.org/ds/fenwick/)

```c++
void update(int x, int k) { // 带修改
	arr[x] = k; // 先将原先的赋值
	for (int i = x; i <= n; i += lowbit(i)) {
        // 枚举受影响的区间
		tree[i] = arr[i];
		for (int j = 1; j < lowbit(i); j*=2) { // 与子树比较
			tree[i] = max(tree[i], tree[i - j]);
		}
	}
}
```

**树状数组求逆序对**：

```c++
const int N = 5e5 + 5;
ll arr[N], tmp[N], tree[N], si, n;
int lowbit(int x) {
	return x & -x;
}
void update(int x, int k) {
	for (int i = x; i <= si; i += lowbit(i)) {
		tree[i] += k;
	}
}
ll query(int x) {
	ll sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}
void solve() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}
    // 离散化
	sort(tmp + 1, tmp + 1 + n);
	si = unique(tmp + 1, tmp + 1 + n) - (tmp + 1);
	for (int i = 1; i <= n; i++)arr[i] = lower_bound(tmp + 1, tmp + 1 + si, arr[i]) - tmp;
    // 逆序遍历
	for (int i = n; i >= 1; i--) {
		update(arr[i], 1);
		ans += query(arr[i] - 1);
	}
	cout << ans;
}
```

**树状数组求三元上升子序列**：

```c++
const int N = 3e4 + 5;
ll arr[N], tmp[N], tree[N], _left[N], _right[N], n, si;
int lowbit(int x) {
	return x & -x;
}
void update(int x, int k) {
	for (int i = x; i <= si; i+=lowbit(i)) {
		tree[i] += k;
	}
}
ll query(int x) {
	ll sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i], tmp[i] = arr[i];
	sort(tmp + 1, tmp + 1 + n);
	si = unique(tmp + 1, tmp + 1 + n) - (tmp + 1);
	for (int i = 1; i <= n; i++) {
		arr[i] = lower_bound(tmp + 1, tmp + 1 + si, arr[i]) - tmp;
	}
    // 求左边比该元素小的元素个数
	for (int i = 1; i <= n; i++) {
		update(arr[i], 1);
		_left[i] = query(arr[i] - 1);
	}
    // 记得清0
	memset(tree, 0, sizeof(tree));
    // 求右边比该元素大的元素个数
	for (int i = n; i >= 1; i--) {
		update(arr[i], 1);
		_right[i] = query(si) - query(arr[i]);
	}
	ll ans = 0;
    // 遍历中间元素
	for (int i = 1; i <= n; i++) {
		ans += 1LL * _left[i] * _right[i]; // 乘法原理
	}
	cout << ans;
}
```

### 线段树

详见：[线段树讲解](https://zhuanlan.zhihu.com/p/106118909)

**区间修改、区间查询（懒标记）**：

```c++
const int N = 1e5 + 5;
ll arr[N], tree[N << 2], lazy[N << 2];
int n, m, op, x, y, k;
void push_up(int p) { // 向上传递（子节点区间整合）
	tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
void push_down(int l, int r, int p) { // 向下传递（父节点区间传递懒标记）
	int mid = l + (r - l) / 2;
	lazy[p << 1] += lazy[p]; // 更新子节点的标记
	lazy[p << 1 | 1] += lazy[p];
	tree[p << 1] += (mid - l + 1) * lazy[p]; // 更新子节点的值
	tree[p << 1 | 1] += (r - mid) * lazy[p];
	lazy[p] = 0; // 注意要清除懒标记
}
void build(int l, int r, int p) { // 建树直到遇见叶子节点
	if (l == r) {
		tree[p] = arr[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	push_up(p); // 当子节点建完后，整合父节点
}
void update(int l, int r, int p, int tl, int tr, ll k) {
	if (l >= tl && r <= tr) { // 该区间被包含，更新节点和懒标记
		lazy[p] += k; // 打了个懒标记，就不向下传递了
		tree[p] += (r - l + 1) * k;
		return;
	}
	int mid = l + (r - l) / 2;
	push_down(l, r, p); // 往下面传递时，需要传递懒标记了
	if (tl <= mid)update(l, mid, p << 1, tl, tr, k); // 左子节点和目标区间有交集
	if (tr > mid)update(mid + 1, r, p << 1 | 1, tl, tr, k); // 右子节点和目标区间有交集
	push_up(p); // 子节点的值已经发生改变，需要向上整合
}
ll query(int l, int r, int p, int tl, int tr) {
	if (l >= tl && r <= tr) { // 区间被包含，直接返回
		return tree[p];
	}
	int mid = l + (r - l) / 2;
	push_down(l, r, p); // 向下传递
	ll res = 0;
	if (tl <= mid)res += query(l, mid, p << 1, tl, tr);
	if (tr > mid)res += query(mid + 1, r, p << 1 | 1, tl, tr);
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	build(1, n, 1);
	while (m--) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> k;
			update(1, n, 1, x, y, k);
		}
		else {
			cin >> x >> y;
			cout << query(1, n, 1, x, y) << endl;
		}
	}
}
```

结构体写法：

```c++
const int N = 1e5 + 5;
ll n, m, op, x, y, k, arr[N];
struct tree {
	int l, r;
	ll sum, add;
}tr[N << 2];
void push_up(int p) {
	tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}
void push_down(int p) {
	tr[p << 1].add += tr[p].add;
	tr[p << 1 | 1].add += tr[p].add;
	tr[p << 1].sum += tr[p].add * (tr[p << 1].r - tr[p << 1].l + 1);
	tr[p << 1 | 1].sum += tr[p].add * (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1);
	tr[p].add = 0; // 清除懒标记
}
void build(int l, int r, int p) {
	tr[p].l = l, tr[p].r = r; // 注意给l和r赋值
	if (l == r) {
		tr[p].sum = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	push_up(p);
}
void update(int l, int r, int p, ll k) {
	if (tr[p].l >= l && tr[p].r <= r) {
		tr[p].add += k;
		tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
		return;
	}
	push_down(p);
	int mid = (tr[p].l + tr[p].r) / 2;
	if (l <= mid)update(l, r, p << 1, k);
	if (r > mid)update(l, r, p << 1 | 1, k);
	push_up(p);
}
ll query(int l, int r, int p) {
	if (tr[p].l >= l && tr[p].r <= r) {
		return tr[p].sum;
	}
	push_down(p);
	int mid = (tr[p].l + tr[p].r) / 2;
	ll res = 0;
	if (l <= mid)res += query(l, r, p << 1);
	if (r > mid)res += query(l, r, p << 1 | 1);
	return res;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	build(1, n, 1);
	while (m--) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> k;
			update(x, y, 1, k);
		}
		else {
			cin >> x >> y;
			cout << query(x, y, 1) << endl;
		}
	}
}
```

**维护乘法和加法（先乘后加）**

```c++
const int N = 1e5 + 5;
ll arr[N], tree[N << 2], lz_add[N << 2], lz_mul[N << 2]; // 分别维护加法和乘法的懒标记
ll n, q, m, x, y, k, op;
void push_up(int p) {
	tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % m;
}
void push_down(int l, int r, int p) {
	int mid = l + (r - l) / 2;
	lz_mul[p << 1] = lz_mul[p << 1] * lz_mul[p] % m;
	lz_mul[p << 1 | 1] = lz_mul[p << 1 | 1] * lz_mul[p] % m;
	lz_add[p << 1] = (lz_add[p << 1] * lz_mul[p] + lz_add[p]) % m; // 先乘后加
	lz_add[p << 1 | 1] = (lz_add[p << 1 | 1] * lz_mul[p] + lz_add[p]) % m;
	tree[p << 1] = (tree[p << 1] * lz_mul[p] + lz_add[p] * (mid - l + 1)) % m; // 先乘后加
	tree[p << 1 | 1] = (tree[p << 1 | 1] * lz_mul[p] + lz_add[p] * (r - mid)) % m;
	lz_add[p] = 0;
	lz_mul[p] = 1; // 注意要清除懒标记
}
void build(int l, int r, int p) {
	lz_mul[p] = 1;
	if (l == r) {
		tree[p] = arr[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	push_up(p);
}
void update_add(int l, int r, int p, int tl, int tr, ll k) {
	if (l >= tl && r <= tr) {
		lz_add[p] = (lz_add[p] + k) % m;
		tree[p] = (tree[p] + (r - l + 1) * k) % m;
		return;
	}
	int mid = l + (r - l) / 2;
	push_down(l, r, p);
	if (tl <= mid)update_add(l, mid, p << 1, tl, tr, k);
	if (tr > mid)update_add(mid + 1, r, p << 1 | 1, tl, tr, k);
	push_up(p);
}
void update_mul(int l, int r, int p, int tl, int tr, ll k) {
	if (l >= tl && r <= tr) {
		lz_mul[p] = lz_mul[p] * k % m;
		lz_add[p] = lz_add[p] * k % m; // 更新乘法懒标记时也要更新加法懒标记
		tree[p] = tree[p] * k % m;
		return;
	}
	int mid = l + (r - l) / 2;
	push_down(l, r, p);
	if (tl <= mid)update_mul(l, mid, p << 1, tl, tr, k);
	if (tr > mid)update_mul(mid + 1, r, p << 1 | 1, tl, tr, k);
	push_up(p);
}
ll query(int l, int r, int p, int tl, int tr) {
	if (l >= tl && r <= tr) {
		return tree[p];
	}
	int mid = l + (r - l) / 2;
	push_down(l, r, p);
	ll res = 0;
	if (tl <= mid)res = (res + query(l, mid, p << 1, tl, tr)) % m;
	if (tr > mid)res = (res + query(mid+1, r, p << 1 | 1, tl, tr)) % m;
	return res;
}
```

**区间最值区间修改（加法和赋值）**

```c++
const int N = 1e6 + 5;
ll arr[N], tree[N<<2], lazy1[N<<2], lazy2[N<<2];
bool vis[N<<2];
ll n, q, op, x, y, k;
void push_up(int p) {
	tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}
void push_down(int p) {
	if (vis[p]) { // 如果有赋值操作，则子节点的标记全部删除，父节点传递懒标记给子节点
		lazy1[p << 1] = lazy1[p];
		lazy1[p << 1 | 1] = lazy1[p];
		lazy2[p << 1] = lazy2[p];
		lazy2[p << 1 | 1] = lazy2[p];
		tree[p << 1] = lazy1[p] + lazy2[p];
		tree[p << 1 | 1] = lazy1[p] + lazy2[p];
		vis[p << 1] = vis[p << 1 | 1] = 1;
	}
	else { // 类似于区间加法
		lazy2[p << 1] += lazy2[p];
		lazy2[p << 1 | 1] += lazy2[p];
		tree[p << 1] += lazy2[p];
		tree[p << 1 | 1] += lazy2[p];
	}
	lazy1[p] = lazy2[p] = vis[p] = 0;
}
void build(int l, int r, int p) {
	int mid = l + (r - l) / 2;
	if (l == r) {
		tree[p] = arr[l];
		return;
	}
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	push_up(p);
}
void update1(int l, int r, int p, int tl, int tr, ll k) { // 赋值操作
	int mid = l + (r - l) / 2;
	if (l >= tl && r <= tr) {
		vis[p] = 1;
		lazy1[p] = k;
		lazy2[p] = 0; // 赋值后要清空lazy2标记
		tree[p] = k;
		return;
	}
	push_down(p);
	if (tl <= mid)update1(l, mid, p << 1, tl, tr, k);
	if (tr > mid)update1(mid + 1, r, p << 1 | 1, tl, tr, k);
	push_up(p);
}
void update2(int l, int r, int p, int tl, int tr, ll k) { // 加法操作
	int mid = l + (r - l) / 2;
	if (l >= tl && r <= tr) {
		lazy2[p] += k;
		tree[p] += k;
		return;
	}
	push_down(p);
	if (tl <= mid)update2(l, mid, p << 1, tl, tr, k);
	if (tr > mid)update2(mid + 1, r, p << 1 | 1, tl, tr, k);
	push_up(p);
}
ll query(int l, int r, int p, int tl, int tr) {
	int mid = l + (r - l) / 2;
	if (l >= tl && r <= tr) {
		return tree[p];
	}
	push_down(p);
	ll res = LLONG_MIN;
	if (tl <= mid)res = max(res, query(l, mid, p << 1, tl, tr));
	if (tr > mid)res = max(res, query(mid + 1, r, p << 1 | 1, tl, tr));
	return res;
}
```

**区间最大字段和（单点修改）**

题目链接：[最大字段和](https://www.luogu.com.cn/problem/SP1716)

维护每个区间的以左端点开始的最大字段和、以右端点结束的最大字段和、最大的字段和、区间和，最大的字段和由两个区间的最大字段和以及两个区间中间的部分组成。

```c++
const int N = 5e4+5;
struct tree{
	int l, r;
	ll lmax, rmax, mx, sum; // 维护四个变量，左，右，最大的字段和，总和
}tr[N<<2];
ll n, q, op, x, y, arr[N];
void push_up(int p) {
	tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
	tr[p].lmax = max(tr[p << 1].lmax, tr[p << 1].sum + tr[p << 1 | 1].lmax);
	tr[p].rmax = max(tr[p << 1 | 1].rmax, tr[p << 1 | 1].sum + tr[p << 1].rmax);
	tr[p].mx = max(max(tr[p << 1].mx, tr[p << 1 | 1].mx), tr[p << 1].rmax + tr[p << 1 | 1].lmax); // 三部分
}
void build(int l, int r, int p) {
	tr[p].l = l, tr[p].r = r;
	if (l == r) {
		tr[p].lmax = tr[p].rmax = tr[p].mx = tr[p].sum = arr[l];
		return;
	}
	int mid = (tr[p].l + tr[p].r) / 2;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
	push_up(p);
}
void update(int p, int x, int y) { // 单点更新
	if (tr[p].l == tr[p].r) {
		tr[p].lmax = tr[p].rmax = tr[p].sum = tr[p].mx = y;
		return;
	}
	int mid = (tr[p].l + tr[p].r) / 2;
	if (x <= mid)update(p << 1, x, y);
	else update(p << 1 | 1, x, y);
	push_up(p);
}
tree query(int l, int r, int p) {
	if (tr[p].l >= l && tr[p].r <= r) {
		return tr[p];
	}
	int mid = (tr[p].l + tr[p].r) / 2;
	if (l > mid)return query(l, r, p << 1 | 1); // 只有右边的
	if (r <= mid)return query(l, r, p << 1); // 只有左边的
	tree ans, a, b;
	a = query(l, r, p << 1), b = query(l, r, p << 1 | 1); // 两边都有，整合
	ans.sum = a.sum + b.sum;
	ans.lmax = max(a.lmax, a.sum + b.lmax);
	ans.rmax = max(b.rmax, a.rmax + b.sum);
	ans.mx = max(max(a.mx, b.mx), a.rmax + b.lmax);
	return ans;
}
```



### 离散化

详见：[离散化](https://oi-wiki.org/misc/discrete/)

1. 创建原数组的副本。
2. 将副本中的值从小到大排序。
3. 将排序好的副本去重。
4. 查找原数组的每一个元素在副本中的位置，位置即为排名，将其作为离散化后的值。

```c++
void solve() {
	vector<int>nums {3,4,3,4,5};
	vector<int>tmp(nums.begin(),nums.end());
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	for(int i=0; i<nums.size(); i++) {
		nums[i]=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin()+1;
	}
	for(int i=0;i<nums.size();i++)cout<<nums[i]<<" "; // 1 2 1 2 3
}
```



### 单调队列

题目链接：[设计自助结算系统](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/description/)	[绝对值不超过限制的最长子数组](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

维护一个队列记录商品的增加和删除，维护一个单调递减的双端队列记录当前商品的最大值，为什么是单调递减的，因为在一系列商品后增加一个大的商品，前面比该商品小的都不能成为最大值，因为如果前面的商品还在队列中，它们后面的商品也在队列中，所以前面的删除，放入一个比较小的，虽然不能成为前面的最大值，但有可能成为后面的最大值，所以单调递减。

### 堆的懒删除

题目链接：[餐盘栈](https://leetcode.cn/problems/dinner-plate-stacks/description/)

利用最小堆维护所有的未满栈，每次添加元素时，在最小的未满栈里添加元素，如果满了则弹出；如果堆为空，则stacks添加一个栈，如果容量大于1，将这个下标入堆；删除某个下标的元素同时将stacks末尾的空的栈删除，堆内的下标不需要同时更新（懒删除），当堆里面的最小元素都大于stacks.size()-1时，清空堆。

```c++
class DinnerPlates {
public:
    int capacity;
    vector<stack<int>>stacks; // 末尾的栈非空
    priority_queue<int,vector<int>,greater<int>>pq; // 维护最小的未满栈下标
    DinnerPlates(int capacity):capacity(capacity) {}
    
    void push(int val) {
        if(!pq.empty()&&pq.top()>=stacks.size()){ // 如果最小的下标超过stacks的大小，全部清空
            while(!pq.empty()){
                pq.pop();
            }
        }
        if(pq.empty()){
            stack<int>s;
            s.push(val);
            stacks.emplace_back(s);
            if(capacity>1){
                pq.push(stacks.size()-1); // 新的未满栈
            }
        }else{
            int id=pq.top();
            stacks[id].push(val);
            if(stacks[id].size()==capacity)pq.pop(); // 栈满
        }
    }
    
    int pop() {
        return popAtStack(stacks.size()-1);
    }
    
    int popAtStack(int index) {
        if(index<0||index>=stacks.size()||stacks[index].empty())return -1;
        if(stacks[index].size()==capacity) // 得到新的未满栈
        pq.push(index);
        int ans=stacks[index].top();
        stacks[index].pop();
        while(!stacks.empty()&&stacks.back().empty())stacks.pop_back(); // 懒删除
        return ans;
    }
};
```



### 数位DP

题目链接：[至少有1位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits/description/)

定义dfs(i,mask,is_limit,is_num)为表示构造第 *i* 位及其之后数位的合法方案数，对于记忆化数组只需要记录!is_limit&&is_num的状态，因为对于is_limit状态只有一种重复状态就是按照数字上面的每一位数填，对于!is_num状态只有一种重复状态，就是前面不填数字。

解决题目：

要求统计满足一定条件的数的数量（即，最终目的为计数）；
这些条件经过转化后可以使用「数位」的思想去理解和判断；
输入会提供一个数字区间（有时也只提供上界）来作为统计的限制；
上界很大。

```c++
class Solution {
public:
    int m;
    string str;
    vector<vector<int>>memo;
    int dfs(int i,int mask,bool is_limit,bool is_num){
        if(i==m)return is_num;
        if(!is_limit&&is_num&&memo[i][mask]!=-1)return memo[i][mask];
        int res=0;
        if(!is_num)res=dfs(i+1,mask,false,false);
        int up=is_limit?str[i]-'0':9;
        for(int j=1-is_num;j<=up;j++){
            if(((mask>>j)&1)==0)
            res+=dfs(i+1,mask|(1<<j),is_limit&&j==up,true);
        }
        if(!is_limit&&is_num)
        memo[i][mask]=res;
        return res;
    }
    int numDupDigitsAtMostN(int n) {
        str=to_string(n);
        m=str.size();
        memo.resize(m,vector<int>(1<<10,-1));
        return n-dfs(0,0,true,false); // 刚开始，受限制并且没有数字
    }
};
```

题目链接：[不含连续1的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/description/?envType=daily-question&envId=2024-08-05)

这题不填数字和填0是一样的效果，可以省略参数is_num，pre记录的是前一个数字。

```c++
class Solution {
public:
    vector<vector<int>>memo;
    string str;
    int si;
    int dfs(int i,int pre,bool is_limit){
        if(i==si)return 1;
        if(!is_limit&&memo[i][pre]!=-1)return memo[i][pre];
        int up=is_limit?str[i]-'0':1;
        int res=0;
        for(int j=0;j<=up;j++){
            if(j!=1||pre!=1){
                res+=dfs(i+1,j,is_limit&&j==up);
            }
        }
        if(!is_limit)memo[i][pre]=res;
        return res;
    }
    int findIntegers(int n) {
        while(n){
            str+='0'+n%2;
            n/=2;
        }
        reverse(str.begin(),str.end());
        si=str.size();
        memo.resize(si,vector<int>(2,-1));
        return dfs(0,0,true);
    }
};
```

### 二叉树的四种遍历方式

详见：[二叉树的四种遍历方式](https://blog.csdn.net/zhuguanlin121/article/details/118215643)

**先序遍历**：根-左-右

**中序遍历**：左-根-右

**后序遍历**：左-右-根

**层次遍历**：从上到下每一层从左到右的遍历

**求先序排列**：

详见：[求先序排列](https://www.luogu.com.cn/problem/P1030)

```c++
#include<bits/stdc++.h>
using namespace std;

void dfs(string s1,string s2){
    if(s1.size()>0){
    char ch=s2[s2.size()-1];
    cout<<ch;
    int k=s1.find(ch);
    dfs(s1.substr(0,k),s2.substr(0,k));
    dfs(s1.substr(k+1),s2.substr(k,s2.size()-1-k));
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    dfs(s1,s2);
}
```

### 对称二叉树

题目链接：[对称二叉树](https://leetcode.cn/problems/symmetric-tree/description/)

将一棵树关于y轴对称转化为两颗树关于y轴对称。

```c++
class Solution {
public:
    bool dfs(TreeNode*r1,TreeNode*r2){
        if(r1==NULL&&r2==NULL)return true;
        if(r1==NULL||r2==NULL)return false;
        if(r1->val!=r2->val)return false;
        return dfs(r1->left,r2->right)&&dfs(r2->left,r1->right); // 递归判断左右子树
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};
```

### DFS

**普通DFS**

题目链接：[寻找图中是否存在路径](https://leetcode.cn/problems/find-if-path-exists-in-graph/)

```c++
class Solution {
public:
    vector<int>vis; // 确保每个点只被访问一次
    vector<vector<int>>g; // 邻接表
    void dfs(int s){
        vis[s]=1; // 访问到那个点直接标记
        for(int v:g[s]){ // 访问相邻的点
            if(!vis[v]) // 如果没有被访问才访问，确保每个点只被访问一次
            dfs(v);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int edge_num=edges.size();
        vis.resize(n),g.resize(n);
        for(int i=0;i<edge_num;i++){ // 邻接表存图
            int u=edges[i][0],v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(source);
        return vis[destination];
    }
};
```

**DFS求连通块大小**

题目链接：[统计无向图中无法互相到达点对数](https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

```c++
class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    int n;
    int cnt; // 维护每个连通块大小
    void dfs(int s){
        cnt++;
        vis[s]=1;
        for(int v:g[s]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        this->n=n;
        vis.resize(n),g.resize(n);
        for(int i=0;i<edges.size();i++){ // 建图
            int u=edges[i][0],v=edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long sum_cnt=0,ans=0; // sum_cnt表示先前的连通块大小之和
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt=0; // 连通块大小记得初始化为0
                dfs(i);
                ans+=cnt*sum_cnt;
                sum_cnt+=cnt;
            }
        }
        return ans;
    }
};
```

### BFS

**普通BFS**

```c++
void solve() {
	queue<int>q;
	q.push(0); // 放入起点
	vis[0] = 1; // vis 数组标记是否入队
	while (!q.empty()) {
		int si = q.size();
		for (int i = 0; i < si; i++) { // 分层
			int u = q.front();
			q.pop();
			for (int v : g[u]) {
				if (!vis[v]) { // 没有入队
					vis[v] = 1; // 标记
					q.push(v); // 则入队
				}
			}
		}
	}
}
```

**带状态的BFS**

题目链接：[颜色交替的最短路径](https://leetcode.cn/problems/shortest-path-with-alternating-colors/description/)

```c++
class Solution {
public:
    // 0 red 1 blue
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>g(n);
        vector<int>ans(n,INT_MAX);
        vector<vector<int>>vis(n,vector<int>(2));
        int dep=0;
        ans[0]=0;
        for(int i=0;i<redEdges.size();i++){
            int u=redEdges[i][0],v=redEdges[i][1];
            g[u].push_back({v,0});
        }
        for(int i=0;i<blueEdges.size();i++){
            int u=blueEdges[i][0],v=blueEdges[i][1];
            g[u].push_back({v,1});
        }
        queue<pair<int,int>>q;
        q.push({0,0}),q.push({0,1});
        vis[0][0]=vis[0][1]=1;
        while(!q.empty()){
            int si=q.size();
            dep++;
            for(int i=0;i<si;i++){
                auto t=q.front();
                q.pop();
                int u=t.first,w=t.second;
                for(auto&p:g[u]){
                    int v=p.first,w2=p.second;
                    if(w2!=w&&!vis[v][w2]){
                        vis[v][w2]=1;
                        ans[v]=min(ans[v],dep);
                        q.push({v,w2});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)ans[i]=(ans[i]==INT_MAX?-1:ans[i]);
        return ans;
    }
};
```

**多源BFS**

题目链接：[找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/)

```c++

```

### 树上问题

**二叉树的直径**

一条路径的长度为该路径的节点数-1，所以求直径等价于求节点数再-1，而任意一条路径均可以被看作由某个节点为起点，从其左儿子和右儿子向下遍历的路径拼接得到，所以直径为所有$L+R-1$的最大值再-1。

```c++
class Solution {
public:
    int ans;
    int dep(TreeNode*root){ // 计算最大深度的节点数
        if(root==NULL)return 0;
        int L=dep(root->left); // 左子树深度
        int R=dep(root->right); // 右子树节深度
        ans=max(ans,L+R+1);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;
        dep(root);
        return ans-1; // 答案为节点数-1
    }
};
```

**二叉树中的最大路径和**

最大路径和由某棵子树的根节点的权值和左子树右子树的最大贡献组成，当左子树或右子树的最大贡献小于0时，则舍弃。

```c++
class Solution {
public:
    int ans=INT_MIN;
    int dfs(TreeNode*root){
        if(root==NULL)return 0;
        int L=max(dfs(root->left),0); // 左子树的最大贡献
        int R=max(dfs(root->right),0); // 右子树的最大贡献
        ans=max(ans,L+R+root->val);
        return max(L,R)+root->val; // 最大贡献
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

**树的直径**

题目链接：[树的直径](https://www.spoj.com/problems/PT07Z/)

**方法一**

若权值为**非负**，根据定理在树上的一个节点进行$DFS$到达的距离其最远的节点必为**直径的一端**，则可以随便在一个节点$DFS$找到直径的一端，再到这个节点进行$DFS$找到另一个直径的一端，于是就找到了直径的两端；

**性质**：若边权非负，从任意一个点$DFS$到达最远的点一定为直径的一端。

**性质**：若树上所有边权均为正，则树的所有直径中点重合。

```c++
const int N = 1e4 + 5;
vector<int>g[N];
int d[N], n, node; // d数组记录到起点的距离，node记录直径的端点
void dfs(int u, int fa) {
	for (int v : g[u]) {
		if (v != fa) {
			d[v] = d[u] + 1;
			if (d[v] > d[node])node = v;
			dfs(v, u);
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1); // 从仍一节点出发到达最远的节点为直径的一端
	d[node] = 0; // 以node为起点
	dfs(node, -1); // 找直径的另一端
	cout << d[node] << endl;
}
```

**方法二**

若权值有负，则采用树形dp，求出以$u$为起点出发的最长路径，那么直径长度为每个节点为根节点的两条最大路径长度之和的最大值。

```c++
const int N = 1e4 + 5;
vector<int>g[N];
int dp[N], n, d; // d记录直径长度，dp[u]表示以u为根的子树中，从u出发的最长路径
void dfs(int u, int fa) {
	for (int v : g[u]) {
		if (v != fa) {
			dfs(v, u);
			d = max(d, dp[u] + dp[v] + 1); // 在更新之前，d=max(d,dp[u]+dp[v]+w(u,v))
			dp[u] = max(dp[u], dp[v] + 1); // 更新路径的最大值
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	cout << d << endl;
}
```



### 最小环

详见：[最小环](https://oi-wiki.org/graph/min-cycle/)

题目链接：[图中的最短环](https://leetcode.cn/problems/shortest-cycle-in-a-graph/description/)

**删边+最短路**，枚举每条边，假设删除这条边，求两者的最短路，最小环的权值等于最小路加上删除的边权，注意有向图的方向。

```c++
class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    int bfs(int start,int end){ // bfs求最短路
        fill(vis.begin(),vis.end(),0);
        int dep=0;
        queue<int>q;
        q.push(start),vis[start]=1;
        while(!q.empty()){
            int si=q.size();
            dep++;
            for(int i=0;i<si;i++){
                int u=q.front();
                q.pop();
                for(int v:g[u]){
                    if(u==start&&v==end)continue; // 删边
                    if(v==end)return dep; // 找到终点
                    if(!vis[v]){
                        q.push(v),vis[v]=1;
                    }
                }
            }
        }
        return INT_MAX/2; // 没有路径
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX/2;
        g.resize(n),vis.resize(n);
        for(auto&e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for(auto&e:edges){ // 枚举每条边
            ans=min(ans,bfs(e[0],e[1])+1); // 最短路+删除的边权
        }
        return ans<INT_MAX/2?ans:-1;
    }
};
```

### 拓扑排序

详见：[拓扑排序](https://oi-wiki.org/graph/topo/)

题目链接：[课程表Ⅱ](https://leetcode.cn/problems/course-schedule-ii/description/)

先遍历所有的点，将所有入度为0的点入队，每次弹出一个点并将其加入答案，将所有与它相邻的点的入度-1，如果入度为0，则入队，直到队列为空，判断入队的点数是否为所有的点数，如果是，则是$DAG(有向无环图)$，否则有环；有向无环图一定能拓扑排序。

```c++
class Solution {
public:
    vector<int>ans;
    vector<vector<int>>g;
    vector<int>indeg; // 记录入度
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses),indeg.resize(numCourses);
        for(auto&e:prerequisites){
            g[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)q.push(i); // 入度为0的入队
        }
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u); // 加入答案
            q.pop();
            for(int v:g[u]){ // 所有相邻的点入度减1
                indeg[v]--;
                if(indeg[v]==0){ // 入度为0入队
                    q.push(v);
                }
            }
        }
        if(ans.size()<numCourses)return {};
        return ans;
    }
};
```

### 最近公共祖先（LCA）

题目链接：[最近公共祖先](https://www.luogu.com.cn/problem/P3379)

倍增的思想，设$fa[i][j]$为第$i$个节点的$2^j$个祖先节点，$fa[i][0]$就等于它的父节点，值为0表示没有这个祖先，先让它们到达同一高度，然后每次跳到$2^k$个节点，注意$k$是从大到小的，因为从低位开始会有反悔的动作，并且不能跳到祖先节点和它上方，要跳到祖先节点下面一个节点，最后返回这个节点的父节点。

```c++
const int N = 5e5+5;
struct edge {
	int to, next;
}ed[2*N];
int head[N], depth[N], lg[N];
int fa[N][30];
int cnt = 0, n, m, s;
void add_edge(int u, int v) {
	cnt++;
	ed[cnt].to = v;
	ed[cnt].next = head[u];
	head[u] = cnt;
}
void dfs(int u, int parent) {
	depth[u] = depth[parent] + 1;
	fa[u][0] = parent; // 第一个祖先节点为父节点
	for (int i = 1; i <= lg[depth[u]]; i++) {
		fa[u][i] = fa[fa[u][i-1]][i - 1];
	}
	for (int i = head[u]; i; i = ed[i].next) {
		if (ed[i].to != parent) {
			dfs(ed[i].to, u);
		}
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);
	int t = depth[a] - depth[b]; // 距离差值
	for (int i = 0; i <= lg[t]; i++) { // 二进制分解，使它们到达同一高度
		if ((t >> i) & 1) {
			a = fa[a][i];
		}
	}
	if (a == b)return a; // 已经重合直接返回
	for (int i = lg[depth[a]]; i >= 0; i--) { // 从大到小
		if (fa[a][i] != fa[b][i]) { // 要跳到下方一个节点
			a = fa[a][i], b = fa[b][i];
		}
	}
	return fa[a][0]; // 返回父节点
}
void solve() {
	cin >> n >> m >> s;
	for (int i = 2; i < N; i++)lg[i] = lg[i / 2] + 1;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(s, 0);
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
}
```

### 并查集

题目链接：[寻找图中是否存在路径](https://leetcode.cn/problems/find-if-path-exists-in-graph/description/)

详见：[并查集](https://oi-wiki.org/ds/dsu/)

**路径压缩版**并查集：

find函数是路径压缩的版本，fa表示每个节点的父节点，如果两个节点都有同一个父节点，说明他们是相连的；cnt表示每个联通的集合的大小，只有当节点是集合的父节点时才表示这个集合的大小，merge采用启发式合并，合并时，选择哪棵树的根节点作为新树的根节点会影响未来操作的复杂度。我们可以将节点较少或深度较小的树连到另一棵，以免发生退化。

```c++
struct Union{
    vector<int>fa,cnt;
    Union(int n):fa(n),cnt(n,1){
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x])); // 路径压缩
    }
    // 启发式合并
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return;
        if(cnt[x]<cnt[y])swap(x,y); 
        fa[y]=x; // 选择节点较小的树连到另一颗
        cnt[x]+=cnt[y];
    }
    bool isConect(int x,int y){
        return find(x)==find(y);
    }
    void disConnect(int x){
        --cnt[find(x)];
        fa[x]=x;
    }
};
```

**按秩合并**并查集：

rank[x]代表x这个元素在自己集合构成的森林中的层数。因为并查集还未合并，所以每个元素代表一个集合，即他自己就是代表元，并且层数是0，把秩小的连到大的上面，如果秩不相等，则秩不变，否则被连的秩增加。

```c++
struct Union{
    vector<int>fa,rank;
    Union(int n):fa(n),rank(n){
        for(int i=0;i<n;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    // 按秩合并
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            if(rank[x]>rank[y]){
                fa[y]=x;
            }else{
                if(rank[x]==rank[y])rank[y]++;
                fa[x]=y;
            }
        }
    }
    bool isConect(int x,int y){
        return find(x)==find(y);
    }
    void disConnect(int x){
        fa[x]=x;
    }
};
```

**并查集求连通块大小**：

题目链接：[统计无向图中无法互相到达点对数](https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

```c++
class Solution {
public:
    vector<int>fa,si; // si统计连通块大小
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){ // 按秩合并，合并后，父节点的si值增加
            if(si[x]>si[y]){
                fa[y]=x;
                si[x]+=si[y]; 
            }else{
                fa[x]=y;
                si[y]+=si[x];
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        fa.resize(n),si.resize(n,1);
        for(int i=0;i<n;i++)fa[i]=i;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            merge(u,v);
        }
        long long ans=0,cnt=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){ // 判断父节点是不是自己
                ans+=cnt*si[find(i)]; // 这里必须使用find(i)找它的父节点，而不是fa[i]
                cnt+=si[find(i)];
            }
        }
        return ans;
    }
};
```

**并查集求连通块数量**：

题目链接：[连通网络的操作次数](https://leetcode.cn/problems/number-of-operations-to-make-network-connected/description/)

```c++
class Solution {
public:
    vector<int>fa;
    int cnt; // 连通块数量
    int find(int x){
        return fa[x]==x?x:(fa[x]=find(fa[x]));
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){ // 不是同一个连通块时合并
            fa[x]=y;
            cnt--; // 两个连通块合并时，数量-1
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        fa.resize(n),cnt=n;
        for(int i=0;i<n;i++)fa[i]=i;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0],v=connections[i][1];
            merge(u,v);
        }
        return cnt-1;
    }
};
```

**种类并查集**：

题目链接：[食物链](https://www.luogu.com.cn/problem/P2024)  [团伙](https://www.luogu.com.cn/problem/P1892)

1. 种类并查集：即在普通并查集“**亲戚的亲戚也是亲戚**”的基础上再进行一些“**分类**”，但是这个分类呢并不是根据物品的种类来进行分类，而是类似“**敌人的敌人是朋友**”的分类（**并没有说明“朋友的敌人是我的敌人”！要根据具体题目分析**）
2. 种类并查集常规套路：不是开多个或多维并查集数组，而是**扩大并查集规模**

对于敌人的敌人是朋友，可以开两倍规模的并查集，前一半维护朋友，后一半维护敌人，例如a和b是朋友，直接将它们合并；如果它们是敌人将a和（b+n）合并，b和（a+n）合并，这样当a和c是敌人时，a和（c+n）合并，c和（a+n）合并，b和c由于都和（a+n）合并，所以成为了朋友，注意并查集合并时是有顺序的，要让后面的指向前面。

对于食物链，可以开三倍的长度，分别代表三种族群，对于每次同类或者天敌进行三次合并。

```c++
struct Union {
	vector<int>fa, rank;
	Union(int n) :fa(2 * n + 1), rank(2 * n + 1) { // 开两倍大小，前面为朋友，后面为敌人
		for (int i = 1; i <= 2 * n; i++)
			fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}
	void merge(int x, int y) { // 后一半指向前一半
		x = find(x), y = find(y);
		if (x != y)fa[y] = x;
	}
	bool isConnect(int x, int y) {
		return find(x) == find(y);
	}
};
void solve() {
	int n, m;
	cin >> n >> m;
	Union uni(n);
	for (int i = 0; i < m; i++) {
		char ch;
		int x, y;
		cin >> ch >> x >>  y;
		if (ch == 'F') {
			uni.merge(x, y);
		}
		else {
			uni.merge(x, y + n); // 后一半指向前一半
			uni.merge(y, x + n);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (uni.fa[i] == i)cnt++;
	}
	cout << cnt;
}
```

**带权并查集**：

在对并查集进行路径压缩和合并操作时，这些权值具有一定属性，即可将他们与父节点的关系，变化为与所在树的根结点关系；在发生路径压缩时，当前节点到父节点这个区间的结点的权值都要发生改变，在进行合并时，其父节点的权值要改变。

详见：[带权并查集](https://blog.csdn.net/yjr3426619/article/details/82315133)

题目链接：[食物链](https://www.luogu.com.cn/problem/P2024)

```c++
const int N = 5e4 + 5;
int fa[N], re[N];

int find(int x) {
	if (fa[x] != x) {
		int t = fa[x];
		fa[x] = find(fa[x]);
		re[x] = (re[x] + re[t]) % 3; // 权值的修改
	}
	return fa[x];
}
void solve() {
	int n, k,ans=0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)fa[i] = i;
	while (k--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (x > n || y > n) { ans++; continue; }
		int fx = find(x), fy = find(y);
		if (op == 1) {
			if (fx == fy) {
				if (re[x] != re[y]) {
					ans++;
				}
			}
			else {
				fa[fx] = fy;
				re[fx] = (re[y] - re[x] + 3) % 3; // 父节点权值的修改
			}
		}
		else {
			if (fx == fy) {
				if ((re[x] - re[y] + 3) % 3 != 1) {
					ans++;
				}
			}
			else {
				fa[fx] = fy;
				re[fx] = (re[y] - re[x] + 3 + 1) % 3; // 父节点权值的修改
			}
		}
	}
	cout << ans;
}
```

### 最短路径算法

详见：[最短路径算法](https://blog.csdn.net/ZHUO_SIR/article/details/80628663)

A、$dijkstra$求最短路径

题目链接：[单源最短路径](https://www.luogu.com.cn/problem/solution/P4779)

$dijkstra$是一种单源最短路径算法,时间复杂度上限为$O(n^2)$(朴素),在实际应用中较为稳定;加上堆优化之后更是具有$O((n+m)log_2n)$的时间复杂度,在稠密图中有不俗的表现。$dijkstra$只能解决**单源**最短路径，并且只能解决**非负**权值的路径问题。

朴素版：$O(n^2)$

```c++
void dij(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++) { // 每次标记一个点
        int t = -1;
        for (int j = 1; j <= n; j++) { // 找到距离最近且未被标记的点
            if (!vis[j] && (t == -1 || dis[t] > dis[j])) {
                t = j;
            }
        }
        vis[t] = 1;
        for (int j = 1; j <= n; j++) { // 以这个点更新所有的最短路径
            dis[j] = min(dis[j], dis[t] + w[t][j]);
        }
    }
}
```

其中图的存储采取**邻接矩阵**存储。

堆优化版：$O((m+n)log_2n)$

```c++
// 链式前向星存储
void dij(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>q;
    q.push({dis[s],s});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u])continue;
        vis[u] = true;
        for (int i = head[u]; i; i = ed[i].next) {
            int v = ed[i].to, w = ed[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push({ dis[v],v });
                }
            }
        }
    }
}
// 邻接表存储
void dij(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q; // 小根堆
    q.push({dis[s],s});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int u= t.second;
        if (vis[u])continue;
        vis[u] = true;
        for (auto& p : g[u]) {
            int v = p.first, w = p.second;
            if (dis[v]>dis[u]+w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push({ dis[v],v });
                }
            }
        }
    }
}
```

其中图的存储采取**链式前向星**存储：

```c++
struct edge {
    int to, w, next;
};
void add(int u, int v, int w) {
    cnt++;
    ed[cnt].w = w;
    ed[cnt].to = v;
    ed[cnt].next = head[u];
    head[u] = cnt;
}
edge ed[M];
// 遍历
for (int i = head[u]; i; i = ed[i].next) {
            int v = ed[i].to, w = ed[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push({ dis[v],v });
                }
            }
		}
```

数据小也可以采取**邻接表**存储：

```c++
vector<pair<int,int>>g[N];
for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
}
```

B、$floyed$算法

题目链接：[吝啬的拒绝](https://ac.nowcoder.com/acm/contest/73799/A)

$floyed$算法是解决给定的加权图中顶点间的最短路径的一种算法，可以正确处理有向图或负权的最短路径问题，同时也被用于计算有向图的传递闭包。$floyed$算法可以算出任意两点的最短路径，可以处理带有负权边的图，但不能处理带有负环的图，时间复杂度为$O(n^3)$，空间复杂度为$O(n^2)$。

```c++
for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
}
```

C、$Bellman-ford$算法

其主要思想：对所有的边进行n-1轮松弛操作，因为在一个含有n个顶点的图中，任意两点之间的最短路径最多包含n-1边。换句话说，第1轮在对所有的边进行松弛后，得到的是源点最多经过一条边到达其他顶点的最短距离；第2轮在对所有的边进行松弛后，得到的是源点最多经过两条边到达其他顶点的最短距离；第3轮在对所有的边进行松弛后，得到的是源点最多经过一条边到达其他顶点的最短距离......

单源最短路径算法$Bellman-ford$ 算法比$dijkstra$算法更具普遍性，因为它对边没有要求，可以处理负权边与负权回路。缺点是时间复杂度过高，高达$O(VE)$, $V$为顶点数，$E$为边数。

```c++

```

D、$SPFA$算法

我们用数组dis记录每个结点的最短路径估计值，用邻接表或邻接矩阵来存储图G。我们采取的方法是动态逼近法：设立一个先进先出的队列用来保存待优化的结点，优化时每次取出队首结点u，并且用u点当前的最短路径估计值对离开u点所指向的结点v进行松弛操作，如果v点的最短路径估计值有所调整，且v点不在当前的队列中，就将v点放入队尾。这样不断从队列中取出结点来进行松弛操作，直至队列空为止，是队列优化的$Bellman-ford$算法，最差复杂度还是$O(V*E)$。

```c++

```

### 最小生成树（MST）

详见：[最小生成树](https://oi-wiki.org/graph/mst/)

题目链接：[最小生成树](https://www.luogu.com.cn/problem/P3366)

**Kruskal算法**

从边的角度出发，每次选最短的边，看两个点是否联通，如果不连通，将这条边加入最小生成树里面，并且使它们连通，直到边的数目能构成最小生成树（等于点的数目减1），所以先对边进行排序。

```c++
#include<bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

const int N = 5005;
int n, m;
struct edge {
    int u, v, w;
};
bool cmp(edge e1, edge e2) { // 按照边从小到大排序
    return e1.w < e2.w;
}
edge arr[200005];
struct Union { // 并查集
    vector<int>fa, rank, cnt;
    Union(int n) :fa(n), rank(n), cnt(n, 1) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (rank[x] > rank[y]) {
                fa[y] = x;
                cnt[x] += cnt[y];
            }
            else {
                if (rank[x] == rank[y])rank[y]++;
                fa[x] = y;
                cnt[y] += cnt[x];
            }
        }
    }
    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }
};
void solve() {
    cin >> n >> m;
    int cnt = 0;
    ll ans = 0;
    Union uni(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        arr[i].u = u, arr[i].v = v, arr[i].w = w;
    }
    sort(arr, arr + m, cmp); // 对边排序
    for (int i = 0; i < m; i++) {
        int u = arr[i].u, v = arr[i].v, w = arr[i].w;
        if (!uni.isConnect(u, v)) {
            cnt++;
            uni.merge(u, v);
            ans += w;
        }
        if (cnt == n - 1)break; // 直到边的数目为点的数目减1
    }
    if (cnt == n - 1)cout << ans;
    else cout << "orz";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
}
```



### 字符串哈希

题目链接：[字符串哈希](https://www.luogu.com.cn/problem/P3370)

字符串哈希一般采用类似于进制的方法，每一位乘以对应的进制位，一般进制$base$取大于所有字符对应的数字的最大值，不要含有模数的质因子，模数的选择（尽量选择质数，范围尽量在1e18），也可以不选，使用$unsigned\ long\ long$自然溢出，最稳妥的方法是选择两个模数使用双$hash$，当两个$hash$值都相等时才相等。

**自然溢出版**：

```c++
const int N = 1e5;
ull arr[N];
ull hashs(string& s) {
	ull ans = 0, base = 131;
	for (int i = 0; i < s.size(); i++) {
		ans = ans * base + (ull)s[i]; // 不取模，自然溢出
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr[i] = hashs(str);
	}
	sort(arr, arr + n);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1])ans++;
	}
	cout << ans;
}
```

**取模单hash**：

```c++
const int N = 1e5;
ull arr[N];
ull mod = 1e9 + 7;
ull hashs(string& s) {
	ull ans = 0, base = 131;
	for (int i = 0; i < s.size(); i++) {
		ans = (ans * base + (ull)s[i])%mod; // 取模
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr[i] = hashs(str);
	}
	sort(arr, arr + n);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1])ans++;
	}
	cout << ans;
}
```

**双hash**：

```c++
const int N = 1e5;
pair<ull,ull> arr[N];
ull mod1 = 1e9 + 7,mod2=1e9+9;
int base = 131;
ull hash1(string& s) {
	ull ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = (ans * base + (ull)s[i])%mod1;
	}
	return ans;
}
ull hash2(string& s) {
	ull ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = (ans * base + (ull)s[i]) % mod2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr[i] = make_pair(hash1(str),hash2(str));
	}
	sort(arr, arr + n);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i].first != arr[i - 1].first || arr[i].second != arr[i - 1].second) { // 有一个不相等就不等
			ans++;
		}
	}
	cout << ans;
}
```

### 位运算通用模板

题目链接：[按位或最大的最小子数组长度](https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

根据或运算和与运算的性质，一个数的改变次数不超过$log_2n$次，可以用一个数组存储按位或的值+子数组的右端点的最小值，再进行原地去重。

```c++
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<pair<int,int>>ors; // 按位或的值+对于子数组的右端点的最小值
        for(int i=n-1;i>=0;i--){ // 逆序
            ors.push_back({0,i}); // 与运算是{-1,i}
            int cnt=0;
            for(int j=0;j<ors.size();j++){ // 原地去重
                ors[j].first|=nums[i];
                if(ors[j].first==ors[cnt].first){
                    ors[cnt].second=ors[j].second; // 更新右端点的最小值
                }else{
                    ors[++cnt]=ors[j];
                }
            }
            ors.resize(cnt+1); // 总共有cnt+1个不同的元素
            ans[i]=ors[0].second-i+1; // 按位或的最大值
        }
        return ans;
    }
};
```
