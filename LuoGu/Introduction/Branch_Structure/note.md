# note

> cpp中`<<` 优先级高于逻辑计算

来自于[Special_Number.cpp](./Special_Number.cpp)中

```cpp
  cout << (special1 && special2);
```

如这里的表达式的外层括号不加上会发生被抢先计算

先输出cout<<special1 然后再将得到的恒真的outs流对象和special2做逻辑与

注意到cpp语法中是允许没有被bind到变量上的纯表达式的，只是没有意义而已，于是这样执行下来发生了问题，而且还不易被发现

> cpp向上取整的简单实现

整数除法取整简单实现是调用`<cmath>`库中的`ceil(double x)`函数

但要注意潜在的类型转换问题

以$\frac{3}{2}$为例，分子分母都是int类型，直接计算会按int截断

```cpp
ceil(3/2); // 3/2按int截断，得到1,1隐式类型转换为double,调用ceil,得到1
ceil(static_cast<double>(3/2));// 3/2先按int截断为1后再转换成double 1.0，再调用ceil得到1

ceil(static_cast<double>(3)/2);
ceil(3/static_cast<double>(2));
//以上两种相同，只要表达式中有一个double便会进行隐式类型转换，得到1.5,然后再调用ceil得到2
}
```

简单的实现是直接套用公式

$\lceil \frac{a}{b}\rceil=\frac{a+b-1}{b}$

利用int自带的截断即可实现向上取整，这样完全避开了类型转换和额外调用ceil函数