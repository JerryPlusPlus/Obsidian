#### ARM 和 x64 处理器不支持内联汇编程序。

Visual Studio目前只支持32位(x86)的内联汇编，而不支持64位(x64)下的内联汇编，在x64下编译的话，  会报错 “使用了非标准扩展: 不支持在此结构上使用“__asm”关键字”。  

Visual C++ 至今都禁止 x64 编译模式下使用 __asm 关键字内联汇编。  每次要用汇编的时候都得另外开一个 ASM 文件写，然后 call 过去。  始终不能理解微软为何要禁止这一特性。

