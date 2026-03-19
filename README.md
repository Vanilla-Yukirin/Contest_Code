# README：我的 VS Code + clang++ 竞赛 C++ 工作流

我现在采用的是多阶段法，核心目标是：

* 纯 Windows
* VS Code 写题
* clang++ 编译
* CPH 抓题和测样例
* 支持模板、快捷编译、快捷运行、debug

## 0. 如何使用万能头？

有两种方式：

### 方式 1：直接放到 clang++ 搜索路径下

我目前是这样做的：

```text
C:\Program Files\LLVM\lib\clang\22\include\bits\stdc++.h
```

这样就可以直接继续写：

```cpp
#include <bits/stdc++.h>
```

### 方式 2：通过 `-I` 指定公共头文件目录

也可以在编译参数里加：

```text
-I D:\Github\Contest_Code\common
```

然后把万能头放到：

```text
D:\Github\Contest_Code\common\bits\stdc++.h
```

## 1. 模板怎么生成？

模板来源于根目录下这两个文件：

* `template.cpp`
* `template_no_vars.cpp`

其中：

* `template.cpp`：给我自己的 snippet 用
* `template_no_vars.cpp`：给 CPH 自动生成代码用

之所以要分成两个，是因为 **CPH 不支持填充日期和路径这两个变量**，所以只能专门准备一个 `no_vars` 版本。

## 2. 模板怎么使用？

使用 `create_template.py`，它会生成 `cp.code-snippets`。

然后在 VS Code 里：

* 按 `Ctrl + Shift + P`
* 搜索 `Preferences: Configure User Snippets`
* 选择 `cpp.json`
* 把生成好的 snippet 放进去

这样以后无论在哪里，都可以直接输入：

```text
cp
```

然后展开生成代码模板，并且还会自动带上：

* 日期时间戳
* 题号

## 3. 如何编译？

默认编译快捷键是：

```text
Ctrl + Shift + B
```

它的原理是调用 `tasks.json`。

如果存在**用户级别**的 task，那么会优先走用户级别的 task，而不是临时让 VS Code 自动生成。

所以这里要做的是：

* 按 `Ctrl + Shift + P`
* 搜索 `Tasks: Open User Tasks`
* 编辑用户级别的 `tasks.json`

我已经写好了。
这套编译参数里会自动带上：

```text
-DTH
```

## 4. 如何使用 CPH？

### 基本流程

1. 先手动创建好比赛文件夹
2. 再用 VS Code 打开这个比赛文件夹作为工作区
3. 然后正常使用 CPH

注意：**不要直接在 Contest_Code 根目录开着然后乱抓题**，不然 CPH 会把文件生成到根目录。

### 我当前的 CPH 配置

#### 代码模板自动生成

```json
"cph.general.defaultLanguage": "cpp",
"cph.general.defaultLanguageTemplateFileLocation": "D:\\Github\\Contest_Code\\template_no_vars.cpp"
```

#### 代码编译命令

```json
"cph.language.cpp.Command": "clang++",
"cph.language.cpp.Args": "-std=c++20 -O2 -Wall -Wextra -Wshadow -I D:\\\\Github\\\\Contest_Code\\\\common"
```

这里的：

```text
-I xxx
```

其实可以去掉。
因为我已经把万能头放到了 clang++ 搜索路径下：

```text
C:\Program Files\LLVM\lib\clang\22\include\bits\stdc++.h
```

所以这项现在对我来说可有可无。

## 5. 如何编译并运行？

和编译同理。

因为我在 `tasks` 里面额外配置了一个“编译 + 运行”的 task，
所以只需要在 `keybindings.json` 里面再绑定一个快捷键就行。

例如：

```json
[
  {
    "key": "ctrl+f5",
    "command": "workbench.action.tasks.runTask",
    "args": "build and run active file"
  }
]
```

这样以后：

* `Ctrl + Shift + B`：编译
* `Ctrl + F5`：编译并运行

## 6. 如何 debug？

可以用：

* 右上角的调试按钮
* 或者直接按 `F5`

### 但是注意

在我这边，**直接用 clang++ 那套默认调试链会有问题**。
所以我最终采用的是：

```text
cppvsdbg
```

来调试。

### 正确做法

请在当前比赛文件夹里新建：

```text
.vscode/launch.json
```

然后把：

```text
Contest_Code/.vscode/launch.json
```

里面的内容，也就是：

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug active C++ file (clang + cppvsdbg)",
      "type": "cppvsdbg",
      "request": "launch",
      "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "console": "integratedTerminal",
      "preLaunchTask": "clang++ build active file"
    }
  ]
}
```

复制进去。

接着点击右上角的调试，选择这个配置：

```text
Debug active C++ file (clang + cppvsdbg)
```

并且确保它里面的：

```text
preLaunchTask: clang++ build active file
```

是存在的。

### 为什么一定要这样？

因为：

* **必须用 `cppvsdbg`**
* 不能走默认那套 `lldb / clang++` 调试方式
* 不然会报错，之前已经踩过坑了

另外，这里的：

```text
preLaunchTask
```

是依赖于你前面配置好的**用户级 task** 的。

### 关于 `-DTH`

debug 时默认是不带 `-DTH` 的。

我个人觉得这很合理，因为都进入 debug 了，已经可以直接看变量和流程了，也不太需要再输出这些中间调试信息。

# 总结

我的当前工作流是这样的：

* **模板**：`template.cpp / template_no_vars.cpp`
* **模板展开**：用户级 snippet
* **编译**：用户级 `tasks.json`
* **运行**：用户级 task + `Ctrl + F5`
* **CPH**：只在比赛文件夹内使用
* **debug**：必须走 `cppvsdbg + launch.json`
* **万能头**：放到 clang++ 搜索路径，或者走 `-I common`

如果后面这套流程还有变化，我再继续更新这个 README。
