# Note

## 高精度加法/乘法

用vector<int>来存储各个数位

加法模拟竖式加法，按位加了按位进位

乘法不是简单模拟竖式乘法，而是用一个双重循环来实现

```cpp
  // Overloading operator +.
  BigInt operator+(const BigInt &b) const {
    BigInt res;
    res.digits.clear();
    int carry = 0, i = 0;
    while (i < digits.size() || i < b.digits.size() || carry) {
      int sum = carry;
      if (i < digits.size())
        sum += digits[i];
      if (i < b.digits.size())
        sum += b.digits[i];
      res.digits.push_back(sum % 10);
      carry = sum / 10;
      i++;
    }
    return res;
  }

  // Overloading operator *.
  BigInt operator*(const BigInt &b) const {
    if (b.digits.size() == 1 && b.digits[0] == 0)
      return BigInt(0);
    if (this->digits.size() == 1 && this->digits[0] == 0)
      return BigInt(0);
    BigInt res;
    res.digits.assign(digits.size() + b.digits.size(), 0);
    for (size_t i = 0; i < digits.size(); i++) {
      for (size_t j = 0; j < b.digits.size(); j++) {
        res.digits[i + j] += digits[i] * b.digits[j];
        res.digits[i + j + 1] += res.digits[i + j] / 10;
        res.digits[i + j] %= 10;
      }
    }
    // clear the leading zeros.
    while (res.digits.size() > 1 && res.digits.back() == 0)
      res.digits.pop_back();
    return res;
  }
```

如果使用竖式的乘法，则相当于每次乘一位然后再移位后相加一次，显然慢了

乘法在双循环遍历时，两个乘数的第m位和第n位相乘会贡献到结果的第m+n位上，每次累加并进位取余即可

## 质数的几种优化判断法

> base：除尽法

判断n是否为质数，由对称性，只用检查$\sqrt{n}$以下的所有整数是否整除即可，复杂度为$\sqrt{n}$

> 优化：$6k\pm1$法

2和3是质数，判断返回

判断若整除2或3则返回

从5开始，以6为步长开始判断

由于按6分类将数可以分为6个等价类$6k,6k+1,6k+2,6k+3,6k+4,6k+5$

其中$6k,6k+2,6k+4$被2整除

$6k+3$被3整除，已经被筛选过，故剩下只用判断$6k+1,6k+5$

也即可以写成$6k\pm 1$

也即是说从5开始的所有质数都可以写成$6k\pm 1$的形式，循环进行判断即可

```cpp
bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}
```

> 涉及区间内取很多素数的情况：埃氏筛法

基本步骤是从最小的素数2开始，将该素数的所有倍数标记成合数，而下一个尚未被标记的最小自然数3即是下一个素数。如此重复这一过程，将各个素数的倍数标记为合数并找出下一个素数，最终便可找出一定范围内所有素数。适用于在一个区间内找素数时，这样一次构造筛完剩下只用查表就行，复杂度$\Theta(nlog(logn))$不用每个数都遍历一次，复杂度为$\Theta(n\sqrt{n})$

![](./pic/Sieve_of_Eratosthenes_animation.gif)

```cpp
#include <vector>

auto eratosthenes(int upperbound) {
  std::vector<bool> flag(upperbound + 1, true);
  flag[0] = flag[1] = false; //exclude 0 and 1
  for (int i = 2; i * i <= upperbound; ++i) {
    if (flag[i]) {
      for (int j = i * i; j <= upperbound; j += i)
        flag[j] = false;
    }
  }	
  return flag;
}
```

## 回文数和质数的性质：

> 除了11外，所有的偶数位的回文数都不是质数

对于偶数位的回文数是质数，设其前缀为$a_1a_2a_3...a_i$

则其可以写成$a_1a_2a_3...a_na_na_{n-1}...a_2a_1=\sum_{k=1}^{n}a_k(10^{2n-k}+10^{k-1})$

分析其中每一项$10^{2n-k}+10^{k-1}$

由$10\equiv-1(mod11)$

有$10^{2n-k}+10^{k-1}\equiv(-1)^{2n-k}+(-1)^{k-1}=0(mod11)$

即上式整除11

故求和后也是11的倍数

也就是说除了11外，所有的偶数位回文数都不是质数

## 需要按位处理输入数字时可以按位读取字符

如要反转数字的输入，不需要输入后把每一位手动除十计算出来，直接

```cpp
char c;
while(cin>>c){...}
```

即可

但是这样往往有个问题在于while循环不会自动结束，需要手动ctrl+d才能结束输入流

为了方便使用，循环条件继续可以迭代成

```cpp
while (cin.get(c)&& c != '\n')
```

使用get，会读入输进去的所有字符（包括被>>忽略的空格换行等），再加个判断回车即可，这样当输入123后按下回车即可结束循环。

