# OJ_3_Record

> 主要使用贪心策略解决

## A. Sorrowful Cows

> 给定M个木板，S个坑，坑中有C个位置分布有牛，要求木板长度总和最短且能挡住所有的牛

### 思路

显然木板用得更多粒度更细，总长度越小，故这里需要用完所有的M个木板

$M$个木板排在一起会产生$M-1$个空隙（可以为0），且由于尽可能要求木板总长度小，这样的空隙显然是与牛与牛之间的某些空隙重合的。

整体来看，这$M-1$个空隙和所有板子的长度$L$一起构成了固定长度的$S_1$，即

$S_1=L+\sum_{i=1}^{M-1}{Gap_i}$

式中$S_1=C_{max} - C_{min} + 1$

即有牛分布的坑位的长度

故为了让$L$最小，这里让$\sum_{i=1}^{M-1}Gap_i$最大即可

$Gap_i$由牛与牛之间的举例产生，$C$头牛总共产生$C-1$个空隙，且

$Gap[i] = C[i+1] - C[i] - 1,1\le i\le C-1$

故只用先计算所有的$Gap$后再排序后选最大的$M-1$个即可

## B. Sick Cows

>长度为n的01串代表牛是否健康，被感染的牛每天晚上都会感染左右两边的牛，问一开始最少有多少只病牛

### 问题的结构

01串上会有若干个独立的连续1区间，代表独立的感染区域

显然对于一个区域，达成这样感染情况的时间越长，原始的感染牛数最少

故问题分为三步：

1. 遍历所有的连续1区间，得到其对应的可能最长的时间
2. 取所有最长时间里的最小值，即传染的时间
3. 再遍历一遍所有的连续1区间，参照传染时间确定需要几个传染源并相加即可

现在进一步分解为：

1. 给定长度为n的连续1区间，怎么得到可能最长时间？
2. 给定长度为n和给定的感染时间t，对应的最少传染源为？

如果区域有一端在边界，这样的问题还得继续分类讨论

### 给定长度n的区间的最长感染时间

#### 区间在边界上

最长感染时间为`n-1`对应从边界点开始

#### 非边界区间

* n为奇数

  对应从正中间开始生长，时间为$\frac{n-1}{2}$

* n为偶数

  感觉情况有些复杂？分类讨论下尝试

  如果偶数区间由一个病原体生成，则对应最短时间为0，因为一个病原体必长成奇数

  如果偶数区间由两个病原体生成，则一边生成一半最快

  如果偶数区间由三个病原体生成，则时间肯定更短，故**只用考虑最长时间为两个病原体导致的情况**

  最长时间就是中间两个病原体背靠背生成对应的时间，即$\frac{n}{2}-1$

### 给定长度n和t的区间最小感染源个数

#### 边界条件t=0

则感染源个数=区间长度n

#### 边界条件t刚好等于该区间的最大时间

奇数区间1，偶数区间2，边界区间1

#### 区间在边界

t时间，一个感染源最多生成长度为$s=2(t-1)+1=2t-1$，故此时为了感染源最少，则从非边界方向朝边界方向开始将长度n尽可能分为s的倍数，最后剩下的余数，用剩下那堆里中间一个当核即可，这样实际上做了一个向上取整，故对应的核数量为$core=\lceil \frac{n}{s}\rceil$

#### 区间非边界

同样的用s去组装n，由于时间的限制，此时每个n内至少可以放一个s

同样排布尽可能多的s后剩下的，用一个生成了重叠部分的区间放下，故对应的病原体个数也为

$core=\lceil \frac{n}{s}\rceil$

至此我们已经解决了所有的情况，构造两个辅助函数再遍历几遍就可以解决这个问题了

## C. Minimum Number of Straights

> 输入一个数组对应一手牌，每个位置的值对应该牌面的牌数，每次可以打出任意长度的顺子，问最少多少次能把所有的牌打完

### 问题的结构

1. 最优子结构

   砍成两个不相连的区间后，显然各部分之间出牌彼此没有影响，分别把两个不相连的区间打完即可，即局部最优=全局最优

2. 贪心策略

   对于序列依次考察，从前往后推。比如序列24123，先看2，如果只有一个2，那么结果是显然的，打两次牌即可，所以这个情况下答案是2 。然后再看24，那么打两次之后，2打完了还有4，于是就要打4次。然后再看241，显然也只需要4次。因为那个1可以在第一次就打完，同样即使是242，也只需4次。这个说明什么呢？可以这样理解，递增的部分，比如242中的24，取最大值即4，非递增部分，比如242中的42，是没有意义的，因为4后面只要跟着的是一个小于等于4的数字，那么打牌的时候就可以把它“顺便”打出去

