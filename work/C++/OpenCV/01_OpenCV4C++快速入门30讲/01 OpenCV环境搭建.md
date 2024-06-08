1. 配置包含目录
2. 配置库目录
3. 配置链接器
4. 通过新建项目属性表的方式配置包含目录、库目录和链接器
5. 配置环境变量并重启Visual Studio
6. image Watch插件的下载和使用
7. opencv_contrib扩展模块的编译

### 1.配置包含目录
1）在GitHub上（https://github.com/opencv/opencv/releases）下载最新版OpenCV
![[GitHub上下载最新版OpenCV.png]]
2）下载完成后双击打开，选择解压路径
![[OpenCV下载完成后解压.png]]
3）为Visual Studio2022下的OpenCV解决方案下的Project1项目配置包含目录
![[配置包含目录1.png]]
为Debug x64配置好包含目录
![[配置包含目录2.png]]
### 2. 配置库目录
同样在Project1的Property页中配置库目录
![[配置库目录.png]]
### 3. 配置链接器
![[配置链接器.png]]
#### 4. 通过新建项目属性表的方式配置包含目录、库目录和链接器
![[配置opencv项目属性表1.png]]
![[配置opencv项目属性表2.png]]
![[创建属性表4.png]]
![[配置opencv项目属性表3.png]]
![[将属性表导入其他项目.png]]
![[配置opencv项目属性表4.png]]
### 5. 配置环境变量并重启Visual Studio
![[将OpenCV配置到环境变量中.png]]
重启Visual Studio后，测试配置是否成功，如果弹出对应图片窗口，则配置成功
```C++
#include<opencv2/opencv.hpp>
#include<iostream>

int main(int argc, char* argv[]) {
	cv::Mat src = cv::imread(R"(F:\C++\OpenCV\OpenCV_images\OpenCV_Logo_with_text.png)");
	if (src.empty()) {
		std::cout << "图像加载失败！" << std::endl;
		return -1;
	}
	cv::imshow("输入图像", src);
	cv::waitKey(0);

	return 0;
}
```

![[OpenCV配置成功.png]]
#### 6. image Watch插件的下载和使用
1）在visual studio的Extensions下载
![[visual studio中下载image Watch插件.png]]
2）首次启动 Image Watch：进入调试器并选择**View** > **Other Windows** > **Image Watch**。请注意，您只需执行一次：就像 Visual Studio 内置的 Watch 窗口一样，当您停止调试时，Image Watch 会消失，并在下次开始调试时自动重新打开。
![[打开扩展·image Watch的方式.png]]
2）展示代码详情，断点位置以及运行界面。
```C++
#include<opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat img;
	img = imread(R"(F:\C++\OpenCV\OpenCV_images\OpenCV_Logo_with_text.png)");
	if (img.empty())
	{
		cout << "Error: Couldn't open image!" << endl;
		return -1;
	}
	Mat img1;
	imshow("Image", img);
	waitKey(0);
	return	0;
}
```
![[使用Image Watch的详细代码及展示.png]]
3）image Watch支持图片的移动和放大，放大到一定时会显示像素点的具体信息
![[当图像放大到足够大时会显示像素点信息.png]]
#### 7. opencv_contrib扩展模块编译
1）在GitHub上下载，并选择对应的版本
![[下载opencv_contrib源码.png]]
2）编译opencv_contrib文件需要配置的选项
![[编译opencv_contrib的目标平台.png]]
BUILD_open_world变量的含义是生成一个大的.lib文件，例如opencv_world409d.lib
OPENCV_ENABLE_NONFREE变量的含义是在编译成功后，可以使用具有专利保护的算法
OPENCV_EXTRA_MODULES_PATH变量告诉编译器扩展模块在什么位置
![[编译opencv_contrib配置选项.png]]
编译过程中如果遇到如下网络问题，根据报错信息进行手动下载
![[编译opencv_contrib时可能会遇到的网络问题.png]]
找到配置的build文件目录下的CmakeDownloadLog.txt文件
![[根据opencv_contrib的CmakeDownloadLog.txt手动下载下载失败的文件.png]]
查看CmakeDownloadLog.txt文件下的内容
![[CmakeDownloadLog文件内容和手动下载文件存放位置.png]]
手动下载的文件和cmake自动下载失败后的文件比较
![[手动下载文件和自动下载的失败文件对比.png]]
此项为英伟达视频编解码库，若不需要可以在CMake中取消勾选WITH_NVCUVID与WITH_NVCUVENC解决。若需要安装，则需要下载Nvidia Video Codec SDK下载完成后解压，将Lib和Interface中所有文件分别复制到CUDA Toolkit文件夹下的lib和include中解决。
![[Nvidia Video Codec SDK错误截图.png]]
![[Nvidai Video Codec SDK下载截图.png]]
`OPENCV_GENERATE_SETUPVARS`选项表示在安装过程中生成`setupvars`脚本。这个脚本通常用于设置环境变量，以便在运行时正确配置OpenCV。它会设置一些必要的路径，例如库路径和包含路径，以确保OpenCV可以正确运行。启用该选项时，会在安装目录中生成一个脚本（如`setupvars.sh`或`setupvars.bat`），用户可以在命令行中运行该脚本，以便配置环境变量，确保OpenCV的所有依赖项和库路径都正确设置。**我们选择取消该选项，在后续过程中手动配置OpenCV在Windows下的环境变量。**
![[validate setupvars script错误截图.png]]
编译：
编译失败错误分析：
![[编译错误1.png]]
![[编译错误2.png]]
![[编译错误3.png]]

![[解决编译Nvidia Video Codec SDK12.2错误1.png]]

![[解决编译Nvidia Video Codec SDK12.2错误2.png]]

![[编译成功.png]]