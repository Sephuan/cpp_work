# Neovim 竞赛环境快速上手

打竞赛专用的 neovim 环境,装在 `~/cpp_work`,只配了 Python(pypy3)。

## 启动

```bash
cd ~/cpp_work
nvim
```

第一次进会看到 dashboard,可以直接 `l` 开启题目监听,或 `f` 找文件。

## 导入题目

**两种方式,端口 27121 同一时间只有一个能监听:**

1. **在 nvim 里监听** —— 在 `~/cpp_work` 下打开 nvim 会自动监听,或者手动 `:CpListen`
   - cfapp 点"Push to VSCode Judge",选 Python
   - 浏览器 Competitive Companion 扩展也能推(Codeforces/AtCoder/Luogu 都支持)
   - 题目自动建在 `CF/<比赛名>/<题目名>.py`,带 2-3 个样例

2. **在 VSCode 里监听** —— 关掉 nvim 的监听(`:CpStopListen`),让 VSCode 插件占端口
   - VSCode 设置里把 `codeforces.general.defaultLanguage` 改成 `"none"` 或留空
   - 每次导入会弹语言选择器(cpp/python/java/...)
   - 模板自动按语言走:`~/cpp_work/templates/template.py` 或 `template.cpp`
   - **已有代码的文件不会被覆盖** —— re-import 只更新测试点,不动源文件

## 快捷键(竞赛核心)

### 评测 & 做题

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `<leader>cr`      | 跑当前文件的所有测试点(本地 judge)     |
| `<leader>cx`      | 取消当前运行                           |
| `<leader>ca`      | 手动添加一个测试点(交互式输入)         |
| `<leader>cu`      | 查看题目 URL                           |
| `<leader>cs`      | 查看状态(监听/题目/测试点数量)         |

评测面板快捷键(`:CpPanel` 或自动弹出):
- `<CR>` / `<Tab>` — 展开/折叠当前测试点的输入输出
- `r` — 重跑所有测试点
- `a` — 添加测试点
- `d` — 删除当前测试点
- `i` — 复制当前测试点的输入
- `o` — 复制当前测试点的实际输出
- `q` — 关闭面板

### Git 提交

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `<leader>gc`      | 快速提交+推送(自动填题目名作 commit msg)|
| `<leader>gg`      | 打开 lazygit(完整 Git TUI)             |
| `<leader>gs`      | 暂存当前文件的改动                     |
| `<leader>gr`      | 重置当前文件的改动                     |
| `<leader>gp`      | 预览 hunk                              |
| `<leader>gb`      | 查看当前行的 blame                     |
| `]h` / `[h`       | 跳到下一个/上一个改动块                |

### 文件 & 查找

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `<leader>ff`      | 查找文件(模糊搜索)                     |
| `<leader>fg`      | 全局搜索内容                           |
| `<leader>fc`      | 在 CF/ 目录下查找文件                  |
| `<leader>fb`      | 切换已打开的 buffer                    |
| `<leader>e`       | 文件树(NvimTree)                       |
| `<S-h>` / `<S-l>` | 前一个/后一个 buffer                   |
| `<C-s>`           | 保存(任何模式下)                       |

### 窗口 & 导航

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `<C-h/j/k/l>`     | 切换到左/下/上/右窗口                  |
| `<C-w>v`          | 垂直分屏                               |
| `<C-w>s`          | 水平分屏                               |
| `<C-\\>`          | 打开浮动终端                           |

### 编辑

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `gcc`             | 注释/取消注释当前行                    |
| `gc` (visual)     | 注释/取消注释选中                      |
| `<leader>p` (vis) | 粘贴但不覆盖剪贴板                     |
| `J/K` (visual)    | 向下/向上移动选中行                    |

### LSP(Python only)

| 键位              | 功能                                   |
|-------------------|----------------------------------------|
| `gd`              | 跳到定义                               |
| `gr`              | 查看引用                               |
| `K`               | 悬停文档                               |
| `<leader>rn`      | 重命名                                 |
| `<leader>la`      | 代码动作                               |
| `<leader>lf`      | 格式化                                 |
| `]d` / `[d`       | 下一个/上一个诊断                      |

## 命令速查

