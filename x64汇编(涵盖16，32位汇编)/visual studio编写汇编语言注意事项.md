
#### 配置文件以及运行一个简单的汇编代码
1.打开visual studio2022创建一个简单的C++空项目
2.配置项目依赖项，勾选masm。右键项目->Build Dependencies ->Build Customizations
![[Pasted image 20240708092651.png]]
3.查看`.asm`后缀文件属性
![[Pasted image 20240708092815.png]]
4.配置库路径
1）`Configuration Properties -> Linker -> General -> Additional Library Directories`，添加相应的库路径。对于 MASM，可以添加 `$(VC_LibraryPath_x64)`。
2）导航到 `Configuration Properties -> Linker -> Input -> Additional Dependencies`，添加必要的库文件，如 `libcmt.lib` 或 `ucrt.lib` 以及 `vcruntime.lib`。
![[Pasted image 20240708100517.png]]

5. 创建`.cpp`文件和`.asm`文件，代码如下
**main.cpp**:
```cpp
#include <iostream>

extern "C" void asm_function();

int main() {
    asm_function();
    return 0;
}
```
**asm_file.asm**:
```asm
extrn printf:PROC

.data
    message db 'Hello, World!', 0

.code
asm_function PROC
    sub rsp, 28h        ; 为堆栈帧调整栈指针
    lea rcx, [message]  ; 将消息地址加载到 rcx
    call printf         ; 调用 printf 函数
    add rsp, 28h        ; 恢复堆栈帧
    ret
asm_function ENDP
END
```

6.编译`.asm`后缀文件`asm_file.asm`，确保编译无误。为程序打上断点。Ctrl+F5 运行项目
![[Pasted image 20240708100613.png]]7. CTRL+ALT+G 打开寄存器，查看寄存器状态
![[Pasted image 20240708100802.png]]
![[ASCII.png]]






