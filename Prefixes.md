#                                  前缀和 差分

## 前缀和

> **前缀和是指某序列的前n项和，可以把它理解为数学上的数列的前n项和，而差分可以看成前缀和的逆运算。合理的使用前缀和与差分，可以将某些复杂的问题简单化**
>
> **作用：快速(O(1))查询到某个区间的和**

#### 一维前缀和

* **预处理O(n),查询O(1)**

```
输入长度为n的整数序列，接下来m个询问,每个询问输入一对l,r。对于每个询问，输出原序列中从l到r的r-l+1个数之和
```

容易想到的暴力做法：

```c
int n,m;
scanf("%d %d",&n,&m);
int num[n+1];
for (int i=1;i<=n;i++) scanf("%d",&num[i]);
while (m--){
    int l,r;
    scanf("%d %d",&l,&r);
    int ans = 0;
    for (int i=l;i<=r;i++) ans += num[i];
    printf("%d\n",ans);
}
```

这样写时间复杂度O(n*m)，答案显然是对的，但是如果数据规模比较大的话，如1<=n,m<=1e6，那么在极端情况下无法在几秒内运行得到结果，会超时

接下来讲讲时间复杂度O(n+m)的做法

首先做一个预处理，定义一个`sum[]`数组，`sum[i]`代表`a`数组中前`i`个数的和

我们可以在进行m次查询之前，输入`num[]`数组之后O(n)求出`sum[]`数组

```c
for (int i=1;i<=n;i++) scanf("%d",&num[i]);
sum[0] = 0;
for (int i=1;i<=n;i++) sum[i] = sum[i-1] + num[i];
```

在进行m次询问的时候，我们就没必要再暴力计算l到r的和了，具体代码：

```c
while (m--){
    int l,r;
    scanf("%d %d",&l,&r);
    ans = sum[r] - sum[l-1];
    printf("%d\n",ans);
}
```

原理：
$$
sum[r] = num[1]+num[2]+...+num[r-1]+num[r]
$$

$$
sum[l-1] = num[1]+num[2]+...+num[l-2]+num[l-1];
$$

$$
sum[r]-sum[l] = num[l]+num[l+1]+...+num[r-1]+num[r]
$$

![图1](http://luf.woyioii.cn:82/Images/Prefixes/sample1.png)

#### 二维前缀和

* **预处理O(n*m),查询O(1)**

如果数组变成了二维了呢？

给出问题：

```
输入一个n行m列的整数矩阵，再输入q个询问，每个询问包含四个整数x1, y1, x2, y2，表示一个子矩阵的左上角坐标和右下角坐标。对于每个询问输出子矩阵中所有数的和
```

容易想到的暴力:

```c
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
int num[n+1][m+1];
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        scanf("%d",&num[i][j]);
    }
}
while (q--){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int ans = 0;
    for (int i=x1;i<=x2;i++){
        for (int j=y1;j<=y2;j++){
            ans += num[i][j];
        }
    }
    printf("%d\n",ans);
}
```

复杂度O(nmq)数据范围大一点同样超时

接下来讲复杂度O(max(nm,q))的做法

首先预处理`sum[][]`数组，`sum[i][j]`表示二维数组左上角(1,1)到右下角(i,j)所包围的矩阵元素的和

```c
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + num[i][j];
    }
}
```

![图2](http://luf.woyioii.cn:82/Images/Prefixes/sample2.png)

查询时:`ans=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]`

原理：

![图3](http://luf.woyioii.cn:82/Images/Prefixes/sample3.png)

代码:

```c
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
int num[n+1][m+1];
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        scanf("%d",&num[i][j]);
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + num[i][j];
    }
}
while (q--){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int ans = sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
    printf("%d\n",ans);
}
```

## 差分

> **类似于数学中的求导和积分，差分可以看成前缀和的逆运算**
>
> > 差分数组：
> >
> > 首先给定一个原数组a：a[1], a[2], a[3],,,,,, a[n];
> >
> > 然后我们构造一个数组d ： d[1], d[2], d[3]...,d[i];
> >
> > 使得 a[i] = d[1] + d[2] + d[3] + ... + b[i]
> >
> > 也就是说，a数组是d数组的前缀和数组，反过来我们把d数组叫做a数组的差分数组。换句话说，每一个a[i]都是d数组中从头开始的一段区间和
>
> **作用：快速处理区间加减问题**

#### 一维差分

```
输入长度为n的整数序列，接下来m个修改操作，每次操作给定l,r,x,要求把[l,r]里的每一个数加上x,m次操作完之后输出该数组
```

暴力做法(O(mn))：

```c
int n,m;
scanf("%d %d",&n,&m);
int num[n+1];
for (int i=1;i<=n;i++) scanf("%d",&num[i]);
while (m--){
    int l,r,x;
    scanf("%d %d %d",&l,&r,&x);
    for (int i=l;i<=r;i++) num[i] += x;
}
for (int i=1;i<=n;i++) printf("%d ",num[i]);
```

考虑用差分数组优化成O(n)

我们修改区间的左右端点的差分数组的值即可

```c
int n,m;
scanf("%d %d",&n,&m);
int num[n+1];
int d[n+2];//防止越界
memset(d,0,sizeof(d));
for (int i=1;i<=n;i++){
    scanf("%d",&num[i]);
    d[i] = num[i] - num[i-1];//构建差分数组
}
while (m--){
    int l,r,x;
    scanf("%d %d %d",&l,&r,&x);
    d[l] += x;
    d[r+1] -= x;
}
for (int i=1;i<=n;i++){
    num[i] = num[i-1] + d[i];
}
for (int i=1;i<=n;i++) printf("%d ",num[i]);
```

#### 二维差分

```
输入一个n行m列矩阵，再进行q次操作，每次操作给定x1,y1,x2,y2,c,其中(x1,y1)和(x2,y2)表示一个子矩阵的左上角和右下角，每次操作都要将这个子矩阵的所有元素加上c，输出操作之后的矩阵
```

暴力做法O(nmq)，写法略

考虑二维差分优化(复杂度O(nm))

```c
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
int num[n+1][m+1];
int d[n+2][m+2];
memset(d,0,sizeof(d));
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        scanf("%d",&num[i][j]);
        d[i][j] = num[i][j]-num[i-1][j]-num[i][j-1]+num[i-1][j-1];//构建差分数组
    }
}
while (q--){
    int x1,y1,x2,y2,c;
    scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&c);
    d[x1][y1] += c;
    d[x1][y2+1] -= c;
    d[x2+1][y1] -= c;
    d[x2+1][y2+1] += c;
}
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        num[i][j] = num[i-1][j]+num[i][j-1]-num[i-1][j-1]+d[i][j];
    }
}
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
        printf("%d ",num[i][j]);
    }
    printf("\n");
}
```

图解：

![图4](http://luf.woyioii.cn:82/Images/Prefixes/sample4.png)



```c
d[x1][y1]+=c ; //让整个num数组中矩形面积的元素都加上了c。
d[x1][y2+1]-=c ; //让整个num数组中绿色矩形面积的元素再减去c，使其内元素不发生改变。
d[x2+1][y1]-=c ; //让整个num数组中紫色矩形面积的元素再减去c，使其内元素不发生改变。
d[x2+1][y2+1]+=c; //让整个num数组中红色矩形面积的元素再加上c，红色内的相当于被减了两次，再加上一次c，才能使其恢复。
```

