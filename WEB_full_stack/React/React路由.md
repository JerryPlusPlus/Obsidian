




### 相对路径中./css/bootstrap.css和 /css/bootstrap.css有什么区别吗


#### 1. `./css/bootstrap.css`

- **相对于当前文件的路径**。
- 适用于 `import` 模块语法中，比如在某个 `.js` 或 `.jsx` 文件里：
    
`import './css/bootstrap.css';`

这表示：从当前文件所在目录开始，查找 `css/bootstrap.css` 文件。

---

#### 2. `/css/bootstrap.css`

- **相对于网站根目录（也就是 `/public` 目录下的文件）**。
- 通常出现在 HTML 文件或组件中，比如：

`<link rel="stylesheet" href="/css/bootstrap.css">`

- React 开发环境中，它会去访问类似 `http://localhost:3000/css/bootstrap.css`。
- 因此这个路径是相对于网站的根目录，不是 JS 文件的位置。

---

#### 区别总结：

|路径类型|含义|常见用法|依赖文件放置位置|
|---|---|---|---|
|`./css/bootstrap.css`|相对当前 JS 文件路径|`import` 引入 CSS 或模块|放在 `src/css/bootstrap.css`|
|`/css/bootstrap.css`|相对网站根目录（通常是 `public/`）|`<link>` 标签、图片地址等资源|放在 `public/css/bootstrap.css`|

---

### 建议使用场景：

- 如果你使用的是 `import` 来加载样式（推荐做法）：
    - 把 CSS 放在 `src` 目录中，并使用 `./` 相对路径。
- 如果你是在 `public/index.html` 里直接 `<link>` 引入：
    - 把 CSS 放在 `public` 目录中，用 `/css/bootstrap.css`。


