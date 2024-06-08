创建环境：`conda create --name Tensorflow tensorflow-gpu`
`tensorflow-gpu`表示创建一个使用gpu的tensorflow环境。
```python
from tensorflow.python.client import device_lib
print(device_lib.list_local_devices())
```
如果TensorFlow使用了GPU，你将在输出中看到包含GPU信息的设备。如果只有CPU信息，那么你的TensorFlow是CPU版本。请注意，为了使用GPU版本的TensorFlow，你需要确保正确安装了GPU驱动和CUDA库，并且安装了与你的GPU兼容的cuDNN库。如果你在安装TensorFlow时选择了GPU版本，但你的系统上没有正确配置GPU相关的依赖项，TensorFlow将自动安装为CPU版本。

一些常见的conda命令：
```
查看所有存在的conda环境： conda env list
激活conda环境：conda activate 环境名称

```