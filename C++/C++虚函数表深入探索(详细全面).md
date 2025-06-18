#### 什么是虚函数表？

对于一个类来说，**如果类中存在虚函数，那么该类的大小就会多4个字节，然而这4个字节就是一个指针的大小，这个指针指向虚函数表**。所以，如果对象存在虚函数，那么编译器就会生成一个指向虚函数表的指针，所有的虚函数都存在于这个表中，**虚函数表就可以理解为一个数组，每个单元用来存放虚函数的地址**。


**虚函数（Virtual Function）是通过一张虚函数表来实现的**。简称为V-Table。在这个表中，主要是一个类的虚函数的地址表，**这张表解决了继承、覆盖的问题，保证其真实反应实际的函数**。这样，在有虚函数的类的实例中分配了指向这个表的指针的内存，所以，当用父类的指针来操作一个子类的时候，这张虚函数表就显得尤为重要了，它就像一个地图一样，指明了实际所应该调用的函数。                                                                                                                        

#### 虚函数表存在的位置

   由于虚函数表是由编译器给我们生成的，那么编译器会把虚函数表安插在哪个位置呢？下面可以简单的写一个示例来证明一下虚函数表的存在，以及观察它所存在的位置，先来看一下代码：

```C++
#include <iostream>
#include <stdio.h>
using namespace std;

class A{
public:
	int x;
	virtual void b() {}
};

int main()
{
	A* p = new A;
	cout << p << endl;
	cout << &p->x << endl;
	return 0;
}
```

   定义了一个类A，含有一个x和一个虚函数，实例化一个对象，然后输出对象的地址和对象成员x的地址，我们想一下，如果对象的地址和x的地址相同，那么就意味着编译器把虚函数表放在了末尾，如果两个地址不同，那么就意味着虚函数表是放在最前面的。运行结果为16进制，然后我们把它转为10进制观察一下：

![[Pasted image 20241212144500.png]]

   可以观察到结果是不同的，而且正好相差了4个字节，由此可见，**编译器把生成的虚函数表放在了最前面**。

#### 获取虚函数表

   既然虚函数表是真实存在的，那么我们能不能想办法获取到虚函数表呢？其实我们可以通过指针的形式去获得，因为前面也提到了，我们可以把虚函数表看作是一个数组，每一个单元用来存放虚函数的地址，那么当调用的时候可以直接通过指针去调用所需要的函数就行了。我们就类比这个思路，去获取一下虚函数表。首先先定义两个类，一个是基类一个是派生类，代码如下：


```C++
class Base {
public:
	virtual void a() { cout << "Base a()" << endl; }
	virtual void b() { cout << "Base b()" << endl; }
	virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
	virtual void b() { cout << "Derive b()" << endl; }
};
```

   现在我们设想一下Derive类中的虚函数表是什么样的，它应该是含有三个指针，分别指向基类的虚函数a和基类的虚函数c和自己的虚函数b(因为基类和派生类中含有同名函数，被覆盖)，那么我们就用下面的方式来验证一下：


```C++
    Derive* p = new Derive;
	long* tmp = (long*)p;             // 先将p强制转换为long类型指针tmp

	// 由于tmp是虚函数表指针，那么*tmp就是虚函数表
	long* vptr = (long*)(*tmp);
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr[i]);
	}
```

   同理，我们把基类的虚函数表的内容也用这种方法获取出来，然后二者进行比较一下，看看是否是符合我们上面所说的那个情况。先看一下完整的代码：


```C++
#include <iostream>
#include <stdio.h>
using namespace std;

class Base {
public:
	virtual void a() { cout << "Base a()" << endl; }
	virtual void b() { cout << "Base b()" << endl; }
	virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
	virtual void b() { cout << "Derive b()" << endl; }
};

int main()
{
	cout << "-----------Base------------" << endl;
	Base* q = new Base;
	long* tmp1 = (long*)q;
	long* vptr1 = (long*)(*tmp1);
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr1[i]);
	}

	Derive* p = new Derive;
	long* tmp = (long*)p;
	long* vptr = (long*)(*tmp);
	cout << "---------Derive------------" << endl;
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr[i]);
	}
	return 0;
}
```

   运行结果如下图所示：

