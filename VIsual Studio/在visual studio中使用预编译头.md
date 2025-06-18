### ✅ 一、概念说明

Visual Studio 使用两个文件来实现预编译头机制：

|文件名|作用|
|---|---|
|`stdafx.h` 或 `pch.h`|头文件，写你要预编译的公共头内容|
|`stdafx.cpp` 或 `pch.cpp`|源文件，**只包含头文件**，用于生成 `.pch` 文件|

默认是 `stdafx.h/cpp`，从 VS2017 开始有时叫 `pch.h/pch.cpp`。你可任选其一。

### 🧭 二、手动添加和配置步骤（分别以 `stdafx.h` / `stdafx.cpp`和`pch.h/pch.cpp` 为例）

#### ✅ 步骤 1：添加两个文件

在你的项目目录中创建这两个文件：
头文件`pch.h`
```cpp
#ifndef PCH_H 
#define PCH_H  
// 在此文件中添加要预编译的头文件  
#include <iostream> 
#include <QtWidgets/QApplication> 
#include <QtWidgets/QMainWindow> 
#include <QtWidgets/QPushButton> 
#include <QtWidgets/QVBoxLayout> 
#include <QtWidgets/QCommandLinkButton>  
// 其他常用 Qt 头文件根据项目需要添加  
#endif // PCH_H
```

源文件`pch.cpp`
```cpp
#include "pch.h"
```

> `pch.cpp` **必须只包含 `#include "pch.h"`**，不能有其他内容。

### ✅ 步骤 2：在项目中设置使用预编译头

1. **右键项目 → 属性（Properties）**
2. 在左边展开：**C/C++ → Precompiled Headers（预编译头）**
3. 设置为：
    - **Precompiled Header**：`Use (/Yu)`（用于大多数源文件）
    - **Precompiled Header File**：`pch.h`
    ⚠️ 对于 `pch.cpp`，设置为：
    - **Precompiled Header**：`Create (/Yc)`
4. 点击 **应用（Apply）** 和 **确定（OK）**

### ✅ 步骤 3：在你的每个 `.cpp` 文件最顶部加入：

`#include "pch.h"`

必须是第一个 `#include`，否则会编译出错。

### ✅ 步骤 4：重新生成

- 菜单 → 生成 → 清理解决方案；
- 然后 → 生成解决方案。
![[Pasted image 20250526162431.png]]

## 🧩 补充说明

- Qt 项目通常包含很多重复包含的 Qt 模块头，使用预编译头可以显著加快编译速度。
- 如果你使用了多个构建配置（如 Debug 和 Release），建议两种配置都重复上述设置。
- 你可以将 Qt 常用模块 `#include` 写在 `pch.h` 里，以便自动预编译。

---
## ✅ 一、添加预编译头文件

### 📄 `stdafx.h`（预编译头文件）

```cpp
#pragma once  
// 标准 C++ 头文件 #include <iostream>  

// Qt 常用头文件（根据你的项目需求选择） 
#include <QtWidgets/QApplication> 
#include <QtWidgets/QMainWindow> 
#include <QtWidgets/QPushButton> 
#include <QtWidgets/QVBoxLayout> 
#include <QtWidgets/QCommandLinkButton>

```


### 📄 `stdafx.cpp`（用于生成 .pch 文件）

`#include "stdafx.h"`

> 注意：该文件**只能包含这一行**，不能写其他代码！

## ✅ 二、配置项目属性启用预编译头

### 👉 1. 设置 `stdafx.cpp` 为“生成预编译头”

1. 右键 `stdafx.cpp` → **属性（Properties）**
2. 左侧选择：`C/C++` → `Precompiled Headers`
3. 设置如下：
    - **Precompiled Header**：`Create (/Yc)`
    - **Precompiled Header File**：`stdafx.h`

### 👉 2. 设置项目其他源文件为“使用预编译头”

1. 右键项目名称 → **属性**
2. 左侧选择：`C/C++` → `Precompiled Headers`
3. 设置如下：
    - **Precompiled Header**：`Use (/Yu)`
    - **Precompiled Header File**：`stdafx.h`
4. 应用到所有 `.cpp` 文件（除了 `stdafx.cpp`）
    
## ✅ 三、源文件顶部引入 `stdafx.h`

每个 `.cpp` 文件的开头必须加上：

`#include "stdafx.h"`

例如：
```cpp
#include "stdafx.h" 
#include "mainwindow.h" 
#include <QApplication>  

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);     
	MainWindow w;     
	w.show();     
	return app.exec(); 
}

```

## ✅ 四、构建顺序

1. 菜单 → **生成** → **清理解决方案**
2. 然后 → **重新生成解决方案**

![[Pasted image 20250526162431.png]]

























