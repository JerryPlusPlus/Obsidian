## C++代码片段文件保存位置

```shell
C:\Users\<你的用户名>\Documents\Visual Studio <版本>\Code Snippets\Visual C++\My Code Snippets\
```

![[导入的Viusal C++代码片段保存位置.png]]

`c.snippet`

```xml
<?xml version="1.0" encoding="utf-8"?>
<CodeSnippets xmlns="http://schemas.microsoft.com/VisualStudio/2005/CodeSnippet">
	<CodeSnippet Format="1.0.0">
		<Header>
			<Title>c</Title>
			<Shortcut>#1</Shortcut>
			<Description>c 初始化</Description>
			<Author>Microsoft Corporation</Author>
			<SnippetTypes>
				<SnippetType>Expansion</SnippetType>
				<SnippetType>SurroundsWith</SnippetType>
			</SnippetTypes>
		</Header>
		<Snippet>

			<Code Language="cpp">
				<![CDATA[#define _CRT_SECURE_NO_WARNINGS
			#include <stdio.h>
			#include <stdlib.h>
			#include <string.h>
			
            int main()
		{
			$selected$ $end$
            system("pause");
            return 0;
		}]]>
			</Code>
		</Snippet>
	</CodeSnippet>
</CodeSnippets>

```



`cpp.snippet`

```xml
<?xml version="1.0" encoding="utf-8"?>
<CodeSnippets xmlns="http://schemas.microsoft.com/VisualStudio/2005/CodeSnippet">
	<CodeSnippet Format="1.0.0">
		<Header>
			<Title>cpp</Title>
			<Shortcut>#2</Shortcut>
			<Description>c++ 初始化</Description>
			<Author>Microsoft Corporation</Author>
			<SnippetTypes>
				<SnippetType>Expansion</SnippetType>
				<SnippetType>SurroundsWith</SnippetType>
			</SnippetTypes>
		</Header>
		<Snippet>
			<Declarations>
			</Declarations>
			<Code Language="cpp">
				<![CDATA[#define _CRT_SECURE_NO_WARNINGS
			#include <iostream>
			#include <string>
			#include <vector>
			#include <set>
			#include <map>
			#include <unordered_set>
			#include <unordered_map>
			#include <list>
			#include <algorithm>
			#include <sstream>
			
			using namespace std;

            int main()
		{
			$selected$ $end$
            system("pause");
            return 0;
		}]]>
			</Code>
		</Snippet>
	</CodeSnippet>
</CodeSnippets>

```


![[代码片段选项卡.png]]
![[导入代码片段操作.png]]