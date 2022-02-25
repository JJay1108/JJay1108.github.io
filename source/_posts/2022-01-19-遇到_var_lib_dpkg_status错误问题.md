---
title: 遇到/var/lib/dpkg/status错误问题
date: 2022-01-19
tags: 
- 配置
categories:
- 环境/工具配置
---

# 遇到/var/lib/dpkg/status错误问题（软件包缓存错误）

在输入`apt-get update`或者类似`apt`命令时，可能会有本文中遇到的问题；

解决方法来自**CSDN**

[ ubuntu遇见/var/lib/dpkg/status错误_重在积累-CSDN博客_/var/lib/dpkg/status](https://blog.csdn.net/qq_33392383/article/details/86415037)

依次输入以下命令：

```shell
sudo mkdir -p /var/lib/dpkg/{alternatives,info,parts,triggers,updates}

sudo cp /var/backups/dpkg.status.0 /var/lib/dpkg/status

sudo apt-get download dpkg

sudo dpkg -i dpkg*.deb

sudo apt-get download base-files

sudo dpkg -i base-files*.deb

sudo apt-get update
sudo apt-get check
```

