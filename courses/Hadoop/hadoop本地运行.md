![[Pasted image 20231203145518.png]]
在`/opt/module/hadoop-3.1.3`路径下创建一个文件夹`wcinput`
### 编写集群开发脚本
1.scp(secure copy)安全拷贝，scp可以实现服务器与服务器之间的数据拷贝
基本语法：
```
scp   -r     $pdir/$fname            $user@host:$host:$pdir/$fname
命令  递归   要拷贝的文件路径/名称    目的地用户@主机：目的地路径/名称

例如在hadoop102服务器上，将hadoop102在/opt/module/jdk1.8.0_212/路径下的文件拷贝到hadoop103服务器/opt/module路径下。
[root@hadoop102 opt]# scp -r /opt/module/jdk1.8.0_212/             jerrry@hadoop103:/opt/module/
The authenticity of host 'hadoop103 (192.168.10.103)' can't be established.
ECDSA key fingerprint is SHA256:fTRBsGtxhKid5aKwh2clNrofrsHM8nBaegbLCjfEsu0.
ECDSA key fingerprint is MD5:c5:56:e1:76:b6:7c:b2:17:98:cb:1d:ec:fb:e5:22:4c.
Are you sure you want to continue connecting (yes/no)? y
Please type 'yes' or 'no': yes
Warning: Permanently added 'hadoop103,192.168.10.103' (ECDSA) to the list of known hosts.
jerrry@hadoop103's password: 
###例如在hadoop103服务器上，将hadoop102在/opt/module/jdk1.8.0_212/路径下的###文件拷贝到hadoop104服务器/opt/module路径下。
[jerrry@hadoop103 opt]$ scp -r jerrry@hadoop102:/opt/module/jdk1.8.0_212/    jerrry@hadoop104:/opt/module/
The authenticity of host 'hadoop102 (192.168.10.102)' can't be established.
ECDSA key fingerprint is SHA256:fTRBsGtxhKid5aKwh2clNrofrsHM8nBaegbLCjfEsu0.
ECDSA key fingerprint is MD5:c5:56:e1:76:b6:7c:b2:17:98:cb:1d:ec:fb:e5:22:4c.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'hadoop102,192.168.10.102' (ECDSA) to the list of known hosts.
jerrry@hadoop102's password: 
The authenticity of host 'hadoop104 (192.168.10.104)' can't be established.
ECDSA key fingerprint is SHA256:fTRBsGtxhKid5aKwh2clNrofrsHM8nBaegbLCjfEsu0.
ECDSA key fingerprint is MD5:c5:56:e1:76:b6:7c:b2:17:98:cb:1d:ec:fb:e5:22:4c.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'hadoop104,192.168.10.104' (ECDSA) to the list of known hosts.
jerrry@hadoop104's password: 
```
2.rsync远程同步工具
rsync主要用于备份和镜像。具有速度快、避免重复复制相同的内容和支持符号链接的优点。rsync和scp区别：用rsync做文件的复制要比scp的速度快，rsync只对差异文件做更新，scp是把所有文件都复制过去
基本语法：
```
rsync   -av       $pdir/$fname            $user@$host:$pdir/$fname
命令    选项参数  要拷贝的文件路径/名称   目的地用户@主机：目的地路径/名称
选项参数说明：     -a 归档拷贝      -v  显示复制过程
注意事项
[jerrry@hadoop104 opt]$ rsync -av  jerrry@hadoop102:/opt/module/      jerrry@hadoop103:/opt/module/
The source and destination cannot both be remote.
rsync error: syntax or usage error (code 1) at main.c(1274) [Receiver=3.1.2]

```

### 免密登录
原理：
![[免密登录原理图 1.png]]

### 集群配置
![[Pasted image 20231212215235.png]]
![[Pasted image 20231212215616.png]]

