
JSX（javascript XML，javascript扩展语法）：简化创建虚拟DOM的代码量

```javascript
//创建虚拟DOM：<h1 id="title"><span>hello jsx</span></h1>

//React.createElement('标签名',标签属性对象,标签体内容)
const VDOM = React.createElement('h1',{id:'title'},React.createElement('span',{},'hello jsx'))

//React.render(虚拟DOM,容器)
```



```
jsx语法规则：
	1. 定义虚拟DOM时，不要写引号。
	2. 标签中混入JS表达式时，要用{}
	3. 样式的类名指定不要用class，要用className
	4. 内联样式，要用style={{key:value}}的形式去写。
	5. 只能有一个根标签
	6. 标签必须闭合
	7. 标签首字母
		1. 若是小写字母开头，则将转为html同名标签，若html中无该标签对应的同名元素，则报错
		2. 若大写字母开头，react就去渲染对应的组件，若组件没有定义，则报错。
```



