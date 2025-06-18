### 1)下载sqlite3
[下载地址](https://www.sqlite.org/download.html)
![[下载sqlite3.png]]

![[Pasted image 20241007215446.png]]
### 2)制作使用的动态库sqlie3.lib

```cmd
C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64>LIB /out:C:\sqlite3\sqlite3.lib /MACHINE:IX86 /DEF:C:\sqlite3\sqlite3.def
Microsoft (R) Library Manager Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

  正在创建库 C:\sqlite3\sqlite3.lib 和对象 C:\sqlite3\sqlite3.exp
  C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64>
```
### 3)设置依赖
现在打开Visual Studio 2022，需要做的事情有：1、指定头文件所在目录。2、指定需要使用到的lib。3、指定lib文件夹，也就是代码的实现部分所在的目录
打开属性页面
1.指定头文件所在目录：
找到C/C+±>常规->附加包含目录，添加刚才下载的sqlite3.h的路径
![[sqlite3_1.png]]
2.指定需要使用到的lib：
找到链接器->输入->附加依赖项，添加lib的名称(就是sqlite3.lib)
![[sqlite3_2.png]]
3.指定lib文件夹，也就是代码的实现部分所在的目录：
找到链接器->常规->附加库目录，添加生成的sqlite3.lib的路径
![[sqlite3_3.png]]
### 4)查看
至此，完成了VS2022下使用sqlite3的环境配置
新建项目，在项目中使用#include<sqlite3.h>
没有报错说明环境配置成功
![[sqlite3_4.png]]