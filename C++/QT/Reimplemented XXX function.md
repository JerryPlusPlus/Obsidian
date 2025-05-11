
`Reimplemented xxx function`并不是抽象函数，它指的是你`可以重写的父类的虚函数`。也就是说：**你不重写它，程序也可以跑起来，但行为可能不是你想要的，所以会想重写它来实现自己的功能**


![[Reimplemented xxx fuction.png]]


## ✅ 所以，“Reimplemented Public Functions” 通常是：

```cpp
class QWidget { public:     virtual void paintEvent(QPaintEvent *event);  // 👈 已经有默认实现了 };`
```

你可以在子类中重写：

```cpp
class MyWidget : public QWidget { protected:     void paintEvent(QPaintEvent *event) override; // ✅ Reimplemented };`
```


Qt 文档经常会在类参考手册里列出这样的函数，告诉你：

> ⚠️ “你可能想要重新实现这些函数，以定制控件行为。”



```nginx
QObject
  ↑
QPaintDevice
  ↑
QWidget  ← 🎯 这里定义了 minimumSizeHint()
  ↑
QFrame / QPushButton / QLabel / QMainWindow 等等……
```

## 🧠 什么是 minimumSizeHint()？

- `minimumSizeHint()` 提供控件的 **最小推荐尺寸**
    
- 通常被布局管理器（如 `QHBoxLayout` / `QVBoxLayout`）用来计算合适的布局
    
- Qt 默认的 `QWidget::minimumSizeHint()` 返回的是一个空的 `QSize()`，即不指定最小尺寸

## 💡 补充知识：与 `sizeHint()` 区别？

- `sizeHint()`：推荐大小
    
- `minimumSizeHint()`：推荐的最小大小
    
- 控件最终大小由 layout、容器、用户设置共同决定，但 layout 会优先参考这些 hint

✅ 总结一句话：
minimumSizeHint() 最底层定义在 QWidget 中，属于 Qt 控件布局和自适应机制的一部分，子类通常会重写它来提供合适的尺寸。