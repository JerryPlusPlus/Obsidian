- 两台电脑网络情况解析
- 两台电脑互通的解决方案

### 两台电脑网络情况解析
远程服务器：

#### **电脑 A（Jerry）**

- WLAN IP: `192.168.0.105`
- 子网掩码: `255.255.255.0`
- 默认网关: `192.168.0.1`

这是典型的家用路由网络配置。

![[Pasted image 20250515143234.png]]


#### **电脑 B（geniu）**

- WLAN IP: `10.98.140.143`
- 子网掩码: `255.255.128.0`
- 默认网关: `10.98.128.1`

这是企业或学校网络中常见的配置。

![[Pasted image 20250515143323.png]]

### 两台电脑互通的解决方案

#### ✅ **使用局域网虚拟网卡（如 ZeroTier 或 Tailscale）**

如果你不能控制网络环境（如 geniu 使用的是公司/校园网络），可以考虑使用虚拟局域网工具：

- **[Tailscale](https://tailscale.com/)**
- **[ZeroTier](https://www.zerotier.com/)**

它们可以让两台电脑即使在不同物理网络中，也能像在同一个局域网里一样通信。

### 🔧 推荐工具 1：**[Tailscale](https://tailscale.com/)**

#### ✅ 特点：

- 基于 WireGuard，**非常安全**
- 不需要手动配置端口映射
- 可穿透公司/学校网络、防火墙
- 支持 Windows、macOS、Linux、iOS、Android
    

#### 🚀 快速使用步骤：

1. 两台电脑都访问 [https://tailscale.com/](https://tailscale.com/) 并下载安装客户端。
2. 登录同一个 Tailscale 账号（可以用 Google、Microsoft 账户登录）。
3. 启动后，两台电脑会自动获取一个 Tailscale 虚拟 IP（如 `100.x.x.x`）。
4. 你可以用这个虚拟 IP 进行 SSH、远程桌面、ping 等操作，就像在同一局域网一样。
#### 🎯 示例：

`ping 100.107.32.45 ssh user@100.107.32.45`

---

### 🔧 推荐工具 2：**[ZeroTier](https://www.zerotier.com/)**

#### ✅ 特点：

- 更接近传统局域网模式，甚至能模拟 VLAN
- 每台设备有一个 ZeroTier 虚拟 IP（通常是 `10.x.x.x`）
- 跨平台，功能强大
- 可手动控制 IP 分配、路由等
    
#### 🚀 使用步骤：

1. 两台电脑安装 ZeroTier 客户端
2. 创建一个网络（在 ZeroTier 网站）
   ![[Pasted image 20250515170307.png]]
   
3. 加入相同网络（输入网络 ID）
   
![[Pasted image 20250515170529.png]]
   
4. 在 Web 控制台上批准设备加入
   ![[Pasted image 20250515170644.png]]
   
5. 使用 ZeroTier 分配的虚拟 IP 互相通信

   ![[Pasted image 20250515170748.png]]
   
   📌 1. 服务器端代码（Boost Asio TCP IPv6）
```cpp
// server.cpp
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // 创建 IPv6 端点
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v6(), 3333));
        std::cout << "Server listening on port 3333 (IPv6)..." << std::endl;

        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "Client connected from " << socket.remote_endpoint() << std::endl;

        std::string message = "Hello from server via IPv6!";
        boost::asio::write(socket, boost::asio::buffer(message));

    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }

    return 0;
}
```
📌 2. 客户端代码（Boost Asio TCP IPv6）
```cpp
// client.cpp
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        // 使用 IPv6 地址连接
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(tcp::v6(), "fda0:cbf4:b62a:e8b1:2699:934f:0916:bc23", "3333");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::cout << "Connected to server!" << std::endl;

        char reply[1024];
        size_t len = socket.read_some(boost::asio::buffer(reply));
        std::cout << "Server says: ";
        std::cout.write(reply, len);
        std::cout << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }

    return 0;
}
```


✅ 运行步骤

先运行服务器端代码，在运行客户端代码：


![[Pasted image 20250515172152.png]]




![[Pasted image 20250515172309.png]]



🧪 输出示例
服务器端输出：

![[Pasted image 20250515172333.png]]

客户端输出：

![[Pasted image 20250515172347.png]]








