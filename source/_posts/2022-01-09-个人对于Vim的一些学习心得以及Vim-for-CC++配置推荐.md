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

已经有很长时间没有写过什么总结或者知识点整理了，上次写东西还是写了一篇关于termux的使用。

期末考完了，我也彻底boom了，十二月一直在肝各种ddl，什么计网实验，公共课期末考核等等……这学期概率论和OS是我学的最不牢靠的两门课，计网倒是勉强还凑合。再加上我校按排名定GPA（~~什么nc规定啊~~），这学期前本还想着好好学习，想办法把成绩拉上来一点好出去读水硕混个学历，结果大概率这学期是没了。



### 话说回来，我为什么要学习并配置Vim？

因为我想在Linux环境下写代码，Windows对于我更适合日常娱乐。Linux相较于Windows，配置环境也更加的方便。（但烦人的地方还是烦）

有兄弟可能会说：Linux环境下用VSCode不香吗？用IDE(如CLion, QT Creator，轻量的有Code::Blocks, CodeLite, Geany......)不香吗？

我觉得，确实很香！好用就完事了啊！！！！

***但如果我没有图形化界面怎么办？***

这个学期我租用了某云的轻量应用服务器；只能用Terminal远程SSH写程序的我，自然逃不掉Vim的使用了。

除了这个所谓的“**刚需**”，个人学习Vim操作并配置Vim，纯粹是自己喜欢折腾，想尝试新东西（对我个人来说），并且这学期我还“有时间”。（问就是这学期代码量少得可怜，所以有“时间”瞎搞，~~另外不拿键盘敲点什么，人就感觉不舒服~~）

**另外，**

**这篇文章不敢说是什么入门教程，连“学习心得”都不一定算得上，但我想分享一些我自己配置折腾Vim的感受，请各路大佬或者IDE党勿喷！绝无显摆或是踩一捧一的意思）**我也没有上过y总的Linux课，文章内容若存在重复的，请见谅！



### 参考的一些资料

这里也得感谢某乎，精准推送了Vim相关内容，我就进了Vim的坑。

另外，某乎以及广大的互联网世界（包括AcWing在内）有不少大佬出没，如@韦易笑，会分享一些Vim相关配置还有好用的插件介绍。有兴趣的同学可以自行搜索~



## 正文

本文是面向刚入坑Vim的新人的（其实我也是新人），希望能对同学们有所帮助。接下来从**如何上手**，一些**键位技巧（辅助记忆）**，**Vim个性化配置**等分别来介绍。在写这篇文章时，本人使用的环境是：Debian 11, Vim 8.2	（Ubuntu20.04，Vim8.1应该也是适用的）

### 如何上手

在Linux环境下安装Vim是很简单的，只需要命令行输入`sudo apt install vim`即可（如果是普通用户）。

终端中输入`vim --version`，即可查看Vim版本，以及一些功能的支持。例如：

![image-20220109023231766](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109023231.png)

最简单粗暴的一个方法，上网搜索Vim键位去多打多练，形成所谓的肌肉记忆。

另外，直接在终端里输入`vimtutor`，跟着官方教程来练习也是个不错的选择。但前提是你英语过得去，不过网上也有vimtutor中文翻译可供参考。

另外我还看过一个不错的vim教程*《简明Vim练级攻略》*，大家可以自行搜索。

但熟练掌握Vim键位还是需要不断地练习，这个过程可能会比较痛苦。（这也许就是Vim劝退大部分人的原因吧）但掌握了Vim键位，敲击键盘的感觉真的让人很舒服。



### 键位记忆技巧

Vim作为一种编辑器，其特点就是命令及输入内容的分离。Vim有多个模式，最常用的是Insert插入模式以及Normal常规模式。

当然还有其他的一些模式，比如Visual可视模式，也是很常用的。

