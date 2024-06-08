![[react目录结构.png]]

# node_modules
	node_modules是react脚手架的依赖项
# public中存放静态资源文件
### favicon.ico
   网站页签图标，图标可以更换，但是名字不能变，而且后缀只能是.ico
### index.html
   react应用的主页面,用于呈装各个组件。
```html
<!DOCTYPE html>
<html lang="en">
  <!-- 用于指定网站语言 -->
  <head>
    <meta charset="utf-8" />
    <link rel="icon" href="%PUBLIC_URL%/favicon.ico" />
    <!-- 用于指定网站页签的图标，%PUBLIC_URL%是一个特殊的占位符，当你的项目被构建时，Create React App会将这个占位符替换为实际的公共URL。在这个 HTML 文件中，%PUBLIC_URL% 被用于指定一些静态资源的路径，使用 %PUBLIC_URL% 可以确保无论你的应用部署在哪里，这些文件的路径都是正确的。 -->
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <!--这是一个 HTML 元标签，它用于控制页面在移动设备上的布局。这个标签对于响应式设计非常重要，因为它可以确保你的网页在移动设备上正确显示。width=device-width：这个属性设置布局视口的宽度等于设备的屏幕宽度，这样可以确保页面在不同设备上都能以正确的宽度显示。initial-scale=1：这个属性控制页面首次加载时的缩放级别。设置为1表示页面按照设备宽度的100%显示，不进行缩放。  -->
    <meta name="theme-color" content="#000000" />
    <!-- 一个 HTML 元标签，它用于定义网页在某些移动浏览器中的主题颜色。兼容性不太好。几乎不用 -->
    <meta
      name="description"
      content="Web site created using create-react-app"
    />
    <!-- 描述网站信息 -->
    <link rel="apple-touch-icon" href="%PUBLIC_URL%/logo192.png" />
    <!--只支持apple手机， 用指定网页添加到手机主屏幕后的图标 -->
    <link rel="manifest" href="%PUBLIC_URL%/manifest.json" />
    <!-- 它用于指定网页的 Web 应用程序清单（Web App Manifest）。Web 应用程序清单是一个 JSON 文件，它提供了有关你的网页的信息，包括应用的名称、图标、颜色、启动 URL 和显示模式等。这些信息可以被浏览器用于在用户的设备上将你的网页显示为“近似原生”的应用。例如，当用户将你的网页添加到他们的主屏幕时，浏览器会使用这些信息来确定应用的图标、名称和启动屏幕等。 -->
    <title>React App</title>
  </head>
  <body>
    <noscript>You need to enable JavaScript to run this app.</noscript>
    <!-- 当你的浏览器不支持Javascript时，显示该标签内的内容 -->
    <div id="root"></div>
    <!-- react根容器。当你在 React 中创建一个应用时，你需要选择一个DOM元素作为你的应用的根元素。在这个元素内部，React 将管理所有的内容和交互。-->
  </body>
</html>
```
### logo192.png
	图标，用于显示应用加壳的logo，大小192*192
### logo512.png
	图标，用于显示应用加壳的logo，大小512*512
### manifest.json
	应用加壳。 Web 应用程序清单（Web App Manifest）的文件，它是一个 JSON 格式的文件，提供了有关你的网页的信息，包括应用的名称、图标、颜色、启动 URL 和显示模式等。这些信息可以被浏览器用于在用户的设备上将你的网页显示为“近似原生”的应用。例如，当用户将你的网页添加到他们的主屏幕时，浏览器会使用这些信息来确定应用的图标、名称和启动屏幕等。
### robots.txt
	爬虫规则文件，君子协议，可遵守也可不遵守。

# src中存放动态资源
### index.css和index.js文件
	分别是是index.html的样式和交互文件，index.js也称为入口文件,index.css用于存放通用样式
```javaScript
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
//以上代码等价于以下代码
ReactDOM.render(<App/>,getElementById('root'));
```
### App.css、App.js、 App.test.js
	三个文件构成了组件App，其中App.test.sj文件为组件App的测试文件

### logo.svg
	`import logo from './logo.svg';`用于图片引用，使用浏览器打开该文件可显示图片。

![[logo.svg图片.png]]
### reportWebVitals.js
	页面性能分析文件，需要web-vitals库的支持
### setup.Tests.js
	组件单元测试的文件，需要jest-dom库支持
### .gitignore
	gitignore是一个文本文件，他告诉Git那些文件或目录不应该被添加到Git仓库中。通常用于排除某些特定文件或目录，比如日志文件、临时文件、编译的二进制文件等。
### package-lock.json 
	文件是在你运行 `npm install` 时自动生成的。它描述了你的项目的完整依赖树，包括所有依赖项的确切版本号（直接依赖包和直接依赖包的依赖包）。这样，当你或其他人在不同的时间或不同的机器上安装项目的依赖项时，可以确保安装的是完全相同的依赖项。
### package.json
	一个标准的文件，它在 Node.js 项目中定义了项目的各种属性，包括项目的名称、版本、描述、作者、许可证等。最重要的是，它列出了项目的直接依赖项（即项目需要的其他 Node.js 包，而不包括直接依赖包依赖的依赖包）
### README.md
	仓库说明文档


