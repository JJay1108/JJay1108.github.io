---
title: CPP-OPP review(3)
date: 2021-07-22
tags: C/C++
---

# CPP-OPP review(3)


A **BIG THREE**:

1. 拷贝构造函数
2. 拷贝赋值函数
3. 析构 

有指针成员的函数，必须要有拷贝构造+拷贝赋值  

否则就产生多重引用



```C++

#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:                                 
   String(const char* cstr=0);                     
   String(const String& str);                    
   String& operator=(const String& str);         
   ~String();                                    
   char* get_c_str() const { return m_data; }
private:
   char* m_data;
};

#include <cstring>

inline
String::String(const char* cstr)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1];//动态分配内存， +1因为包括结束符
      strcpy(m_data, cstr);
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';//注意这里是*m_data
   }
}

inline
String::~String()
{
   delete[] m_data;//注意这里是delete[]，而不是delete
}

inline
String& String::operator=(const String& str)//拷贝赋值
{
   if (this == &str)//&符号的含义结合具体情况，加在类型后面就是引用，
       				//如果加在变量名前，就是取地址
      return *this;//这种情况检验自我赋值。例如s1 = s1;
    				//特殊情况特殊处理

   delete[] m_data;//先delete，再分配空间+拷贝
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

inline
String::String(const String& str)//拷贝构造
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif
```



------



![构造函数 和 析构函数](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723231933.png)





![拷贝构造](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723232041.png)



![拷贝赋值函数](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723232232.png)

![自我赋值造成可能的危险](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723232327.png)



------

![new 申请空间](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723232632.png)

![delete 释放空间](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723232713.png)

`new`实际上先申请了一部分内存，在进行构造

`delete`则反过来，先调用析构函数，再释放内存



--------

接下来是底层的内存分配示意图

![](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723233051.png)

红色部分是 *cookie*，各占四个字节；灰色部分是 *debugger header*，以及*no man land*，当然还有内存对齐所需要的空间。	从52到64，是为了让申请的内存块大小达到16Byte的倍数。



之后的图片说明了，`delete`和`delete[]`的区别：

![delete的使用](https://gitee.com/jasonstudyield/imagesbed/raw/master/20210723233633.png)

确实会造成**memory leak**，但其实是打**？！**的内存区域没有被回收，而不是想象中的**21h**部分。
