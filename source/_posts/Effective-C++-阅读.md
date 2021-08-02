---
title: 《Effective C++》 阅读随记
date: 2021-07-08
tags: 
- C/C++
- 《Effective C++》
categories: 读书
---

# 读《Effective C++》第一章

## C++是一个语言联邦

C++是一个多重范型(muitiparidigm)语言，其支持：过程形式、面向对象形式、函数形式、泛型形式、元编程形式。

次语言(sublanguage)：C, Object-Oriented C++, Template C++, STL

正因如此，高效编程需要随着编程者切换次语言来采取不同的守则、通例。

## 用 `const` `enum` `inline` 替换 `#define`

1. 对于常量

   例如：`#define ASPECT_RATIO 1.653` 该记号名称也许从未被编译器看见，很可能在编译器处理源码之前，就被预处理器移走。这样的后果：ASPECT_RATIO 有可能未进入 symbol table （***注：符号表等概念可以查阅CSAPP第七章***）。于是一旦发生编译错误，可能就因此让编程者产生困惑。

   解决方法：用常量替换一个上述的宏

<img src="https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708142830.png" style="zoom:80%;" />

​		两种特殊情况：

​		**常量指针**

<img src="https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708143130.png" style="zoom:80%;" />

​		**`class`专属常量**

<img src="https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708143415.png" style="zoom:80%;" />





<img src="https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708143755.png" style="zoom:80%;" />

​		**enum hack** 技术，能够避免出现可能的（编译器不够优秀）为“整数型const对象” 进行内存分配

​		**enum hack** 技术，是模板元编程的基础技术。



2. 用`inline` 替代macro

（暂时略……）



**总结**

> 对于单纯常量，最好以const对象 或 enum 替换 #define
>
> 对于形似函数的宏（macros），最好改用 inline 函数替换 #define



## 尽可能使用 `const`

`const`关键字允许指定一个语义约束（说人话就是指定一个改动不了的对象）

例如：

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708190027.png)

**`const` 若出现在星号左边，表示被指物为常量；在星号右边，表示指针是常量；如果星号两边都有`const`,说明被指对象和指针本身都是常量。**

注：

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708190839.png)

-----

对于STL迭代器的`const`，和命名指针(T类型的指针, `T*`)类似。

```c++
vector<int> vec;

const vector<int>::iterator iter = vec.begin();// iter的作用类似于 T* const
												//指向的东西必须一样，但东西的值可以改变
*iter = 10;//ok
iter ++;//not allowed
vector<int>::const_iterator cIter = vec.begin();// cIter的作用类似于 const T*  
												//被指向的东西不得改变
*cIter = 10;//not allowed
cIter ++;//ok
```

令函数返回一个常量值，往往可以能够降低因client端的错误而造成的意外。详细例子见书P19

### const 成员函数

这类函数重要，原因有两个：

1. 让class接口更好理解，client端知道哪个函数可以改变对象内容，而哪个不行。

2. 让操作`const`对象成为可能，因为提升C++程序效率的一条原则：***pass by reference to const***

   这技术可行的前提：有`const`成员函数用来处理取得的`const`对象

一个事实：如果两个函数只是常量性不同，可以被重载。

如图：

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708215257.png)

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708215407.png)

因为`non-const operator[]`的返回类型是**reference to char**，不是`char`；如果返回的是`char`，该语句无法通过编译。因为函数如果返回类型是内置类型（如`int`,`char`,`bool`）, 改动返回值就是不合法的。



----



还有两个概念**logical constness** 和 **bitwise constness** 

后者支持者认为成员函数只有在不改变认为成员变量（除静态`static`变量以外）的情况下，才可以被称为`const`.

也就是不改动任何一个**bit**. 但却有很多函数符合该规则，却不是十足具备`const`性质，如：

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708220107.png)

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708220127.png)



另一派支持：**`const`成员函数可以修改对象的某些bits，但要在客户端侦测不到的时候才得如此。**

例如：

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708220438.png)

重要： **用`mutable`“骗过”编译器**

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210708220501.png)







### 在const 和 non-const成员函数中避免重复

*暂时略……反正`const`很强就完事了……*





**总结：**

> 将有些东西声明为`const`可以帮助编译器侦测出错误用法。 `const`可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
>
> 编译器强制实施 **bitwise constness**, 但实际编写程序应该使用“概念上的常量性”（比如使用mutable）
>
> 用`const`和`non-const`成员函数有着实质等价的实现时，令`non-const`版本调用`const`版本可避免代码的重复。







## 确定对象被使用前已先被初始化

