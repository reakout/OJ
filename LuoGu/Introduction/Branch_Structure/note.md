# note

> cpp中`<<` 优先级高于逻辑计算

来自于[Special_Number.cpp](./Special_Number.cpp)中

```cpp
  cout << (special1 && special2);
```

如这里的表达式的外层括号不加上会发生被抢先计算

先输出cout<<special1 然后再将得到的恒真的outs流对象和special2做逻辑与

注意到cpp语法中是允许没有被bind到变量上的纯表达式的，只是没有意义而已，于是这样执行下来发生了问题，而且还不易被发现