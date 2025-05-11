

Linux chmod（英文全拼：change mode）命令是控制用户对文件的权限的命令

Linux/Unix 的文件调用权限分为三级 : 文件所有者（Owner）、用户组（Group）、其它用户（Other Users）。

![[Pasted image 20250318110914.png]]

只有文件所有者和超级用户可以修改文件或目录的权限。可以使用绝对模式（八进制数字模式），符号模式指定文件的权限。

![[Pasted image 20250318110856.png]]




```bash
chmod -R o=rwx /path/to/folder
```

使用` -R`递归修改权限，使得`/path/to/folder`路径下的所有文件和文件夹的读写执行权限赋予other users

仅修改目录（不修改文件）的权限
```bash
find /path/to/folder -type d -exec chmod o=rwx {} +
```

仅修改文件（不修改文件夹）的权限
```bash
find /path/to/folder -type f -exec chmod o=rwx {} +
```

`{} +`的作用
- `{ }`：占位符，表示`find`发现的每一个匹配项（文件/目录）
- `+`：将所有匹配项批量传递给`--exec`后的命令（而不是逐个执行）
拓展
- `\`的作用是每找到一个匹配项就执行`--exec`后面的命令

