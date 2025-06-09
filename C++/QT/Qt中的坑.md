- QMetaObject::methodCount() 只统计通过 Qt 的元对象编译器（moc）注册的方法。
- QMetaMethod的tag方法使用
- Q_TAG不建议使用
- Q_PROPERTY设置属性代码片段中的`()`和`[]`应该怎么理解
- 什么是像素比`Device Pixel Ration,DPR`
- QWidget::paintEngine: Should no longer be called w.paintEngine():  0x0
- 设置属性时，没有设置DESIGNABLE，默认值为true，但是仍然没有在qt design中显示
- QLabel的openExternalLinks属性
- QWidget::grabKeyboard()在qt 帮助文档中的解释

#### QMetaObject::methodCount() 只统计通过 Qt 的元对象编译器（moc）注册的方法。

只有信号（signals）、槽（slots）和`Q_INVOKABLE`修饰的成员函数，才会被 moc 记录到元对象系统中，并且返回值（总数）记录的是基类加上自己的方法。

![[Pasted image 20250526230639.png]]

![[Pasted image 20250526223008.png]]

![[Pasted image 20250527125938.png]]

`main.cpp`
```cpp
#include <QtCore/QCoreApplication>
#include"MyObject.h"
#include<QMetaMethod>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyObject o;
    const QMetaObject* metaObj = o.metaObject();
    //const QMetaObject metaObj = MyObject::staticMetaObject;
    
    QMetaMethod metaMethod;
    int offset = metaObj->methodOffset();
    int count = metaObj->methodCount();
    qDebug() << "offset = " << offset << " , counte = " << count;
    for (int  i = 0; i < count; i++)
    {
        metaMethod = metaObj->method(i);
        qDebug() <<metaMethod.methodIndex()<<" , "
            << metaMethod.access()<<" , "
            << metaMethod.methodType()<<" , "
            <<metaMethod.name() << " , "
            <<metaMethod.isValid()<<" , "
            <<metaMethod.methodSignature();
    }
    QMetaMethod destroyedSignal = QMetaMethod::fromSignal(&QObject::destroyed);
    qDebug() << metaObj->indexOfMethod("destroyed(QObject*)");
    qDebug() << metaObj->indexOfMethod("destroyed()");
    qDebug() << "----下面是自定义的方法标签----";
    int index = metaObj->indexOfMethod("myMethod()");
    QMetaMethod myMethodObj = metaObj->method(index);
    qDebug()<<myMethodObj.tag();

    return a.exec();
}
```
`MyObject.h`
```cpp
#pragma once
#include<qobject.h>
#include<qdebug.h>

#ifndef Q_MOC_RUN  // 这句很关键：确保宏对 moc 可见，对 C++ 编译器不可见
/*定义一个标签，该标签放在对应方法前，并且必须定义为空，这样编译器就看不见，而Qt的元对象编译器可以看见，并进行处理*/
#define MY_CUSTOM_TAG
#endif

class MyObject :public QObject
{
    Q_OBJECT

public:
    MyObject();
    ~MyObject();
    MY_CUSTOM_TAG Q_INVOKABLE void myMethod();
   //Q_INVOKABLE void myMethod() Q_TAG("myTag");

signals:
    //void add();

private slots:

private:
    int a;

};
```
`MyObject.cpp`
```cpp
#include "MyObject.h"

MyObject::MyObject()
{
	a = 1;
	qDebug() << "MyObject constructed";
}

MyObject::~MyObject()
{
	qDebug() << "MyObject destroyed";
}

void MyObject::myMethod()
{
	qDebug() << "my Method called";
}
```

#### QMetaMethod的tag方法使用

![[Pasted image 20250526235701.png]]

### ✅ 实际用途示例

- 给槽函数打上“标签”，在运行时做反射或动态处理（比如自动注册、权限判断、日志标记等）。
- 标签只是“附加信息”，moc 会解析并记录，但不会干预其含义，你可以自由解释这个标签。

你可以使用这种方式为槽函数打上功能性标签，例如：

```cpp

#define ADMIN_ONLY 
#define LOGGED_ACTION 
#define DONT_EXPOSE_IN_UI

```


然后运行时用 tag 做如下判断：

```cpp

if (method.tag() == QByteArray("ADMIN_ONLY")){

// 检查权限或跳过非管理员方法 

}
```

### ✅ 注意事项

