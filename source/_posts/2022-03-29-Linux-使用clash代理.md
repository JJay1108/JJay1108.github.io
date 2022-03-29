---
title: Linux 使用clash代理
date: 2022-03-29
---



# Linux如何使用clash服务？

继上次随手写了篇关于Linux虚拟机如何使用clash代理的服务之后，

我大概在寒假结束前的一个礼拜（我隔了一个月才写）探索出了Linux虚拟机直接使用clash服务的方法（而不是以前用那种Host主机开启LAN的方法……那种方法多少有点残废，且网速很堪忧）

## 第一种，直接下载config文件并使用

```shell
wget https://....
```

wget+相应链接即可。

如果没有安装`wget`，需要输入：`sudo apt install wget`

之后输入`./clash -d .`

如果发现输出的不是`starting download MMDB`，而是输出什么`start listening mixed port 9090`(*注，这里指的是第一次使用clash*)

这里可惜现在当前路径下输入`ls`查看当前目录下的文件，如果有`config.yaml`和`config.yml`文件的话，可以先分别打开这两个文件进行查看，默认的配置后缀名是`yaml`，我下载的服务配置文件则是`yml`后缀，这个时候，只要删除自动生成的`.yaml`文件，并将订阅的`.yml`文件后缀名修改为`.yaml`即可

## 第二种，直接从你的Windows PC 上copy配置文件到Linux上就行，

因为在没有良好网络环境的情况下，很有可能无法下载对应的代理配置。但是有`windows`服务能够使用，所以`copy`配置文件到Linux上也是可行的。

## 另，Country.mmdb的下载

这个文件下载起来速度相当缓慢，建议采用copy的方法（直接下载还是比较耗时的）。



Linux上简单的网络配置不需要我多说了，也是动动鼠标和键盘的事情。