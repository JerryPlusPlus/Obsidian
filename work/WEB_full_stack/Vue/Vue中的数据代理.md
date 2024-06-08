Vue.js 中的数据代理是指将组件实例（`this`）上的某个属性的访问和修改操作代理到其数据对象中的属性上，以便更方便地访问和修改数据。
在 Vue 实例中，数据对象通常由 `data` 选项定义。Vue 会将 `data` 选项中的属性代理到 Vue 实例上，使得你可以通过 `this.property` 直接访问和修改数据。
下面是一个简单的示例：
```html
<template>
  <div>
    <p>{{ message }}</p>
    <button @click="updateMessage">Update Message</button>
  </div>
</template>

<script>
export default {
  data() {
    return {
      message: 'Hello, Vue!'
    };
  },
  methods: {
    updateMessage() {
      // 直接修改数据对象中的属性
      this.message = 'Updated Message';
    }
  }
};
</script>
```

在这个例子中，`data` 选项中的 `message` 属性被代理到了 Vue 实例上，因此在模板中可以直接使用 `{{ message }}` 来渲染数据，而在方法中可以直接使用 `this.message` 来修改数据。

Vue.js 在实例化时会遍历 `data` 对象中的属性，并使用 `Object.defineProperty` 将每个属性代理到 Vue 实例上。这样做的好处是，当数据变化时，Vue 能够追踪到数据的变化，并触发视图的更新。

需要注意的是，如果后续需要添加新的属性，Vue 不会代理新添加的属性，因此最好在组件实例创建时就将所有需要的属性定义在 `data` 中。如果需要动态添加属性，可以使用 `Vue.set` 或 `this.$set` 方法（注意：对象不能是Vue实例或者Vue实例的根对象，即vm和_data不能作为target对象）。
![[错误用法_直接给对象添加属性.png]]
```

只有使用以下七 种方法修改数组，Vue才能监测到数组内数据发生改变，否者检测不到数组内部数据的变化，从而不能将变化的数据在页面上渲染出来
```
![[Vue检测数组改变的方式.png]]
这其中方法都被vue重写，顺着原型链找到的第一个方法就是vue重写的数组方法
![[vue数组方法重写_原型链查找.png]]
