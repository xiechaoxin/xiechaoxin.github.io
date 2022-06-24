---
title: mac(intel)安装iterm+ohmyzsh
category: 
  - tools
  - mac装机参考
tags:
  - tools
  - mac装机参考
date: 2022-06-17 17:59:12
---

---
版权声明：本文为CSDN博主「sHlsy1995」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_35104586/article/details/103604964
---





Mac系统默认使用dash作为终端，可以使用命令修改默认使用zsh：

```bash
chsh -s /bin/zsh
```

如果想修改回默认dash，同样使用chsh命令即可：

```bash
chsh -s /bin/bash
```







### 安装Oh my zsh

安装方法有两种，可以使用curl或wget，看自己环境或喜好：



```bash
# curl 安装方式

sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```



```bash
# wget 安装方式

sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
```







原地址被墙了
更为使用国内的项目地址
项目mirror地址: https://gitee.com/mirrors/oh-my-zsh

以下命令功能下载我修改过的ohmyzsh的install.sh并执行，改变了文件中指向的git仓库从github移到gitee。 如果有问题欢迎留言。

via curl

```
sh -c "$(curl -fsSL https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
```


via wget

```
sh -c "$(wget -O- https://gitee.com/shmhlsy/oh-my-zsh-install.sh/raw/master/install.sh)"
```

![image-20220606085950536](mac(intel)安装iterm+ohmyzsh/image-20220606085950536.png)





安装好了就挑选你的主题吧

[Themes · ohmyzsh/ohmyzsh Wiki (github.com)](https://github.com/ohmyzsh/ohmyzsh/wiki/themes)



当然，你不太熟悉上面的操作，可以直接打开 `.zshrc` 的文件，然后用普通的编辑器直接修改那个 `ZSH_THEME` 的值，最后保存就好。

上面介绍的都是 oh-my-zsh默认自带了一些默认主题，存放在 `~/.oh-my-zsh/themes` 目录中。

你可以在终端输入 `cd ~/.oh-my-zsh/themes && ls` 就可以观察到。

