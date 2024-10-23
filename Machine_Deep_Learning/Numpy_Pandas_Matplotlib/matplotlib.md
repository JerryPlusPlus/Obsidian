matplotlib是最流行的Python底层绘图库，主要做数据可视化图表，名字取材于MATLAB，模仿MATLAB构建。
1.能将数据进行可视化，更直观的呈现
2.使数据更加客观、更具有说服力

matplotlib初体验
```python
#导入matplotlib库中的pyplot
from matplotlib import pyplot as plt  
#数据在x轴的位置，是一个可迭代对象
x=range(2,26,2)
#数据在y轴是一个可迭代对象
y=[15,13,14.5,17,20,25,26,26,24,22,18,15]
#传入x和y，通过plot绘制出折线图
plt.plot(x,y)
#在执行程序的时候展示图形
plt.show()
```
![[matplotlib初体验1.png]]

```
1.设置图片大小
2.保存到本地
3.描述信息，例如x轴和y轴表示什么，这个图表示什么
4.调整x或y轴的刻度间距
5.线条的样式
6.标记出特殊的点
7.给图片添加水印（防伪防盗）


_xtick_labels=["10点{}分".format(i) for i in range(60)]
_xtick_labels+=["11点{}分".format(i) for i in range(60)]
plt.xticks(list(x)[::3],_xtick_labels[::3],rotation=90)
#rotaion旋转的度数，但是会出现中文乱码现象.哔哩哔哩上教的方法好像不行



```

### 绘制散点图

散点图初体验
```python
from matplotlib import pyplot as plt
from matplotlib import font_manager
#三月份数据
y_3=[11,17,16,11,12,11,6,6,7,8,9,12,15,14,17,18,21,16,17,20,14,15,15,15,15,19,21,22,22,22,23]
#十月份数据
y_10=[26,26,28,19,21,17,16,19,18,20,20,19,22,23,17,20,21,20,22,15,11,15,5,13,17,10,11,14,12,14,6]
#x取值范围
x=range(1,32)
#绘制散点图
plt.scatter(x,y_3)
#展示散点图
plt.show()
```

```python
#解决了中文报错问题方式一
import matplotlib.pyplot as plt
import matplotlib

font={'family':'SimSun',
      'weight':'bold',
      'size':'20'}
matplotlib.rc('font',**font)

#三月份数据
y_3=[11,17,16,11,12,11,6,6,7,8,9,12,15,14,17,18,21,16,17,20,14,15,15,15,15,19,21,22,22,22,23]
#十月份数据
y_10=[26,26,28,19,21,17,16,19,18,20,20,19,22,23,17,20,21,20,22,15,11,15,5,13,17,10,11,14,12,14,6]
#x取值范围
x=range(1,32)
#绘制散点图
plt.scatter(x,y_3)
plt.xticks(x)
plt.xlabel('我是x轴标签')
#展示散点图
plt.show()
```
![[matplotlib中文报错解决方式一.png]]
```python
#解决中文报错方式二
import matplotlib.pyplot as plt
from matplotlib import font_manager

songti=font_manager.FontProperties(family='SimSun')
#三月份数据
y_3=[11,17,16,11,12,11,6,6,7,8,9,12,15,14,17,18,21,16,17,20,14,15,15,15,15,19,21,22,22,22,23]
#十月份数据
y_10=[26,26,28,19,21,17,16,19,18,20,20,19,22,23,17,20,21,20,22,15,11,15,5,13,17,10,11,14,12,14,6]
#x取值范围
x=range(1,32)
#绘制散点图
plt.scatter(x,y_3)
plt.xticks(x[::3],['第{}天'.format(i)  for i in x][::3],fontproperties=songti,rotation=90)
plt.xlabel('我是x轴标签',fontproperties=songti)
#展示散点图
plt.show()
```
![[matplotlib中文报错问题解决方法二.png]]

### matplotlib常见问题总结
```
1. 应该选择哪种图形来呈现数据
2. matplotlib.plot()
3. matplotlib.bar()
4. matplotlib.scatter(x,y)
5. matplotlib.hist()
6. xticks和yticks的设置
7. label和title.grid的设置
8. 绘图的大小和保存图片
```


