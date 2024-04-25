# 创建OpenTableDriver脚本

# `任务计划程序`

- 创建任务
	- 触发器选择`用户登陆`
	- 操作设为`启动程序`
		- 程序或脚本：`C:\Windows\System32\cscript.exe`
		- 添加参数：`"D:\Game\.Tool\OpenTabletDriver\OTD.vbs"`
			> 这个参数为脚本所在的位置
	- 保存


要在运行 VBScript 脚本时不显示命令行窗口，你可以使用 `wscript.exe` 替代 `cscript.exe`。`wscript.exe` 是 Windows 脚本宿主的另一种形式，它会在后台运行脚本而不显示命令行窗口。

所以，你可以这样修改你的命令：

```
C:\Windows\System32\wscript.exe "C:\.Time Machine\3-Props\0-其他\IE\IE浏览器.vbs"
```

这样就可以在运行脚本时不显示命令行窗口了。