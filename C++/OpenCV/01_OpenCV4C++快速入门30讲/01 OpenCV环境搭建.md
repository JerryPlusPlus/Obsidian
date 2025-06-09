
**注意：编译opencv和外部扩展opencv_contrib可以使用①opencv预编译版本②自己从源码编译。推荐选择自己从源码编译，步骤如下所示：**

下图显示的是伴随opencv的`xxx.windows.exe`安装时安装的opencv预编译版本
![[Pasted image 20250603003035.png]]

1）准备工作
1.安装依赖工具
- visual studio2022（必须安装了C++桌面开发组件）
- CMake

2.下载opencv和opencv_contrib

![[Pasted image 20250603005729.png]]

![[Pasted image 20250603005404.png]]

2）开始编译
1.先创建一个myBuild文件夹，用于存放生成的配置文件

![[Pasted image 20250603010228.png]]

2.cmake配置

![[Pasted image 20250603011044.png]]

**网络问题容易出现下述错误**

![[Pasted image 20250603011931.png]]

解决方法：找到下载日志，根据内容使用浏览器手动下载相应的文件。下载的文件要存放在日志中的路径下，并根据日志内容命名文件名

![[Pasted image 20250603012132.png]]

![[Pasted image 20250603013129.png]]

**下载完对应文件后，重新生成配置文件**

![[Pasted image 20250603013933.png]]

3.选择构建选项

✅ 一、基础建议设置

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`CMAKE_BUILD_TYPE`|构建类型|`Release`|性能最优版本|
|`CMAKE_INSTALL_PREFIX`|安装路径|自定义|默认安装到 `install/`|
|`BUILD_opencv_world`|构建单一大库|`ON`|减少多个 `.lib` 文件依赖|
|`BUILD_SHARED_LIBS`|构建 DLL|`ON`|默认是 `ON`，构建 `.dll`|
|`WITH_IPP`|Intel IPP 加速|`ON`|默认启用，加速图像处理|
|`WITH_OPENMP`|多线程并行优化|`ON`|支持并行加速（有时要装支持库）|
|`WITH_TBB`|Intel TBB 并行库|`OFF`（或ON）|更好的多线程加速，若已装推荐开启|

📷 二、图像/视频编解码相关

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`WITH_JPEG`|支持 JPEG 读写|`ON`|默认打开|
|`WITH_PNG`|支持 PNG 图像|`ON`|默认打开|
|`WITH_TIFF`|支持 TIFF 图像|`ON`|可按需打开|
|`WITH_WEBP`|支持 WebP|`ON`|现代图像格式|
|`WITH_OPENEXR`|支持 HDR 图像格式|`ON`|用于高质量图像处理|
|`WITH_GSTREAMER`|使用 GStreamer 读写视频流|`OFF`（或ON）|Linux 上有优势，Windows 需额外配置|
|`WITH_FFMPEG`|使用 FFmpeg 解码视频|`ON`|视频处理强烈推荐|

📐 三、GUI 与可视化

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`WITH_QT`|使用 Qt GUI|`OFF`（或ON）|启用后支持高级窗口、滑条等，需要 Qt 安装|
|`WITH_GTK`|使用 GTK GUI|Linux 专用|Windows 不需要|
|`WITH_OPENGL`|支持 OpenGL 显示|`ON`|加速图像显示，3D 可视化等|


🧪 四、编译测试 & 示例 & 文档（开发者向）

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`BUILD_TESTS`|构建测试集|`OFF`|开发者调试用，一般关闭|
|`BUILD_PERF_TESTS`|构建性能测试|`OFF`|同上|
|`BUILD_DOCS`|构建 Doxygen 文档|`OFF`|用不到可关闭|
|`BUILD_EXAMPLES`|构建示例程序|`ON`|学习推荐开启|

📦 五、模块选择（可手动排除不需要的模块）

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`BUILD_opencv_python_bindings_generator`|构建 Python 绑定|`ON`|如果需要 `cv2` 模块|
|`BUILD_opencv_java`|构建 Java 接口|`OFF`|非 Java 用户关闭|
|`BUILD_opencv_dnn`|深度学习模块|`ON`|用于加载 ONNX 等模型|
|`BUILD_opencv_apps`|构建 opencv_apps|`OFF`|可选|

