### Custom instance defaults
```javascript
// Set config defaults when creating the instance
const instance = axios.create({
  baseURL: 'https://api.example.com'
});

// Alter defaults after instance has been created
instance.defaults.headers.common['Authorization'] = AUTH_TOKEN;
```

### 自定义实例的默认值
	使用该方法，等于创建一个几乎等价于axios对象的实例对象。
```javascript
//创建一个名为instance的实例对象，
//并设置默认的baseURL为：https://api.example.com
const instance = axios.create({
  baseURL: 'https://api.example.com'
});
//同时也可以使用类似于axios设置默认值的方法设置默认值
instance.defaults.headers.common['Authorization'] = AUTH_TOKEN;
//创建出来的实例对象的使用方法类似于axios对象的使用。
instance({
url:'url路径',
}).then(response=>console.log(response);)
```
