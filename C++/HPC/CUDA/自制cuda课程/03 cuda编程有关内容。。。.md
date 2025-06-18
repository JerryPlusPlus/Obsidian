### 编写一段hello_world.cu程序
```c++
#include<stdio.h>

__global__ void helloFromGPU()
{
	printf("Hello world from GPU \n");
}

int main(void)
{
	printf("hello world from cpu\n");
	helloFromGPU<<<1,32>>>();
	cudaDeviceReset();

	return 0;
}
```
使用指令`nvcc 文件.cu -o 可执行文件名`编译运行上述程序
```bash
jerry@jerry-ubuntu:/media/jerry/新加卷/Code/cuda$ nvcc ./Chapter01/hello_world.cu -o hello_world
jerry@jerry-ubuntu:/media/jerry/新加卷/Code/cuda$ ./hello_world 
hello world from cpu
Hello world from GPU 
Hello world from GPU 
Hello world from GPU 
Hello world from GPU 
```


为什么相同block中的线程可以进行数据交换，而不同的block之间不能进行数据交换。（从GPU的cuda模型内存架构方面解释）

![[cuda内存架构.png]]