🧠 六、其他实用项

|CMake 变量|功能说明|建议值|说明|
|---|---|---|---|
|`WITH_EIGEN`|启用 Eigen 库加速|`ON`|默认启用|
|`WITH_VTK`|与 VTK 配合可视化|`OFF`|科研 3D 领域用|
|`ENABLE_CXX11` 或 `CMAKE_CXX_STANDARD`|使用 C++11/C++17|`ON` / `17`|启用现代 C++ 编译|
|`WITH_LAPACK`|线性代数加速（用于 calib3d）|`OFF`|若需要 SVD 拍照求解，可考虑开|
|`WITH_OPENCL`|启用 OpenCL 加速|`ON`|GPU 无 CUDA 可选 OpenCL|

**过程中遇到问题，请询问GPT解决**

✅ 如何在 CMake GUI 中配置 vcpkg toolchain 文件
**添加变量**：
- 点击上方的 **“Add Entry”**，位于search右侧
- 输入如下内容：

| 名称                     | 类型         | 值（Value）                                                  |
| ---------------------- | ---------- | --------------------------------------------------------- |
| `CMAKE_TOOLCHAIN_FILE` | `FILEPATH` | `E:/VS/C++/vcpkg-master/scripts/buildsystems/vcpkg.cmake` |
     ⚠️ 你要把路径替换为你自己 vcpkg 所在位置。

🔍 检查是否成功应用 vcpkg

- 如果你看到 CMake 输出中有 `Found Eigen3`, `Found JPEGXL`, `Found Freetype` 等字样，说明 vcpkg 的依赖已成功被使用。

✅ 安装并配置 NVIDIA Video Codec SDK（高级）

![[Pasted image 20250604015032.png]]


将对应的文件复制到相应的文件夹内

![[Pasted image 20250604014837.png]]

cmake会自动检测到相应的文件路径

![[Pasted image 20250604014700.png]]


✅ 将 C++ 标准设置为 **C++17**
原因：std::string_view 只在 C++17 及以上版本中才有。你的项目使用的是 C++14，所以标准库里没有 std::string_view。

```
E0135: namespace "std" has no member "string_view"
```

|名称|类型|值|
|---|---|---|
|`CMAKE_CXX_STANDARD`|`STRING`|`17`|

🔍 验证方式
你可以查看 CMake 配置输出是否出现类似：`C++ standard: 17 C++ Compiler: cl.exe ...`

