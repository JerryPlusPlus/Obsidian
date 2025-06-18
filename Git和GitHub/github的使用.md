## 推荐使用`SSH`方式而不是`HTTPS`方式
1）没有配置.ssh密钥
```bash
geniu@DESKTOP-BQO3PGV MINGW64 /f/remote
$ git clone git@github.com:JerryPlusPlus/git_test135.git
Cloning into 'git_test135'...
Connection closed by 20.205.243.166 port 22
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
```
2）配置.ssh密钥
```bash
#1.进入用户根目录下的.ssh目录
cd ~/.ssh
#2.使用 ssh-keygen 生成密钥，-t指定协议为rsa， -b指定生成大小为4096
$ ssh-keygen -t rsa -b 4096
#指定密钥文件名为test后，将会生成下面两个文件，
#其中test文件为私钥文件（谁都不要给！！！），
#test.pub为公钥文件，上传到github
-rw-r--r-- 1 geniu 197609 3389 May 24 16:46 test
-rw-r--r-- 1 geniu 197609  747 May 24 16:46 test.pub
3.使用vim命令打开公钥文件（test.pub），复制其中的内容上传到github
```
![[GitHub添加公钥.png]]

![[Windows上启动ssh-agent 1.png]]
![[Windows上启动ssh-agent 2.png]]

