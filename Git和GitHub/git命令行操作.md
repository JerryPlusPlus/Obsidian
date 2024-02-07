## 本地库初始化

`git init`，初始化当前目录，并创建`.git`文件
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git init
Initialized empty Git repository in D:/git_test/WeChat/.git/
```

`ls -la`，显示当前路径下的所有文件，包括隐藏文件
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ ls -la
total 4
drwxr-xr-x 1 geniu 197609 0 Feb  7 00:08 ./
drwxr-xr-x 1 geniu 197609 0 Feb  7 00:08 ../
drwxr-xr-x 1 geniu 197609 0 Feb  7 00:08 .git/
```
设置签名。
```bash
形式：
	用户名：JerryPlusPlus
	Email地址：huangjiejiang66@gmail.com
作用：区分不同开发人员的身份
辨析：这里设置的签名和登录远程库（代码托管中心）的账号密码没有任何关系。
命令：
	项目级别/仓库级别：仅在当前本地库范围内有效
		git config user.name Jerry_project
		git config user.email huangjiejiang66@gmai.com
	系统用户级别：登录当前操作系统的用户范围
		git config --global user.name Jerry_global
		git config --global user.email huangjiejiang66@gmai.com
	优先级：
		就近原则：项目优先级先于系统用户优先级
		二者都没有则验证不了身份，是不允许的。
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

`git status`、`git add` 、`git rm --cached`的用法示例：
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ vim goog.txt

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        goog.txt

nothing added to commit but untracked files present (use "git add" to track)

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git add goog.txt
warning: in the working copy of 'goog.txt', LF will be replaced by CRLF the next time Git touches it

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   goog.txt
geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git rm --cached goog.txt
rm 'goog.txt'

geniu@DESKTOP-BQO3PGV MINGW64 /d/git_test/WeChat (master)
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        goog.txt

nothing added to commit but untracked files present (use "git add" to track)
```

`git commit`的示例
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

回退到不同版本`git reset --hard`
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
