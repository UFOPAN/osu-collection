  

Open sidebar

ChatGPT 3.5

![User](https://lh3.googleusercontent.com/a/AGNmyxb547KiF5lxmUn7Fjsb29Wjic-9zt514N3nIwLn=s96-c)

You

So, there is better way (imo) to start driver at Windows startup. This way nothing pops up at start and no GUI is loaded (only daemon starts). If you want to reconfigure tablet you're free to launch GUI App. Open WIN+R. Launch shell:startup Create new file OTD.vbs Paste following code: Set oShell = CreateObject ("Wscript.Shell") Dim OTDDaemonPath OTDDaemonPath = "X:\Your\Path\To\OpenTabletDriver.win-x64\OpenTabletDriver.Daemon.exe" oShell.Run OTDDaemonPath, 0, false Don't forget to change OTDDaemonPath to your path to OpenTabletDriver.Daemon.exe. You're good to go.

ChatGPT

ChatGPT

It seems like you've provided a script to run a program at Windows startup without displaying any GUI. This can be a useful method to run certain applications or services silently in the background. If you have any questions or if you'd like assistance with something specific related to this script or another topic, feel free to ask!

![User](https://lh3.googleusercontent.com/a/AGNmyxb547KiF5lxmUn7Fjsb29Wjic-9zt514N3nIwLn=s96-c)

You

如何创建OTD.vbs文件

ChatGPT

ChatGPT

创建一个 VBS（Visual Basic Script）文件相对简单。你可以使用文本编辑器，如Notepad，按照以下步骤创建 OTD.vbs 文件：

1. 打开文本编辑器，如Notepad。
2. 复制并粘贴以下代码到文本编辑器中：

vbsCopy code

`Set oShell = CreateObject("Wscript.Shell") Dim OTDDaemonPath OTDDaemonPath = "X:\Your\Path\To\OpenTabletDriver.win-x64\OpenTabletDriver.Daemon.exe" oShell.Run OTDDaemonPath, 0, false`

3. 将代码中的 `X:\Your\Path\To\OpenTabletDriver.win-x64\OpenTabletDriver.Daemon.exe` 替换为实际的 OpenTabletDriver.Daemon.exe 文件的路径。
    
4. 保存文件时，选择“另存为”（Save As），并将文件名设为 OTD.vbs。确保文件类型选择为“所有文件”（All Files）。
    
5. 选择保存的位置，最好保存在一个容易找到的地方。
    

现在，你已经创建了一个名为 OTD.vbs 的 Visual Basic Script 文件，其中包含运行 OpenTabletDriver.Daemon.exe 的代码。这个脚本可以在 Windows 启动时运行，启动 OpenTabletDriver.Daemon 而无需显示 GUI。

![User](https://lh3.googleusercontent.com/a/AGNmyxb547KiF5lxmUn7Fjsb29Wjic-9zt514N3nIwLn=s96-c)

You

Thank you very much for this To those who want to run OpenTabletDriver without GUI on Windows startup and with administrator privillages, you have to create a task in Task Scheduler and enable "run with highest privillages". Set it to run on login and then set the action to be to run "C:\System32\cscript.exe" and set the argument to be the location to the OpenTabletDriver.vbs script created here

ChatGPT

ChatGPT

You're welcome! That's a great additional tip for running scripts with administrator privileges using Task Scheduler. Task Scheduler indeed provides a flexible way to manage the execution of scripts and tasks on Windows, including running them with elevated privileges.

If you or anyone else has further questions or needs more assistance, feel free to ask. Happy scripting!

![User](https://lh3.googleusercontent.com/a/AGNmyxb547KiF5lxmUn7Fjsb29Wjic-9zt514N3nIwLn=s96-c)

You

如何实现

ChatGPT

ChatGPT

Sure, here are step-by-step instructions to create a task in Task Scheduler to run your VBScript with administrator privileges on Windows startup:

1. **Open Task Scheduler:**
    
    - Press `Win + S`, type "Task Scheduler," and press `Enter`.
2. **Create a Basic Task:**
    
    - In the Actions pane on the right side, click on "Create Basic Task."
3. **Name and Description:**
    
    - Enter a name and description for your task, then click "Next."
4. **Trigger:**
    
    - Choose "When I log on" and click "Next."
5. **Action:**
    
    - Select "Start a program" and click "Next."
6. **Program/script:**
    
    - Browse and select `C:\Windows\System32\cscript.exe` (cscript.exe is the Windows Script Host executable for running scripts).
7. **Add arguments (optional):**
    
    - In the "Add arguments (optional)" field, provide the full path to your VBScript file. For example: `"C:\Path\To\OTD.vbs"`.
8. **Start In (optional):**
    
    - If your script relies on a specific working directory, you can specify it in the "Start in (optional)" field.
9. **Finish:**
    
    - Review your settings and click "Finish."
10. **Run with highest privileges:**
    

- In the Task Scheduler Library, find your task.
- Right-click on your task and select "Properties."
- In the "General" tab, check the "Run with highest privileges" option.

11. **Test:**

- You can now test the task by right-clicking on it in Task Scheduler and selecting "Run." Ensure that your script runs as expected.

Now, your VBScript should run with administrator privileges on Windows startup. If you need further clarification on any step, feel free to ask!

![User](https://lh3.googleusercontent.com/a/AGNmyxb547KiF5lxmUn7Fjsb29Wjic-9zt514N3nIwLn=s96-c)

You

使用中文

ChatGPT

ChatGPT

当然，以下是在任务计划程序中创建任务，以在Windows启动时以管理员权限运行VBScript的逐步说明：

1. **打开任务计划程序:**
    
    - 按下 `Win + S`，键入 "任务计划程序"，然后按 `Enter`。
2. **创建基本任务:**
    
    - 在右侧的操作窗格中，单击 "创建基本任务"。
3. **命名和描述:**
    
    - 为任务输入名称和描述，然后单击 "下一步"。
4. **触发器:**
    
    - 选择 "当我登录时"，然后单击 "下一步"。
5. **操作:**
    
    - 选择 "启动程序"，然后单击 "下一步"。
6. **程序/脚本:**
    
    - 浏览并选择 `C:\Windows\System32\cscript.exe`（cscript.exe 是用于运行脚本的 Windows 脚本主机可执行文件）。
7. **添加参数 (可选):**
    
    - 在 "添加参数 (可选)" 字段中，提供您的VBScript文件的完整路径。例如："C:\Path\To\OTD.vbs"。
8. **起始位置 (可选):**
    
    - 如果您的脚本依赖于特定的工作目录，可以在 "起始位置 (可选)" 字段中指定。
9. **完成:**
    
    - 查看您的设置，然后单击 "完成"。
10. **以最高权限运行:**
    
    - 在任务计划程序库中找到您的任务。
    - 右键单击任务，选择 "属性"。
    - 在 "常规" 选项卡中，选中 "以最高权限运行" 选项。
11. **测试:**
    
    - 您现在可以通过右键单击任务计划程序中的任务并选择 "运行" 来测试任务。确保您的脚本按预期运行。

现在，您的VBScript应该会在Windows启动时以管理员权限运行。如果您对任何步骤有进一步的疑问，请随时提问！

ChatGPT can make mistakes. Consider checking important information.

?

要在运行 VBScript 脚本时不显示命令行窗口，你可以使用 `wscript.exe` 替代 `cscript.exe`。`wscript.exe` 是 Windows 脚本宿主的另一种形式，它会在后台运行脚本而不显示命令行窗口。

所以，你可以这样修改你的命令：

```
C:\Windows\System32\wscript.exe "C:\.Time Machine\3-Props\0-其他\IE\IE浏览器.vbs"
```

这样就可以在运行脚本时不显示命令行窗口了。