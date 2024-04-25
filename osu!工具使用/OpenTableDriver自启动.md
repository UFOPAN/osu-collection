
---
# 创建OpenTableDriver脚本
1. 创建一个文本文件，后缀.txt改为.vbs，使用记事本或文本编辑器打开
2. 输入以下代码
```vb
Set oShell = CreateObject("Wscript.Shell")

Dim OTDDaemonPath

OTDDaemonPath = """D:\Game\.Tool\OpenTabletDriver\OpenTabletDriver.Daemon.exe"""

oShell.Run OTDDaemonPath, 0, false
```
>路径位置填入`OpenTabletDriver.Daemon.exe`所在位置，注意路径为三引号

3. 保存

---

# 设置任务计划程序

1. 创建任务
2. 触发器选择`用户登陆`
	- 操作设为`启动程序`
	- 程序或脚本：
		```
		C:\Windows\System32\cscript.exe
		```
	- 添加参数：
		```
		"D:\Game\.Tool\OpenTabletDriver\OTD.vbs"
		```
		> 这个参数为脚本所在的位置
3. 保存