| 命令                  | 功能                                   |
|-----------------------|----------------------------------------|
| `:CpRun`              | 运行测试                               |
| `:CpStop`             | 停止运行                               |
| `:CpAddTest`          | 添加测试点                             |
| `:CpNew`              | 手动新建题目文件(不导入)               |
| `:CpListen`           | 开启 Companion 监听                    |
| `:CpStopListen`       | 停止监听(让给 VSCode)                  |
| `:CpStatus`           | 显示状态                               |
| `:CpTemplate`         | 插入模板到光标位置                     |
| `:CpEditTemplate`     | 编辑模板                               |
| `:CpInstallTemplates` | 把内置模板写到 `~/cpp_work/templates/`|
| `:LazyGit`            | 打开 lazygit                           |

## 判定说明

本地 judge 用 pypy3 跑测试点,判定规则:

- **AC** — 输出完全正确(忽略行尾空格)
- **WA** — 输出错误
- **PE** — Presentation Error:数字对但格式不对(多半是空格/换行写错)
- **TLE** — 超时(Python 默认 4 秒)
- **RE** — 运行时错误(崩溃 / 非零退出)
- **CE** — 编译错误(Python 极少遇到,除非语法炸了)

面板里 AC 的自动折叠,失败的自动展开 diff,省得手动翻。

## 模板系统

**优先级:项目模板 > 全局设置**

1. **推荐**:`~/cpp_work/templates/template.py` 和 `template.cpp`
   - 自动按文件后缀选
   - 支持占位符:`$NAME` `$URL` `$CONTEST` `$DATE`
   - 首次运行 `:CpInstallTemplates` 会写入内置模板,之后随便改

2. VSCode 全局设置(fallback):
   - `codeforces.general.defaultLanguageTemplateFileLocation`
   - 只在项目模板不存在时才用

## 美化 & 丝滑

- **光标拖尾** —— kitty 原生 GPU 绘制,终端级流畅(不是 Lua 卡顿方案)
  - 配置在 `~/.config/kitty/kitty.conf`,已经调好
  - 只有移动 ≥2 格才触发,不会逐字输入时满屏拖影
- **平滑滚动** —— `<C-d>/<C-u>/gg` 都有缓动,不再跳跃
- **主题** —— Catppuccin Mocha + 透明背景(0.9),配合 kitty 磨砂感
- **状态栏** —— 显示当前比赛名(从 meta.json 读),一眼看清在哪场
- **通知** —— 右上角浮动提示(测试通过/Git 推送成功)

## 环境路径

- **neovim** → `~/.local/bin/nvim`
- **pypy3** → `~/.local/bin/pypy3`
- **lazygit** → `~/.local/bin/lazygit`
- **配置** → `~/.config/nvim/`
- **插件** → `~/.local/share/nvim/lazy/`
- **题目** → `~/cpp_work/CF/<比赛名>/<题目>.py`
- **测试点** → `~/cpp_work/CF/<比赛名>/.cp/<题目>/N.in` + `N.out`

所有东西都在 `~/.local` 和 `~/.config`,零 sudo,卸载直接 `rm -rf` 这俩目录。

## Troubleshooting

**端口冲突** —— `:CpListen` 报 `EADDRINUSE`
  - VSCode 正开着占端口 27121
  - 要么关 VSCode,要么在 nvim 里 `:CpStopListen`

**LSP 不生效**
  - `:Mason` 检查 pyright/ruff 是否安装
  - `:LspInfo` 看是否 attach 到当前 buffer

**Treesitter 高亮失效**
  - `:TSInstall python` 手动装 parser
  - `:checkhealth nvim-treesitter` 看诊断

**测试点丢了**
  - 测试点在 `.cp/` 隐藏文件夹,re-import 会覆盖
  - 想保留手动添加的测试点,先备份 `.cp/<题目>/`

**Git 推送要密码**
  - 确认 `git config --global credential.helper` 是 `store`
  - `~/.git-credentials` 里应该有 GitHub token

## 进阶

- **自定义键位** → `~/.config/nvim/lua/config/keymaps.lua`
- **改主题** → `~/.config/nvim/lua/plugins/ui.lua`,换 `catppuccin` 的 flavour
- **调时限** → `~/.config/nvim/lua/cp/init.lua`,改 `time_limit_ms`
- **加语言** → 同一文件,`langs` 里加条目(需要写 compile/run 命令)
