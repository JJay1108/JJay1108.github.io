---
title: CPP-OPP review(1)
date: 2021-07-18
tags: C/C++
---

# CPP-OPP review(1)



这个*review*系列是本人观看侯捷老师的面向对象的讲解视频，并结合 *effective C++* 这本经典书籍，进行的一些知识点的零散记录。



----



1. class中的成员函数，默认成为`inline`函数的候选

2. 外部的函数想要成为`inline`，需要加关键字`inline`

3. 构造函数的写法：

   1. 赋值写法

   2. 运用**初值列**(*initialization list*),进行初始化

      这两种的区别是，构造函数先进行初始化，再进行{}内部的操作，用*initialization list*更有效率。
      
      ```c++
      class complex
      {
      	public:
          	complex(double r = 0, double i = 0):
          		re(r),im(i){}
          private:
          	double re, im;
      };
      ```
      
      

4. 构造函数允许有很多个 - **overloading**

   *但如果出现以下的例子，则not allowed*:

   ```c++
   public:
   	complex(double r = 0, double i = 0)
           :re(r),im(i)
           {}//这里不需要加分号了
   	complex():re(0),im(0){}//与上面一个构造函数冲突
   private:
   	double re, im;
   ```

5. 构造函数也有可能写在`private`中，这种模式叫做*singleton*.
6. 在写成员函数的时候，就需要考虑好，是否需要加上`const`.**该加上就要加上！**

7. 尽可能多用*pass-by-reference*，pass-by-value(to const)需要将数据 *打包* 压入栈，（可能爆栈）

8. 相同`class`的各个对象互为友元，例如：

   ```c++
   class complex
   {
   public:
       complex(double r = 0, double i = 0):
       	re(r),im(i){}
       int func(const complex &pra)
       {
           return (pra.re + pra.im);
   	}
   private:
       double re , im;
   };
   
   //////////以下为main函数///////
   {
       complex c1(2,1);
       complex c2;
       c2.func(c1);//实部虚部相加 
   }
   ```

   