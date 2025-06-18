1. 卸载MySQL8.0
2. 安装MySQL8.0
3. 使用workbench远程访问Ubuntu中的MySQL

### 1. 卸载MySQL8.0

- 首先，停止MySQL服务以确保所有MySQL进程都已终止。
```bsah
service mysql stop
```

- 使用`apt`或`dpkg`命令卸载MySQL服务器及其相关软件包

```bash
#使用dpkg命令
dpkg -l | grep -i mysql 
```

```bash 
#使用apt命令
apt list --installed | grep -i mysql
```

```bash
#卸载MySQL服务器及其相关软件包
sudo apt-get remove --purge mysql-server mysql-client mysql-common
```

```bash
#卸载配置和数据文件
sudo rm -rf /etc/mysql /var/lib/mysql
sudo rm -rf /var/log/mysql
```

```bash
#删除MySQL用户和组
sudo rm -rf /etc/mysql /var/lib/mysql
sudo rm -rf /var/log/mysql
```

```bash
#检查是否还有遗留文件
sudo find / -iname 'mysql*' -exec rm -rf {} \;
```

### 2. 安装MySQL8.0

```bash
sudo apt update
sudo apt install mysql-server
```
### 3. 使用workbench远程访问Ubuntu中的MySQL
- windows下使用`ping`和`telnet`检测主机之间是否连通以及端口是否开放

```bash
ping '远程主机ip'
#使用telnet需要在windows中打开telnet客户端
telnet '远程主机ip' '端口'
```
- 如果端口没有开放，使用`ufw`命令

```bash
sudo ufw status #查看防火墙状态以及开放端口情况
sudo ufw enable #启动防火墙
sudo ufw allow '端口' #开放某一个端口
sudo ufw disable #关闭防火墙，并停止防火墙规则的应用
```

```

- 登录MySQL：首先使用root用户登录到MySQL。如果之前没有设置过root用户密码，则-p选项可以不需要。

```bash
sudo mysql -u root -p 'your_password'
```

- 修改mysql数据中的user表，允许使用root用户进行远程访问
```mysql
SHOW DATABASES;
USE mysql;
SELECT host,user FROM  user;
UPDATE user set host='%' where user='root';
```

![[Pasted image 20241120004705.png]]

- 更改root用户的登录方式：默认情况下，MySQL 使用 `auth_socket` 插件对 `root` 进行身份验证，这可能会阻止远程登录。要改为使用密码认证，请执行以下命令。
```bash 

ALTER USER 'root'@'%' IDENTIFIED WITH 'mysql_native_password' BY 'your_password';
FLUSH PRIVILEGES;
```

- 修改MySQL配置以允许远程连接：编辑MySQL配置文件`/etc/mysql/mysql.conf.d/mysqld.cnf` 或 `/etc/mysql/my.cnf`。找到 `bind-address` 和`mysqlx-bind-address`项，把`127.0.0.1`更改为 `0.0.0.0` 或注释掉这两行，以允许从任何 IP 地址连接。
```bash
bind-address = 0.0.0.0
mysqlx-bind-address     = 0.0.0.0
```

- 重启MySQL服务