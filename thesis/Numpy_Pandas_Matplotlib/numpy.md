需要注意的是，`range` 对象在 Python 2 中的行为和 Python 3 中有些许不同。在 Python 2 中，`range` 返回的是一个列表。在 Python 3 中，为了提高性能，`range` 返回的是一个对象，其行为类似于生成器，实际上不会立即生成所有的元素，只有在需要时才生成。总之，在 Python 3 中，`range` 返回的是一个 `range` 类型的对象，它是一个可迭代的对象，你可以使用 `list()` 函数将其转换为列表。

### 使用numpy创建数组的三种方式
```python
import numpy as np
import random

a=np.array([[1,2,3,4,5],[11,22,33,44,55]])
b=np.array(range(1,6))
c=np.arange(1,6)
#指定数据存储的类型
d=np.array(range(1,6),dtype=bool)
#数据类型转换
e=d.astype("int8")
f=np.array([random.random() for i in range(10)])
#保留固定位数的小数
g=np.round(f,2)

print("a:\n ",a,"\n","type(a): ",type(a))
print("b:\n ",b,"\n","type(b): ",type(b))
print("c:\n ",c,"\n","type(c): ",type(c))
print("d:\n ",d,"\n","type(d): ",type(d),"\n d.dtype:  ",d.dtype)
print("e:\n ",e,"\n","type(e): ",type(e),"\n e.dtype:  ",e.dtype)

print("f:\n ",f,"\n","type(f): ",type(f),"\n f.dtype:  ",f.dtype)
print("g:\n ",g,"\n","type(g): ",type(g),"\n g.dtype:  ",g.dtype)

输出结果
a:
  [[ 1  2  3  4  5]
 [11 22 33 44 55]]
 type(a):  <class 'numpy.ndarray'>
b:
  [1 2 3 4 5]
 type(b):  <class 'numpy.ndarray'>
c:
  [1 2 3 4 5]
 type(c):  <class 'numpy.ndarray'>
d:
  [ True  True  True  True  True]
 type(d):  <class 'numpy.ndarray'>
 d.dtype:   bool
e:
  [1 1 1 1 1]
 type(e):  <class 'numpy.ndarray'>
 e.dtype:   int8
f:
  [0.99179429 0.33196154 0.49476432 0.71326351 0.23917968 0.87131844
 0.11096083 0.91493724 0.7566212  0.60053865]
 type(f):  <class 'numpy.ndarray'>
 f.dtype:   float64
g:
  [0.99 0.33 0.49 0.71 0.24 0.87 0.11 0.91 0.76 0.6 ]
 type(g):  <class 'numpy.ndarray'>
 g.dtype:   float64
```
### numpy数组之间的加减乘除运算
 ```
 查看numpy数组形状函数shape()
 修改已有数组形状函数reshape()
 两个形状相同的numpy数组进行加减乘除运算，对应位置元素进行加减乘除
	 两个不同形状的numpy数组满足广播原则，则可以进行加减乘除运算。广播原则：如果两个数组的后缘维度（即从末尾开始算起的维度）的轴长度相符，或则其中一方的轴长度为1，则认为它们是广播兼容的。广播会在缺失和长度为一的维度上进行。
```
```python
import numpy as np

a=np.arange(24).reshape(2,3,4)
b=np.arange(4)
c=np.arange(8).reshape(2,1,4)
d=np.array([[[0,1,2,3],[0,1,2,3],[0,1,2,3]],[[4,5,6,7],[4,5,6,7],[4,5,6,7]]])

print("a ",a)
print("b ",b)
print("c ",c)

print("a-b= ",a-b)#满足后缘维度
print("a+c= ",a+c)#满足后缘维度
print("a+d= ",a+d)#判断扩展方式，c数组扩展后的样子是d数组
print("a*c= ",a*c)
print("a/c= ",a/c)
运行结果：
a  [[[ 0  1  2  3]
  [ 4  5  6  7]
  [ 8  9 10 11]]

 [[12 13 14 15]
  [16 17 18 19]
  [20 21 22 23]]]
b  [0 1 2 3]
c  [[[0 1 2 3]]

 [[4 5 6 7]]]
a-b=  [[[ 0  0  0  0]
  [ 4  4  4  4]
  [ 8  8  8  8]]

 [[12 12 12 12]
  [16 16 16 16]
  [20 20 20 20]]]
a+c=  [[[ 0  2  4  6]
  [ 4  6  8 10]
  [ 8 10 12 14]]

 [[16 18 20 22]
  [20 22 24 26]
  [24 26 28 30]]]
a+d=  [[[ 0  2  4  6]
  [ 4  6  8 10]
  [ 8 10 12 14]]

 [[16 18 20 22]
  [20 22 24 26]
  [24 26 28 30]]]
a*c=  [[[  0   1   4   9]
  [  0   5  12  21]
  [  0   9  20  33]]

 [[ 48  65  84 105]
  [ 64  85 108 133]
  [ 80 105 132 161]]]
C:\Code\thesis\Numpy_Pandas_Matplotlib\Matplotlib\NUMPY.py:16: RuntimeWarning: divide by zero encountered in divide
C:\Code\thesis\Numpy_Pandas_Matplotlib\Matplotlib\NUMPY.py:16: RuntimeWarning: invalid value encountered in divide
a/c=  [[[       nan 1.         1.         1.        ]
  [       inf 5.         3.         2.33333333]
  [       inf 9.         5.         3.66666667]]

 [[3.         2.6        2.33333333 2.14285714]
  [4.         3.4        3.         2.71428571]
  [5.         4.2        3.66666667 3.28571429]]]
```

