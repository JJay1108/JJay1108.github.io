---
title: 对于Vim的一些学习感受以及Vim for C/C++配置推荐
date: 2022-01-09
tags:
- vim
- 折腾
categories:
- 环境/工具配置
---

# 初学者对于Vim的一些学习感受以及Vim for C/C++配置推荐

## 前言

~~话说自己很久没有写过文章了，~~上次写东西还是写了一篇关于termux的使用。

期末考完了，我也彻底boom了，十二月一直在肝各种ddl，什么计网实验，公共课期末考核等等……这学期概率论和OS是我学的最不牢靠的两门课，计网倒是勉强还凑合。再加上我校按排名定GPA（~~什么nc规定啊~~），这学期前本还想着好好学习，想办法把成绩拉上来一点好出去读水硕混个学历，结果大概率这学期是没了。



### 话说回来，我为什么要学习并配置Vim？

因为我想在Linux环境下写代码。Linux相较于Windows，配置环境也更加的方便。~~Windows下用VSCode写C/C++的经历给我整吐了。~~

有兄弟可能会说：用VSCode不香吗？用IDE(如CLion, QT Creator，轻量的有Code::Blocks, CodeLite, Geany......)不香吗？

我觉得，确实很香！好用就完事了啊！！！！

**但如果我没有图形化界面怎么办？**~~虽然我本机用图形化界面~~

这个学期我租用了某云的轻量应用服务器；只能用Terminal远程SSH写程序的我，自然逃不掉Vim的使用了。



除了这个所谓的“**刚需**”，个人学习Vim操作并配置Vim，纯粹是自己喜欢折腾，想尝试新东西（对我个人来说），并且这学期我还“有时间”。（问就是这学期代码量少得可怜，所以有“时间”瞎搞，~~另外不拿键盘敲点什么，人就感觉不舒服~~）



### 参考的一些资料

这里也得感谢某乎，精准推送了Vim相关内容，我就进了Vim的坑。

另外，某乎以及广大的互联网世界有不少大佬出没，如@韦易笑，会分享一些Vim相关配置还有好用的插件介绍。有兴趣的同学可以自行搜索~



## 正文

本文是写给刚入坑Vim的新人的，希望能对各位同学有所帮助。接下来从**如何上手**，一些**键位技巧（辅助记忆）**，**Vim个性化配置**等分别来介绍。写这篇文章时，本人使用的环境是：Debian 11, Vim 8.2	（Ubuntu20.04，Vim8.1应该也是适用的）

### 如何上手

在Linux环境下安装Vim是很简单的，只需要命令行输入`sudo apt install vim`即可（如果是普通用户）。

终端中输入`vim --version`，即可查看Vim版本，以及一些功能的支持。例如：

![image-20220109023231766](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109023231.png)

最简单粗暴的一个方法，上网搜索Vim键位去多打多练，形成所谓的肌肉记忆。

另外，直接在终端里输入`vimtutor`，跟着官方教程来练习也是个不错的选择。但前提是你英语过得去，不过网上也有vimtutor中文翻译可供参考。

另外我还看过一个不错的vim教程《简明Vim练级攻略》，大家可以自行搜索。

但熟练掌握Vim键位还是需要不断地练习，这个过程可能会比较痛苦。（这也许就是Vim劝退大部分人的原因吧）但掌握了Vim键位，敲击键盘的感觉真的让人很舒服。



### 键位记忆技巧

Vim作为一种编辑器，其特点就是命令及输入内容的分离。Vim有多个模式，最常用的是Insert插入模式以及Normal常规模式。

当然还有其他的一些模式，比如Visual可视模式，也是很常用的。

所以可以根据首字母来进入不同的模式。刚进入Vim，默认是在Normal常规模式下。比如输入`i`进入Insert 模式， 输入`v`进入Visual可视化模式。敲`<ESC>`键则是离开当前模式，回到Normal模式。在Normal模式下输入`:`则是进入了命令模式，比如stackoverflow的高赞问题 *如何退出Vim编辑器？*输入`:q`即可。（q代表quit）

**这里我想先特别强调出一个键位** `<ESC>`，这个键位可以说是除了英文字母以外，使用频率很高的一个键。但！这个键却在大部分键盘上，离我们的手相当的远，未免有些反人类了。这里提供一些解决方法：

