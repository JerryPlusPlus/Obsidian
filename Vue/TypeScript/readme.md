如果变量的声明和赋值是同时进行的，TS可以自动对变量进行类型检查。
```typescript
let a =10
let a = '10'  //给a重新赋值成字符串类型会报错
```
第一个number和第二个number限制了变量a和变量b的类型，第三个number限制了函数返回值的类型
```typescript
function sum(a:number,b:number):number{
	return a+b
}
```

可以使用`|` 来连接多个类型（联合类型）
```typescript
let c:boolean|string;
c = true
c = 'hello world'
```
any和unkown的区别
```typescript
let a:any      //关闭了类型检查，可以赋值给其他类型的变量
let b:unkown   //类型安全的any，不可以赋值给其他类型的变量
```
`as`类型断言，可以用来告诉解释器变量的实际类型
```typescript
s = e as string   //断言写法一
s = <string>e    //断言写法二
```
		