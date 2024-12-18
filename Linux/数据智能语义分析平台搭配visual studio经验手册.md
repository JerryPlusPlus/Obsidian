1. 关于sudo权限问题
2. 安装anaconda虚拟环境
3. 创建EC密钥对，免密登录Linux（未解决,猜测是容器原因）
4. 关于xshell使用密码远程连接Ubuntu被拒问题


## 1. 关于sudo权限问题

- 创建容器时，分配sudo权限，ssh连接后

![[创建容器时分配sudo权限.png]]

- ssh连接后进入Ubuntu系统设置密码（HJJ66@shu）

![[设置Ubuntu发行版Linux的root密码.png]]

- 如果创建容器时没有分配sudo权限，系统存在默认密码（未知），安装包会出现权限不足问题

![[apt下载包是缺乏权限问题.png]]

## 2.安装anaconda虚拟环境

1）安装Anaconda
- 到官网上下载Linux版本的anaconda安装包
- 将安装包上传到容器中
- 使用命令`bash <安装包.sh>`安装（比较耗费时间）

2）将新安装的conda设置为默认环境
通过修改.bashrc文件中的路径，指定使用的conda环境，重启.bashrc文件

![[指定使用的conda环境.png]]

3）卸载Anaconda
- 打开终端，删除整个Anaconda目录即可：`rm -rf <Anaconda安装路径`>

![[命令行下查看Anaconda安装路径.png]]

- 在环境变量文件`.bashrc`中删除配置代码

![[指定使用的conda环境.png]]

- 卸载miniconda3可能会导致一下问题
![[智能语义平台卸载minconda3后果.png]]
## 3. 创建密钥对，免密登录Linux（未解决）
注意：
- [visual studio由于版本迭代，只能通过EC密钥对来远程连接Linux]([Connect to your target Linux system in Visual Studio | Microsoft Learn](https://learn.microsoft.com/en-us/cpp/linux/connect-to-your-remote-linux-computer?view=msvc-170#set-up-the-remote-connection))

![[visual studio只兼容EC密钥对.png]]

- `.ssh`目录并不是初始化系统必须的，`.ssh`下面，一般保存着你自己的公私钥对,信任登录的公钥以及用当前用户登录过的机器的信息。root下面的`.ssh`也不是默认就有的，他是在你首次使用ssh登录root用户时，创建的`.ssh`，同时把你当前客户端信息记录到.ssh/known_ hosts文件中。

- 如果你使用的是 OpenSSH 服务器，可以在服务器的配置文件中（`/etc/ssh/sshd_config`）查看以下选项，确保服务器允许这些类型的密钥：

	- `PubkeyAuthentication yes`
	- `AuthorizedKeysFile .ssh/authorized_keys`

此外，确保服务器端的 `sshd_config` 中没有禁止这些算法的选项（比如 `HostKeyAlgorithms`）。

#### 1）在Linux系统中使用命令`ssh-keygen -m pem -t ecdsa -f <key-name>`创建EC密钥对

```txt



```

![[创建EC密钥对.png]]

使用 `ssh-copy-id` 或***手动复制公钥***，将公钥添加到服务器的 `~/.ssh/authorized_keys` 文件中



![[SSH服务器拒绝了用户密钥.png]]

#### 2）使用`sudo service ssh restart`重启ssh服务

```bash
kai@master-0:~/.ssh$ sudo service ssh restart
 * Restarting OpenBSD Secure Shell server sshd                  [ OK ] 
```


3）在虚拟机中创建Ubuntu系统（用户名：jerry），在visual studio中使用EC密钥对连接成功。
![[visual studio中使用EC类型密钥远程连接Ubuntu成.png]]


### 4. 关于xshell使用密码远程连接Ubuntu被拒问题

使用命令`sudo vim /etc/ssh/sshd_config`修改文件内容如下
![[xshell使用密码远程连接被拒解决方法.png]]



