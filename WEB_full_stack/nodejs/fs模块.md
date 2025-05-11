- 1. 写入文件
- 2. 同步与异步
- 3. 文件追加写入
- 4. 文件流式写入
- 5. 文件写入场景
- 6. 文件读取
- 7. 文件流式读取
- 8. 文件复制
- 9. 文件重命名与移动
- 10. 文件删除
- 11. 文件夹操作
- 12. 查看资源状态
- 13. 路径补充说明
- 14. 相对路径的Bug与解决
- 15. 批量重命名


##  1. 写入文件

``` javaScript
//异步写入文件
const fs = require('fs');

fs.writeFile("./test.txt", "hello world", (err) => {
    //err 写入失败：错误对象   写入成功：null
    if (err)
        console.log(err);
    else
        console.log("File written successfully");
})
```

##  2. 同步与异步

``` javaScript
const fs = require('fs');
//异步写入文件
fs.writeFile("./test.txt", "hello world", (err) => {
    //err 写入失败：错误对象   写入成功：null
    if (err)
        console.log(err);
    else
        console.log("File written successfully");
})
console.log("I'm first");
//同步写入文件
fs.writeFileSync('./testSync.txt', "hello world Sync")
```

##  3. 文件追加写入

``` javaScript

```

##  4. 文件流式写入

``` javaScript

```

##  5. 文件写入场景

``` javaScript

```

##  6. 文件读取

``` javaScript

```

##  7. 文件流式读取

``` javaScript

```

##  8. 文件复制

``` javaScript

```

##  9. 文件重命名与移动

``` javaScript

```

##  10. 文件删除

``` javaScript

```

##  11. 文件夹操作

``` javaScript

```

##  12. 查看资源状态

``` javaScript

```

##  13. 路径补充说明

``` javaScript

```

##  14. 相对路径的Bug与解决

``` javaScript

```

##  15. 批量重命名

``` javaScript

```