![[Pasted image 20241212144743.png]]

   可见基类中的三个指针分别指向a,b,c虚函数，而派生类中的三个指针中第一个和第三个和基类中的相同，那么这就印证了上述我们所假设的情况，那么这也就是虚函数表。但是仅仅只是观察指向的地址，还不是让我们观察的特别清楚，那么我们就通过定义函数指针，来调用一下这几个地址，看看结果是什么样的，下面直接上代码：


```C++
#include <iostream>
#include <stdio.h>
using namespace std;

class Base {
public:
	virtual void a() { cout << "Base a()" << endl; }
	virtual void b() { cout << "Base b()" << endl; }
	virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
	virtual void b() { cout << "Derive b()" << endl; }
};

int main()
{
	typedef void (*Func)();
	cout << "-----------Base------------" << endl;
	Base* q = new Base;
	long* tmp1 = (long*)q;
	long* vptr1 = (long*)(*tmp1);
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr1[i]);
	}
	Func a = (Func)vptr1[0];
	Func b = (Func)vptr1[1];
	Func c = (Func)vptr1[2];
	a();
	b();
	c();

	Derive* p = new Derive;
	long* tmp = (long*)p;
	long* vptr = (long*)(*tmp);
	cout << "---------Derive------------" << endl;
	for (int i = 0; i < 3; i++) {
		printf("vptr[%d] : %p\n", i, vptr[i]);
	}
	Func d = (Func)vptr[0];
	Func e = (Func)vptr[1];
	Func f = (Func)vptr[2];
	d();
	e();
	f();

	
	return 0;
}
```

   运行结果如下：
![[Pasted image 20241212144626.png]]

   这样就清晰的印证了上述所说的假设，那么虚函数表就获取出来了。

