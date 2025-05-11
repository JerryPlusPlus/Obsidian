书本上的例子：中文翻译第58页
```CMake
#例子正确，结果为false也正确，但是表述有问题
set(VAR1,FALSE)
set(VAR2,"VAR1")
if(${VAR2})
```

![[camke的var1和var2案例.png]]

![[cmake的foo案例.png]]

![[CMake中if条件判断规则.png]]

总结：
1. `if(<constant>)`:参数为`constant`常量（常量大小写不敏感），如果constant为1、ON、YES、TRUE、Y或者一个非零数字（包括浮点数），判断结果为true，若constant为0、OFF、NO、FALSE、N、IGNORE、NOTFOUND、以-NOTFOUND为结尾、空字符串，判断结果为false。注意：当argument不是这些特殊常量之一，则被认为是变量或者字符串，，将应用下面两条规则
2. `if(<variable>)`:参数是`variable`变量，如果variable被定义为一个非false常量，则判断结果为true。variable为false常量或者是未被定义的情况，则判断结果为false。注意macro参数不是变量，环境变量也不能用这种方式测试。例如`if(ENV{some_var}`总是会被判断为false。
3. `if(<string>)`：参数是`string`引用字符串。一个引用字符串总是会被判断为false，除非
	- 这个字符串的值是true常量之一，或者
	- 在CMake版本高于4.0中，策略CMP0054没有被设置为NEW，同时字符串的值恰好是一个变量的名称，如上例`if(${VAR2})->if("VAR1")`中"VAR1"恰好是变量名VAR1


![[CMP0054.png]]

策略CMP0054:
![[CMP0054解析.png]]

 ![[Pasted image 20250317165301.png]]

![[CMP0054在脚本中测试.png]]

![[Pasted image 20250317165552.png]]

#### 两个测试环境下，`CMP0054` 的行为不一样
**原因如下：**
![[Pasted image 20250319161413.png]]
此策略在 CMake 版本 3.1 中引入。在 CMake 版本 4.0 移除之前，可以通过 `cmake_policy()` 或 `cmake_minimum_required()` 进行设置。若未设置，CMake 会发出警告，并使用 OLD 行为。

**情况 1：使用 `cmake -P CMP0054.cmake`**
 ![[Pasted image 20250317165301.png]]

CMake **发出了警告**，说明 `CMP0054` **未被设置**，所以默认使用 **OLD** 行为。由于 `CMP0054` 是 **OLD**，`if("${A}")` **会展开变量值**，即 `if("E" STREQUAL "")`，因为 `"E"` 不是空字符串，条件为 **TRUE**。
![[Pasted image 20250319160540.png]]


**情况 2：在 `CMakeLists.txt` 里运行**

![[CMP0054在CMakeLists中测试.png]]



















