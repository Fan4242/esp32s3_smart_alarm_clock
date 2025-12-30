# ESP-IDF 编译输出着色工具使用说明

## 简介

这个工具可以为 ESP-IDF 的编译输出添加颜色，使错误、警告、成功信息等更容易识别。

## 文件说明

- `colorize_build.sh` - 主要的着色脚本
- `build_aliases.sh` - 别名配置文件

## 使用方法

### 方法 1: 直接使用脚本（推荐）

```bash
# 编译时使用着色
./colorize_build.sh idf.py build

# 清理时使用着色
./colorize_build.sh idf.py clean

# 烧录时使用着色
./colorize_build.sh idf.py flash
```

### 方法 2: 使用别名（更方便）

```bash
# 加载别名配置
source build_aliases.sh

# 然后就可以使用简短的命令
cbuild      # 等同于 idf.py build（带颜色）
cclean      # 等同于 idf.py clean（带颜色）
cfullclean  # 等同于 idf.py fullclean（带颜色）
cflash      # 等同于 idf.py flash（带颜色）
cmonitor    # 等同于 idf.py monitor（带颜色）
call        # 等同于 idf.py build flash monitor (带颜色)
```

### 方法 3: 永久启用别名

将以下内容添加到 `~/.bashrc` 文件中：

```bash
# ESP-IDF 编译着色别名
source /home/fc/esp32_new/my_lvgl_1/build_aliases.sh
```

然后重新加载配置：
```bash
source ~/.bashrc
```

## 颜色说明

- **红色（加粗）**: 错误信息（error, failed 等）
- **黄色**: 警告信息（warning, deprecated, unused 等）
- **绿色（加粗）**: 成功信息（Successfully, complete, done 等）
- **青色**: 编译进度（Building, Compiling, Linking 等）
- **洋红色**: 文件名和路径（.c:, .h:, In file 等）
- **蓝色**: 数字和地址（0x..., bytes, size 等）

## 故障排除

如果颜色不显示，可以尝试：

1. 设置环境变量强制启用颜色：
   ```bash
   export FORCE_COLOR=1
   ./colorize_build.sh idf.py build
   ```

2. 检查终端是否支持颜色：
   ```bash
   echo $TERM
   # 如果不是 xterm, xterm-256color 等，脚本会自动设置
   ```

3. 如果是在 Cursor/VS Code 的集成终端中，确保终端类型设置正确。

## 注意事项

- 脚本会保持原始命令的退出码，所以可以安全地用于脚本中
- 如果终端不支持颜色，脚本会自动降级为无颜色输出
- 脚本会尝试自动检测和设置 TERM 环境变量

