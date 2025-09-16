# DP

+++

|      类型      | 例题1                                                        | 例题2                                                        | 例题3                                                        | 例题4                                                        |
| :------------: | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **线性状态dp** | [导弹拦截](https://www.luogu.com.cn/problem/P1020)           | [最长公共子序列](https://www.luogu.com.cn/problem/P1439)     | [编辑距离](https://www.luogu.com.cn/problem/P2758)           | [Road Band](https://vjudge.net.cn/contest/653975#problem/B)  |
|   **区间dp**   | [涂色](https://www.luogu.com.cn/problem/P4170)               | [石子合并](https://ac.nowcoder.com/acm/contest/24213/1030)   | [能量项链](https://www.luogu.com.cn/problem/P1063)           | [USACO16OPEN 262144 P](https://www.luogu.com.cn/problem/P3147) |
|   **树上dp**   | [Accumulation Degree](https://ac.nowcoder.com/acm/contest/25022/1014) | [Great Cow Gathering G](https://www.luogu.com.cn/problem/P2986) | [选课](https://www.luogu.com.cn/problem/P2014)               | [战略游戏](https://www.luogu.com.cn/problem/P2016)           |
|   **状压dp**   | [互不侵犯KING](https://ac.nowcoder.com/acm/contest/25022/1017) | [中国象棋](https://ac.nowcoder.com/acm/contest/25022/1024)   | [德玛西亚万岁](https://ac.nowcoder.com/acm/contest/25022/1020) | [炮兵阵地](https://ac.nowcoder.com/acm/contest/25022/1016)   |

++++++++

+++

**解题步骤**：

* 1.将原问题分解为子问题

>* 把原问题分解为若千个子问题，子问题和原问题形式相同或类似，只不过规模变小了。子问题都解决，原问题即解决(数字三角形例)
>
>* 子问题的解一旦求出就会被保存，所以每个子问题只需求解一次

* 2.确定状态（一些子问题的解）

>* 将和子问题相关的各个变量的一组取值，称之为一个“状态”。一个“状态”对应于一个或多个子问题,所谓某个“状态”下的“值”就是这个“状态”所对应的子问题的解
>
>* 所有“状态”的集合，构成问题的“状态空间”，“状态空间”的大小，与用动态规划解决问题的时间复杂度直接相关
>
>* 整个问题的时间复杂度是状态数目乘以计算每个状态所需时间。

* 3.确定初始条件和边界条件

>* 以“数字三角形”为例，初始状态就是底边数字，值就是底边数字值

* 4.确定状态转移方程

>定义出什么是“状态”，以及在该“状态”下的“值”后，就要找出不同的状态之间如何迁移，即**如何从一个或多个“值”已知的“状态”，求出另一个“状态”的“值”**
>
>注：dp[i]只考虑子问题最优的情况，不需要考虑是不是原问题最优情况

+++

## 1.线性状态dp

> **一般规律**：
>
> >$dp[i] [j]$ 表示考虑到一个的前i项和另一个的前j项时的答案
> >
> >$dp[i] [j]$ 表示考虑前i项，选了j项的答案
> >
> >$dp[i] $表示以第i项结尾的答案
> >
> >$dp[i]$为考虑前i项时的答案
>
> **常见类型：**
>
> *背包*   *LIS*   *LCS*   *划分dp*

* ***导弹拦截*‘**

题目大意：

```Chinese
给定一个数组，求数组中最长不升子序列长度和包含所有元素所需的最少的不升子序列数量
```

例：

输入：

```
389 207 155 300 299 170 158 65
```

输出： 

```
6 2
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int>arr;
	int x;
	while (cin>>x) arr.push_back(x);
    //求最长不升子序列模板
	int dp[arr.size()+5];
    //dp[i]为长度为i的最长不升子序列结尾最小的元素
	for (int i=0;i<arr.size();i++) dp[i] = INT_MAX;
	int low = 1;
	dp[low] = arr.back();
	for (int i=arr.size()-2;i>=0;i--){
		int pos = upper_bound(dp+1,dp+low+1,arr[i])-dp;//找到第一个大于以low长度结尾的元素将其替换为更小的
		dp[pos] = arr[i];
		if (pos>low) low++;//如果pos比low大了说明没找到前面比arr[i]大的元素，那么直接将他加在++low的位置
	}
	cout << low;
    //求最长不降子序列模板
	int cnt = 0;
	int xx[arr.size()+5];
	for (int i=0;i<arr.size()+5;i++) xx[i] = 0;
	for (int i=0;i<arr.size();i++){
		int pos = lower_bound(xx,xx+cnt+1,arr[i])-xx;//同理
		xx[pos] = arr[i];
		if (pos>cnt) cnt++;
	}
	cout << '\n';
	cout << cnt;
	return 0;
}
```

知识点：*Dilworth*定理  ([详见·](https://www.luogu.com.cn/problem/solution/P1020))

内容：对于任意有限偏序集，其最大反链中元素的数目必等于最小链划分中链的数目

+++

* ***最长公共子序列（LCS）***

题目大意：

```Chinese
给出 1,2,…,n 的两个排列P1,P2， 求他们的最长公共子序列
```

例：

输入：

```
5 
3 2 1 4 5
1 2 3 4 5
```

输出：

```
3
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int b[100005];
int f[100005];//f[len]为长度为len的公共子序列最后一个元素在b中的下标（尽量要让f[len]小才有可能有更长的子序列
int len;
map<int,int>mp;
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
    //如果是排列的话15~26这部分可忽略
	int len1,len2;
	len1 = len2 = 0;
	set<int>s1,s2;
	for (int i=1;i<=n;i++){
		s1.insert(a[i]);
		s2.insert(b[i]);
	}
	for (int i=1;i<=n;i++){
		if (s2.count(a[i])) a[++len1] = a[i];
		if (s1.count(b[i])) b[++len2] = b[i];
        //取出a，b中共有的部分重新组成a，b
	}
	for (int i=1;i<=len2;i++) mp[b[i]] = i;
	if (len1) len = 1,f[len] = mp[a[1]];//如果a，b不存在共有元素的话，那么len（答案）为0
	for (int i=2;i<=len1;i++){
        //可类比LIS问题
		int pos = upper_bound(f+1,f+len+1,mp[a[i]])-f;
		f[pos] = mp[a[i]];
		if (pos>len) ++len;
	}
	cout << len;
	return 0;
}
```

+++

* ***编辑距离***

题目大意：

```Chinese
设 A 和 B 是两个字符串。我们要用最少的字符操作次数，将字符串 A 转换为字符串 B。这里所说的字符操作共有三种：1.插入一个字符 2.删除一个字符 3.替换一个字符。求将字符串A变成B需要的最小操作次数
```

例：

输入：

```Chinese
sfdqxbw
gfdgw
```

输出：

```
4
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2;
int dp[2005][2005];//dp[i][j]表示将A的前i项替换成B的前j项所需要的最小操作次数
signed main(){
	cin >> s1 >> s2;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	dp[0][0] = 0;
	int le n1 = s1.length() - 1;
	int len2 = s2.length() - 1;
	for (int i=1;i<=len1;i++) dp[i][0] = i;
	for (int i=1;i<=len2;i++) dp[0][i] = i;
	for (int i=1;i<=len1;i++){
		for (int j=1;j<=len2;j++){
			if (s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
		}
	}
	cout << dp[len1][len2];
	return 0;
}
```

+++

* ***Road Band***

题目大意：

```
Axes Point 乡村社区的所有居民都住在两条平行街道的其中一条上，两条街道被一片绿色的公园绿地隔开。最近，当地的监事会获得了一笔拨款，终于可以为小镇提供无线服务了。这笔拨款为他们提供了足够的资金来安装 k个接入点，监事们决定将这些接入点以一条直线的方式放置在县道 "B "上，该道路位于两条住宅街道中间的林带中。他们希望将用户与最近的入点之间的距离最小化。
具体来说，他们希望将每个用户与其最近接入点之间距离的平方和最小化。
给定两条街道沿线所有客户的位置、街道之间的距离和接入点的数量，帮助当地政府确定可实现的最小平方距离之和。
```

例：

输入：

```
m n k s
4 4 2 3
0.5 1.0 3.0 3.5
1.0 2.5 3.0 3.5
```

输出：

```
18.86666667
```

![例](http://luf.woyioii.cn:82/Images/DP/sample1.png)

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,m,k,s;
	cin >> n >> m >> k >> s;
	double num[m+n+1];
	for (int i=1;i<=m+n;i++) cin >> num[i];
	sort(num+1,num+m+n+1);
	double sum[m+n+1],sum_2[m+n+1];
	sum[0] = sum_2[0] = 0;
	for (int i=1;i<=m+n;i++){
		sum[i] = sum[i-1] + num[i];
		sum_2[i] = sum_2[i-1] + num[i]*num[i];
	}
	double dp[m+n+1][k+1];//dp[i][j]表示考虑到前i项，分为j组时的最小代价
	for (int i=0;i<=m+n;i++){
		for (int j=0;j<=k;j++){
			dp[i][j] = 1e10;//初始化
		}
	}
	dp[0][0] = 0;
	for (int i=1;i<=m+n;i++){//考虑到前i项
		for (int j=1;j<=min(i,k);j++){//枚举把前i项分为几组
			for (int p=0;p<=i-1;p++){//枚举i前面的点
				double cost = sum_2[i]-sum_2[p]-(sum[i]-sum[p])*(sum[i]-sum[p])/(i-p);
				dp[i][j] = min(dp[i][j],dp[p][j-1]+cost);
			}
		}
	}
	double ans = dp[m+n][k] + (m+n)*s*s/4.0;
	printf("%.8f",ans);
	return 0;
}
```

*第p+1项到第 i项的花费：*
$$
cost = \sum_{pos=p+1}^{i}(\frac{sum[i]-sum[p]}{i-p}-num[pos])^2
$$

$$
cost=(i-p)*(\frac{sum[i]-sum[p]}{i-p})^2+sum^2[i]-sum^2[p]-2*(sum[i]-sum[p])*(\frac{sum[i]-sum[p]}{i-p})
$$

$$
cost=sum^2[i]-sum^2[p]-\frac{(sum[i]-sum[p])^2}{i-p}
$$

+++

## 2.区间dp

> **一般规律**
>
> >dp[i] [j] 表示区间[i,j]的最优解
> >
> >>思路：1.枚举区间长度 2.枚举区间左端点i，可以得到右端点为j 3.枚举区间中间的点k 4.状态转移
> >>
> >>**$dp[i] [j] = min/max(dp[i] [j],dp[i] [k],dp[k+1] [j]);$**
> >
> >dp[i] [j] 表示以i为左端点，答案为j时的右端点
> >
> >> 思路（以USACO16OPEN 262144 P为例）: 与倍增求LCA里的fa[i] [j]数组类似
> >>
> >> **$dp[i][j] = dp[dp[i][j-1]][j-1]$**

* ***USACO16OPEN 262144 P***

题目大意：

```Chinese
贝西被她最近玩的一款游戏迷住了，游戏一开始有 n (2<= n <= 262144) 个正整数，范围在 1~40 。在一步中，贝西可以选相邻的两个相同的数，然后合并成一个比原来的大一的数（例如两个 7 合并成一个 8)，目标是使得最大的数最大，请帮助 Bessie 来求最大值。
```

例：

输入：

```
4
1 1 1 2
```

输出：

```
3
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[500005];
int dp[300000][60];//以i为左端点，合并出j时的右端点
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n;i++) dp[i][num[i]] = i+1;
	for (int j=2;j<=90;j++){
		for (int i=1;i<=n;i++){
			if (!dp[i][j]){
				dp[i][j] = dp[dp[i][j-1]][j-1];//倍增思想
			}
		}
	}
	int ans = 0;
	for (int j=1;j<=58;j++){
		for (int i=1;i<=n;i++){
			if (dp[i][j]){
				ans = max(ans,j);
			}
		}
	}
	cout << ans;
	return 0;
}
```

+++

* ***合并石子***

题目大意：

```
将n堆石子绕圆形操场排放，现要将石子有序地合并成一堆。规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆的石子数记做该次合并的得分。
请编写一个程序，读入堆数n及每堆的石子数，并进行如下计算：
1.选择一种合并石子的方案，使得做n-1次合并得分总和最大
2.选择一种合并石子的方案，使得做n-1次合并得分总和最小
```

例：

输入：

```
4
4 5 9 4
```

输出：

```
43
54
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[2005];
int dp[2005][2005];//dp[i][j]表示合并区间[i,j]里的石子的得分
int dp2[2005][2005];
int sum[2005];
signed main(){
	cin >> n;
	for (int i=0;i<=2*n+1;i++){
		for (int j=0;j<=2*n+1;j++){
			dp[i][j] = LONG_LONG_MAX-1e10;
			dp2[i][j] = 0;
		}
	}
	for (int i=1;i<=n;i++){
		cin >> num[i];
		num[n+i] = num[i];//区间为环形
		dp[i][i] = dp[n+i][n+i] = 0;
	}
	for (int i=1;i<=2*n;i++) sum[i] = sum[i-1] + num[i];
	for (int len=2;len<=n;len++){//1.枚举区间长度
		for (int i=1;i+len-1<=2*n;i++){//2.枚举区间左端点
			int j = i+len-1;
			for (int k=i;k<=j-1;k++){//3.枚举区间中间的点
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
				dp2[i][j] = max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	int mn = LONG_LONG_MAX;
	int mx = 0;
	for (int i=1;i<=n;i++){
		mx = max(mx,dp2[i][i+n-1]);
		mn = min(mn,dp[i][i+n-1]);
	}
	cout << mn << '\n' << mx << '\n';
	return 0;
}
```

+++

## 3.树上dp

+++

> **一般规律**
>
> $dp[i][j]$表示以i为根节点，选了j个节点的最优解
>
> $dp[i]$表示以i为节点的解
>
> $dp[i][2]$表示以i为根节点，第i号节点选与不选的解
>
> **常见类型**
>
> *树上背包*   *01dp*   *换根dp*

* ***选课***

题目大意：

```Chinese
在大学里每个学生，为了达到一定的学分，必须从很多课程里选择一些课程来学习，在课程里有些课程必须在某些课程之前学习，如高等数学总是在其它课程之前学习。现在有 N 门功课，每门课有个学分，每门课有一门或没有直接先修课（若课程 a 是课程 b 的先修课即只有学完了课程 a，才能学习课程 b）。一个学生要从这些课程里选择 M 门课程学习，问他能获得的最大学分是多少？
```

例：

输入：

```
N M
fa score
7  4
2  2
0  1
0  4
2  1
7  1
7  6
2  2
```

输出：

```Chinese
13
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>arr[305];
int n,m;
int num[305];
int dp[305][305];//dp[i][j]表示以i为根节点，选了j个的最大得分
void dfs(int node,int fa){
	dp[node][1] = num[node];//初始化
	for (auto e : arr[node]){
		if (e!=fa){
			dfs(e,node);
			for (int j=m;j>=1;j--){//j>=1因为根节点必须选了才能选子节点
				for (int k=1;k<=j;k++){
					dp[node][j] = max(dp[node][j],dp[node][k]+dp[e][j-k]);
				}
			}
		}
	}
}
signed main(){
	cin >> n >> m;
	m++;//注意将森林合成一棵根节点为0的树方便操作，m要+1
	for (int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		arr[x].push_back(i);
		arr[i].push_back(x);
		num[i] = y;
	}
	dfs(0,-1);
	cout << dp[0][m];
	return 0;
}
```

+++

* ***战略游戏***

题目大意：

```
Bob 喜欢玩电脑游戏，特别是战略游戏。但是他经常无法找到快速玩过游戏的办法。现在他有个问题。
他要建立一个古城堡，城堡中的路形成一棵无根树。他要在这棵树的结点上放置最少数目的士兵，使得这些士兵能瞭望到所有的路。
注意，某个士兵在一个结点上时，与该结点相连的所有边将都可以被瞭望到。
请你编一程序，给定一树，帮 Bob 计算出他需要放置最少的士兵。
```

输入：

```
格式：
第一行一个整数 n表示树中结点的数目。
2~n+1行：每行一个k,接着k个数，表示有k条边与i相连
结点在0~n-1之间，保证是一棵树
4
0 1 1
1 2 2 3
2 0
3 0
```

输出：

```
1
```

示例程序:

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>arr[2000];
int dp[2000][2];以i为根节点，第i个节点放与不放时的最优解
void dfs(int node,int fa){
	dp[node][1] = 1;
	for (auto e : arr[node]){
		if (e!=fa){
			dfs(e,node);
			dp[node][1] += min(dp[e][0],dp[e][1]);
			dp[node][0] += dp[e][1];
		}
	}
}
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		int pos,cnt;
		cin >> pos >> cnt;
		++pos;
		for (int j=1;j<=cnt;j++){
			int x;
			cin >> x;
			++x;
			arr[pos].push_back(x);
			arr[x].push_back(pos);
		}
	}
	dfs(1,0);
	cout << min(dp[1][1],dp[1][0]);
	return 0;
}

```

+++



* ***Great Cow Gathering G***

题目大意：

```Chinese
n个农场，每个农场有ai头奶牛，有n-1条道路相连，并且从任意一个农场都能够到达另外一个农场。道路i连接着农场Ai和Bi，它们之间长度为Ci。
现在要选取一点作为集会点，在选择集会的地点的时候，Bessie 希望最大化方便的程度（也就是最小化不方便程度）。比如选择第 X 个农场作为集会地点，它的不方便程度是其它牛棚中每只奶牛去参加集会所走的路程之和。帮助 Bessie 找出最方便的地点来举行大集会。
即最小化所有奶牛所走路径长度之和
```

例：

输入：

```Chinese
n
a1,a2,...,an
Ai Bi Ci
5 
1 1 0 0 2 
1 3 1 
2 3 2 
3 4 3 
4 5 3 
```

输出：

```
15
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int num[100005];
int cnt[100005];
int sum[100005];
vector<pair<int,int>>arr[100005];
int ans = LONG_LONG_MAX;
void pre(int node,int fa){
	cnt[node] = num[node];
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
			pre(nxt,node);
			cnt[node] += cnt[nxt];
			sum[node] += sum[nxt] + cnt[nxt]*val;
		}
	}
}
void dfs(int node,int fa){
	ans = min(ans,sum[node]);//每次以不同的node为根节点时更新答案，取最小值
	for (auto e : arr[node]){
		auto [nxt,val] = e;
		if (nxt!=fa){
            //将根从node换向子节点nxt
			int last_cntnode = cnt[node];
			int last_cntnxt = cnt[nxt];
			int last_sumnode = sum[node];
			int last_sumnxt = sum[nxt];
			cnt[node] -= cnt[nxt];
			sum[node] -= sum[nxt] + cnt[nxt]*val;
			cnt[nxt] += cnt[node];
			sum[nxt] += sum[node] + cnt[node]*val;
			dfs(nxt,node);
			cnt[node] = last_cntnode;
			cnt[nxt] = last_cntnxt;
			sum[node] = last_sumnode;
			sum[nxt] = last_sumnxt;
		}
	}
}
signed main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> num[i];
	for (int i=1;i<=n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		arr[x].push_back(make_pair(y,z));
		arr[y].push_back(make_pair(x,z));
	}
	pre(1,0);//预处理，得到以1为根节点时的答案
	dfs(1,0);//换根
	cout << ans << '\n';
	return 0;
}
```

换根dp板子及讲解[详见](https://www.nowcoder.com/discuss/353147922789376000?sourceSSR=users)

+++

## 4.状压dp

> **一般规律**
>
> $dp[i][j]$表示考虑到第i行，当前状态为j时的情况
>
> $dp[i] [j] [k]$表示考虑到第i行，选了j个，当前状态为k时的情况
>
> $dp[i][j]$考虑到第i行，有j列满足某种状态的情况

* ***互不侵犯KING***

题目大意：

```
在N*N的棋盘里放k个国王，使他们互不攻击，共有多少种摆放方案
国王能攻击到其上下左右，以及左上左下右上右下八个方向上附近的各一个格子，共8个格子
输入只有一行，包含两个数N，K （ 1 ≤ N ≤ 9, 0 ≤ K ≤ N * N），输出方案数
```

例：
输入：

```
N K
3 2
```

输出：

```
16
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[10][100][1<<10];//dp[i][j][k]表示考虑到第i行，选了j个国王，当前（第i行）状态为k时的方案数
int CNT[1<<10];
int n,k;
int lowbit(int x){
	return x&(-x);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (int i=1;i<(1<<n);i++){
		CNT[i] = CNT[i-lowbit(i)] + 1;//预处理每个数字二进制下1的个数，节省时间复杂度
	}
	dp[0][0][0] = 1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=k;j++){
			for (int now=0;now<(1<<n);now++){
				if (now&(now<<1)||now&(now>>1)) continue;//1：使得当前行状态合法
				int cnt = CNT[now];
				for (int lst=0;lst<(1<<n);lst++){
					if (lst&(lst<<1)||lst&(lst>>1)) continue;//2：使得上一行状态合法
					if (lst&now||(lst>>1)&now||(lst<<1)&now) continue;//3：使得上一行和当前行构成的情况合法
					if (j<cnt) continue;
					dp[i][j][now] += dp[i-1][j-cnt][lst];
				}
			}
		}
	}
	int ans = 0;
	for (int i=0;i<(1<<n);i++) ans += dp[n][k][i];
	cout << ans;
	return 0;
}
```

+++

* ***中国象棋***

题目大意：

```
在N行M列的棋盘上，放若干个炮可以是0个，使得没有任何一个炮可以攻击另一个炮。 请问有多少种放置方法，中国像棋中炮的行走方式大家应该很清楚吧.一个炮要能攻击另一个炮他们必须要处于同一行或者一列且他们之间有且仅有一个棋子.
输入一行包含两个整数N，M，中间用空格分开.输出所有的方案数，由于值比较大，输出其mod 9999973
```

例：

输入：

```
1 3
```

输出：

```
7
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[105][105][105];//i,j个1,k个2
int n,m;
int mod = 9999973;
signed main(){
	dp[0][0][0] = 1;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=m;j++){
			for (int k=0;k<=m;k++){
				if (j+k>m) continue;
				//不放
				dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k])%mod;
				//放1个在0里
				if (j>=1) dp[i][j][k] = (dp[i][j][k]+(m-j-k+1)*dp[i-1][j-1][k])%mod;
				//放1个在1里
				if (k>=1) dp[i][j][k] = (dp[i][j][k]+(j+1)*dp[i-1][j+1][k-1])%mod;
				//放两个在0里
				if (j>=2) dp[i][j][k] = (dp[i][j][k]+(m-j-k+2)*(m-j-k+1)/2*dp[i-1][j-2][k])%mod;
				//放1个在0里，放1个在1里
				if (k>=1) dp[i][j][k] = (dp[i][j][k]+(m-j-k+1)*j*dp[i-1][j][k-1])%mod;
				//放两个在1里
				if (k>=2)dp[i][j][k] = (dp[i][j][k]+(j+2)*(j+1)/2*dp[i-1][j+2][k-2])%mod;
			}
		}
	}
	int ans = 0;
	for (int i=0;i<=m;i++){
		for (int j=0;j<=m;j++){
			if (i+j>m) continue;
			ans = (ans+dp[n][i][j])%mod;
		}
	}
	cout << ans;
	return 0;
}
```

* 设置状态：$f[i] [j] [k]$表示考虑到第i行，有j列放了一个棋子，有k列放了两个棋子

*  确定情况：
* * 第i行不放棋子
  * 第i行放一个棋子
  * 第i行放两个棋子
* 分类讨论：
* * 不放棋子： $f[i][j][k]+=f[i-1][j][k]$
  * 放一个棋子：
  * * 放一个棋子在0列里：$f[i][j][k]+=f[i-1][j-1][k]*(m-j-k+1)$
    * 放一个棋子在1列里：$f[i][j][k]+=f[i-1][j+1][k-1]*(j+1)$
  * 放两个棋子：
  * * 放一个棋子在0列，一个棋子在1列：$f[i][j][k]+=f[i-1][j][k-1]*(m-j-k+1)*j$
    * 放两个棋子在0列：$f[i][j][k]+=f[i-1][j-2][k]*C_{m-j-k+2}^{2}$
    * 放两个棋子在1列：$f[i][j][k]+=f[i-1][j+2][k-2]*C_{j+2}^{2}$

+++

* ***德玛西亚万岁***

题目大意：

![题目](http://luf.woyioii.cn:82/Images/DP/sample2.png)

输入描述：

```
输入包含多组测试数据；
每组数据的第一行包含2个整数n和m (n <= 12, m <= 12 )，之间用空格隔开；
接下来的n行，每行m个数，表示n*m的比尔吉沃特领土。
```

输出描述：

```
输出一个整数n代表安排应用的方法。（答案取膜100000000）
```

例：

输入：

```
3 3
1 1 1
0 1 1
1 0 0
```

输出：

```
24
```

示例程序：

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[15][1<<15];//dp[i][j]表示考虑到第i行，当前状态为j时的方案数
int mod = 100000000;
int n,m;
signed main() {
	while (cin>>n>>m){
		int num[n+1][m+1];
		map<int,int>mp;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin >> num[i][j];
				mp[i] = (mp[i]<<1) + num[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<(1<<m);j++){
				if ((j&mp[i])!=j) continue;//当前状态不合法
				if (j&(j>>1)) continue;//和左右有相邻
				//开始转移，由上推下
				for (int k=0;k<(1<<m);k++){
					if (k&j) continue;//和上一行有相邻
					dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
		int ans = 0;
		for (int i=0;i<(1<<m);i++) ans = (ans+dp[n][i])%mod;
		cout << ans << '\n';
	}
	return 0;
}
```

