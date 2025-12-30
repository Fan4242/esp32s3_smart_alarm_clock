# Git 常用命令速查表

本文档整理了 Git 最常用的命令，帮助快速上手 Git 版本控制。

## 1. 初始化和配置

### 初始化仓库
```bash
git init                    # 在当前目录初始化 Git 仓库
git clone <url>            # 克隆远程仓库到本地
```

### 配置用户信息
```bash
git config --global user.name "Your Name"          # 设置全局用户名
git config --global user.email "your.email@example.com"  # 设置全局邮箱
git config --list          # 查看所有配置
```

## 2. 基本操作

### 添加和提交文件
```bash
git add <file>             # 添加指定文件到暂存区
git add .                  # 添加当前目录所有修改的文件
git add -A                 # 添加所有修改、新增、删除的文件

git commit -m "提交信息"     # 提交暂存区的文件
git commit -am "提交信息"   # 添加并提交所有修改的文件（跳过新文件）
git commit --amend         # 修改最后一次提交
```

### 查看状态和历史
```bash
git status                 # 查看工作区和暂存区的状态
git log                    # 查看提交历史
git log --oneline          # 简洁的提交历史（一行显示）
git log --graph --oneline  # 图形化显示分支历史
git diff                   # 查看工作区和暂存区的差异
git diff --staged          # 查看暂存区和最后提交的差异
```

## 3. 分支操作

### 分支管理
```bash
git branch                 # 查看本地分支
git branch -a              # 查看所有分支（包括远程）
git branch <branch-name>   # 创建新分支
git checkout <branch-name> # 切换到指定分支
git checkout -b <branch-name>  # 创建并切换到新分支
git branch -d <branch-name>    # 删除分支
git branch -D <branch-name>    # 强制删除未合并的分支
```

### 分支合并
```bash
git merge <branch-name>    # 合并指定分支到当前分支
git rebase <branch-name>   # 变基，将当前分支的提交应用到指定分支上
```

## 4. 远程仓库操作

### 远程仓库管理
```bash
git remote -v              # 查看远程仓库信息
git remote add origin <url> # 添加远程仓库
git remote remove origin   # 删除远程仓库
git push -u origin main    # 推送分支并设置上游分支
git pull                   # 拉取并合并远程分支
git fetch                  # 仅拉取远程分支，不合并
```

### 推送和拉取
```bash
git push origin <branch>   # 推送本地分支到远程
git push -f origin <branch> # 强制推送（谨慎使用）
git pull origin <branch>   # 拉取远程分支并合并
git pull --rebase origin <branch>  # 拉取并变基合并
```

## 5. 撤销和重置操作

### 撤销更改
```bash
git checkout -- <file>     # 撤销工作区的文件修改
git reset HEAD <file>      # 取消暂存区的文件
git reset --soft HEAD~1    # 撤销最后一次提交，但保留更改在暂存区
git reset --mixed HEAD~1   # 撤销最后一次提交，保留更改在工作区（默认）
git reset --hard HEAD~1    # 完全撤销最后一次提交和所有更改
```

### 恢复删除的文件
```bash
git checkout HEAD -- <file> # 从最后一次提交恢复文件
git reflog                  # 查看所有操作历史
git reset --hard <commit-hash>  # 重置到指定提交
```

## 6. 标签操作

```bash
git tag                     # 查看所有标签
git tag <tag-name>          # 创建轻量级标签
git tag -a <tag-name> -m "标签信息"  # 创建带注释的标签
git push origin <tag-name>  # 推送标签到远程
git tag -d <tag-name>       # 删除本地标签
```

## 7. 暂存操作（Stashing）

```bash
git stash                   # 暂存当前工作区更改
git stash save "描述信息"    # 带描述的暂存
git stash list              # 查看暂存列表
git stash apply             # 应用最新的暂存
git stash apply stash@{n}   # 应用指定的暂存
git stash drop              # 删除最新的暂存
git stash pop               # 应用并删除最新的暂存
```

## 8. 其他常用命令

### 查看和比较
```bash
git show <commit>           # 查看指定提交的详细信息
git blame <file>            # 查看文件的每一行是谁最后修改的
git grep "关键词"            # 在代码中搜索关键词
```

### 清理和维护
```bash
git clean -f                # 删除未跟踪的文件
git clean -fd               # 删除未跟踪的文件和目录
git gc                      # 垃圾回收，优化仓库大小
```

## 9. 工作流程示例

### 标准工作流程
```bash
# 1. 查看状态
git status

# 2. 添加修改
git add .

# 3. 提交更改
git commit -m "完成功能开发"

# 4. 推送到远程
git push origin main
```

### 处理冲突的流程
```bash
# 1. 拉取最新代码
git pull origin main

# 2. 如果有冲突，手动解决冲突文件

# 3. 添加解决后的文件
git add <conflicted-file>

# 4. 完成合并
git commit
```

## 10. 常用快捷命令

```bash
# 查看简洁状态
git status -s

# 查看最近5次提交
git log -5 --oneline

# 创建并切换分支
git checkout -b feature/new-feature

# 强制推送当前分支
git push -f origin HEAD

# 查看分支图
git log --graph --decorate --oneline
```

## 注意事项

1. **谨慎使用强制推送** (`git push -f`)：这会覆盖远程分支的历史
2. **定期提交**：养成频繁提交的习惯，避免一次性提交过多更改
3. **写清晰的提交信息**：提交信息应该描述做了什么，而不是怎么做的
4. **使用分支开发**：在功能分支上开发，避免直接在主分支上修改
5. **备份重要更改**：使用 `git stash` 或创建分支来保存临时更改

## 常用 Git 术语

- **Repository（仓库）**：Git 项目的工作目录
- **Working Directory（工作区）**：当前正在工作的目录
- **Staging Area（暂存区）**：准备提交的更改区域
- **Commit（提交）**：保存到仓库的快照
- **Branch（分支）**：指向提交的轻量级指针
- **HEAD**：指向当前分支的指针
- **Origin**：默认的远程仓库别名

---

*本文档基于 Git 常用操作整理，建议结合实际项目练习使用。*