|注意项|说明|
|---|---|
|必须用 `#ifndef Q_MOC_RUN`|否则宏不会传给 moc，`tag()` 返回空。|
|只能用于函数声明|无法给函数实现或定义加 tag。|
|只能用于 `moc` 能识别的类（即含 `Q_OBJECT` 的类）|否则 metaObject 系统无效。|

#### Q_TAG不建议使用

Q_TAG不是标准 C++ 语法，Qt 的元对象编译器（moc）支持它。在 Qt 官方文档中，**`Q_TAG` 并不是公开的或标准的文档化宏**，所以你在 Qt 官网（如 https://doc.qt.io）直接搜索 `Q_TAG`，**基本找不到相关信息**。

## ✅ 原因说明

- `Q_TAG` 虽然出现在一些 Qt 内部代码中（例如 Qt 自身的模块或测试代码），但它**并不是 Qt 官方文档正式列出的公共 API 或宏**。
- `Q_TAG` 实际上是 `moc` 解析器在处理源码时的一种约定，它类似于 `Q_SIGNAL`, `Q_SLOT`, `Q_INVOKABLE` 等，属于 Qt 元对象系统的标记机制。


如果你是在编写大型 Qt 工具/框架，并想要用 `tag` 机制做元注解式的槽扩展，那我推荐继续使用 `#define` 宏方式，**更透明、跨版本安全**。如你想自己扩展 `moc` 行为，也可以考虑 Qt 的 `Clang MOC` 或 `moc` 替代品（比如 [cmake-qt5](https://cmake.org) 的自动 moc 管理）。


#### Q_PROPERTY设置属性代码片段中的`()`和`[]`应该怎么理解

![[Pasted image 20250527130031.png]]

**例如下面片段中的`()`和`[]`理解**

```
type name 
    (READ getFunction [WRITE setFunction] |
     MEMBER memberName [(READ getFunction | WRITE setFunction)])

```

其中的括号 `()` 和方括号 `[]` 是**语法描述符号**，用来表示选项和可选项，不是实际代码的一部分。具体含义如下：

---

### 1. `()` 圆括号：表示**必须选择其中一种形式**

`(READ getFunction [WRITE setFunction] |  MEMBER memberName [(READ getFunction | WRITE setFunction)])`

这个圆括号`()`整体表示你必须在**这两种形式中选其一**：

- 第一种形式：`READ getFunction [WRITE setFunction]`
    
- 第二种形式：`MEMBER memberName [(READ getFunction | WRITE setFunction)]`
    

也就是说，一个属性的定义必须是以上两种结构中的一种。

### 2. `[]` 方括号：表示**可选项**

- 在 `READ getFunction [WRITE setFunction]` 中，`WRITE setFunction` 是可选的，你可以只提供读函数。
	
- 在 `MEMBER memberName [(READ getFunction | WRITE setFunction)]` 中，后面这个括号内的内容是**整个可选**，意思是可以仅指定成员变量名（`MEMBER memberName`），也可以再附带一个 `READ` 或 `WRITE` 函数（或两者之一）。

### 总结

- `()`：表示必须选其中一个分支（是语法结构，不要写在代码里）。
- `[]`：表示可选部分，可以有，也可以省略。
- `|`：表示“或”，即二选一或多选一的情况。

#### 什么是像素比`Device Pixel Ration,DPR`

像素比指的是**物理像素**与**逻辑像素**之间的比例关系。
•	逻辑像素：Qt 程序中坐标和尺寸的单位，和你的布局、控件大小相关。
•	物理像素：显示设备实际的像素点。
例子
•	普通显示器：DPR = 1。1 个逻辑像素 = 1 个物理像素。
•	高分屏（如 **Retina**）：DPR = 2。1 个逻辑像素 = 2x2 = 4 个物理像素。
作用
•	**让你的应用在高分辨率屏幕上依然显示清晰，不会变模糊。**
•	Qt 会自动根据 DPR 缩放界面元素和图片。

#### QWidget::paintEngine: Should no longer be called w.paintEngine():  0x0

解释如下：
1. QWidget::paintEngine: Should no longer be called
•	这是 Qt 在运行时输出的警告，意思是QWidget 的 paintEngine() 方法不应该再被调用。
•	在 Qt 5.0 及以后，QWidget::paintEngine() 主要用于内部绘制机制，官方建议不要在用户代码中直接调用。
•	对于顶层窗口（如 QWidget 本身），paintEngine() 可能返回 nullptr，因为 Qt 可能使用原生平台绘制（如 Windows 的原生窗口），而不是 Qt 的 paint engine。

---
2. w.paintEngine():  0x0
•	这表示 w.paintEngine() 返回了 nullptr（即 0x0）。
•	这通常发生在顶层 QWidget 或某些特殊情况下，Qt 不再为该控件分配 paint engine。
•	这也是为什么你会看到上面的警告。

---
总结
•	不要在应用程序中直接调用 paintEngine()，尤其是对顶层 QWidget。
•	**该方法返回 nullptr 并输出警告是 Qt 的正常行为，表示 Qt 现在用原生方式绘制窗口，不再需要 paint engine。**
•	如果你需要自定义绘制，请重写 QWidget::paintEvent()，而不是直接操作 paint engine。

---
建议：
移除或避免直接调用 w.paintEngine()，以消除该警告和无意义的输出。

#### 设置属性时，没有设置DESIGNABLE，默认值为true，但是仍然没有在qt design中显示


![[Pasted image 20250530022629.png]]

在qt design中设置控件后，查看控件属性时会显示出来的属性需要满足以下条件：
1. `可读可写`的属性,设置了对应的`WRITE`函数
2. `DESIGNABLE`为true

```
Q_PROPERTY(int frameWidth READ frameWidth)
```

虽然`frameWidth`的DESIGNABLE没有设置，其默认值为`true`。但是它没有设置`WRITE函数`，是只读属性，所以不在qt design中显示

```
 Q_PROPERTY(QRect frameRect READ frameRect WRITE setFrameRect DESIGNABLE false)
```

`frameRect`的DESIGNABLE为`false`，所以不在qt design中显示

#### QLabel的openExternalLinks属性
在点击QLabel文本超链接时，是否自动使用`QDesktopServices::openUrl()`打开链接，而不是发出`linkActivated()`信号

![[Pasted image 20250531164443.png]]

### 两种行为的区别：

|设置|行为|
|---|---|
|`label->setOpenExternalLinks(true)`|点击链接时，**会自动打开默认浏览器**访问该链接（使用 `QDesktopServices::openUrl()`）。|
|`label->setOpenExternalLinks(false)`（默认）|点击链接时，**不会自动打开**，而是**发出 `linkActivated(const QString &link)` 信号**，你可以通过代码决定如何处理这个链接。|

#### QWidget::grabKeyboard()在qt 帮助文档中的解释

![[Pasted image 20250605124109.png]]

```txt
原文：
The focus widget is not affected, except that it doesn't receive any keyboard events.

解释：
focus widget：当前拥有焦点的控件，即通过 setFocus() 设定或用户操作后获得输入焦点的控件。
“not affected”：即 grabKeyboard() 不会改变焦点控件是谁，焦点依然保持在原来的控件上。
“except that it doesn't receive any keyboard events”：但尽管它还是焦点控件，它将无法接收到键盘事件，因为 grabKeyboard() 把所有键盘事件都劫持到了调用该函数的 widget。
```

```txt
原文：
setFocus() moves the focus as usual, but the new focus widget receives keyboard events only after releaseKeyboard() is called.

解释：
在 grabKeyboard() 之后，你仍然可以调用 setFocus() 改变焦点控件。

焦点确实会改变，系统也会记录新的焦点 widget。

但是新的焦点控件也同样不会收到任何键盘事件，直到你调用 releaseKeyboard() 释放键盘抓取为止。
```

```txt
总结：
grabKeyboard() 的效果是：无论哪个控件有焦点，只有调用了 grabKeyboard() 的 widget 能收到键盘事件。

焦点仍然可以改变（通过 setFocus()），但这不影响键盘事件的“劫持”行为。

要恢复正常键盘事件分发（由焦点控件接收），必须调用 releaseKeyboard()。
```

```txt
示例场景：
假设有两个文本框 A 和 B，还有一个隐藏控件 C 调用了 grabKeyboard()。

用户点击 A，A 有焦点；

C 调用 grabKeyboard()；

用户再点击 B，焦点转移到 B（setFocus() 生效）；

但 A 和 B 都无法收到键盘输入，因为键盘事件仍然只发送给 C；

调用 releaseKeyboard() 后，B 才能开始接收键盘输入。
```

