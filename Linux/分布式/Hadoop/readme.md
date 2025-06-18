hadoop100:
账号:jerrry       密码:hadoop100
账号:root        密码:hadoop100


hadoop102:


hadoop103:


hadoop104:



### 网络配置信息:
#### VMware网络配置:
`编辑->虚拟网络编辑器->更改设置->VMnet8`
![[VMware网络配置1 1.png]]
![[VMware网络配置2 1.png]]
#### 主机端网络配置:
![[主机端网络配置 1.png]]
虚拟机内部网络配置:
修改网络配置文件:
`[root@hadoop100 jerrry]# vim /etc/sysconfig/network-scripts/ifcfg-ens33 `
![[虚拟机centos网络配置1 1.png]]
修改主机名hostname
`[root@hadoop100 jerrry]# vim /etc/hostname`
将主机名称修改为对应的主机名,例如修改为Hadoop100

主机名称映射
使用主机名称映射就可以把主机名映射成IP地址.方便后续IP地址更改
`[root@hadoop100 jerrry]# vim /etc/hosts`
![[主机名映射 1.png]]

### 将hadoop100做为模板虚拟机,进行配置.
1.安装epel-release
Extra Packages for Enterprise Linux是为红帽系的操作系统提供额外的软件包,适用于RHEL,Centos和Scientific Linux.相当于是一个软件仓库,大多数rpm包在官方repository中是找不到的
`[root@hadoop100 jerrry]# yum install -y epel-release`

2.防火墙相关命令
在企业开发时,通常单个服务器的防火墙是关闭的,公司整体对外设置防火墙即可.
![[防火墙设置 1.png]]

```
[root@hadoop100 jerrry]# systemctl stop firewalld
[root@hadoop100 jerrry]# systemctl disable firewalld.service
查看防火墙状态
systemctl status firewalld
开启防火墙
systemctl start firewalld.service
关闭防火墙
systemctl stop firewalld.service
设置开机启动
systemctl enable firewalld.service
查看防火墙开放端口情况
firewall-cmd --list-all
防火墙设置开放端口
#添加指定端口和连接方式到防火墙 --permanent表示永久生效
firewall-cmd --add-service=http --permanent
sudo firewall-cmd --add-port=80/tcp --permanent
#重新加载配置
fire-cmd --reload
```

3.在/opt路径下创建两个文件夹,并改变其所有者
```
[root@hadoop100 jerrry]# cd /opt
[root@hadoop100 opt]# mkdir module
[root@hadoop100 opt]# mkdir software
[root@hadoop100 opt]# ll
总用量 0
drwxr-xr-x. 2 root root 6 12月  2 15:57 module
drwxr-xr-x. 2 root root 6 10月 31 2018 rh
drwxr-xr-x. 2 root root 6 12月  2 15:57 software
[root@hadoop100 opt]# sudo chown jerrry:jerrry module software
[root@hadoop100 opt]# ll
总用量 0
drwxr-xr-x. 2 jerrry jerrry 6 12月  2 15:57 module
drwxr-xr-x. 2 root   root   6 10月 31 2018 rh
drwxr-xr-x. 2 jerrry jerrry 6 12月  2 15:57 software
```
4.卸载虚拟机自带的JDK
如果虚拟机是最小化安装,则不需要执行该操作
`[root@hadoop100 opt]# rpm -qa|grep -i java |xargs -n1 rpm -e --nodeps`
```
rpm -qa:查询所安装的所有rpm软件包
grep -i:忽略大小写
xargs -n1:表示每次只传递一个参数
rpm -e -nodeps:强制卸载软件
```

### 克隆模板虚拟机,生成集群
![[克隆虚拟机1 1.png]]
![[克隆虚拟机2 1.png]]
### JDK和Hadoop安装
1.将需要使用的两个压缩包文件传入到hadoop102虚拟机对应新建的文件夹software下
![[Pasted image 20231203103409.png]]
2.将两个压缩文件使用linux下的解压命令，解压到/opt/module文件夹下。
```
[jerrry@hadoop102 software]$ tar -zxvf jdk-8u212-linux-x64.tar.gz  -C /opt/module/
[jerrry@hadoop102 software]$ tar -zxvf hadoop-3.1.3.tar.gz  -C /opt/module/
```
```
//查看解压结果
[jerrry@hadoop102 software]$ cd /opt/module/
[jerrry@hadoop102 module]$ ll
总用量 0
drwxr-xr-x. 9 jerrry jerrry 149 9月  12 2019 hadoop-3.1.3
drwxr-xr-x. 7 jerrry jerrry 245 4月   2 2019 jdk1.8.0_212

```
3.配置环境变量
通过命令查看环境配置文件
```
[jerrry@hadoop102 module]$ sudo vim /etc/profile
[sudo] jerrry 的密码：
```
![[Pasted image 20231203104443.png]]
在`/etc/profile.d`路径下建立一个my_env.sh文件,填入以下内容：
```
#JAVA_HOME
export JAVA_HOME=/opt/module/jdk1.8.0_212
export PATH=$PATH:$JAVA_HOME/bin

#HADOOP_HOME
export HADOOP_HOME=/opt/module/hadoop-3.1.3

export PATH=$PATH:$HADOOP_HOME/bin
export PATH=$PATH:$HADOOP_HOME/sbin
```
重新加载`/etc/profile`文件，该文件夹下的文件`my_env.sh`也会被重新加载
`source /etc/profile`
```
输入以下命令查看测试重新加载是否生效
[root@hadoop102 profile.d]# java
[root@hadoop102 profile.d]# java
```