所以可以根据首字母来进入不同的模式。刚进入Vim，默认是在Normal常规模式下。比如输入`i`进入Insert 模式， 输入`v`进入Visual可视化模式。敲`<ESC>`键则是离开当前模式，回到Normal模式。在Normal模式下输入`:`则是进入了命令模式，比如stackoverflow的高赞问题 *如何退出Vim编辑器？*输入`:q`即可。（q即quit）

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

Vim的配置文件是`.vimrc`，可以在用户目录`home/username/` 也就是`~`目录下进行配置。

终端中输入`vim ~/.vimrc`，即可创建Vim的配置文件。

>  另外：
>
> 还有人习惯在用户目录下创建`.vim`文件夹，然后在`.vim`文件夹中新建一个Vim配置文件，即`vim ~/.vim/.vimrc`（这样做可以方便使用git，对.vim文件夹进行同步，从而达到不同机器上的配置统一）。
>
> 我个人的习惯也是用户目录下创建一个.vimrc文件，即`vim ~/.vimrc`，随后在~/.vim/.vimrc中配置真正想要
>
> 至于`~/.vimrc`的内容，如下所示，仅一行即可：

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
set cursorline		"使得当前光标所在行出现一条下划线，以标明所在行
set showcmd			"可以显示正输入的命令
set ruler			"显示光标现在的位置（坐标）
set syntax=on
```

相信各位也发现了，`vimscript`的语法并不难，自己也可以通过模仿别人的样例，来修修改改，配置自己的`.vimrc`。



#### leader键是干嘛用的？

接下来是关于`leader`键的设置，`leader`键对于vim个性化操作是非常重要的。

`let mapleader=','`	我个人把`leader`设为了逗号`,`		而这里完全可以根据个人喜好来设置。

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

if has ('gui_running')
	set background=light
else
	set background=dark
endif

set t_Co = 256

if has ("termguicolors")
	set termguicolors
endif
```

你可以使用Vim时，进入Normal模式，然后输入`:colorscheme `+ 你喜欢的颜色，

例如`:colorscheme solarized`，就可以查看当前颜色主题（solarized）下的效果。

然后在`.vimrc`里，固定下你想要的颜色即可（当然也可以设置随机配色）

**虽然，更加重要的是，终端的颜色...！！！**



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

比如写了一个hello_world.cpp，进入normal模式，然后按下`r`，就能直接在当前目录下编译，并把可执行文件放入了当前目录的`build`文件夹中（不污染代码文件），并执行可执行文件。



### Vim插件

网上有很多，包括AcWing上也有不少大佬，分享了自己的Vim配置，包括括号补全这种功能也是手动实现。我只能说一句respect！

但正是丰富的Vim插件，让我彻底爱上了这款编辑器。喜欢DIY电脑的我，也特别享受给自己编辑器装插件，实现功能的过程。

但在此之前，我要先介绍一款插件管理工具：`vim-plug`，这将大大方便Vim维护插件的易用性。



#### 插件管理工具：vim-plug

详细的如何安装，如何使用可以参考Github上该项目的README。

但可能安装该工具（包括后续安装插件）会遇到一些网络问题（原因懂得都懂），可以采取科学上网的方式解决；或是换镜像源来方便使用。换源的方式可以自行查询；如果有可能，我也可能会写一篇有关Linux环境遇到的坑。



#### 有关写代码、阅读代码的插件

声明：这些插件几乎全部可以在Github上找到，一些如何安装、使用的基本问题以官方文档为准。在这里还推荐一个网站叫VimAwesome，是对刚接触插件的新人的一个”宝藏网站“。

1. `vim-cpp-enhanced-highlight`

   提供C/C++的高亮显示

2. `auto-pairs`

   这个顾名思义，就是提供了括号补全功能

3. `ale`

   这个插件就比较有意思了，支持异步检错，同时它还可以和`cppcheck`等工具产生类似“联动”的效果，可能的内存泄漏都能检测出来。~~虽然我cppcheck就被配置成功过~~	但是`ale`也是一个非常庞大的插件，功能也不仅仅限于检错这一种，所以ale也需要自己的配置；也可参考网上大佬的配置。

