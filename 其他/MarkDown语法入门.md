标题
---------------------------

# 标题1

## 标题2

### 标题3

样式
---------------------------

*强调* _强调_

**加粗** __加粗__

==标记文本==

~~删除线文本~~

> 块引用文本

H~2~O是一种液体

2^10^是1024

列表
---------------------------

- 列表项
  * 列表项
    + 列表项

1. 列表项 1
2. 列表项 2
3. 列表项 3

- [ ] 未完成项
- [x] 已完成项

链接
---------------------------

一个[链接](http://example.com).

一张图片: ![图片描述](img.jpg)

一张调整大小的图片: ![图片描述](img.jpg =60x50)

代码
---------------------------

一些`行内代码`.

```
// 一个代码块
var foo = 'bar';
```

```javascript
// 一个高亮代码块
var foo = 'bar';
```

表格
---------------------------

| Item     | Value |
| -------- | ----- |
| Computer | $1600 |
| Phone    | $12   |
| Pipe     | $1    |

| Column 1 | Column 2      |
|:--------:| -------------:|
| centered | right-aligned |

定义列表
---------------------------

Markdown
:  文本到HTML转换工具

作者
:  张三
:  李四

脚注
---------------------------

一些带有脚注的文本。[^1]

[^1]: 脚注内容。

缩写
---------------------------

Markdown将文本转换为 HTML。

*[HTML]: 超文本标记语言

LaTeX数学表达式
---------------------------

满足 $\Gamma(n) = (n-1)!\quad\forall
n\in\mathbb N$ 的Gamma函数是通过欧拉积分

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$




# 标题2

## 标题3

>这是一段引用
>引用通过回车换行

## 有序列表
1. 需要在后面加上空格
2. 使用回车换行

## 无序列表
- 使用短横线 - 来显示
- 依然要加空格在后面
* 也可以使用 * 来显示

## 任务列表
- [ ] 短横线 + 空格 + 中括号左 + 空格 + 中括号右 + 空格
- [ ] 在空格中间写上 X 打勾
- [x] 例如这样

## Markdown双链接
[使用一个中括号+一个圆括号，括号里面写上网址]([哔哩哔哩](https://www.bilibili.com/)))
[括号内只能有网址，不能存在其他的文本，不然无法跳转](https://www.bilibili.com/))
[哔哩哔哩](https://www.bilibili.com/)
直接粘贴进来的网址会自动生成名称，可以修改这个名称

## 在双链接前加上一个感叹号
用于生成预览
![可以用于生成视频预览，和Onenote一样](https://www.youtube.com/watch?v=4P2kJWhvAWQ)



## 标签的用法
#学习

---
## 分割线

---

## 代码块
```cpp
#include <iostrem>
using namespace std;

int main()
{
	cout<<"helloword!"<<endl;
	return 0;
}
```

~~~ python
import pandas as pd
print('helloworld!')
~~~

波浪线也可以用


## 数学公式

$$ \frac{\partial f}{\partial x}=2\sqrt{a} x $$


## 表格
| 表格头         |        格式要求 |   得画的像个表格    |
| :---------- | ----------: | :----------: |
| 冒号放在左边表示左对齐 | 冒号放在右边表示右对齐 | 冒号放在两边表示居中对齐 |


## 脚注
脚注的内容[^脚注的名称]

[^脚注的名称]:：脚注的解释，放在其他地方

一键三连[^三连]

[^三连]:脚注的解释


这是一个脚注 [^1]。

[^1]: 参考文献1


## 链接
似乎不支持悬浮显示标题
[百度](https://www.baidu.com/ "标题")

[链接文字](链接地址 "Title")

可以打开文件，记得去掉两端双引号
[打开文件](file:C:\Users\Hanataba\OneDrive\图片\插图\7a3747a171b2746556273fa425919831.jpg)

显示图片，指定外部链接
![打开文件](file:C:\Users\Hanataba\OneDrive\图片\插图\7a3747a171b2746556273fa425919831.jpg)

### 引用链接

[百度][id]

	[id]:https://www.baidu.com

Obsidian似乎没有这个功能
> 链接的对象可以是标题，可以是段落，可以是代码块

## 文本格式
*单个星号表示斜体*
**两个星号表示加粗，再打两个星号结束加粗**
	** 使用空格使其无效
	* 斜体 *
	**选中文本，直接输入星号，使其变为加粗**
	*英文的斜体还蛮好看的*
	*English Fonts looks good*
<u> 下划线 </u>
`行内代码printf()`
:smile: 表情符号
行内数学公式
$  \frac{\partial f}{\partial x}=2\sqrt{a} x  $

H~2~O，H^2 
==高亮==

![fdaffdaf](https://www.bilibili.com/video/BV1JA411h7Gw\)

Markdown将文本转换为 HTML。

*[HTML]: 超文本标记语言

# 来自其他的文档

## 标题2

### 标题3

样式
---------------------------

*强调* _强调_

**加粗** __加粗__

==标记文本==

~~删除线文本~~

> 块引用文本

H~2~O是一种液体

2^10^是1024

列表
---------------------------

- 列表项
  * 列表项
    + 列表项

1. 列表项 1
2. 列表项 2
3. 列表项 3

- [ ] 未完成项
- [x] 已完成项

链接
---------------------------

一个[链接](http://example.com).

一张图片: ![图片描述](img.jpg)

一张调整大小的图片: ![图片描述](img.jpg =60x50)

代码
---------------------------

一些`行内代码`.

```
// 一个代码块
var foo = 'bar';
```

```javascript
// 一个高亮代码块
var foo = 'bar';
```

表格
---------------------------

| Item     | Value |
| -------- | ----- |
| Computer | $1600 |
| Phone    | $12   |
| Pipe     | $1    |

| Column 1 | Column 2      |
|:--------:| -------------:|
| centered | right-aligned |

定义列表
---------------------------

Markdown
:  文本到HTML转换工具

作者
:  张三
:  李四

脚注
---------------------------

一些带有脚注的文本。[^1]

[^1]: 脚注内容。

缩写
---------------------------

Markdown将文本转换为 HTML。

*[HTML]: 超文本标记语言

LaTeX数学表达式
---------------------------

满足 $\Gamma(n) = (n-1)!\quad\forall
n\in\mathbb N$ 的Gamma函数是通过欧拉积分

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$