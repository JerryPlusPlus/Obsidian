Github仓库链接：`https://github.com/typicode/json-server`

安装JSON Server
```
npm install json-server
```
创建db.json文件
```json
{
  "posts": [
    { "id": "1", "title": "a title", "views": 100 },
    { "id": "2", "title": "another title", "views": 200 }
  ],
  "comments": [
    { "id": "1", "text": "a comment about post 1", "postId": "1" },
    { "id": "2", "text": "another comment about post 1", "postId": "1" }
  ],
  "profile": {
    "name": "typicode"
  }
}
```
打开JSON Server服务
```
$ npx json-server db.json
```
