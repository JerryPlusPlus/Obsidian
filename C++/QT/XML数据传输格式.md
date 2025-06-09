XML（Extensible Markup Language）是一种类似于 [HTML](https://developer.mozilla.org/zh-CN/docs/Glossary/HTML)，但是**没有使用预定义标记**的语言。因此，**可以根据自己的设计需求定义专属的标记**。这是一种强大将数据存储在一个可以**存储、搜索和共享的格式**中的方法。最重要的是，因为 XML 的基本格式是标准化的，如果你在本地或互联网上跨系统或平台共享或传输 XML，由于标准化的 XML 语法，接收者仍然可以解析数据。
有许多基于 XML 的语言，包括 [XHTML](https://developer.mozilla.org/zh-CN/docs/Glossary/XHTML)、[MathML](https://developer.mozilla.org/zh-CN/docs/Web/MathML)、[SVG](https://developer.mozilla.org/zh-CN/docs/Web/SVG)、[RSS](https://developer.mozilla.org/zh-CN/docs/Glossary/RSS) 和 [RDF](https://developer.mozilla.org/zh-CN/docs/Glossary/RDF)。


```xml
<?xml version="1.0" encoding="UTF-8"?>
<Company name="示例科技有限公司" location="北京">
    <Departments>
        <Department id="D001" name="研发部">
            <Employee id="E1001">
                <Name>张三</Name>
                <Age>30</Age>
                <Position>软件工程师</Position>
                <Email>zhangsan@example.com</Email>
            </Employee>
            <Employee id="E1002">
                <Name>李四</Name>
                <Age>28</Age>
                <Position>测试工程师</Position>
                <Email>lisi@example.com</Email>
            </Employee>
        </Department>
        <Department id="D002" name="人事部">
            <Employee id="E2001">
                <Name>王五</Name>
                <Age>35</Age>
                <Position>人力资源主管</Position>
                <Email>wangwu@example.com</Email>
            </Employee>
        </Department>
    </Departments>
</Company>

```

上面是一段稍微复杂的xml代码片段，描述一个包含多位员工信息的公司结构。它包括嵌套元素和属性：
- 根元素是 `<Company>`，带有 `name` 和 `location` 两个属性。
- `<Departments>` 是一个容器元素，包含多个 `<Department>`。
- 每个 `<Department>` 拥有一个 `id` 和 `name` 属性，内部包含若干 `<Employee>`。
- `<Employee>` 元素也有自己的 `id` 属性，内部是员工的具体信息。

### XML主要用于存储和传输结构化数据：
### 1. **数据传输**
- XML 经常用于**不同系统之间的数据交换，尤其是在跨平台或不同编程语言之间**。
- 示例：Web 服务中的 **SOAP 协议** 就使用 XML 作为通信格式。
###  2. **配置文件**
- 很多软件和框架用 XML 来**保存配置参数**。
- 示例：
    - Java 的 `web.xml` 用于配置 Java Web 应用。
    - `.NET` 中的 `app.config` / `web.config` 文件。
### 3. **网页与内容描述**
- 在网页中用于描述结构化内容，尤其是结合 XSLT（样式表转换）可以输出 HTML 或其他格式。
- 示例：RSS、Atom 等订阅源格式就是基于 XML。
### 4. **文档格式标准**
- 很多办公文档本质上是 XML，比如：
    - Microsoft Office 文件（.docx、.xlsx、.pptx）其实是 ZIP 压缩包，里面包含 XML 描述内容和格式。
    - OpenOffice、LibreOffice 的文档格式也是基于 XML。
### 5. **数据存储**
- **某些轻量级系统或嵌入式应用，会用 XML 文件代替数据库来存储数据**。
- 示例：配置数据、日志文件、小型数据库等。
### 6. **与其他技术结合**
- XML 可配合多种技术使用，例如：
    - **XSLT**：用于转换 XML 数据成 HTML 或其他格式。
    - **XPath/XQuery**：用于查询 XML 文档内容。
    - **DTD / XML Schema**：用于验证 XML 数据结构。
### 7. **跨平台/跨系统集成**
- 在企业级系统中，XML 是很多集成方案（如 ESB、消息中间件）的标准数据格式。


#### 在visual studio中使用Google浏览器打开xml格式的文档
类似在window中用对应的工具打开某种格式的文件，例如使用`Notepad++`打开`.txt`文件

![[Pasted image 20250530041218.png]]

下面是使用浏览器打开xml文件的步骤：

![[Pasted image 20250530041422.png]]

![[Pasted image 20250530041821.png]]



#### 标签对大小写敏感，且不允许标签交叉

![[Pasted image 20250530045630.png]]


#### 实体

像 HTML 一样，XML 为一些特别预留的符号定义了一些方法，称为实体（entities），例如用于标记的大于号。

| 实体       | 符号  | 描述    |
| -------- | --- | ----- |
| `&lt;`   | <   | 小于符号  |
| `&gt;`   | >   | 大于符号  |
| `&amp;`  | &   | 和     |
| `&quot;` | "   | 一个双引号 |
| `&apos;` | '   | 一个单引号 |
为什么会有实体呢？因为当编译器读取到`<`、`>`等符号的时候，会认为读取到了标签的开始和结束符号，为了避免这些冲突，所以使用实体代替这些符号

#### 属性就是描述标签自身的一些额外信息

![[Pasted image 20250530052531.png]]




![[Pasted image 20250530053307.png]]

```xml
<?xml version="1.0" encoding="utf-8"?>

<root>
	<![CDATA[写在这里的内容不会被xml解析，例如<、>、"、"等]]>
</root>
```

