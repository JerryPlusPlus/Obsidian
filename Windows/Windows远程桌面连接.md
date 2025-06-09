极其重要的一点：不要使用校园网和手机热点，具体原因暂未完全弄明白。
注意：有时候连不上可能是网络原因，需要打开网页进入网络设置界面，然后等一会再连接。
注意：IPv6需要用`[]`包裹起来


- 使用zerotier异地组网
- 远程连接

#### 使用zerotier异地组网

**不要使用校园网和手机热点，具体原因暂未完全弄明白。**

将zerotier设置为私网
##### ✅ 解决方案：强制修改 ZeroTier 网络为“专用网络”

我们采用 **注册表法** 手动修改。建议将远程设备和本机都改成专用网络，请按照以下步骤操作：
1. **按下 Win + R，输入 `regedit`，回车**
2. 导航到这个路径：
`HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Profiles`
3. 展开 `Profiles`，你会看到一堆类似 `{6B...}` 这样的子项，每一个代表一个网络配置。
4. 逐个点击这些子项，查看右边的键值，找到：
    - `ProfileName` 为 `ZeroTier One [35c192ce9b149269]` 或 `网络 6` 的那一项
    - 找到后，双击修改 **`Category`** 项，值改为：
        `1 = Private（专用网络） 0 = Public（公共网络） 2 = Domain（域网络）`
        👉 改成 `1`，然后点“确定”
5. 修改完后关闭注册表编辑器。
6. 重启电脑（必须重启才能生效）

![[Pasted image 20250526033434.png]]

![[Pasted image 20250526033555.png]]

使用Test-NetConnection命令来查看是否连通。

```txt
连接是否成功
Ping 状态
使用的接口
端口通不通（TcpTestSucceeded = True 表示通
```

![[Pasted image 20250526034636.png]]


注意：在 Clash 的环境下，你的 ZeroTier 流量有可能被“挟持”进了 Clash 的 TUN/代理通道，导致 Peer-to-Peer 的 UDP 握手根本出不去——ZeroTier 又不能走 TCP 443，所以两端虽然都 “在线” 状态，但实际上根本无法互相直连。要解决这个问题，需要让 ZeroTier 的流量绕过 Clash 代理。具体操作询问GPT。

![[Pasted image 20250526035616.png]]

![[Pasted image 20250526035651.png]]

YAML 对**缩进**特别敏感，不能用 Tab 键，只能用空格。常见错误包括：
- 缩进不对
- 缺冒号 `:` 或多了空格
- 缺少引号或冒号后没加值

![[Pasted image 20250526040508.png]]

![[Pasted image 20250526040633.png]]



#### 远程连接

打开远程机器上的远程桌面开关

![[Pasted image 20250526033104.png]]


![[Pasted image 20250526041100.png]]

点击是即可连接成功

![[Pasted image 20250526041119.png]]