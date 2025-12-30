#!/bin/bash
# ESP-IDF 编译输出着色脚本
# 使用方法: 
#   1. ./colorize_build.sh idf.py build
#   2. 或者使用别名: cbuild (需要先 source build_aliases.sh)

# 设置 TERM 环境变量以支持颜色
if [ "$TERM" = "dumb" ] || [ -z "$TERM" ]; then
    export TERM=xterm-256color 2>/dev/null || export TERM=xterm
fi

# ANSI 颜色代码定义
RED='\033[0;31m'           # 红色 - 用于错误
GREEN='\033[0;32m'         # 绿色 - 用于成功信息
YELLOW='\033[1;33m'        # 黄色 - 用于警告
BLUE='\033[0;34m'          # 蓝色 - 用于信息
MAGENTA='\033[0;35m'       # 洋红色 - 用于文件名
CYAN='\033[0;36m'          # 青色 - 用于进度信息
BOLD='\033[1m'             # 粗体
RESET='\033[0m'            # 重置颜色

# 检查是否在支持颜色的终端中运行
USE_COLOR=false
if [ -t 1 ] && command -v tput >/dev/null 2>&1; then
    if [ "$(tput colors)" -ge 8 ]; then
        USE_COLOR=true
    fi
fi

# 如果强制启用颜色（通过环境变量）
if [ "$FORCE_COLOR" = "1" ] || [ "$FORCE_COLOR" = "true" ]; then
    USE_COLOR=true
fi

# 执行命令并着色输出
"$@" 2>&1 | while IFS= read -r line || [ -n "$line" ]; do
    if [ "$USE_COLOR" = true ]; then
        # 错误信息 - 红色加粗
        if echo "$line" | grep -qiE "(error:|Error|ERROR|failed|Failed|FAILED|stopped|Stopped)"; then
            echo -e "${RED}${BOLD}${line}${RESET}"
        # 警告信息 - 黄色
        elif echo "$line" | grep -qiE "(warning:|Warning|WARNING|deprecated|Deprecated|unused|Unused)"; then
            echo -e "${YELLOW}${line}${RESET}"
        # 成功信息 - 绿色加粗
        elif echo "$line" | grep -qiE "(Successfully|successfully|SUCCESS|complete|Complete|done|Done|Project build complete)"; then
            echo -e "${GREEN}${BOLD}${line}${RESET}"
        # 编译进度 - 青色
        elif echo "$line" | grep -qE "(\[.*/.*\]|Building|Compiling|Linking|Generating|Executing)"; then
            echo -e "${CYAN}${line}${RESET}"
        # 文件名和路径 - 洋红色
        elif echo "$line" | grep -qE "(\.c:|\.h:|\.cpp:|\.hpp:|\.c\.obj|In file included|from|../.*\.c|../.*\.h)"; then
            echo -e "${MAGENTA}${line}${RESET}"
        # 十六进制地址和大小 - 蓝色
        elif echo "$line" | grep -qE "(0x[0-9a-fA-F]+|bytes|size)"; then
            echo -e "${BLUE}${line}${RESET}"
        # 其他信息 - 默认颜色
        else
            echo "$line"
        fi
    else
        # 不支持颜色时直接输出
        echo "$line"
    fi
done

# 获取原始命令的退出码
exit ${PIPESTATUS[0]}

