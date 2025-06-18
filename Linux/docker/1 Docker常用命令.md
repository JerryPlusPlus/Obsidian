### 帮助启动类命令
```
启动docker：systemctl start docker
停止docker: systemctl stop docker
重启docker: systemctl restart docker
查看docker命令: systemctl status docker
开机启动: systemctl enable docker
查看docker概要信息： docker info 
查看docker总体帮助文档: docker --help
查看docker命令帮助文档：docker 具体命令 --help
```

### 镜像命令
```
列出本地主机的所有镜像：docker images
options: -a 列出本地所有镜像（含历史镜像） -q 只显示镜像ID

搜索镜像：docker search 镜像名 
option: --limit 数字 只列出N个镜像

下载某个版本的镜像：docker pull 镜像名字[:TAG]

查看镜像/容器/数据卷所占空间：docker system df

删除镜像：docker rmi -f 镜像ID  或者 docker rmi -f 镜像名1:TAG 镜像名2:TAG ...
docker rmi -f $(docker images -qa)

```

### 容器类命令
```
创建容器：docker run [options] 镜像名 [command][arg...]
options说明：
--name="容器名称"  为容器指定一个名称：
-d: 后台运行容器并返回容器ID，也即启动守护式容器（后台运行）
-i:以交互模式运行容器，通常与-t同时使用
-t:为容器重新分配一个伪输入终端，通常与-i同时使用
也即启动交互式容器（前台有伪终端，等待交互）
-P:随机端口映射
-p:指定端口映射
docker run -it --name=myubuntu ubuntu /bin/bash

列出当前所有正在运行的容器：docker ps [options] 
options说明：
-a:列出当前所有正在运行的容器+历史上运行过的容器
-l:显示最近创建的容器
-n:显示最近n个创建的容器
-q:静默模式，只显示容器编号

退出容器：
exit：run进去容器，exit退出，容器停止
ctrl+p+q：run进去容器，ctrl+p+q退出，容器不停止

启动已停止运行的容器 docker start 容器ID或者容器名

重启容器 docker restart 容器ID或者容器名

停止容器 docker stop 容器ID或者容器名

强制停止容器 docker kill 容器ID或者容器名

删除已停止的容器 docker rm 容器ID



```