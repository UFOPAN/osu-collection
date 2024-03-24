> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [zhuanlan.zhihu.com](https://zhuanlan.zhihu.com/p/131325579)

LoadRunner 是软件测试利器。

**本教程可以帮你完成一次软件测试实验。**

**题目：**

使用 LoadRunner 自带的测试项目 -- 航班订票管理系统 WebTours，网站地址为：[http://127.0.0.1:1080/WebTours/](https://link.zhihu.com/?target=http%3A//127.0.0.1%3A1080/WebTours/)(用户名为 jojo，密码为 bean), 完成性能测试，要求：

1、 虚拟用户为 10；

2、 每隔 15s 启动 2 个 Vusers；

3、 运行时间为 5min；

4、 每隔 15s 停止 2 个 Vusers；

5、在分析工具中自定义一个图形。

下载
--

链接你不需要找了，我已经给你找好了。

[LoadRunner 12 链接](https://link.zhihu.com/?target=https%3A//shimo.im/docs/XJTJVRwPy6yYTXp9/)

《LoadRunner 12 链接》，可复制链接后用石墨文档 App 或小程序打开

安装
--

下载解压后应该是这个样子的

![](https://pic1.zhimg.com/v2-e03ea911fcf406866c700480af454240_r.jpg)![](https://pic2.zhimg.com/v2-98c569bac0a4de9207d2c020ff6d31f5_r.jpg)

选好安装位置点击 Install

![](https://pic3.zhimg.com/v2-d9fbf711fc58351aa3c71c6672e0c70a_r.jpg)

安装好之后还提示安装运行依赖库 **直接点击确定**

![](https://pic3.zhimg.com/v2-049a89e0b1dcc305b5ea69f0b3312faa_r.jpg)![](https://pic3.zhimg.com/v2-3269453803bf64635047cef3c1849e42_r.jpg)

同样，直接点确定

![](https://pic1.zhimg.com/v2-636cc7ceb6f9e4bd21f3437675b1482c_r.jpg)

这里需要选择第一个 **从网上下载**

![](https://pic3.zhimg.com/v2-b8de114acaf3ac057e06109e72383dae_r.jpg)![](https://pic2.zhimg.com/v2-4a31ce1513316f14f1e14372eb9d538d_r.jpg)

运行依赖库安装好后就会出现安装向导

![](https://pic1.zhimg.com/v2-fa9e61d01faf34ef63c2a97548e82e9c_r.jpg)

选择好路径 点击安装

![](https://pic2.zhimg.com/v2-23c3c8d495c8e6337790593c5ff4e1a5_r.jpg)

我的安装目录

![](https://pic3.zhimg.com/v2-c3667da9fa1dc83185effb52fc8e222a_r.jpg)

等待安装

![](https://pic1.zhimg.com/v2-5b1845d77d39639759ee12cd924609cc_r.jpg)

**取消勾选指定 LoadRunner 代理将要使用的证书 后点下一步**

![](https://pic4.zhimg.com/v2-5e0f1c5f94e6bd5403f6406a93d0edb7_r.jpg)![](https://pic2.zhimg.com/v2-8947c1b12fe68d79872cbbd2b2dc33cd_r.jpg)

在桌面已经生成了快捷方式

![](https://pic2.zhimg.com/v2-b528e37ac4b93c5dcdeacde801ad6d95_r.jpg)

**安装完成！！！**

必知必会
----

**LoadRunner 的组件**：

*   Virtual User Generator—虚拟用户生成器
*   LoadRunner Controller—创建、运行和监控场景
*   LoadRunner Analysis—分析测试结果

**官方使用指南**

我们可以结合官方的使用指南进行学习

![](https://pic2.zhimg.com/v2-c20f4baf257659970c0efce135402d75_r.jpg)

LoadRunner 相关的术语：

![](https://pic4.zhimg.com/v2-53337b82e150f481f6a41b3148dc3763_r.jpg)

*   **Scenario(场景)** 定义测试阶段出现的事件，基于性能需求
*   **Virtual Users or Vusers** Vusers 模拟用户在你的系统上操作的动作。一个场景可以包含几十，上百，甚至上千的虚拟用户。
*   **Vuser Script(脚本)** 记录你的应用程序中执行业务流程的动作
*   Protocal 协议是客户端和服务器之间交流的方式
*   **Transaction(事务)** 你所定义的事务，用于测试你的系统性能。一个事务代表一个或多个终端用户的业务流程。一个事务允许你测试这些业务流程花费了多长时间。

**LoadRunner 负载测试的流程是什么？**

1.  Plan the load test **计划负载测试**
2.  Create Vuser scripts **创建脚本**
3.  Define the scenario **定义场景**
4.  Analyze the results **分析结果**

第一个例子
-----

**启动 HP WebTours 服务器**

1.  快捷键 **Win+S 搜索 Start HP**

![](https://pic1.zhimg.com/v2-f1761c93e20055dc4a03cf79eec4771c_r.jpg)![](https://pic4.zhimg.com/v2-8cf25f170ee23d2193f44377c73061a3_r.jpg)

你也可以根据路径找到该文件

```
C:\ProgramData\Microsoft\Windows\Start Menu\Programs\HP Software\HP LoadRunner\Samples\Web
```

![](https://pic2.zhimg.com/v2-56722d38f063ea592cf0e8037f0b9f29_r.jpg)

2. 双击启动服务器

![](https://pic4.zhimg.com/v2-b2052b7ae13220db3625860ac846988f_r.jpg)

不出意外你会看到这样的命令行窗口

![](https://pic4.zhimg.com/v2-e614f65d88bcd18de40e69bd74193fef_r.jpg)

造成该问题的原因是服务器未配置 ip 地址，解决办法就是给它配置咯

**所以接下来我要做一件事情**

在 LoadRunner 的安装位置找到 WebTours 文件夹 并双击进入

![](https://pic1.zhimg.com/v2-84d1652acdf4c259f9966fbf57fbd104_r.jpg)![](https://pic2.zhimg.com/v2-1e66172d2ad0537e87f5d88ba3ce2d2d_r.jpg)![](https://pic4.zhimg.com/v2-beedfc2a7b0f8823afa29f98a6326d7b_r.jpg)![](https://pic2.zhimg.com/v2-50054740f2020f23531ca528f8bcc511_r.jpg)![](https://pic2.zhimg.com/v2-555ec477fcb4d8ca398c6b46682e79b1_r.jpg)

再次重复 双击 Start HP Web Tours Server

![](https://pic3.zhimg.com/v2-2bbc8fa33e01ae30f64a7c31c1b5f01a_r.jpg)

这样就表示已经成功启动啦

**注意：需要保持这个命令行窗口状态，如果关闭就代表关闭服务器。**

然后我们再双击 **HP Web Tours Application**

![](https://pic2.zhimg.com/v2-ef0149dbd69ba9b3309d27c268d4e4d5_r.jpg)

能够成功访问网页了。

登录测试

Username:**jojo**

Password:**bean**

![](https://pic4.zhimg.com/v2-e694f42eedfebd216a95538aa6298e4b_r.jpg)

录制脚本
----

1. 启动 Virtual User Generator

![](https://pic3.zhimg.com/v2-4b1f30f84cbc66a3be77cc1d33dd5346_r.jpg)

2. 新建脚本和解决方案

![](https://pic4.zhimg.com/v2-24c2172ba0c877ed6887b36400dd2d0b_r.jpg)

3. 选择 Web-HTTP/HTML

![](https://pic4.zhimg.com/v2-5fc3b348655a2ad8c66dea6d557d8b1b_r.jpg)

4. 创建好之后是这个样子的

![](https://pic2.zhimg.com/v2-d5bba58b5d17863ed29de67eec584311_r.jpg)

此时，解决方案是一个空的脚本。

*** 如果你的左侧没有 Solution Explorer（解决方案资源管理器）。**

不要慌，很简单，一下就能解决。

![](https://pic4.zhimg.com/v2-38aab3a916d0380748466ae77ccef007_r.jpg)

**开始录制**

1. 点击 Record>Record

![](https://pic1.zhimg.com/v2-1b4baf638fff9d639d89411274e53a40_r.jpg)

2. 填入 URL 地址

```
http://localhost:1080/WebTours
```

其他选项保持默认，但需要与我保持一致。

![](https://pic2.zhimg.com/v2-f6d7f9c4c5a6e4eb123891bb1e7e45c9_r.jpg)![](https://pic1.zhimg.com/v2-fdea79e02798eafe240e9936fb9b4aac_r.jpg)

开始录制

![](https://pic3.zhimg.com/v2-65253162a2ad029ad35dda2400828d7e_r.jpg)![](https://pic2.zhimg.com/v2-632e59e969d9033589f25231e9686f09_r.jpg)![](https://pic4.zhimg.com/v2-ad79a0ae02a76a44cdc1922198458f73_r.jpg)

此时已经开始录制了。

你需要进行以下动作：

**用户名登录**

![](https://pic3.zhimg.com/v2-e263faf71e35d4fe141a909ee22ed652_r.jpg)

**进入航班详情**

![](https://pic2.zhimg.com/v2-071545a61d446cf656f879c3cbdaaf29_r.jpg)![](https://pic3.zhimg.com/v2-fcd83410efc293bfc9550056eaf29766_r.jpg)

**选择航班**

![](https://pic1.zhimg.com/v2-11f7fb724869c4d39069cf026f2cc9a0_r.jpg)![](https://pic2.zhimg.com/v2-944dd61b89dc2a8e1033481a1f58cae9_r.jpg)

**进入订单详情**

![](https://pic1.zhimg.com/v2-8db068e6ae6bcf15b241d5e98de45bfc_r.jpg)![](https://pic4.zhimg.com/v2-73869c437d4e8608fcfe31399ed6649b_r.jpg)

**查看日程**

![](https://pic3.zhimg.com/v2-102daca39b32798efe5fd03cbfb1076a_r.jpg)

**停止录制**

![](https://pic4.zhimg.com/v2-c75862ed97bb30c7375db18159991017_r.jpg)![](https://pic2.zhimg.com/v2-3e4c02b2fde788c23f578e2eb4b20349_r.jpg)

**查看脚本**

步骤导航

![](https://pic1.zhimg.com/v2-28594c4ade11b93dd72eaa866801b1d8_r.jpg)

重播脚本
----

**Runtime Settings**

![](https://pic4.zhimg.com/v2-d95f3935b919939c5ac11b8a250a02fb_r.jpg)![](https://pic2.zhimg.com/v2-5095567887b7635d18abfdf233097e49_r.jpg)

**设置迭代次数**

![](https://pic4.zhimg.com/v2-3b4e2235e96d67829fba0bdf167c9c13_r.jpg)

**设置步调**

![](https://pic4.zhimg.com/v2-3644c64b15cad749e1eb83cdb5591543_r.jpg)

**选择无代理**

![](https://pic3.zhimg.com/v2-dc4a12bad4def78b16542769a27914f2_r.jpg)

运行

![](https://pic2.zhimg.com/v2-c032cb55289806f9feacc3543b30c17d_r.jpg)

Nice！

![](https://pic1.zhimg.com/v2-9fdb974d69aefd0915e6e9399dacfbf8_r.jpg)

怎么办？不用怕。

解决常见的重播问题
---------

**打开 Web Tours 主页**

![](https://pic3.zhimg.com/v2-bb4149291b469c6c313252d447807066_r.jpg)![](https://pic1.zhimg.com/v2-1e1589b5959fd77325edd00ea6c59eec_r.jpg)

回到主页

![](https://pic2.zhimg.com/v2-0c60c92d315b783071a83cc1cb05ff0d_r.jpg)

使用 Controller 打开解决方案
--------------------

**启动 Controller**

![](https://pic4.zhimg.com/v2-8b09324d83551f1d81f568eb5918895b_r.jpg)

**新建场景**

![](https://pic2.zhimg.com/v2-aa12f7cfc33d1cf0586c1db7e4b79ec9_r.jpg)

**开启场景**

![](https://pic1.zhimg.com/v2-dbf35a9e8c5c8df4184d060dd7954720_r.jpg)

**出现错误**

![](https://pic4.zhimg.com/v2-2a78cd3adebe7af334df8c753d725c7b_r.jpg)

不用害怕

接下来我们要做一些事情

**查询本机 IP**

![](https://pic3.zhimg.com/v2-f92cc3f47886ae916c0b848142a822a2_r.jpg)![](https://pic1.zhimg.com/v2-dc16483e27af6360081141b0c84a52d4_r.jpg)![](https://pic4.zhimg.com/v2-6cb3aa595f2ac5fe8f7401629df7ba7f_r.jpg)

**再次开启场景**

![](https://pic2.zhimg.com/v2-75163955327f2d19e8ee09f876febeed_r.jpg)

**开始运行**

![](https://pic4.zhimg.com/v2-100af01e02c71c672b391293e54ffbb3_r.jpg)

**分析总结**

![](https://pic4.zhimg.com/v2-5cc92250652e875ed0ca8794f18fa43b_r.jpg)

Nice！Nice！Nice！

你已经入门啦！