#### 多重继承的虚函数表：

   虚函数的引入其实就是为了实现多态(对于多态看到了一篇很不错的博客：[传送门](https://cloud.tencent.com/developer/tools/blog-entry?target=https%3A%2F%2Fblog.csdn.net%2Fqq_39412582%2Farticle%2Fdetails%2F81628254&objectId=1599283&objectType=1&isNewArticle=undefined))，现在来研究一下多重继承的虚函数表是什么样的，首先我们先来看一下简单的一般继承的代码：

```C++
class Base1 {
public:
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Derive : public Base1{
public:
	virtual void MyA() { cout << "Derive MyA()" << endl; }
};
```

   这是一个类继承一个类，这段代码如果我们通过派生类去调用基类的函数，应该结果可想而知，这里就不再演示和赘述了。我们来分析这两个类的虚函数表，**对于基类的虚函数表其实和上面所说的虚函数表是一样的，有自己的虚函数指针，并指向自己的虚函数表**，重点是在于派生类的虚函数表是什么样子的，它的样子如下图所示：

![[Pasted image 20241212144824.png]]

   那么**Derive的虚函数表就是继承了Base1的虚函数表，然后自己的虚函数放在后面，因此这个虚函数表的顺序就是基类的虚函数表中的虚函数的顺序+自己的虚函数的顺序**。那么我们现在在Derive中再添加一个虚函数，让它覆盖基类中的虚函数，代码如下：


```C++
class Base1 {
public:
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Derive : public Base1{
public:
	virtual void MyA() { cout << "Derive MyA()" << endl; }
	virtual void B() { cout << "Derive B()" << endl; }
};
```

   那么对于这种情况的虚函数表如下图所示：

![[Pasted image 20241212144844.png]]

   这个是单继承的情况，然后我们看看多重继承，也就是Derive类继承两个基类，先看一下代码：

```C++
class Base1 {
public:
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Base2 {
public:
	virtual void D() { cout << "Base2 D()" << endl; }
	virtual void E() { cout << "Base2 E()" << endl; }
};

class Derive : public Base1, public Base2{
public:
	virtual void A() { cout << "Derive A()" << endl; }           // 覆盖Base1::A()
	virtual void D() { cout << "Derive D()" << endl; }           // 覆盖Base2::D()
	virtual void MyA() { cout << "Derive MyA()" << endl; }
};
```

   首先我们明确一个概念，**对于多重继承的派生类来说，它含有多个虚函数指针，对于上述代码而言，Derive含有两个虚函数指针**，所以它不是只有一个虚函数表，然后把所有的虚函数都塞到这一个表中，为了印证这一点，我们下面会印证这一点，首先我们先来看看这个多重继承的图示：

![[Pasted image 20241212144901.png]]

   由图可以看出，在第一个虚函数表中首先继承了Base1的虚函数表，然后将自己的虚函数放在后面，对于第二个虚函数表中，继承了Base2的虚函数表，由于在Derive类中有一个虚函数D覆盖了Base2的虚函数，所以第一个表中就没有Derive::D的函数地址。那么我们就用代码来实际的验证一下是否会存在两个虚函数指针，以及如果存在两个虚函数表，那么虚函数表是不是这个样子的。来看下面的代码：


```C++
#include <iostream>
#include <stdio.h>
using namespace std;

class Base1 {
public:
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Base2 {
public:
	virtual void D() { cout << "Base2 D()" << endl; }
	virtual void E() { cout << "Base2 E()" << endl; }
};

class Derive : public Base1, public Base2{
public:
	virtual void A() { cout << "Derive A()" << endl; }           // 覆盖Base1::A()
	virtual void D() { cout << "Derive D()" << endl; }           // 覆盖Base2::D()
	virtual void MyA() { cout << "Derive MyA()" << endl; }
};

int main()
{
	typedef void (*Func)();
	Derive d;
	Base1 &b1 = d;
	Base2 &b2 = d;
	cout << "Derive对象所占的内存大小为：" << sizeof(d) << endl;
	
	cout << "\n---------第一个虚函数表-------------" << endl;
	long* tmp1 = (long *)&d;              // 获取第一个虚函数表的指针
	long* vptr1 = (long*)(*tmp1);         // 获取虚函数表

	Func x1 = (Func)vptr1[0];
	Func x2 = (Func)vptr1[1];
	Func x3 = (Func)vptr1[2];
	Func x4 = (Func)vptr1[3];
	x1();x2();x3();x4();

	cout << "\n---------第二个虚函数表-------------" << endl;
	long* tmp2 = tmp1 + 1;               // 获取第二个虚函数表指针 相当于跳过4个字节
	long* vptr2 = (long*)(*tmp2);

	Func y1 = (Func)vptr2[0];
	Func y2 = (Func)vptr2[1];
	y1(); y2();

	return 0;
}
```

   先看看运行结果，然后再去分析证明：

![[Pasted image 20241212144920.png]]

   因为在包含一个虚函数表的时候，含有一个虚函数表指针，所占用的大小为4个字节，那么这里输出了8个字节，就说明Derive对象含有两个虚函数表指针。然后我们通过获取到了这两个虚函数表，并调用其对应的虚函数，可以发现输出的结果和上面的示例图是相同的，因此就证明了上述所说的结论是正确的。

**简单的总结一下：**

> **1. 每一个基类都会有自己的虚函数表，派生类的虚函数表的数量根据继承的基类的数量来定。** **2. 派生类的虚函数表的顺序，和继承时的顺序相同。** **3. 派生类自己的虚函数放在第一个虚函数表的后面，顺序也是和定义时顺序相同。** **4. 对于派生类如果要覆盖父类中的虚函数，那么会在虚函数表中代替其位置。**

#### 虚函数指针和虚函数表的创建时机：

   对于虚函数表来说，在编译的过程中编译器就为含有虚函数的类创建了虚函数表，并且编译器会在构造函数中插入一段代码，这段代码用来给虚函数指针赋值。因此**虚函数表是在编译的过程中创建**。

   对于虚函数指针来说，由于虚函数指针是基于对象的，所以对象在实例化的时候，虚函数指针就会创建，所以**是在运行时创建**。由于在实例化对象的时候会调用到构造函数，所以就会执行虚函数指针的赋值代码，从而将虚函数表的地址赋值给虚函数指针。

#### 虚函数表的深入探索：

   经过上面的学习说明，我们知道了虚函数表的作用，是用来存放虚函数的地址的，那么我们先来看一下这个代码：

```C++
#include <iostream>
using namespace std;

class A{
public:
	int x;
	A(){
		memset(this, 0, sizeof(x));       // 将this对象中的成员初始化为0
		cout << "构造函数" << endl;
	}
	A(const A& a) {
		memcpy(this, &a, sizeof(A));      // 直接拷贝内存中的内容
		cout << "拷贝构造函数" << endl;
	}
	virtual void virfunc() {
		cout << "虚函数func" << endl;
	}
	void func() {
		cout << "func函数" << endl;
	}
	virtual ~A() {
		cout << "析构函数" << endl;
	}
};

int main()
{
	A a;
	a.virfunc();
	return 0;
}
```

   在构造函数中用的是memset()函数进行初始化操作，在拷贝构造函数中使用memcpy的方式来拷贝，可能这样的方法效率会更高，其运行结果如下图所示：

![[Pasted image 20241212144935.png]]

   可以运行，但是我们要对代码进行分析，前面我们提到了虚函数表是在编译的时候就已经生成好了，那么对于上面的代码中的virfunc来说，它的地址就已经存在于虚函数表中了，又根据前面我们提到的，在实例化对象的时候，编译器会为构造函数中插入一些代码，这些代码用来给虚函数指针进行赋值，那么这些操作都是在我们执行memset之前进行的，因此在执行了这些操作后，调用了memset函数，使得所有内容都清空了，那么虚函数指针就指向了0，那为什么我们还可以调用virfunc函数和析构函数呢？

   这里就涉及到了静态联编和动态联编的问题，我们先来明确一下静态联编和动态联编的定义：

> **静态联编：在编译时所进行的这种联编又称静态束定，在编译时就解决了程序中的操作调用与执行该操作代码间的关系。** **动态联编：编译程序在编译阶段并不能确切知道将要调用的函数，只有在程序运行时才能确定将要调用的函数，为此要确                      切知道该调用的函数，要求联编工作要在程序运行时进行，这种在程序运行时进行联编工作被称为动态联编。**

 由于我们把虚函数表指针设为了0，所以我们就无法通过前面的方法来获取它，这里我们可以通过反汇编来查看virfunc的地址：

![[Pasted image 20241212144952.png]]

  我们发现virfunc函数的地址并不是我们设置的0，那么它就变的和普通的函数没有什么区别了(普通函数采用静态联编，在编译时就绑定了函数的地址)，这显然不是我们想要的虚函数，那么肯定就无法实现多态，**对于类的多态性，一定是基于虚函数表的，那么虚函数表的实现一定是动态联编的，因此也不可缺少虚函数指针寻址的过程，那么我们要实现动态联编，就需要用到指针或者引用的形式。**如果按上面代码的方式去执行，由于是非指针非引用的形式，所以编译器采用了静态绑定，提前绑定了函数的地址，那么就不存在指针寻址的过程了；如果使用指针或引用的形式，那么由于对象的所属类不能确定，那么编译器就无法采用静态编联，所以就只有通过动态编联的方式，在运行时去绑定调用指针和被调用地址。那么我们把代码改成下面的样子：


```C++
A *a = new A;
a.virfunc();
```

   这个时候我们再运行程序，由于我们将虚函数指针置为0，从而找不到了虚函数的位置，那么程序就会崩溃，然后我们再通过反汇编查看一下，如图所示：

![[Pasted image 20241212145005.png]]

   比之前的多了一些汇编指令，其中mov就是寻址的过程，这样就实现了动态绑定，也是根据这一点来实现多态性，这里我只用了一个类来进行展示说明，其实用两个类更好。总之，**如果要实现虚函数和多态，就需要通过指针或者引用的方式**。
