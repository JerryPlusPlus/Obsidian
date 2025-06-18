- 设置DNS
- 解析DNS


#### 设置DNS

在本地hosts文件（如 `/etc/hosts` 或 `C:\Windows\System32\drivers\etc\hosts`）中添加了如下条目：
```txt
fda0:cbf4:b62a:e8b1:2699:934f:0916:bc23    www.samplehost.com
```

![[Pasted image 20250520213929.png]]

否则DNS无法解析，除非你自己运行DNS服务或者局域网里有解析`www.samplehost.com`的DNS
#### 解析DNS

```C++
 #include<boost/asio.hpp>
#include<iostream>

int main(void) {
	try{
		std::string host = "www.samplehost.com";
		std::string service = "3333";
		boost::asio::io_context ioc;
		boost::asio::ip::tcp::resolver resolver(ioc);

		boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp> resluts = resolver.resolve(host, service);
		boost::asio::ip::basic_resolver_results<boost::asio::ip::tcp>::iterator it;
		boost::asio::ip::tcp::endpoint ep;
		for (it = resluts.begin(); it != resluts.end(); it++) {
			ep = *it;
			std::cout << "IP address: " << ep.address().to_string() << std::endl;
			std::cout << "Port: " << ep.port() << std::endl;
		}
	}catch (const boost::system::system_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

```

输出结果：

![[Pasted image 20250520214302.png]]