4. `YouCompleteMe`,简称YCM

   一款很强的智能补全插件（支持多语言），但要一番功夫进行配置。本人并没有采用YCM.

5. `coc.nvim`

   这款插件，我最初知道是因为它能比较方便地进行补全（同样支持多语言）。但实际上，`coc`的野心绝不至于此，他的目标似乎是把Vim打造成另一个VSCode（？？？）这里就不做过多的阐述，感兴趣的同学可以自行查询资料。
   
   这是我个人使用`coc.nvim`的效果图：
   
   ![image-20220109213343483](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109213343.png)
   
6. 配置`ctags`和`gutentags`

   tags其实是阅读项目所需要的。这里由于篇幅限制，就不再赘述。

7. `nerdtree`

   这款插件，提供了文件树的效果。

   但我现在已经把他替换成了`coc-explorer`，而这是`coc.nvim`的扩展插件（属于是插件的插件，套娃了）

8. `LeaderF`（需要python支持）

   这是一款支持模糊查找的插件，也是国人开发的一款Vim插件，功能很多，也很好用，我直接将之替代了下面的Tagbar

9. `tagbar`

   配置好tags之后，tagbar就能在一旁显示出效果。

   这是`tagbar`的效果图：

   ![image-20220109205929880](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109205930.png)

   *当然，这是github上一个sudoku项目的代码，不是我自己的代码....*



​		这是之前所提到的我用来替代`tagbar`的东西，这也只是`Leaderf`的其中一个功能而已（当然也需要tags已经配置好）...:

​		![image-20220109210159269](https://gitee.com/jasonstudyield/imagesbed/raw/master/20220109210159.png)



#### 外观插件

1. `vim-airline`
2. `vim-airline-themes`
3. `vim-airline-clock`

这三个插件以`airline`为基础，给较为单调的Vim界面增添了几分活力（其实就是上图中，底部状态栏一样的东西）。`airline`也有不少可以设置的地方，留下了给外观党折腾的空间。



#### 补充

未提到的插件（如`vim-spector`，据说是一款debug神器），我自己可能未上手体验过，或是遗忘了。在这里就不做贸然的推荐，了解的大佬也可以补充~

另外有些插件需要一定环境的支持，比如`Leaderf`需要Python支持，Debian软件源中的Vim似乎并不支持python，还需要下载源码进行手动编译安装，过程较复杂，且容易出错（但Ubuntu就不用）。	而很好用的`coc.nvim`功能多，也需要nodejs的支持。如遇到插件的问题，还是要多参考官方docs/wiki。



## 后记

写完这篇文章，我开始思考：*我配置Vim的意义在哪里？*

我喜欢在自己感兴趣的东西上投入时间，我也没有因为配置Vim，而荒废了学业（虽然这学期我的OS理论课和实践大概率糊了）。我也不是一个喜欢打游戏的人，Steam库的游戏吃灰一个学期了就没打过，在课余时间折腾Linux也好，Vim也好，搞内网穿透也好，也算是我娱乐的一种方式吧。另外，仍有一批前辈在给Vim 或 Neovim 贡献自己的力量，也非常感谢这些前辈的努力！

期末前，恰应计网实践课要求，拿自己配置的Vim写了个简单的socket的demo程序，体验还ok。

这也是我第一次写那么长的总结。**若有需要提意见的，都可以在评论区直接指出，我将不胜感激。**（如果这东西真有人看的话）



这个寒假不出意外，我会多刷点算法题，数据结构这块我一直学的不扎实；另外学学网络编程这方面的东西；还有太多要补的： Makefile, gdb,  CMake, etc. 下学期要学数据库了，寒假里试着跟个CMU15-445学学其实也不错。虽然现在列了很多要做的，但哪怕最后只有一件事情做好了，也还不错了233



