1. chrome技术介绍
2. VS2019 CEF编译与使用
3. QWebEngineView基本用法
4. CMake VS2019编译QCefView
5. C++ QT项目中使用QCefView
6. C++ QT html js交互
7. C++QT Echarts显示K线图
8. C++ QT Echarts数据交互动态修改

#### 1. chrome技术介绍：CEF、QCefView、QWebEngineView
Web组件：
	大多数web技术都是基于chrome，例如CEF、QCefView以及本课程需要学习的QWebEngineView，这些都是在native界面里用来显示html网页，并且可以与web交互，例如常见的登录窗口等，这些都是用web技术实现的，而native端，只需要把网页展示出来，实现交互即可。

#### 2. VS2019 CEF编译与使用
CEF的GitHub仓库：https://github.com/chromiumembedded/cef
	 DownLoad：https://cef-builds.spotifycdn.com/index.html
![[Pasted image 20240612123711.png]]

![[Pasted image 20240612124806.png]]

#### 3. QWebEngineView基本用法
注意：ui界面的内容发生改变时，visual studio不会理解感知到修改。忽略错误列表的内容，直接运行代码即可。强迫症可以重启visual studio，可解决错误列表显示错误的问题
```C++
//web3.h
#pragma once
#include<qwebengineview.h>
#include <QtWidgets/QWidget>
#include "ui_web3.h"

class web3 : public QWidget
{
    Q_OBJECT

public:
    web3(QWidget *parent = nullptr);
    ~web3();

private:
    Ui::web3Class* ui;
};
```
```C++
//web3.cpp
#include "web3.h"

web3::web3(QWidget *parent)
	: QWidget(parent), ui(new Ui::web3Class)
{
    ui->setupUi(this);
	ui->web->load(QUrl("https://www.google.com"));
	ui->web->show();
}

web3::~web3(){
	delete ui;
}
```
```C++
//main.cpp
#include "web3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    web3 w;
    w.show();
    return a.exec();
}
```
![[web3项目相关配置和运行结果.png]]
#### 4. CMake VS2019编译QCefView



#### 5. C++ QT项目中使用QCefView



#### 6. C++ QT html js交互



#### 7. C++QT Echarts显示K线图



#### 8. C++ QT Echarts数据交互动态修改


