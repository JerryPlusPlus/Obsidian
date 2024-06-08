shell脚本语言属于一种弱类型语言，无需声明变量类型，直接定义使用。shell语言定义的变量，数据类型都默认是字符串类型

shell变量
1. 变量定义与赋值，注意变量和值之间不得有空格




 ### Linux内置命令和外置命令
 使用`which 命令`的方式可以查看命令文件存放位置。
 可以使用`type 命令`的方式判断该命令是内置命令还是外置命令，cd是内置命令，ps是外置命令
 ```shell
 [12/11/23]seed@VM:~/.../shellStudy$ type cd
cd is a shell builtin
[12/11/23]seed@VM:~/.../shellStudy$ type ps
ps is /usr/bin/ps
```
外置命令的特点是：一定会开启子进程执行。
```shell
[12/11/23]seed@VM:~/.../shellStudy$ ps -f --forest
UID          PID    PPID  C STIME TTY          TIME CMD
seed       10279   10272  0 00:46 pts/0    00:00:00 bash
seed       10352   10279  0 00:56 pts/0    00:00:00  \_ ps -f --forest
```