1. 更改键盘映射，把CAPS LOCK映射成CTRL
2. 用`ctrl` + `[` 代替`Esc`键，在vim中，ctrl + [ 是等效于Esc键的。
3. 对于输入`ctrl`键，对于一大部分人来说，仍然是不太顺利的。这个时候可以选择如同(1)的方法，互换CAPS LOCK和Ctrl的映射。此外，我根据网上的讨论，发现有前辈选择用小拇指根，或者手掌的外边沿侧（大约是靠近小指以下的区域）去敲击`Ctrl`。本以为这样误触会比较多，但实际体验下来，几乎是没有误触，只是感觉可能会略有些奇怪hh
4. 自定义配置，映射某些键作为`ESC`，这个待会儿具体在**自定义配置**部分讨论。

我本人使用的是`ctrl`+`[`来代替escape键，体验也很顺畅，没有什么问题（除了有的时候力气太小导致ctrl没触发到）。

*顺便说句，为什么有些键位那么的反人类？因为，那个时候的键盘布局和现在还是有挺大区别的。默认的键位映射放到现在，也是属于“历史遗留问题”了*



**说回正题！**vim的键位是比较复杂的，功能也很多，例如`y`,`gg`,`G`,`i`,`A`,`d`,`o`,`0`等等。

`y`的作用是复制，输入`yy`则会复制当前光标所在行。`y`其实代表的是 yank，有复制的含义。

再比如，`dd`是删除当前行，`dw`则是删除当前光标到下一个空格的内容。`daw`则是可以删除当前光标所在单词（delete a word）。还有`di(` `di[`,这是删除相应括号内的内容（delete in ()/ delete in []）。

还有`A`键，光标会移动到当前行末尾，并进入Insert模式。A代表Append.....

通过英文单词来辅助记忆一些键位，并加以一定量的训练。正常流畅的使用是指日可待的。



### Vim个性化配置

Vim有一批“信徒”“狂热爱好者”的原因就是：Vim可以自由定制，自己想怎么玩怎么玩。几乎想映射什么键到什么键都可以实现！

Vim的配置文件是`.vimrc`，可以在用户目录`home/username/`下进行配置。

进入用户目录，终端中输入`vim .vimrc`，即可创建Vim的配置文件。

>  另外：
>
> 还有人习惯在用户目录下创建`.vim`文件夹，然后在`.vim`文件夹中新建一个Vim配置文件（这样做可以方便使用git，对.vim文件夹进行同步，从而达到不同机器上的配置统一）。
>
> 我个人的习惯也是用户目录下创建一个.vimrc文件，随后在~/.vim/.vimrc中配置真正想要
>
> 至于~/.vimrc的内容，如下所示，仅一行即可：

![image-20220109041759482](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109041759.png)



> 如果采用和我类似方法的同学这里不要有差错或遗漏，否则可能会报错。

#### 一些基本的..

下面是个人Vim配置的一小部分

```
set showtabline=2	"tabline强制显示
set nu				"在一旁显示行号
set tabstop=4
set shiftwidth=4	“这行和上一行是负责设置缩进宽度
set autoindent		"设置自动缩进
set cursorline		"使得当前光标所在行出现一条下划线（标明所在行，就和一把尺子一样）
set showcmd			"可以显示正输入的命令
set ruler			"显示光标现在的位置（坐标）
set syntax=on
```

相信各位也发现了，`vimscript`的语法并不难，自己也可以通过模仿别人的样例，来修修改改，配置自己的`.vimrc`。



#### leader键是干嘛用的？

接下来是关于`leader`键的设置，`leader`键对于vim个性化操作是非常重要的。

`let mapleader=','`我这里直接把`leader`设为了`,`，这里完全可以根据个人喜好来设置。

如果有同学和我一样，**对Vim配置文件需要做大量修改的**。可以选择定制键位如下：

```js
"quickly edit the .vimrc
nnoremap <silent> <leader>ee :e ~/.vim/.vimrc<CR>	"<CR>是回车键
```

这样，在Normal模式下，输入leader键+连续两个`e`，就能快速打开`.vimrc`来进行查看并编辑。

**注：**这里的`nnoremap` 实际含义是(in)normal mode, no re- map，意指在normal模式下，不进行重映射（重映射也就是键位可以映射再映射的意思），一次映射完结束。

同理，`inoremap` 实际含义是(in)insert mode, no re- map



#### Vim难道也有外观党？

大部分同学通常会发现，一些大佬的Vim配置得“花里胡哨”，功能多还好看！

下面是一些外观方面的设置

```json
if exists('$TMUX')
	set term=screen-256color
endif
//兼容TMUX的使用

colorscheme koehler 	"设置Vim主题颜色为koehler
"colorscheme solarized
"colorscheme desert 	
```

你可以使用Vim时，进入Normal模式，然后输入`:colorscheme `+ 你喜欢的颜色，

例如`:colorscheme solarized`，就可以查看当前颜色主题（solarized）下的效果。

然后在`.vimrc`里，固定下你想要的颜色即可（当然也可以设置随机配色）

**虽然，更加重要的是，终端的颜色。。！！！**



#### C/C++快速编译+运行一段代码

如下所示：

```json
"---------------QUICK COMPILE---------
nnoremap r :call CompileRunGcc()<CR>

function! CompileRunGcc()
	execute "w"
	if &filetype == 'c'
		if !isdirectory('build')
			execute "!mkdir build"
		endif	
		execute "!gcc % -o build/%< -g"
		execute "!time ./build/%<"
	endif	

	if &filetype == "cpp" 
		if !isdirectory('build')
			execute "!mkdir build"
		endif	
		execute "!g++ % -o build/%< -g"
		execute "!time ./build/%<"
	endif
endfunction	
```

比如写了一个hello_world.cpp，进入normal模式，然后按下r，就能直接在当前目录下编译，并把可执行文件放入了当前目录的`build`文件夹中（不污染代码文件），并执行可执行文件。