### numpy轴的概念
```
在numpy中可以理解为方向，使用数字0，1，2，3...表示，对于三维数组shape(2,2,3)，由0，1，2轴
有了轴的概念之后，我们计算会更加方便，例如计算平均值时，必须指定是计算哪个方向上的平均值。
```

### numpy读取数据（不常用，pandas更好用）
```
这里不做介绍
```


### numpy数组的拼接
```
竖直拼接函数：np.vstack()     v：vertically
水平拼接函数：np.hstack()     h: horizontally
```

```python
import numpy as np

a=np.arange(8).reshape(2,4)
b=np.arange(8).reshape(2,4)

c=np.vstack((a,b))#竖直拼接
d=np.hstack((a,b))#水平拼接


print("竖直拼接\n",c)
print("水平拼接\n",d)
输出结果：
竖直拼接
 [[0 1 2 3]
 [4 5 6 7]
 [0 1 2 3]
 [4 5 6 7]]
水平拼接
 [[0 1 2 3 0 1 2 3]
 [4 5 6 7 4 5 6 7]]
```

### 数组的行列交换
```python
import numpy as np

t=np.arange(12,24).reshape(3,4)
print('t:\n',t)
t[[1,2],:]=t[[2,1],:]
print('行交换\n',t)
t[:,[1,2]]=t[:,[2,1]]
print('列交换\n',t)
运行结果：
t:
 [[12 13 14 15]
 [16 17 18 19]
 [20 21 22 23]]
行交换
 [[12 13 14 15]
 [20 21 22 23]
 [16 17 18 19]]
列交换
 [[12 14 13 15]
 [20 22 21 23]
 [16 18 17 19]]
```

### 其他数组操作

```
1.获取某个方向上的最大值最小值的位置np.argmax(t,axis=n),np.argmin(t,aixs=n)
	t:数组，aixs：方向
2.创建一个全为0的数组：np.zeros(元组)
3.创建一个全为1的数组，np.ones(元组)
4.创建一个对角线为1的正方形的数组： np.eye(n)
```
```python
import numpy as np

a=np.zeros((3,4))
print('a：',a)
b=np.ones((3,4))
print('b：',b)
c=np.eye(4)
print('c',c)
d=np.arange(16).reshape(4,4)
print('d',d)
print('0方向上的最大值',np.argmax(d,axis=0 ))
print('0方向上的最小值',np.argmin(d,axis=0 ))
运行结果：
a： [[0. 0. 0. 0.]
 [0. 0. 0. 0.]
 [0. 0. 0. 0.]]
b： [[1. 1. 1. 1.]
 [1. 1. 1. 1.]
 [1. 1. 1. 1.]]
c [[1. 0. 0. 0.]
 [0. 1. 0. 0.]
 [0. 0. 1. 0.]
 [0. 0. 0. 1.]]
d [[ 0  1  2  3]
 [ 4  5  6  7]
 [ 8  9 10 11]
 [12 13 14 15]]
0方向上的最大值 [3 3 3 3]
0方向上的最小值 [0 0 0 0]![[Pasted image 20231207171431.png]]
```

![[numpy生成随机数.png]]

![[Pasted image 20231207182456.png]]

### nan和inf
```
1.nan和nan不相等
2.任何数和nan做运算都是nan
3.可以使用np.isnan(t)，t为数组，来判断数组的每一个元素是否为nan，如果为nan，则为true，反之为false。

```



