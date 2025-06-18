## 本地库初始化

1. `git init`，初始化当前目录，成为git仓库
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git init
Initialized empty Git repository in D:/git_test/WeChat/.git/
```
注意：`.git`文件夹很重要，有该文件夹才是git仓库，删除掉该文件夹后就是普通文件了
2. 通过从GitHub上clone远程仓库
```bash
PS F:\remote> git clone https://github.com/axios/axios.git
Cloning into 'axios'...
remote: Enumerating objects: 9985, done.
remote: Counting objects: 100% (522/522), done.
remote: Compressing objects: 100% (304/304), done.
remote: Total 9985 (delta 326), reused 362 (delta 205), pack-reused 9463
Receiving objects: 100% (9985/9985), 14.16 MiB | 796.00 KiB/s, done.
Resolving deltas: 100% (6305/6305), done.
```
## 设置签名：区分不同开发人员的身份。
```bash
形式：
	用户名：JerryPlusPlus
	Email地址：huangjiejiang66@gmail.com
作用：区分不同开发人员的身份
辨析：这里设置的签名和登录远程库（代码托管中心）的账号密码没有任何关系。
命令：
	1. 省略Local，本地配置：仅在当前git仓库范围内有效
		git config user.name Jerry_local
		git config user.email huangjiejiang66@gmai.com
	2. 全局配置：本地用户的所有仓库生效
		git config --global user.name Jerry_global
		git config --global user.email huangjiejiang66@gmai.com
	3. --system：系统配置，对所有用户生效
		git config --system user.name Jerry_system
		git config --system user.email huangjiejiang66@gmai.com
	优先级：
		就近原则：本地配置>全局配置>系统配置
		
查看项目/仓库级别用户配置：
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ cat .git/config
[core]
        repositoryformatversion = 0
        filemode = false
        bare = false
        logallrefupdates = true
        symlinks = false
        ignorecase = true
[user]
        name = Jerry_project
        email = huangjiejiang66@gmail.com
查看系统用户级别用户配置
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ cat ~/.gitconfig
[user]
        name = Jerry_global
        email = huangjiejiang66@gmail.com
[safe]
        directory = D:/
directory = D:/: 这是你设置的安全目录。在 Git 中，当你进行某些敏感操作时（如添加文件），如果文件位于这个目录下，Git 将不会执行对该目录的检查，以防止误报或其他问题。
```
![[git config的三种级别.png]]
`git status`：查看仓库状态
```bash
PS F:\Git_test> git status
On branch master  //当前处于master主分支

No commits yet    //当前仓库没有任何提交

nothing to commit (create/copy files and use "git add" to track)
//当前仓库没有任何变化需要提交
```
注意：git不会讲空的文件夹添加到版本控制中去
`git add` :将文件添加到暂存区或者跟踪文件
```shell

```
`git rm --cached <file>`:将文件从暂存区中移除
```shell

```
`git commit`：提交
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git commit goog.txt
warning: in the working copy of 'goog.txt', LF will be replaced by CRLF the next time Git touches it
[master (root-commit) e1c7f90] My first commit. new file goog.txt
 1 file changed, 1 insertion(+)
 create mode 100644 goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ vim goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   goog.txt

no changes added to commit (use "git add" and/or "git commit -a")

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git add goog.txt
warning: in the working copy of 'goog.txt', LF will be replaced by CRLF the next time Git touches it

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git commit -m "the second commit use -m option" goog.txt
warning: in the working copy of 'goog.txt', LF will be replaced by CRLF the next time Git touches it
[master a98a7bd] the second commit use -m option
 1 file changed, 1 insertion(+)
```

查看历史纪录的方式 `git log`、` git log --pretty=oneline`、`git reflog`
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git log
commit cc2a837e5c0221a5208df16407b790af52227085 (HEAD -> master)
Author: Jerry_project <huangjiejiang66@gmail.com>
Date:   Wed Feb 7 02:11:30 2024 +0800

    the third commit

commit a98a7bd0f4491ba3582b1ac569622a647d552d69
Author: Jerry_project <huangjiejiang66@gmail.com>
Date:   Wed Feb 7 02:00:18 2024 +0800

    the second commit use -m option

commit e1c7f906d1af02e40c677632a38d1476ee77b2e4
Author: Jerry_project <huangjiejiang66@gmail.com>
Date:   Wed Feb 7 01:20:07 2024 +0800

    My first commit. new file goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git log --pretty=oneline
cc2a837e5c0221a5208df16407b790af52227085 (HEAD -> master) the third commit
a98a7bd0f4491ba3582b1ac569622a647d552d69 the second commit use -m option
e1c7f906d1af02e40c677632a38d1476ee77b2e4 My first commit. new file goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git log --oneline
cc2a837 (HEAD -> master) the third commit
a98a7bd the second commit use -m option
e1c7f90 My first commit. new file goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git reflog
cc2a837 (HEAD -> master) HEAD@{0}: commit: the third commit
a98a7bd HEAD@{1}: commit: the second commit use -m option
e1c7f90 HEAD@{2}: commit (initial): My first commit. new file goog.txt

```
`git reset`：回退到不同版本（mixed是reset的默认参数）
![[git reset的三种模式.png]]
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git reflog
cc2a837 (HEAD -> master) HEAD@{0}: commit: the third commit
a98a7bd HEAD@{1}: commit: the second commit use -m option
e1c7f90 HEAD@{2}: commit (initial): My first commit. new file goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git reset --hard a98a7bd
HEAD is now at a98a7bd the second commit use -m option

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git reflog
a98a7bd (HEAD -> master) HEAD@{0}: reset: moving to a98a7bd
cc2a837 HEAD@{1}: commit: the third commit
a98a7bd (HEAD -> master) HEAD@{2}: commit: the second commit use -m option
e1c7f90 HEAD@{3}: commit (initial): My first commit. new file goog.txt
```
`git diff`：    1. 查看工作区、暂存区、本地仓库之间的差异
		    2. 查看不同版本之间的差异
		    3. 查看不同分支之间的差异
![[git diff.png]]
```bash

```
![[Pasted image 20240524105809.png]]
`git remote add 别名 远程库HTTPS地址`示例
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git remote -v

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git remote add origin https://github.com/JerryPlusPlus/test.git

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git remote -v
origin  https://github.com/JerryPlusPlus/test.git (fetch)
origin  https://github.com/JerryPlusPlus/test.git (push)
```
`git push 别名 分支名`示例
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git push origin master
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 16 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (6/6), 493 bytes | 493.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/JerryPlusPlus/test.git
 * [new branch]      master -> master
```
Git文件的四种状态
![[Git文件的四种状态.png]]

![[Pasted image 20240524111051.png]]
.gitignore:忽略掉不应该加入到版本库的文件
1. 系统或软件自动生成的文件
2. 编译产生的中间文件和结果文件
3. 运行时生成的日志文件、缓存文件、临时文件
4. 涉及身份、密码、口令、密钥等敏感信息文件
```
```


第一次连接时需要打开ssh-agent，不然授权会失败

```git
//这是错误示范
Jerry@myComputer MINGW64 /e/Obsidian (main)
$ ssh-add ~/.ssh/github
Could not open a connection to your authentication agent.

```

```git
//这是打开了ssh-agent的输出
Jerry@myComputer MINGW64 /e/Obsidian (main)
$ eval $(ssh-agent -s)
Agent pid 1615

Jerry@myComputer MINGW64 /e/Obsidian (main)
$ ssh-add ~/.ssh/github
Identity added: /c/Users/Jerry/.ssh/github (huangjiejiang66@gmail.com)
```