✅ [启用cudnn](https://blog.csdn.net/qq_41822101/article/details/137079271)

**早不到cuDNN错误信息如下**

```
CMake Error at modules/dnn/CMakeLists.txt:53 (message):
  DNN: CUDA backend requires cuDNN.  Please resolve dependency or disable
  OPENCV_DNN_CUDA=OFF
Call Stack (most recent call first):
  modules/world/CMakeLists.txt:13 (include)
  modules/world/CMakeLists.txt:50 (include_one_module)

```

**`dnnl_DIR` 和 `cuDNN` 是两个完全不同的东西。**

前提条件：
- 正确安装CUDA Toolkit
- 正确将cuDNN的文件内容拷贝到相应的CUDA Toolkit文件夹下
- 若正确安装则，勾选`Advance`选项，搜索`cudnn`，将`CUDNN_LIBRARY`项设置为`cudnn.lib`位置一般在`C:\Program Files\NVIDIA\CUDNN\v9.0\lib\???\x64`下


在【CMake GUI】中：
1. 先点【Configure】
2. 然后查找并勾选或设置：

| 名称                      | 类型   | 值                                                                          |
| ----------------------- | ---- | -------------------------------------------------------------------------- |
| `WITH_CUDA`             | BOOL | `ON`                                                                       |
| `OPENCV_DNN_CUDA`       | BOOL | `ON`                                                                       |
| `OPENCV_DNN_CUDNN`      | BOOL | `ON`                                                                       |
| `CUDA_TOOLKIT_ROOT_DIR` | PATH | 你的 CUDA 安装目录，例如 `C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.3` |

**如果找不到 `OPENCV_DNN_CUDNN`，可以手动点【Add Entry】，类型选 `BOOL`，值设为 `ON`。**

手动添加变量

| 变量名                 | 类型       | 值（路径）                                                                                  |
| ------------------- | -------- | -------------------------------------------------------------------------------------- |
| `CUDNN_INCLUDE_DIR` | PATH     | `C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.9/include`                     |
| `CUDNN_LIBRARY`     | FILEPATH | `C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.9/lib/x64/cudnn.lib（或你的实际文件名）` |

配置完成后，CMake 输出中应看到：

![[Pasted image 20250603152548.png]]

配置完成后，再次点击 **Configure**，没有红色项就点击 **Generate**

---
3）点击generate，完成后点击open project进入visual studio界面

✅ 使用多线程构建，提高CPU的利用率

步骤 1：在 CMake GUI 中设置 `/MP`
开启 Visual Studio 的每个项目多核编译：

|Name|Type|Value|
|---|---|---|
|`CMAKE_CXX_FLAGS`|`STRING`|`/MP`|
|`CMAKE_C_FLAGS`|`STRING`|`/MP`|

这表示告诉编译器启用多处理器文件编译（即让 `.cpp` 文件并发编译）。

![[Pasted image 20250604195758.png]]

步骤 2：在 Visual Studio 中并行项目编译

`工具 → 选项 → 项目和解决方案 → 生成和运行 → 最大并行项目数`

设置为你的核心数，例如 8、16、32。

![[Pasted image 20250604195620.png]]

---

你可以通过以下几种方式查看你电脑的 **CPU 核心数（物理核）** 和 **线程数（逻辑核）**，以便设置并行编译线程数：

✅ 方法一：通过任务管理器（图形界面最直观）

1. 右键点击任务栏 → 打开 **任务管理器**
2. 切换到顶部标签页：**“性能”**
3. 左侧选择 **“CPU”**
4. 在右下角你会看到：
    - **内核数（即物理核心数）**
    - **逻辑处理器数（即线程数，通常 = 核心数 × 2）**

![[Pasted image 20250604161138.png]]



✅ 启用vcpkg功能

**注意：1. 每次修改工具链路径后，删除`build`目录并重新配置。有可能会发生安装好但未识别的情况，如Lapack**

| 字段        | 内容                                                                      |
| --------- | ----------------------------------------------------------------------- |
| **Name**  | `CMAKE_TOOLCHAIN_FILE`                                                  |
| **Type**  | `FILEPATH`                                                              |
| **Value** | `E:/VS/C++/vcpkg-master/scripts/buildsystems/vcpkg.cmake` （← 替换成你的实际路径） |

![[Pasted image 20250604183403.png]]



使用vcpkg访问国外网络时，下载包速度慢问题（未解决）


✅启用 lapack功能（未解决）

使用vcpkg下载lapack

![[Pasted image 20250604185021.png]]






✅ 启用GStreamer功能：（未解决）

使用vcpkg安装GStreamer包






**`12.9版本的cuda和opencv有冲突，下面的错误并没有解决，建议安装12.2版本的cuda`**


错误和原因如下：**有些版本的npp.h文件缺失nppGetStreamContext()函数**

![[Pasted image 20250603161826.png]]

![[Pasted image 20250603161932.png]]
![[Pasted image 20250603163316.png]]

![[Pasted image 20250603163845.png]]

![[Pasted image 20250603164529.png]]



首先解决错误：使用12.6版本的cuda toolkit可以解决visual studio版本过高问题

```
严重性	代码	说明	项目	文件	行	禁止显示状态	详细信息
错误	C1189	#error:  -- unsupported Microsoft Visual Studio version! Only the versions between 2017 and 2022 (inclusive) are supported! The nvcc flag '-allow-unsupported-compiler' can be used to override this version check; however, using an unsupported host compiler may cause compilation failure or incorrect run time execution. Use at your own risk.	opencv_world	C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v12.2\include\crt\host_config.h	157		

```




![[Pasted image 20250603231315.png]]

![[Pasted image 20250603155306.png]]















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

**注意·：如果在visual studio extension manager中搜索不到，可以在浏览器中搜索**


![[Pasted image 20250603001538.png]]

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