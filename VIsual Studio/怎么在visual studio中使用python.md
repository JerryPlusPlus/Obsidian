```
在python中，文件的默认存储格式（编码方式）是utf-8，utf-8是一种可变长度的字符编码，它可以表示几乎所有的字符，包括ASCII字符和Unicode字符。在python3中字符串本身是Unicode字符，而不再像Python 2那样是字节字符串。当你写入字符串到文件时，Python会将Unicode字符串自动编码为指定的文件编码，如果没有指定，默认为UTF-8。
```

### 解决Visual Studio中创建python文件中文编码报错问题
```python
print("你好，世界！")
```

![[python文件编码报错信息.png]]

### 解决方案：
![[python中文乱码解决方案1.png]]
![[python中文乱码解决方案2.png]]
![[python中文乱码解决方案3.png]]
![[python中文乱码解决方案4.png]]