---
title: CPP-OPP review(2)
date: 2021-07-20
tags: C/C++
---

# CPP-OPP review(2)

1. 操作符重载，可分为：**成员函数**（含`this`指针）和**非成员函数**。

2. 临时对象，例如之前所写的`complex`类,`complex(2,1)`创建一个 **2 + i ** 的复数临时对象。如果在成员函数当中被临时创建，注意使用 *return by value* , 因为在函数中创建的对象是 *local* 的，临时的。

3. 输入输出流作为参数不可以作为`const`传入

4. 一段代码：

   ```c++
   ostream& operator << (ostream& os, const complex& x)
   {
       return os << "(" << real(x) << "," << imag(x) << ")";
   }
   ```

   这里为什么返回的是`ostream&`，而不是`void`？

   因为很常见的情况：

   ```c++
   complex c1(2,1);
   complex c2(1,1);
   cout << c1;//void 还是ostream&返回 都可以
   cout << c1 << c2;//假设是这种情况，void返回就不行。
   ```

   
   
   ----

**总结**

**initialization list**的使用；函数参数考虑，尽量用*pass_by_reference*；函数参数考虑是否要加`const`；函数返回值考虑是否用*pass_by_reference*。

