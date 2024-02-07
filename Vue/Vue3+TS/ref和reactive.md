```
宏观角度：
ref:定义基本类型数据、对象类型数据
reactive:只可以定义对象数据类型

区别：
ref创建的变量必须使用.value  (可以使用volar插件自动添加.value)
ref的value发生更改必定自动是响应式的：
	refObj.value={brand:'宝马',price:100}
不通过value修改的错误写法：sum = ref(0) sum =ref(9)
reactive重新分配一个新对象，会失去响应式(可以使用Object.assign去整体替换)
错误写法：reactiveObj={brand:'宝马',price:100}  
         reactiveObj=reactive({brand:'宝马',price:100})
正确写法：Object.assign(reactiveobj,object1,...,objectn)
将对象数据类型的键值对，赋值给reactiveobj

使用原则：
	1. 若需要一个基本类型的响应式数据，必须使用ref
	2. 若需要一个响应式对象，层级不深，ref、reactive都可以
	3. 若需要一个响应式对象，层级较深，推荐使用reactive
```

![[ref和reactive定义响应式对象数据的区别.png]]

