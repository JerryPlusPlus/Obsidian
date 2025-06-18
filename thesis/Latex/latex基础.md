```latex
\documentclass{article}
\usepackage{ctex} 
\title{My first document}
\author{My name}
\begin{document}
\maketitle
Hello world你好世界

the $f(x)$ is defined as $$f(x)=2x^3+1$$

\end{document}
```
# 导言区
```latex
\document{}
%导言区
```
# 正文区
```latex
\begin{document}
%这一部分为正文区
\end{document}
```
## 如何开启新的一段
在需要结束的段落后加上一行空行即可开启新的一段，多个空行视为一个空行。
## 如何使用注释
使用`%`来表示单行注释，`%`后面接需要注释的内容
## 公式
使用`$公式$`进行行内嵌入公式，使用`$$公式$$`进行换行嵌入公式

# 使用`texdoc`命令查看宏包使用方法
为了使得latex支持中文字符：
1. 首先将文件编码字符改为utf-8
2. 使用`\usepackage{}`命令导入ctex宏包

查看ctex宏包：`texdoc ctex`

# latex字体的五种属性
## 1、字体编码
正文字体编码：OT1、T1、EU1
数学字体编码：OML、OMS、OMX
## 2、字体族
罗马字体：笔画起始处有装饰
无衬线字体：笔画起始无装饰
打字机字体：每个字符宽度相同，又称等宽字体

字体设置命令：`\textrm{Roman Family}`
字体设置声明：`{\rmfamily Roman Family}`

**注意：设置中文字体时需要使用宏包：ctex**
## 3、字体系列
粗细
宽度
## 4、字体形状
直立
斜体
伪斜体
小型大写
## 5、字体大小


# 图片和图表

三线表宏包：`booktabs`

# 公式



# 矩阵排版





