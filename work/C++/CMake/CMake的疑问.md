### 项目名和可执行文件名在CMake中有不同的含义。
	•	项目名：这是通过 project() 命令在CMake中定义的。它主要用于标识整个项目，并且可以在整个CMakeLists.txt文件中使用。例如，你可以使用 ${PROJECT_NAME} 变量来引用项目名。项目名也可以用于生成一些默认的目录和文件名。
	•	可执行文件名：这是通过 add_executable() 命令在CMake中定义的。这个名字将被用作生成的可执行文件的名字。在 add_executable() 命令中，你需要提供一个目标名（在这里是可执行文件名），然后列出所有的源文件。这个目标名可以在后续的命令中用来引用这个可执行文件，例如设置它的包含目录或链接库。
	所以，项目名和可执行文件名是两个不同的概念。项目名用于标识整个项目，而可执行文件名用于标识一个特定的可执行目标。

```bash
PS D:\Code\Cmake\CMakeProject1\out\build> cmake ../.. 
-- Building for: Visual Studio 17 2022 
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.22631. 
-- The C compiler identification is MSVC 19.39.33523.0 
-- The CXX compiler identification is MSVC 19.39.33523.0 
-- Detecting C compiler ABI info 
-- Detecting C compiler ABI info - done 
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped 
-- Detecting C compile features 
-- Detecting C compile features - done 
-- Detecting CXX compiler ABI info 
-- Detecting CXX compiler ABI info - done 
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped 
-- Detecting CXX compile features 
-- Detecting CXX compile features - done 
-- Configuring done (3.1s) -- Generating done (0.0s) 
-- Build files have been written to: D:/Code/Cmake/CMakeProject1/out/build 
PS D:\Code\Cmake\CMakeProject1\out\build>
```
	这段文字是在运行 cmake ../.. 命令后的输出，它描述了CMake配置和生成构建文件的过程。下面是对每一行的解释：
	•	-- Building for: Visual Studio 17 2022：CMake正在为Visual Studio 2022生成构建文件。
	•	-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.22631.：CMake选择了Windows SDK版本10.0.22621.0，目标是Windows 10.0.22631。
	•	-- The C compiler identification is MSVC 19.39.33523.0：CMake检测到C编译器是MSVC（Microsoft Visual C++）版本19.39.33523.0。
	•	-- The CXX compiler identification is MSVC 19.39.33523.0：CMake检测到C++编译器也是MSVC版本19.39.33523.0。
	•	-- Detecting C compiler ABI info 和 -- Detecting C compiler ABI info - done：CMake正在检测C编译器的ABI（Application Binary Interface）信息，然后完成了检测。
	•	-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped：CMake检查C编译器是否可用，但是这个步骤被跳过了。
	•	-- Detecting C compile features 和 -- Detecting C compile features - done：CMake正在检测C编译器的特性，然后完成了检测。
	•	对于C++编译器，也进行了类似的ABI信息检测和特性检测。
	•	-- Configuring done (3.1s)：CMake完成了配置过程，用时3.1秒。
	•	-- Generating done (0.0s)：CMake完成了生成构建文件的过程，用时0.0秒。
	•	-- Build files have been written to: D:/Code/Cmake/CMakeProject1/out/build：构建文件已经被写入到 D:/Code/Cmake/CMakeProject1/out/build 目录。
	最后，PS D:\Code\Cmake\CMakeProject1\out\build> 是PowerShell的提示符，表示现在的工作目录是 D:\Code\Cmake\CMakeProject1\out\build。

### Application Binary Interface是什么
	Application Binary Interface（ABI）是一个规定了程序模块如何在二进制级别进行交互的接口。它定义了在编译后的程序中如何布局数据和代码。
	ABI涵盖了很多方面，包括：
	•	数据类型的大小和对齐：ABI规定了每种数据类型在内存中的大小和对齐方式。
	•	调用约定：ABI规定了函数参数如何传递（例如，是通过堆栈还是寄存器），以及如何返回结果。
	•	系统调用的编号和参数：对于操作系统提供的系统调用，ABI规定了每个调用的编号和参数。
	•	二进制文件格式：例如，Windows使用PE（Portable Executable）格式，而Linux使用ELF（Executable and Linkable Format）。
	当你编译一个程序时，编译器和链接器会遵循ABI来生成二进制代码。如果你有两个模块，它们是由遵循同一ABI的编译器生成的，那么这两个模块就可以互相调用。
	如果你尝试将两个不同ABI的模块链接在一起，可能会导致错误，因为它们可能有不同的对数据布局和函数调用的理解。这就是为什么在编译代码时需要指定目标平台和编译器的原因。



### 待考察
up视频里使用powershell脚本文件下载依赖组件慢是因为powershell终端流量默认不会走系统代理导致的，两种解决方法，1. 使用终端配置代理的命令对当前终端进程进行配置，比如$Env:http_proxy="http://127.0.0.1:7890";$Env:https_proxy="http://127.0.0.1:7890"，某猫咪甚至可以直接打开一个配置了代理的终端进程。2. 你的代理软件使用tun模式，同样以某猫咪举例，打开TUN Mode，以虚拟网卡的形式从网络层接管数据流量，这样不管软件是否遵守系统代理设置都可以接管到流量并进行代理。