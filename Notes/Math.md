### 判断质数

题目链接：[质数口袋](https://www.luogu.com.cn/problem/P5723)

A、**普通判断**（时间复杂度为$O(\sqrt{n}$））

```c++
bool is_prime(int x) {
	int sq = sqrt(x);
	for (int i = 2; i <= sq; i++) {
		if (x % i == 0)return false;
	}
	return x >= 2; // 注意 0，1都不是质数
}
```

B、**优化版的埃氏筛法**（时间复杂度近似为$O(n)$）

```c++
void solve() {
	for (int i = 2; i * i <= n; i++) { // 只需要筛2~sqrt(n)里面的质数就行了
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) { // 从 i*i 开始
				isPrime[j] = 0;
			}
		}
	}
}
```

**bitset优化的埃氏筛法**（bitset优化节省内存和时间，性能超过线性筛）

```c++
onst int N = 6e6, M = 1e8 + 5;
int n, q, k, cnt; // cnt统计质数个数
int prime[N];
bitset<M>bit;
void solve() {
	cin >> n >> q;
	bit.set(); // 全部置为1,表示都是质数
	bit.reset(0); // 0不是质数
	bit.reset(1); // 1不是质数
	for (int i = 2; i * i <= n; i++) {
		if (bit[i]) {
			for (int j = i * i; j <= n; j += i) {
				bit.reset(j);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		if (bit[i]) {
			prime[++cnt] = i;
		}
	}
	while (q--) {
		cin >> k;
		cout << prime[k] << endl;
	}
}
```

C、**欧拉筛法（线性筛）**（时间复杂度为$O(n)$）

题目链接：[线性筛质数](https://www.luogu.com.cn/problem/P3383)

详见：[质数筛法](https://blog.csdn.net/GD_ONE/article/details/104660294)

```c++
void solve() {
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && prime[j] * i <= n; j++) {
			isPrime[i * prime[j]] = 0;
			if (i % prime[j] == 0)break; // 关键代码
		}
	}
}
```

### 质数唯一分解定理

题目链接：[分解质因子](https://www.luogu.com.cn/problem/B3715)

详见：[质数唯一分解定理应用](https://blog.csdn.net/JdiLfc/article/details/109491376)

质数唯一分解定理：任何一个大于$1$的自然数$N$,如果$N$不为质数，那么$N$可以唯一分解成有限个质数的乘积。

```c++
void solve() {
	ll n;
	cin >> n;
	ll sq = sqrt(n);
	for (int i = 2; i <= sq; i++) { // 埃氏筛法，所以不用判断是否为质数
		while ((n % i) == 0) {
			cout << i << " ";
			n /= i;
		}
	}
	if (n != 1)cout << n << " "; // 不为1说明这个是质数
	cout << endl;
}
```

质数唯一分解定理可以用来求一个数的**因子个数**，因为一个数可以唯一分解成有限个质数，$n$的因子一定是$p_1、p_2、p_3、…、p_k$的组合，并且$p_1$可以取的个数为$[0,e_1]$，$p2$可以取的个数为$[0,e_2]$，$p_k$可以取的个数为$[0,e_k]$，所以根据乘法原理，总的个数为（$e_i+1$）的**连乘**，时间复杂度为求素因子的时间复杂度。

题目链接：[子序列权值和](https://ac.nowcoder.com/acm/contest/76133/F)

详见：[因子数还可以这么求](https://zhuanlan.zhihu.com/p/450942534)

### 快速幂

**普通快速幂**

题目链接：[史莱姆农场](https://ac.nowcoder.com/acm/contest/73799/G)

```c++
ll qpow(ll a, ll b, int p) {
	ll res = 1;
	while (b) { // b 二进制分解
		if (b % 2 == 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b /= 2;
	}
	return res;
}
```

**矩阵乘法**

```c++
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) { // 交换内部两层循环对结果没影响
			for (int t = 0; t < m; t++) {
				c[i][j] += a[i][t] * b[t][j];
			}
		}
	}
}
```

**矩阵快速幂**

详见：[矩阵快速幂](https://blog.csdn.net/wust_zzwh/article/details/52058209)

题目链接：[方程](https://www.lanqiao.cn/problems/16576/learning/?contest_id=168)

相对于一般的快速幂，矩阵快速幂仅仅是把他的底数和乘数换成了矩阵形式，而相应的乘法运算什么的也遵循矩阵的运算法则；矩阵快速幂主要是用于求一个很复杂的递推式的某一项问题，初始答案为**单位矩阵**。

```c++
void mul(ll c[N][N],ll a[N][N],ll b[N][N]) { // 矩阵乘法 c=a*b
	ll res[N][N] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
			}
		}
	}
	memcpy(c, res, sizeof(res)); // 把res拷贝到c中
}
void qpow(ll a[N][N], ll k) { // 矩阵快速幂 a=a^k
	ll res[N][N] = {};
	for (int i = 0; i < n; i++) {
		res[i][i] = 1;
	}
	while (k) {
		if (k % 2 == 1) {
			mul(res, res, a);
		}
		mul(a, a, a);
		k /= 2;
	}
	memcpy(a, res, sizeof(res)); // 把res拷贝到a中
}
```

### 逆元

题目链接：[组合数问题](https://www.luogu.com.cn/problem/B3717)

详见：[逆元超详解](https://blog.csdn.net/weixin_43872728/article/details/107299282)

**逆元**：如果$a*x\equiv1\ (mod\ p) $成立，那么$x$是$a$在$mod\ p$的条件下的逆元，其中$a$和$x$一定都和$p$互质，如果不互质，则逆元不存在。

逆元的作用是将除法改为乘法，由于在求$(a/b)mod\ p$时，如果$b$是一个很大的数，那么会爆$double$的精度，那我们把它转换成乘法来做，我们设$b$的逆元为$inv[b]$，那么$a/b\ (mod)\ p\equiv a*inv[b]\ (mod\ p)$，采用费马定理的话，$inv[b]=b^{p-2}$就是$b$的逆元。

A、**费马小定理**：

详见：[费马小定理](https://baike.baidu.com/item/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86/4776158)

费马小定理：如果$p$是一个质数，而整数$a$不是$p$的倍数，则有$a^{p-1}\equiv1\ (mod\ p)$，由此可得$a*a^{p-2}\equiv1\ (mod\ p)$，则$a^{p-2}$是$a$在$mod\  p$的条件下的逆元。

注意：费马小定理仅在所求数与模数**互质**时存在。

```c++
int n, p;
ll qpow(ll a, ll b) { // a^(p-2)
	ll res = 1;
	while (b) {
		if (b % 2 == 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b /= 2;
	}
	return res;
}
void solve() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cout << qpow(i, p - 2) << endl;
	}
}
```

B、**扩展欧几里得算法**

$a*x\equiv1(\ mod\ p)$转换成$ax+bp\equiv1$，当$gcd(a,b)=1$时有解。

```c++
ll exgcd(ll a, ll b, ll& x, ll& y) { // 返回值为gcd(a,b)
	if (b == 0) { // 此时 ax+by=ax=gcd(a,b)=a
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x); // 注意x和y要互换，前面的a、b与求gcd一样
	y -= (a / b * x);
	return d;
}
```

C、**逆元的线性递推**

详见：[逆元的线性递推](https://blog.csdn.net/roadtohacker/article/details/114649741)

设$inv[i]$表示$i$的逆元，则：

$inv[1]=1$

$inv[i]=(p-p/i)*inv[p\%i]\%p\ (i>=2)$

```c++
void solve() {
	cin >> n >> p;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = (p - p / i) * inv[p % i] % p;
	}
	for (int i = 1; i <= n; i++)cout << inv[i] << endl;
}
```

```c++
// 当x太大时求当个的逆元
ll inv(int x) {
	if (x == 1)return 1;
	return (p - p / x) * inv(p % x) % p;
}
```

### 排列组合

详见：[排列组合公式](https://www.cnblogs.com/1024th/p/10623541.html)

排列公式：$A_n^m=\frac{n!}{(n-m)!}=n(n-1)(n-2)...(n-m+1),0!=1$，表示从$n$个不同元素取出$m(m≤n)$个元素的所有不同排列的个数，叫做从$n$个不同元素种取出$m$个元素的排列数。

组合公式：$C_n^m=\frac{A_n^m}{A_m^m}=\frac{n!}{m!(n-m)!},C_n^0=C_n^n=1$，表示从$n$个不同元素种取出$m(m≤n)$个元素的所有不同组合的个数，叫做从$n$个不同元素种取出$m$个元素的组合数，也记作$\begin{pmatrix}n\\m\end{pmatrix}$，读作$n$选$m$。

递推公式：$C_n^m=C_{n-1}^m+C_{n-1}^{m-1}$，表示含特定元素的有$C_{n-1}^{m-1}$，不含特定元素的有$C_{n-1}^m$。

组合数求和公式：$C_n^0+C_n^1+C_n^2+...+C_n^n=(1+1)^n=2^n$。

**组合数求法**

题目链接：[组合数问题](https://www.luogu.com.cn/problem/B3717)  [卢卡斯定理](https://www.luogu.com.cn/problem/P3807)

详见：[组合数的几种求法](https://www.cnblogs.com/think-twice/p/11205353.html)  [卢卡斯定理](https://oi-wiki.org/math/number-theory/lucas/)

A、递推公式

```c++
void solve() {
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i)C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
}
```

B、乘法逆元（费马小定理）+快速幂

```c++
ll qpow(ll a,ll b){ // 快速幂
	ll res=1;
	while(b){
		if(b%2==1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b/=2;
	}
	return res;
}
ll inv(ll x){ // 求逆元
	return qpow(x,mod-2);
}
const int N=5e6+5;
ll n,m,ans,jc[N];
void solve() {
	int t,k;
	cin>>t>>k;
	jc[0]=1;
	for(int i=1;i<=k;i++){
		jc[i]=jc[i-1]*i%mod; // 预处理阶乘
	}
	while(t--){
		cin>>n>>m;
		ll t=jc[n]*inv(jc[m])%mod*inv(jc[n-m])%mod;
		ans^=t;
	}
	cout<<ans<<endl;
}
```

但每次都需要求逆元太耗时了，所以可以预处理$n!$的逆元，再根据$n!=(n-1)!*n$得出$inv[n-1]=inv[n]*n$，$inv[i]$表示$i!$的逆元，所以可以存所有的阶乘逆元。

```c++
const int N=5e6+5;
int mod=998244353;
ll n,m,t,k,ans,jc[N],inv[N]; // inv[i]表示i的阶乘的逆元
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b%2==1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b/=2;
	}
	return res;
}
void solve() {
	cin>>t>>k;
	jc[0]=1;
	for(int i=1;i<=k;i++)jc[i]=jc[i-1]*i%mod;
	inv[k]=qpow(jc[k],mod-2); // 求出 n!的逆元
	for(int i=k-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod; // 再倒推
	while(t--){
		cin>>n>>m;
		ll t=jc[n]*inv[m]%mod*inv[n-m]%mod;
		ans^=t;
	}
	cout<<ans<<endl;
}
```

C、乘法逆元（线性逆元）

```c++
const int N=5e6+5;
int p=998244353;
ll n,m,t,k,ans,jc[N],inv[N];
void solve() {
	cin>>t>>k;
	jc[0]=jc[1]=inv[0]=inv[1]=1; // 记得赋初值
	for(int i=2;i<=k;i++){
		jc[i]=jc[i-1]*i%p;
		inv[i]=(p-p/i)*inv[p%i]%p; // 线性求出每个数的逆元
	} 
	for(int i=2;i<=k;i++){
		inv[i]=inv[i]*inv[i-1]%p; // 求阶乘的逆元和求阶乘的递推公式一样
	}
	while(t--){
		cin>>n>>m;
		ll t=jc[n]*inv[n-m]%p*inv[m]%p;
		ans^=t;
	}
	cout<<ans<<endl;
}
```

D、卢卡斯定理

卢卡斯定理用于求解大组合数取模的问题，其中模数必须为**素数**。正常的组合数运算可以通过递推公式求解，但当问题规模很大，而**模数是一个不大的质数**的时候，这时阶乘模模数时会等于0，就不能简单地通过递推求解来得到答案，需要用到卢卡斯定理。
$$
\begin{pmatrix}
n\\
m
\end{pmatrix}
\ mod\ p=
\begin{pmatrix}
\lfloor{n/p}\rfloor\\
\lfloor{m/p}\rfloor
\end{pmatrix}*
\begin{pmatrix}
n\ mod\ p\\
m\ mod\ p
\end{pmatrix}
\ mod\ p
$$
因为$n\%p$和$m\%p$都是小于$p$的，所以可以使用费马小定理来求逆元，对于左边的部分可以继续使用$Lucas$定理，直到$m$为0，返回1。

```c++
const int N=2e5+5;
ll n,m,p,jc[N];
ll qpow(ll a,ll b) { // 快速幂
	ll res=1;
	while(b) {
		if(b%2==1) {
			res=res*a%p;
		}
		a=a*a%p;
		b/=2;
	}
	return res;
}
ll inv(ll a) { // 费马小定理求逆元
	return qpow(a,p-2);
}
ll C(ll a,ll b) { // 求组合数
	if(a<b)return 0;
	return jc[a]*qpow(jc[b],p-2)%p*qpow(jc[a-b],p-2)%p;
}
ll Lucas(ll a,ll b) {
	if(b==0)return 1; // 边界条件
	return C(a%p,b%p)*Lucas(a/p,b/p)%p;
}
void solve() {
	cin>>n>>m>>p;
	jc[0]=1;
	for(int i=1; i<N; i++)jc[i]=jc[i-1]*i%p;
	cout<<Lucas(n+m,n)<<endl;
}
```

### 欧几里得算法（辗转相除法）

由$gcd(a,b)=gcd(b,a\%b)$得出下面两种写法

非递归写法

```c++
ll gcd(ll a, ll b) {
	ll c = a % b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
```

递归写法

```c++
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
```

### 扩展欧几里得算法（exgcd）

详见：[扩展欧几里得算法](https://www.cnblogs.com/juruo-zzt/p/exgcd.html)

题目链接：[同余方程](https://www.luogu.com.cn/problem/P1082)

$exgcd$用来求$ax+by=gcd(a,b)$的$x$和$y$，当$b$为0时，$x=1,y=0$。

根据$gcd(a,b)=gcd(b,a\%b)$得出$x=y_0,y=x_0-\lfloor\frac{a}{b}\rfloor{y_0}$。

求最小的正整数解$x$，求出$x_0$后，对$x_0$加上或减去$b$不会使$x$错过任何解，因为$ax+by+(k×ab-k×ab)=1$，那么$a(x+kb)+b(y-ka)=1$，由于$kb$和$ka$都是整数，所以当$k=\frac{1}{gcd(a,b)}$时，$ka$和$kb$最小，$x=x_0+s*\frac{b}{gcd(a,b)}$，$y=y_0+s*\frac{a}{gcd(a,b)}$，$s$是任意整数。

```c++
ll exgcd(ll a, ll b, ll& x, ll& y) { // 返回值为gcd(a,b)
	if (b == 0) { // 此时 ax+by=ax=gcd(a,b)=a
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x); // 注意x和y要互换，前面的a、b与求gcd一样
	y -= (a / b * x);
	return d;
}
void solve() {
	ll a, b, x, y;
	cin >> a >> b;
	ll d=exgcd(a, b, x, y); // 最大公约数
    b/=d; // 本题是1所以可以不用除以gcd(a,b)
	x = (x % b + b) % b; // 求最小的正整数解
	cout << x << endl;
}
```

题目链接：[二元一次不定方程](https://www.luogu.com.cn/problem/P5656)

```c++
ll exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int t = exgcd(b, a % b, y, x);
	y -= (a / b * x);
	return t;
}
ll a, b, c, x, y;
void solve() {
	cin >> a >> b >> c;
	ll t = exgcd(a, b, x, y);
	if (c % t != 0)cout << -1 << endl;
	else {
		ll x1 = x * c / t, y1 = y * c / t;
		ll dx = b / t, dy = a / t;
		ll left = ceil((-x1 + 1.0) / dx), right = floor((y1 - 1.0) / dy); // 满足正整数解的左右边界
		ll dx_min = x1 + left * dx, dy_min = y1 - right * dy;
		ll dx_max = x1 + right * dx, dy_max = y1 - left * dy;
		if (left > right) { // 没有正整数解
			cout << dx_min << " " << dy_min << endl;
		} else {
			cout << (right - left + 1) << " " << dx_min << " " << dy_min << " ";
			cout << dx_max << " " << dy_max << endl;
		}
	}
}
```

### 中国剩余定理（CRT）

详见：[中国剩余定理（CRT）](https://oi-wiki.org/math/number-theory/crt/)

题目链接：[中国剩余定理](https://www.luogu.com.cn/problem/P1495)

中国剩余定理求解一元线性同余方程组（其中模数$n_i$两两**互质**）

计算过程：

1、计算所有模数的积$n$；

2、对于第$i$个方程：

a.计算$m_i=\frac{n}{n_i}$；

b.计算$m_i$在模$n_i$意义下的逆元$m_i^{-1}$；

c.计算$c_i=m_im_i^{-1}(不要对n_i取模)$。

3、方程组在模$n$意义下的唯一解为：$x=\sum_{i=1}^k{a_ic_i}\ (mod \ n)$。

```c++
ll a[11],b[11],n,mul=1,ans,m,x,y; // mul为数组a的连乘 
ll exgcd(ll a,ll b,ll&x,ll&y){ // 扩展欧几里得求逆元
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b*x);
	return d;
}
void solve() {
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	for(int i=0;i<n;i++)mul*=a[i];
	for(int i=0;i<n;i++){
		m=mul/a[i];
		exgcd(m,a[i],x,y);
		ans=(ans+b[i]*m%mul*x%mul)%mul;
	}
	ans=ans>0?ans:ans+mul;
	cout<<ans<<endl;
}
```

### 裴蜀定理

题目链接：[裴蜀定理](https://www.luogu.com.cn/problem/P4549)

已知：$\sum_{i=1}^{n}a_ix_i=f$，其中$a_i,x_i,f\in{Z}$。

结论：此方程有解的充要条件是$gcd(a_1,a_2,...a_n)|f$，其中$n\in{N^+}且n\in{[2,+\infty]}$。

```c++
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
void solve() {
	int n, a;
	cin >> n >> a;
	int ans = a;
	for (int i = 1; i < n; i++) { // 求所有数的gcd
		cin >> a;
		if (a < 0)a = -a; // 负数取绝对值
		ans = gcd(ans, a);
	}
	cout << ans << endl;
}
```

### 赛瓦维斯特定理

详见：[赛瓦维斯特定理](https://www.cnblogs.com/My-flurry/p/11610075.html)

题目链接：[得不到的爱情](https://ac.nowcoder.com/acm/contest/18839/1047)

已知$a$,$b$为大于1的正整数，$gcd(a,b)=1$，则使不定方程$ax+by=C$不存在**负整数解**的最大整数$C=a×b−a−b$。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    cout<<(long long)n*m-n-m;
}
```

### 海伦公式

详见：[海伦公式](https://zhidao.baidu.com/question/1116779861219850299.html)

题目链接：[计算三角形的周长和面积](https://ac.nowcoder.com/acm/contest/18839/1029)

已知三角形**三边**求三角形**面积**，先求出三角形周长的一半，$p=(a+b+c)/2$，然后根据公式
$$
S=\sqrt{p*(p-a)*(p-b)*(p-c)}
$$

### 向量点乘和叉乘的概念及几何意义

详见：[向量点乘与叉乘的概念及几何意义](https://zhuanlan.zhihu.com/p/359975221)       [向量叉乘（外积）及推导](https://zhuanlan.zhihu.com/p/642202049)

题目链接：[小红的平行四边形](https://ac.nowcoder.com/acm/contest/82394/E)

叉乘公式$\vec{a}×\vec{b}=|\vec{a}||\vec{b}|sin\theta\vec{n}$，设$\vec{a}=(x_1,y_1)$，$\vec{b}=(x_2,y_2)$，$\vec{a}×\vec{b}=x_1y_2-x_2y_1$，其绝对值为平行四边形的面积，即三角形的面积的两倍。

### 负进制数转换

详见：[负进制数转换](https://baike.baidu.com/item/%e8%b4%9f%e8%bf%9b%e5%88%b6%e6%95%b0/3054702)

题目链接：[进制转换](https://ac.nowcoder.com/acm/contest/19305/1028)

如果是以R或-R为基数，则需要用到的数码为0，1,....R-1。例如，当R=7时，所需用到的数码是0，1，2，3，4，5和6，这与其是R或-R无关。**被除数÷除数=商……余**，由于余只能是正数（0~R-1），所以当余是负数时，余-=R，商+=1；

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    int q=n;
    string s="";
    do{
        int t=n%r;
        n/=r;
        if(t<0){
            t-=r;
            n++;
        }
        if(t>=0&&t<=9){
            s+='0'+t;
        }else{
            s+=t-10+'A';
        }
    }while(n);           // 记住要用do,while()循环
    reverse(s.begin(),s.end());
    cout<<q<<"="<<s<<"(base"<<r<<")";
}
```

### 距离

详见：[距离](https://oi-wiki.org/geometry/distance/)

**欧氏距离**
$$
|AB|=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}
$$
**曼哈顿距离**

题目链接：[曼哈顿距离的最大值](https://www.luogu.com.cn/problem/P5098)
$$
d(A,B)=|x_2-x_1|+|y_2-y_1|
$$
**切比雪夫距离**
$$
d(A,B)=max(|x_2-x_1|,|y_2-y_1|)
$$
**曼哈顿距离和切比雪夫距离的转换**
$$
d(A,B)=|x_2-x_1|+|y_2-y_1|\\
=max(x_2-x_1+y_2-y_1,x_1-x_2+y_1-y_2,x_2-x_1+y_1-y_2,x_1-x_2+y_2-y_1)\\
=max(|(x_1+y_1)-(x_2+y_2)|,|(x_1-y_1)-(x_2-y_2)|)
$$
将每一个点（x,y）转换为（x+y,x-y）曼哈顿距离转化为切比雪夫距离；

将每一个点（x,y）转换为（(x+y)/2,(x-y)/2）切比雪夫距离转化为曼哈顿距离。

### 容斥定理

题目链接：[单面值组合的第K小金额](https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination/description/)

总共有n个元素，用二进制的每一位来表示每个元素，有$1$~$(1<<n)-1$种情况（这里没有0的情况），根据容斥定理，奇加偶减，统计每种情况$1$的个数。

```c++
long long gcd(long long a,long long b){
        return b==0?a:gcd(b,a%b);
    }
    long long lcm(long long a,long long b){
        return a/gcd(a,b)*b;
    }
    bool check(vector<int>&coins,int k,long long mid){
        int n=coins.size();
        long long ans=0;
        for(int i=1;i<1<<n;i++){ // 1~(1<<n)-1种情况
            int cnt=0;
            long long t=1;
            for(int j=0;j<n;j++){ // 统计1的个数
                if((i>>j)&1){
                    cnt++;
                    t=lcm(t,coins[j]);
                    if(t>mid)break;
                }
            }
            if(t>mid)continue;
            // 奇加偶减
            if(cnt%2)ans+=mid/t;
            else ans-=mid/t;
        }
        return ans>=k;
    }
```

### 极坐标转换

题目链接：[有效可见点的最大数目](https://leetcode.cn/problems/maximum-number-of-visible-points/solutions/1159054/you-xiao-ke-jian-dian-de-zui-da-shu-mu-b-r1qz/)

详见：[atan2函数](https://www.runoob.com/cprogramming/c-function-atan2.html)

atan2()函数用于计算两个参数的反正切值（范围为-Π~Π），参数为一个点的纵坐标和横坐标（如果原点不为（0，0），则需要减去这个点的坐标），这个函数比atan()函数更强大，因为它考虑了x和y的符号，从而可以确定正确的象限。

```c++
#include <math.h>
double atan2(double y, double x); // 注意先y后x
```



### 基本不等式

详见：[基本不等式](https://zhuanlan.zhihu.com/p/352588326)
$$
\frac{2}{\frac{1}{x}+\frac{1}{y}}\leq\sqrt{xy}\leq\frac{x+y}{2}\leq\sqrt{\frac{x^2+y^2}{2}}
$$
这四个值分别是**调和**平均数、**几何**平均值、**算术**平均值、**平方**平均值，记作**调几算方**。

**证明**：

先证基本不等式，$(x-y)^2=x^2+y^2-2xy\geq0$，所以$x^2+y^2\geq2xy$，将$\sqrt{x}$代入$x$，$\sqrt{y}$代入$y$得$x+y\geq2\sqrt{xy}$。

其余证明类似。

### 柯西不等式

详见：[柯西不等式](https://zhuanlan.zhihu.com/p/121702585)

**二维形式**：
$$
(a^2+b^2)(c^2+d^2)\geq(ac+bd)^2\ \ (当且仅当\frac{a}{c}=\frac{b}{d})
$$
**证明**：

$(a^2+b^2)(c^2+d^2)=a^2c^2+a^2d^2+b^2c^2+b^2d^2=(ac+bd)^2+(ad-bc)^2\geq(ac+bd)^2$。

**一般形式**：
$$
\sum_{i=1}^na_i^2\sum_{i=1}^nb_i^2\geq(\sum_{i=1}^na_ib_i)^2
$$
等号成立条件：$\frac{a_1}{b_1}=\frac{a_2}{b_2}=\cdots=\frac{a_n}{b_n},\{a_i\},\{b_i\}至少有一个全为0$。



### 直线方程的几种形式

详见：[直线的五种形式](https://zhidao.baidu.com/question/243923327661554284.html)

点斜式：直线过点$(x_0,y_0)$，斜率为$k$，则直线方程式为$y-y_0=k(x-x_0)$。不能表示斜率不存在的直线。

斜截式：直线在$y$轴上的截距为$b$，斜率为$k$，方程为$y=kx+b$。不能表示斜率不存在的直线。

两点式：直线经过$(x_1,y_1)和(x_2,y_2)$两点，方程为$\frac{y-y_1}{y_2-y_1}=\frac{x-x_1}{x_2-x_1}$。不能表示平行或垂直坐标轴的直线。

截距式：已知在$x$轴和$y$轴的截距为$a$，$b$，方程为$\frac{x}{a}+\frac{y}{b}=1$。不能表示截距为0的直线。

一般式：任何直线都可以写成$Ax+By+C=0(A,B不同时为0)$的形式。

### 已知两点求直线一般式方程

详见：[已知两点求直线一般方程](https://blog.csdn.net/madbunny/article/details/43955883)

已知直线过两点$(x_1,y_1)$和$(x_2,y_2)$，设直线方程为$Ax+By+C=0$。

则$Ax_1+By_1+C=0$，$Ax_2+By_2+C=0$，两者一减得$A(x_1-x_2)+B(y_1-y_2)=0$，不妨设$A=y_2-y_1,B=x_1-x_2$，得$C=x_2y_1-x_1y_2$。

### 点到直线的距离

点$P(x_0,y_0)$到直线$Ax+By+C=0$的距离$d=\frac{|Ax_0+By_0+C|}{\sqrt{A^2+B^2}}$。

用柯西不等式证明：

在直线上任取一点$T(m,n)$，则
$$
PT^2=(x_0-m)^2+(y_0-n)^2\\
=\frac{1}{A^2+B^2}*[(x_0-m)^2+(y_0-n)^2]*(A^2+B^2)\\
\geq\frac{1}{A^2+B^2}[A(x_0-m)+B(y_0-n)]^2\\
=\frac{(Ax_0+By_0+C)^2}{{A^2+B^2}}
$$

### 点和点关于点对称

详见：[直线与点的四类对称求解](https://zhuanlan.zhihu.com/p/444405771)

$A(x_1,y_1),M(x_2,y_2),B(2x_2-x_1,2y_2-y_1)$，点A和点B关于点M对称，即A点坐标和B点坐标的和为M点坐标的两倍。

证明：由全等三角形可证。

### 点关于直线对称

$A(x_1,y_1)$，直线$ax+by+c=0$，直线方向向量为$(b,-a)$，与该直线垂直的方向向量为$(a,b)$，设对称点$B(x_1+ma,y_1+mb)$，中点$M(x_1+\frac{ma}{2},y_1+\frac{mb}{2})$在直线上代入得。

$m=-2*\frac{ax_1+by_1+c}{a^2+b^2}$，就可以求出对称点和两者的中点。

### 直线和直线关于点对称

$M(x_0,y_0)$，$l_1:ax+by+c=0$，直线$l_1$和$l_2$关于点$M$对称，设点$(x,y)$在$l_2$上，则点$(2x_0-x,2y_0-y)$在$l_1$上，代入得出关于$(x,y)$的方程，也就是直线$l_2$的方程。

### 直线和直线关于直线对称

可以取直线上两点，根据点关于直线对称求出两点，让后求出一般式方程。



### 基本不等式

详见：[基本不等式](https://zhuanlan.zhihu.com/p/352588326)
$$
\frac{2}{\frac{1}{x}+\frac{1}{y}}\leq\sqrt{xy}\leq\frac{x+y}{2}\leq\sqrt{\frac{x^2+y^2}{2}}
$$
这四个值分别是**调和**平均数、**几何**平均值、**算术**平均值、**平方**平均值，记作**调几算方**。

**证明**：

先证基本不等式，$(x-y)^2=x^2+y^2-2xy\geq0$，所以$x^2+y^2\geq2xy$，将$\sqrt{x}$代入$x$，$\sqrt{y}$代入$y$得$x+y\geq2\sqrt{xy}$。

其余证明类似。

### 柯西不等式

详见：[柯西不等式](https://zhuanlan.zhihu.com/p/121702585)

**二维形式**：
$$
(a^2+b^2)(c^2+d^2)\geq(ac+bd)^2\ \ (当且仅当\frac{a}{c}=\frac{b}{d})
$$
**证明**：

$(a^2+b^2)(c^2+d^2)=a^2c^2+a^2d^2+b^2c^2+b^2d^2=(ac+bd)^2+(ad-bc)^2\geq(ac+bd)^2$。

**一般形式**：
$$
\sum_{i=1}^na_i^2\sum_{i=1}^nb_i^2\geq(\sum_{i=1}^na_ib_i)^2
$$
等号成立条件：$\frac{a_1}{b_1}=\frac{a_2}{b_2}=\cdots=\frac{a_n}{b_n},\{a_i\},\{b_i\}至少有一个全为0$。



### 直线方程的几种形式

详见：[直线的五种形式](https://zhidao.baidu.com/question/243923327661554284.html)

点斜式：直线过点$(x_0,y_0)$，斜率为$k$，则直线方程式为$y-y_0=k(x-x_0)$。不能表示斜率不存在的直线。

斜截式：直线在$y$轴上的截距为$b$，斜率为$k$，方程为$y=kx+b$。不能表示斜率不存在的直线。

两点式：直线经过$(x_1,y_1)和(x_2,y_2)$两点，方程为$\frac{y-y_1}{y_2-y_1}=\frac{x-x_1}{x_2-x_1}$。不能表示平行或垂直坐标轴的直线。

截距式：已知在$x$轴和$y$轴的截距为$a$，$b$，方程为$\frac{x}{a}+\frac{y}{b}=1$。不能表示截距为0的直线。

一般式：任何直线都可以写成$Ax+By+C=0(A,B不同时为0)$的形式。

### 已知两点求直线一般式方程

详见：[已知两点求直线一般方程](https://blog.csdn.net/madbunny/article/details/43955883)

已知直线过两点$(x_1,y_1)$和$(x_2,y_2)$，设直线方程为$Ax+By+C=0$。

则$Ax_1+By_1+C=0$，$Ax_2+By_2+C=0$，两者一减得$A(x_1-x_2)+B(y_1-y_2)=0$，不妨设$A=y_2-y_1,B=x_1-x_2$，得$C=x_2y_1-x_1y_2$。

### 点到直线的距离

点$P(x_0,y_0)$到直线$Ax+By+C=0$的距离$d=\frac{|Ax_0+By_0+C|}{\sqrt{A^2+B^2}}$。

用柯西不等式证明：

在直线上任取一点$T(m,n)$，则
$$
PT^2=(x_0-m)^2+(y_0-n)^2\\
=\frac{1}{A^2+B^2}*[(x_0-m)^2+(y_0-n)^2]*(A^2+B^2)\\
\geq\frac{1}{A^2+B^2}[A(x_0-m)+B(y_0-n)]^2\\
=\frac{(Ax_0+By_0+C)^2}{{A^2+B^2}}
$$

### 点和点关于点对称

详见：[直线与点的四类对称求解](https://zhuanlan.zhihu.com/p/444405771)

$A(x_1,y_1),M(x_2,y_2),B(2x_2-x_1,2y_2-y_1)$，点A和点B关于点M对称，即A点坐标和B点坐标的和为M点坐标的两倍。

证明：由全等三角形可证。

### 点关于直线对称

$A(x_1,y_1)$，直线$ax+by+c=0$，直线方向向量为$(b,-a)$，与该直线垂直的方向向量为$(a,b)$，设对称点$B(x_1+ma,y_1+mb)$，中点$M(x_1+\frac{ma}{2},y_1+\frac{mb}{2})$在直线上代入得。

$m=-2*\frac{ax_1+by_1+c}{a^2+b^2}$，就可以求出对称点和两者的中点。

### 直线和直线关于点对称

$M(x_0,y_0)$，$l_1:ax+by+c=0$，直线$l_1$和$l_2$关于点$M$对称，设点$(x,y)$在$l_2$上，则点$(2x_0-x,2y_0-y)$在$l_1$上，代入得出关于$(x,y)$的方程，也就是直线$l_2$的方程。

### 直线和直线关于直线对称

可以取直线上两点，根据点关于直线对称求出两点，让后求出一般式方程。

