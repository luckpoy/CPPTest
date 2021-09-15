# ReadNote
![AUR last modified](https://img.shields.io/aur/last-modified/google-chrome)
## data share and protect
### namespace 作用域问题
* 每个源文件的匿名命名空间是彼此不同的，在一个源文件中没有办法访问其他源文件的匿名命名空间。[page 149]
* 具有命名空间作用域的变量也叫全局变量；
### static 局部可见
```cpp 
void fun(){
    static int a=5;
    int b=6;
    return;
}
int main(){
    int a = 3;
    cout<<a<<endl;
    return 0;
}

output:3
```

### 对象的复制
1. 构造参数一致重新构造;
2. 直接ob1 = ob2;
3. 通过默认拷贝函数来复制,Object o1(10); Object o2(o1);<font color = red>(浅赋值)</font>

### 构造函数
构造时可以将参数通过参数列表传递;

### 类型转换
类型转换包括显式和隐式，很多代码不经意的用到了隐式转换；
+ 如果不希望发生隐式转换，可以在构造函数前加上“explicit”；

### 静态数据成员
采用static定义静态数据成员，为该类的所有对象所共有；
它不属于任何对象，可以使用 类名：：标识符 去初始化（除了初始化，外部都不可直接访问）；

### 类的友元
* 友元函数：虽然不是本类的成员函数，但可以通过对象名访问类的私有或保护成员；
* 友元类：若a为b的友元类，则a的所有成员函数都是b的友元函数，都可以访问b的保护或私有成员；声明语法如下
```cpp
class b{
    ...
    friend class a; // 声明a为b的友元类
    ...
}
```
* 友元关系是单向的、不能传递的也不能继承的；

### const
   1. const是函数的一个组成部分，在定义时也要加上；
   2. 如果一个对象被声明为常对象，那么只能调用它的常成员函数；
   3. 常成员函数不能更新目的对象的成员变量，也不能调用其他成员函数；
   4. const可以用于对重载函数的区分；eg：void a(); void a() const;

### 多文件管理和预编译
* 局部变量尽量不用static，应当将不希望被其他编译单元引用的函数和变量放到匿名命名空间里；
* using namespace 尽量不要放在头文件里；
* 预编译指令 #include #define #undef；


## 数组、指针和字符串
### 数组
* 二维数组一般按行优先存储；
* 二维数组的下表可以不用显式，eg：int a[2][3] <=> int a[][3]

### 指针
* 变量的引用
  * <font color=red>&出现在变量声明语句中位于被声明变量的左边时，表示的是引用；</font><br>eg：int &rf;
  * <font color=red>&在给变量赋初值时出现在等号右边或在执行语句中作为一元运算符出现时，表示取对象的地址。</font><br>eg：
    ```cpp
    int a,b;
    int * pa, *pb = &b;
    pa = &a;
    ```
* 指向常量的指针定义后，不可以改变其指向的对象的值，但能改变其指向；const int * p = &a;
* 指针型的常量指针本身不能改变；int * const p = &a;
* void * 型指针可以存储任何类型数据，经过显式转换就可以访问指向的内容；<br>eg:
    ```cpp
    void * pv;
    int i=5;
    pv = & i;
    int * print = static_cast<int *>(pv);
    cout<< "* print = "<<*print<<endl;
    ```
* <font color=orange>指针型函数（p211）专门存放函数代码首地址;</font><br>声明语法：<font color = 0xffffffff>数据类型 （* 函数指针名）（形参列表）</font><br>赋值方式：函数指针名 = 函数名
* 对象访问成员的方式有两个：
  1. 对象命访问：a.x
  2. 指针访问 ：p = & a; p->x
* this指针是一个隐含于每个类的非静态成员函数中的特殊指针（包含构造和析构函数），它用于指向正在被成员函数操作的对象；
* 用new分配的内存，必须用delete释放，否则会内存泄漏；
* new t和new t()的区别在于是否有自定义的构造函数；new int []可以生成数组；
* new 建立的数组必须用delete[]删除；
* 通过类成员访问数组，可以使用assert检查越界问题；<font color = green>( assert only be used in debug mode )</font>
* <font color = red>动态创建的意义在于能在局部作用域建立一个与程序生存周期相同的存储堆，如果用静态创建，则会被创建到运行栈里；</font>
* vector是一个类模板，用于定义动态数组；
* vector <类型名> 对象名(数组长度);  vector定义的所有对象都会被初始化（调用构造换数）；访问用对象名[下标]；
* cin >>  的分隔符是<空格>；
* c++中 . 和 -> 主要是用法上的不同。  
    1、A.B则A为对象或者结构体；  
    2、A->B则A为指针，->是成员提取，A->B是提取A中的成员B，A只能是指向类、结构、联合的指针；
* 共享指针；
  
### 引用和指针
引用是高层机制，指针是底层机制；二者殊途同归，引用的实现需要借助地址，差异主要是语言形式上的；

### 堆栈
* 内存格局通常分为四个区<br>全局数据区：存放全局变量，静态数据，常量; <br>代码区：存放所有的程序代码；<br>栈区：存放为运行而分配的局部变量，参数，返回数据，返回地址等；<br>堆区：即自由存储区。<br>
* 栈， 是硬件， 主要作用表现为一种数据结构， 是只能在一端插入和删除数据的特殊线性表。
* 堆， 是一种动态存储结构， 实际上就是数据段中的自由存储区， 它是C语言中使用的一种名称， 常常用于存储、 分配动态数据。堆中存入的数据地址向增加方向变动。
* 堆可以不断进行分配直到没有堆空间为止， 也可以随时进行释放、 再分配， 不存在顺序问题。<br>堆内存的分配常通过malloc() 、 calloc() 、 realloc() 三个函数来实现。而堆内存的释放则使用free() 函数。(for c process)<br>堆和栈在使用时“生长”方向相反， 栈向低地址方向“生长”， 而堆向高地址方向“生长”。
* 为什么要有堆栈？<br>栈：为了存放运行时的局部变量，参数，返回数据，返回地址等。<br>堆：栈的性能非常高，但是对于所有的变量来说还不太灵活，而且变量的生命周期必须嵌套。<br>通常我们希望使用一种方法分配内存来存储数据，并且方法退出后很长一段时间内数据仍然可以使用。此时就要用到堆（托管堆）。
* 堆(Heap)是应用程序在运行的时候请求操作系统分配给自己内存，一般是申请/给予的过程。<br>由于从操作系统管理的内存分配所以在分配和销毁时都要占用时间，所以用堆的效率低的多！但是堆的好处是可以做的很大，C/C++对分配的Heap是不初始化的。

## 继承与派生
### 派生类的生成过程
1. 吸收基类成员：继承基类的构造和析构以外的非静态成员；
2. 改造基类成员：继承方式和对基类成员的覆盖隐藏；
3. 添加新成员

### 继承理解
首先，继承只是继承了结构，这要做的目地是更加灵活的描述现实逻辑；<font color = red>如B继承了A，B只能通过B的对象访问A定义的成员，不能通过A的对象访问；</font>  
其次，public相当于给外界接口,protected用法上和privated是一样的，区别是它可以继承；privated成员只能在本体内访问并且不能继承；<br>最后，继承方式对privated成员没有影响（继承不了privated成员），而protected方式将puliced成员改为protected；privated方式将所有能继承成员变为私有成员；publiced方式改变成员属性；

### 继承总结
* 类型兼容规则是在需要基类对象的任何地方都可以使用public派生类的对象来替代，替代后只能使用继承下来的成员；例如P263（大替小）
* 作用域分辨符的隐藏规则：在有成员二义性的作用域，使用分辨符可以消除二义性；
* 只有在相同作用域定义的函数才能重载；
* 使用在成员函数的实现里，使用using可以让成员函数和using作用域的内容重载；
* 类的组合，即一个类内嵌其他类的对象；
* 虚基类是用来解决多个类继承之间有重复分配空间的问题的；
* 兼容规则的内存布局问题；

## 多态性
### 概念
多态性是指同样的消息被不同类型的对象接收时导致不同的行为；<br>多态4种类型：重载多态，强制多态，包含多态和参数多态；<br>重载分为编译重载和实现重载; <br>函数重载和运算符重载是编译时多态的基础

### 运算符重载
* 临时对象语法：return 类名（参数）;<br>eg：
  ```cpp
  return complex(real+a.real,imag + a.imag);
  ```
* 声明时的区别：
  | 前置单目运算 | 后置单目运算 |
  | :--------: | :--------: |
  | 重载函数没有形参|重载函数有一个形参|

### 虚函数(理解)
参考：<https://blog.csdn.net/haoel/article/details/1948051>
* 虚函数是动态绑定的基础，虚函数不许是非静态成员函数，经过派生后可以实现运行过程中的多态；
* C++中的虚函数的作用主要是实现了多态的机制，简而言之就是用父类型别的指针指向其子类的实例，然后通过父类的指针调用实际子类的成员函数。这种技术可以让父类的指针有“多种形态”，这是一种泛型技术。<br>所谓泛型技术，说白了就是试图使用不变的代码来实现可变的算法。
* 虚函数（Virtual Function）是通过一张虚函数表（Virtual Table）来实现的。简称为V-Table；<br>在这个表中，主是要一个类的虚函数的地址表，这张表解决了继承、覆盖的问题，保证其容真实反应实际的函数。它就像一个地图一样，指明了实际所应该调用的函数。<br>![](https://p-blog.csdn.net/images/p_blog_csdn_net/haoel/15190/o_vtable1.jpg)

### 虚函数（使用）
使用条件：
1. 满足类型兼容规则；
2. 要声明虚函数；
3. 要由成员函数调用或通过指针引用访问虚函数，如果用对象名访问，绑定在编译时就完成了（静态绑定），用不到虚函数表；

```cpp
//对象访问
void fun(base1 p){p.display();}
int main(int argc, char const *argv[])
{
    base1 b1;
    base2 b2;
    derived d;
    fun(b1);
    fun(b2);
    fun(d);
    return 0;
}
output:
        base1::display//类型兼容
        base1::display
        base1::display

//引用访问
void fun(base1 * p){ p->display();}
int main(int argc, char const *argv[]){
    base1 b1;//b1 b2都是对象名而已
    base2 b2;
    derived d;
    fun(&b1);
    fun(&b2);
    fun(&d);
    return 0;
}
output:
        base1::display
        base2::display
        derived::display

//src stay in test9
```

### 纯虚函数
test:test10
* 带有纯虚函数的类是抽象类，只能继承，不能实例化；
* 若派生类为给出纯虚函数的实现，则派生类仍是抽象类；
* 抽象类可以定义指针或引用去访问派生类的对象，这种访问是具有**多态性**的；

### 多态类型与非多态类型
* 设计多态类型的一个重要原则：把多态类型的析构函数设定为虚函数；
* 对非多态类型的**公有继承**应当慎重，而且一般没太大必要；
* dynamic_cast实例：p337 基类指针向派生类转换；
* c++ 获取类型名称：typeid；test10/typeid
  
## 群体
### 函数模板
* C++最重要的特性之一就是代码重用；
* 通过模板可以实现参数化多态；
* 编译器以函数模板生成一个函数的过程为函数模板的**实例化**，函数为该模板的**实例**；
* 在定义类模板或者函数模板时，typename 和 class 关键字都可以用于指定模板参数中的类型。<br>typename 另外一个作用为：使用嵌套依赖类型(nested depended name)；<br>
  ```cpp 
  class MyArray 
  { 
      public：
      typedef int LengthType;
      .....
  }

  template<class T>
  void MyMethod( T myarr ) 
  { 
      typedef typename T::LengthType LengthType; 
      LengthType length = myarr.GetLength; 
  }
  ```
  这个时候 typename 的作用就是告诉 c++ 编译器，typename 后面的字符串为一个类型名称，而不是成员函数或者成员变量; 
* typedef 和 #define 区别
  ```c
    typedef　char*　pStr1;
    #define　pStr2　char*　
    pStr1　s1, s2;
    pStr2　s3, s4;
  ```
  在上述的变量定义中，s1、s2、s3都被定义为 char* 类型；但是s4则定义成了 char 类型，而不是我们所预期的指针变量 char*，这是因为 #define 只做简单的字符串替换，替换后的相关代码等同于为：
  ```c
  char*　s3, s4; 
  ```
  而使用 typedef 为 char* 定义了新类型 pStr1 后，相关代码等同于为：
  ```c
  char *s3, *s4;
  ```
+ 函数模板本身在编译是不生成目标代码；只有实例化是才生成目标代码；
+ 被多个文件引用的函数模板应将将函数也一并放入头文件中；
+ 函数指针也只能指向模板实例，而不是模板本身；

### 类模板
重载“=”和“[]"时，返回类型都是对对象的引用；

----

### 总结
* 类模板不是类；实例化的类之间也不能兼容；
* 实例化是参数类型必须显式指定；
* 模板的特化是指一个模板在某些特定参数下提供的特殊定义；
* 特化类模板应该放在源文件而非头文件中（p390）；
* 偏特化；
* C++不允许将函数模板偏特化，但函数模板可以重载；
* 模板元编程是指在模板实例化的同时利用编译器完成一些计算任务；从而提程序的运行效率；（p392）

## 泛程序和标准模板库
### 迭代器
* 对于输入迭代器而言，p1 == p2不能保证++p1 == ++p2，更不能保证*(+p1)==*(++p2); 因此输入迭代器只适合做只需要遍历一次的算法输入；
* vector::begin():Return iterator to beginning
  Returns an iterator pointing to the first element in the vector.

  Notice that, unlike member vector::front, which returns a reference to the first element, this function returns a random access iterator pointing to it.

  If the container is empty, the returned iterator value shall not be dereferenced.<br>**----C++ reference**
* 
