#!/bin/bash
# ESP-IDF 编译别名配置
# 使用方法: source build_aliases.sh
# 或者添加到 ~/.bashrc 中: source /path/to/build_aliases.sh

# 获取脚本所在目录
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 彩色编译命令别名
alias cbuild="$SCRIPT_DIR/colorize_build.sh idf.py build"
alias cclean="$SCRIPT_DIR/colorize_build.sh idf.py clean"
alias cfullclean="$SCRIPT_DIR/colorize_build.sh idf.py fullclean"
alias cflash="$SCRIPT_DIR/colorize_build.sh idf.py flash"
alias cmonitor="$SCRIPT_DIR/colorize_build.sh idf.py monitor"
alias call="$SCRIPT_DIR/colorize_build.sh idf.py build flash monitor"

# 显示使用说明
echo "已加载编译别名:"
echo "  cbuild      - 彩色编译 (idf.py build)"
echo "  cclean     - 彩色清理 (idf.py clean)"
echo "  cfullclean - 彩色完全清理 (idf.py fullclean)"
echo "  cflash     - 彩色烧录 (idf.py flash)"
echo "  cmonitor   - 彩色监控 (idf.py monitor)"
echo "  call       - 彩色编译烧录监控 (idf.py build flash monitor)"
echo ""
echo "或者直接使用: ./colorize_build.sh idf.py build"

