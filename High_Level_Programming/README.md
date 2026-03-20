# 个人物品管理程序

## 前言

本项目为转专业后的一次大的实验作业，高级语言程序设计，写出来放上 GitHub以供老师审批、后人参考，如有问题请题issue。

## 规范

个人物品管理程序（英文：Personal Belongings Management，为了方便，以后在项目和其他地方都简称为：PBM）

参照自己以往项目的文件命名规范[[[TrialNeo/Digghper: 后端开发的“毛胚房”，接入gorm+fiber+jwt+redis,实现web后端+scheduled job，“插件式”插拔开发，易拓展](https://github.com/TrialNeo/Digghper)]]README中的项目规范

文件开头需要有创建时间，创建人

**函数变量常量等**命名方式使用**下划线命名方法**，而且全小写，别用驼峰命名了（用习惯驼峰了，但是这里是c/cpp）。

由于c语言只能面向过程，限制特定对象的方法统一规范命名为：type_operation(&T,…..)

## 文件夹说明

2

| file_path | desc     |
| --------- | -------- |
| menu      | 菜单模块 |

## 数据相关

### 持久化存储

这点可以参考csv的文件格式，之前用pandas.read_csv其实还挺好用的

````txt
item,item
item2,item2
````



## 登录方面

*这里要做一个小小的加密，不然让别人盗用密码就不好了









## 开发工具

CLion

## 构建

### dev

其实cmake已经写好了，每次最多写一个

```cmd
cmake .
```

然后又写了一个脚本可以用一下

