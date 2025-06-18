### ref


### props（只读）

```javascript
<Student name="jerry" :age="18" gender="男" />

//简单接收
props:['name','age','gender']
//接收的同时对数据进行类型限制
props:{
	name:String,
	age:Number,
	gender:String
}
//接收的同时对数据进行：类型、默认值、必要性的限制，默认值和必要性一般不同时用于一个属性
props:{
	name:{
		type:String,    //name的类型是字符串
		required:true   //name是必要的
	},
	age:{
		type:Number,
		default:99     //默认值
	},
	gender:{
		type:String,
		required:true
	}
}
```
在Vue.js中，使用`props`传递的数据实际上是父组件中数据的**引用**，而不是副本。这意味着，当子组件修改`props`传递过来的数据时，会影响到父组件中的相应数据。**注意：应该避免修改使用props方法传入子组件的数据**，在`props`中，Vue.js建议保持单向数据流，以确保数据的清晰来源和可维护性。如果需要从子组件向父组件传递数据，通常使用自定义事件或回调函数的方式。