```bash
ssh-add -D #清除所有当前加载的密钥
ssh-add -l #查看当前加载的密钥
ssh-add /密钥/路径 #添加密钥到ssh代理
echo "$SSH_AUTH_SOCK" #查看ssh-agent是否启动
ssh -vT git@github.com #使用调试模式连接github
```
#### 为什么打不开对应密钥却仍可以进行git clone操作
```bash
$ git clone git@github.com:THU-MIG/yolov10.git
Cloning into 'yolov10'...
Warning: Identity file C:Usersgeniu.sshgithubkey not accessible: No such file or directory.
remote: Enumerating objects: 20165, done.
remote: Counting objects: 100% (244/244), done.
remote: Compressing objects: 100% (112/112), done.
remote: Total 20165 (delta 163), reused 206 (delta 132), pack-reused 19921
Receiving objects: 100% (20165/20165), 11.31 MiB | 3.34 MiB/s, done.
Resolving deltas: 100% (14142/14142), done.

```
我们使用命令 `ssh -vt git@github.com`来查看详细的连接信息
```bash
$ ssh -vT git@github.com
OpenSSH_9.7p1, OpenSSL 3.2.1 30 Jan 2024
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: Connecting to github.com [20.205.243.166] port 22.
debug1: Connection established.
debug1: identity file /c/Users/geniu/.ssh/id_rsa type -1
debug1: identity file /c/Users/geniu/.ssh/id_rsa-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_ecdsa type -1
debug1: identity file /c/Users/geniu/.ssh/id_ecdsa-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_ecdsa_sk type -1
debug1: identity file /c/Users/geniu/.ssh/id_ecdsa_sk-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_ed25519 type -1
debug1: identity file /c/Users/geniu/.ssh/id_ed25519-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_ed25519_sk type -1
debug1: identity file /c/Users/geniu/.ssh/id_ed25519_sk-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_xmss type -1
debug1: identity file /c/Users/geniu/.ssh/id_xmss-cert type -1
debug1: identity file /c/Users/geniu/.ssh/id_dsa type -1
debug1: identity file /c/Users/geniu/.ssh/id_dsa-cert type -1
debug1: Local version string SSH-2.0-OpenSSH_9.7
debug1: Remote protocol version 2.0, remote software version babeld-32c28593
debug1: compat_banner: no match: babeld-32c28593
debug1: Authenticating to github.com:22 as 'git'
debug1: load_hostkeys: fopen /c/Users/geniu/.ssh/known_hosts2: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts2: No such file or directory
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: algorithm: curve25519-sha256
debug1: kex: host key algorithm: ssh-ed25519
debug1: kex: server->client cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: kex: client->server cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: SSH2_MSG_KEX_ECDH_REPLY received
debug1: Server host key: ssh-ed25519 SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU
debug1: load_hostkeys: fopen /c/Users/geniu/.ssh/known_hosts2: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts2: No such file or directory
debug1: Host 'github.com' is known and matches the ED25519 host key.
debug1: Found key in /c/Users/geniu/.ssh/known_hosts:1
debug1: ssh_packet_send2_wrapped: resetting send seqnr 3
debug1: rekey out after 134217728 blocks
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: ssh_packet_read_poll2: resetting read seqnr 3
debug1: SSH2_MSG_NEWKEYS received
debug1: rekey in after 134217728 blocks
debug1: SSH2_MSG_EXT_INFO received
debug1: kex_ext_info_client_parse: server-sig-algs=<ssh-ed25519-cert-v01@openssh.com,ecdsa-sha2-nistp521-cert-v01@openssh.com,ecdsa-sha2-nistp384-cert-v01@openssh.com,ecdsa-sha2-nistp256-cert-v01@openssh.com,sk-ssh-ed25519-cert-v01@openssh.com,sk-ecdsa-sha2-nistp256-cert-v01@openssh.com,rsa-sha2-512-cert-v01@openssh.com,rsa-sha2-256-cert-v01@openssh.com,ssh-rsa-cert-v01@openssh.com,sk-ssh-ed25519@openssh.com,sk-ecdsa-sha2-nistp256@openssh.com,ssh-ed25519,ecdsa-sha2-nistp521,ecdsa-sha2-nistp384,ecdsa-sha2-nistp256,rsa-sha2-512,rsa-sha2-256,ssh-rsa>
debug1: SSH2_MSG_SERVICE_ACCEPT received
debug1: Authentications that can continue: publickey
debug1: Next authentication method: publickey
debug1: get_agent_identities: bound agent to hostkey
debug1: get_agent_identities: agent returned 1 keys
debug1: Will attempt key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent
debug1: Will attempt key: /c/Users/geniu/.ssh/id_rsa
debug1: Will attempt key: /c/Users/geniu/.ssh/id_ecdsa
debug1: Will attempt key: /c/Users/geniu/.ssh/id_ecdsa_sk
debug1: Will attempt key: /c/Users/geniu/.ssh/id_ed25519
debug1: Will attempt key: /c/Users/geniu/.ssh/id_ed25519_sk
debug1: Will attempt key: /c/Users/geniu/.ssh/id_xmss
debug1: Will attempt key: /c/Users/geniu/.ssh/id_dsa
debug1: Offering public key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent
debug1: Server accepts key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent
Authenticated to github.com ([20.205.243.166]:22) using "publickey".
debug1: channel 0: new session [client-session] (inactive timeout: 0)
debug1: Entering interactive session.
debug1: pledge: filesystem
debug1: client_input_global_request: rtype hostkeys-00@openssh.com want_reply 0
debug1: client_input_hostkeys: searching /c/Users/geniu/.ssh/known_hosts for github.com / (none)
debug1: client_input_hostkeys: searching /c/Users/geniu/.ssh/known_hosts2 for github.com / (none)
debug1: client_input_hostkeys: hostkeys file /c/Users/geniu/.ssh/known_hosts2 does not exist
debug1: client_input_hostkeys: no new or deprecated keys from server
debug1: pledge: fork
debug1: client_input_channel_req: channel 0 rtype exit-status reply 0
Hi JerryPlusPlus! You've successfully authenticated, but GitHub does not provide shell access.
debug1: channel 0: free: client-session, nchannels 1
Transferred: sent 2136, received 2608 bytes, in 0.7 seconds
Bytes per second: sent 2986.9, received 3646.9
debug1: Exit status 1

```
`debug1: Will attempt key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent`：将尝试使用代理提供的密钥。
`debug1: Offering public key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent`：正在提供密钥进行身份验证。
 `debug1: Server accepts key: huangjiejiang66@gmail.com ED25519 SHA256:Gr8hBew5V6YNdIe39a86J4XTAGlAF6oK+B2kSzqgacU agent`：服务器接受了提供的密钥。
`Authenticated to github.com ([20.205.243.166]:22) using "publickey".`：使用公钥进行了身份验证。
`Hi JerryPlusPlus! You've successfully authenticated, but GitHub does not provide shell access.`：成功验证身份，但是 GitHub 不提供 shell 访问。

#### 将本地仓库文件上传的GitHub
	要将本地文件推送到GitHub，你需要先将你的本地仓库与远程仓库关联，然后推送你的更改。
```bash
#1.初始化本地仓库（如果还没有初始化的话）：
git init
#2.添加远程仓库：
git remote add origin "git仓库地址"
#3. 添加所有文件并提交
git add .
git commit -m "提交有关描述信息"
#4.推送到GitHub：
git push --set-upstream origin main
```

	
`
	
	